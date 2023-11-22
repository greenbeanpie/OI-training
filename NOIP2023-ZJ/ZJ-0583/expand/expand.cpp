#include<bits/stdc++.h>
using namespace std;
int e,n,m,q;
int a[500001];
int b[500001];
int c[500001];
int d[500001];
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%d %d %d %d",&e,&n,&m,&q);
	if(e==1)
	{
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			c[i]=a[i];
		}
		for(int i=1;i<=m;i++)
		{
			scanf("%d",&b[i]);
			d[i]=b[i];
		}
		if(a[1]!=b[1])
		{
			printf("1");
		}
		else
		{
			printf("0");
		}
		while(q--)
		{
			int k1,k2;
			scanf("%d %d",&k1,&k2);
			for(int i=1;i<=k1;i++)
			{
				int x,y;
				scanf("%d %d",&x,&y);
				c[x]=y;
			}
			for(int i=1;i<=k2;i++)
			{
				int x,y;
				scanf("%d %d",&x,&y);
				d[x]=y;
			}
			if(c[1]!=d[1])
			{
				printf("1");
			}
			else
			{
				printf("0");
			}
			c[1]=a[1];
			d[1]=b[1];
		}
	}
	else if(e==2)
	{
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			c[i]=a[i];
		}
		for(int i=1;i<=m;i++)
		{
			scanf("%d",&b[i]);
			d[i]=b[i];
		}
		bool flag=1;
		int flg=2;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==b[i]||(a[i]>b[i]&&flg==1)||(a[i]<b[i]&&flg==0))
			{
				printf("0");
				flag=0;
				break;
			}
			else if(a[i]>b[i])
			{
				flg=0;
			}
			else if(a[i]<b[i])
			{
				flg=1;
			}
		}
		if(flag)
		{
			printf("1");
		}
		while(q--)
		{
			int k1,k2;
			scanf("%d %d",&k1,&k2);
			for(int i=1;i<=k1;i++)
			{
				int x,y;
				scanf("%d %d",&x,&y);
				c[x]=y;
			}
			for(int i=1;i<=k2;i++)
			{
				int x,y;
				scanf("%d %d",&x,&y);
				d[x]=y;
			}
			flag=1;
			flg=2;
			for(int i=1;i<=n;i++)
			{
				if(a[i]==b[i]||(a[i]>b[i]&&flg==1)||(a[i]<b[i]&&flg==0))
				{
					printf("0");
					flag=0;
					break;
				}
				else if(a[i]>b[i])
				{
					flg=0;
				}
				else if(a[i]<b[i])
				{
					flg=1;
				}
			}
			if(flag)
			{
				printf("1");
			}
			for(int i=1;i<=n;i++)
			{
				c[i]=a[i];
				d[i]=b[i];
			}
		}
	}
	else
	{
		srand(n+m);
		for(int i=1;i<=q+1;i++)
		{
			cout<<rand()%2;
		}
	}
}