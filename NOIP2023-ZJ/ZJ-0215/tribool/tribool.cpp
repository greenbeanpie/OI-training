#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,m;
int a[100005];
int b[100005];
int xl[100005];
int xll;
int ans;
void sc()
{
	for(int i=2;i<=n+1;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	scanf("%d%d",&c,&t);
	for(int ti=1;ti<=t;ti++)
	{
		scanf("%d%d",&n,&m);
		for(int i=0;i<=n+1;i++)
		{
			a[i]=i;
			b[i]=0;
		}
		ans=0;
		for(int i=1;i<=m;i++)
		{
			char s[2];
			int x,y;
			scanf("%s",s);
			if(s[0]=='+')
			{
				scanf("%d%d",&x,&y);
				a[x+1]=a[y+1];
			}
			else if(s[0]=='-')
			{
				scanf("%d%d",&x,&y);
				a[x+1]=-a[y+1];
			}
			else
			{
				scanf("%d",&x);
				if(s[0]=='T')
				{
					a[x+1]=1;
				}
				else if(s[0]=='F')
				{
					a[x+1]=-1;
				}
				else
				{
					a[x+1]=0;
				}
			}
		}
		for(int i=2;i<=n+1;i++)
		{
			if(a[i]==i)
			{
				a[i]=1;
			}
			if(a[i]==-i)
			{
				a[i]=0;
			}
		}
		for(int i=2;i<=n+1;i++)
		{
			if(abs(a[i])>1)
			{
				int kk=i;
				b[i]=1;
				int ll=abs(a[kk]);
				xll=0;
				bool ys=0;
				while(!b[ll])
				{
					if(abs(a[ll])<=1)
					{
						xl[++xll]=kk;
						a[kk]=(a[kk]/ll)*a[ll];
						ys=1;
						break;
					}
					xl[++xll]=kk;
					b[ll]=(a[kk]/ll)*b[kk];
					kk=ll;
					ll=abs(a[kk]);
				}
				if(ys)
				{
					for(int j=xll-1;j>=1;j--)
					{
						a[xl[j]]=a[xl[j+1]]*b[xl[j]]*b[xl[j+1]];
					}
				}
				else if((a[kk]/ll)*b[kk]!=b[ll])
				{
					for(int j=1;j<=xll;j++)
					{
						a[xl[j]]=0;
					}
				}
				else
				{
					a[ll]=1;
					a[kk]=(a[kk]/ll);
					for(int j=xll-1;j>=1;j--)
					{
						a[xl[j]]=a[xl[j+1]]*b[xl[j]]*b[xl[j+1]];
					}
				}
				for(int j=1;j<=xll;j++)
				{
					b[xl[j]]=0;
				}
				xll=0;
				
			}
			if(a[i]==0)
			{
				ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
