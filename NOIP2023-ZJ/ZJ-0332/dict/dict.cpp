//维护最大字符串
//完成于9：45
#include<bits/stdc++.h>
using namespace std;

int rd()
{
	int f=1,k=0;char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		k=k*10+c-'0';
		c=getchar();
	}
	return f*k;
}

const int N=3010;

int n,m,c;
char cmin[N][N],cmax[N][N];
//int f[N][LOGN];
bool yange=1;

bool cmp1(char a,char b)
{
	return a<b;
}

bool cmp2(char a,char b)
{
	return a>b;
}

int getmin(int a,int b)
{
	for(int i=0;i<m;i++)
	{
		if(cmax[a][i]<cmax[b][i])
		{
			yange=1;
			return a;
		}
		if(cmax[a][i]>cmax[b][i])
		{
			yange=1;
			return b;
		}
	}
	yange=0;
	return a;
}
//int query(int l,int r)
//{
//	int t=log2(r-l+1);
//	return getmin(f[l][t],f[r-(1<<t)+1][t]);
//}

int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	n=rd(),m=rd();
	c=1;
	for(int i=1;i<=n;i++)
	{
		scanf("%s",cmin[i]);
		for(int j=0;j<=m;j++)
		{
			cmax[i][j]=cmin[i][j];
		}
		sort(cmax[i],cmax[i]+m,cmp2);
		sort(cmin[i],cmin[i]+m,cmp1);
		c=getmin(c,i);
		//cout<<cmax[c][0]<<endl;
	}
	if(n==1)
	{
		cout<<1;
		return 0;
	}
//	for(int j=1;j<=n;j++)
//	{
//		for(int i=1;i+(1<<j)-1<=n;i++)
//		{
//			f[i][j]=getmin(f[i][j-1],f[i+(1<<(j-1))][j-1]);
//		}
//	}

//	for(int i=1;i<=n;i++)
//	{
//		cout<<cmin[i]<<" "<<cmax[i]<<"\n";
//	}
//	cout<<c<<endl;
	
	for(int i=1;i<=n;i++)
	{
		bool flag=0;
		if(i==c)
		{
			if(yange)
			{
				cout<<"1";
				continue;
			}
			for(int j=0;j<m;j++)
			{
				if(cmin[i][j]<cmax[c][j])
				{
					flag=1;
					break;
				}
				if(cmin[i][j]>cmax[c][j])
				{
					break;
				}
			}
			cout<<flag;
			continue;
		}
		for(int j=0;j<m;j++)
		{
			if(cmin[i][j]<cmax[c][j])
			{
				flag=1;
				break;
			}
			if(cmin[i][j]>cmax[c][j])
			{
				break;
			}
		}
		cout<<flag;
	}
	return 0;
}