//这题暴力挂掉了
//还有1h，预计得分100+40+5+44=189
//T3打的最久，得的最少
//现在还有15min，我的暴力还是挂的 
#include<bits/stdc++.h>
#define N 300200
using namespace std;
int c,n,m,q;
int a[N],b[N];
namespace sub1
{
	void main()
	{
		for(int i=1;i<=n;i++)scanf("%d",a+i);
		for(int i=1;i<=m;i++)scanf("%d",b+i);
		printf("%d",a[1]!=b[1]);
		a[2]=a[1];b[2]=b[1];
		for(int i=1,kx,ky;i<=q;i++)
		{
			scanf("%d%d",&kx,&ky);
			for(int j=1,p,v;j<=kx;j++)
			{
				scanf("%d%d",&p,&v);
				a[p]=v;
			}
			for(int j=1,p,v;j<=ky;j++)
			{
				scanf("%d%d",&p,&v);
				b[p]=v;
			}
			printf("%d",a[1]!=b[1]);
			a[1]=a[2];b[1]=b[2];
		}	
	}
}
namespace sub2
{
	int t[N];
	bool dfs(int now,int cnt)
	{
		if(now==n+1)
		{
			for(int i=1;i<=cnt;i++)
			{
				if(t[i]==0)
				{
					cnt=i-1;
					break;
				}
			}
			bool flag1=1,flag2=1;
			for(int i=1,j=1;i<=cnt;i++)
			{
				if(b[j]<=t[i])
				{
					j++;
					if(b[j]<=t[i]||j>m)
					{
						flag1=0;
						break;
					}
				}
				if(i==cnt&&j<m)
				{
					flag1=0;
					break;
				}
				if(m-j==cnt-i)
				{
					for(int k=1;k+j<=m;k++)
					{
						if(b[j+k]<=t[i+k])
						{
							flag1=0;
							break;
						}
					}
					break;
				}
			}
			for(int i=1,j=1;i<=cnt;i++)
			{
				if(b[j]>=t[i])
				{
					j++;
					if(b[j]>=t[i]||j>m)
					{
						flag2=0;
						break;
					}
				}
				if(i==cnt&&j<m)
				{
					flag2=0;
					break;
				}
				if(m-j==cnt-i)
				{
					for(int k=1;k+j<=m;k++)
					{
						if(b[j+k]>=t[i+k])
						{
							flag2=0;
							break;
						}
					}
					break;
				}
			}
			return flag1|flag2;
		}
		for(int i=1;i<=n;i++)
		{
			t[++cnt]=a[now];
			if(dfs(now+1,cnt))
			{
				return 1;
			}
		}
		return 0;
	}
	int aa[N],bb[N];
	void main()
	{
		for(int i=1;i<=n;i++)scanf("%d",a+i);
		for(int i=1;i<=m;i++)scanf("%d",b+i);
		printf("%d",dfs(1,0));
		for(int j=1;j<=n;j++)aa[j]=a[j];
		for(int j=1;j<=m;j++)bb[j]=b[j];
		for(int i=1,kx,ky;i<=q;i++)
		{
			scanf("%d%d",&kx,&ky);
			for(int j=1,p,v;j<=kx;j++)
			{
				scanf("%d%d",&p,&v);
				a[p]=v;
			}
			for(int j=1,p,v;j<=ky;j++)
			{
				scanf("%d%d",&p,&v);
				b[p]=v;
			}
			memset(t,0,sizeof(t));
			printf("%d",dfs(1,0));
			for(int j=1;j<=n;j++)a[j]=aa[j];
			for(int j=1;j<=m;j++)b[j]=bb[j];
		}
	}
}
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%d%d%d%d",&c,&n,&m,&q);
	if(c<=1)sub1::main();//5pts
	else if(c<=4)sub2::main();//0pts
}
/*
1 1 1 3
3
4
1 1
1 2
1 2
1 1
1 3
1 5
2 0
1 2
1 3
*/
