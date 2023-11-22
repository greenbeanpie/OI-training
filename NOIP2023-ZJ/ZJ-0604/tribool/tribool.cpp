#include<bits/stdc++.h>

using namespace std;

struct Node
{
	char vv;
	int ii,jj;
};

char Chan(char x)
{
	if (x=='T') return 'F';
	if (x=='F') return 'T';
	return 'U';
}

int c,t;
int n,m;

Node a[100010];

char b[100010],d[100010];
int minn;

bool CHec()
{
	for (int i=1;i<=n;i++)
	{
		if (d[i]!=b[i]) return false;
	}
	return true;
}

void dfs(int x,int s)
{
	if (s>minn) return ;
	if (x==n)
	{
		for (int i=1;i<=n;i++)
		{
			d[i]=b[i];
		}
		for (int i=1;i<=m;i++)
		{
			if (a[i].vv=='+')
			{
				d[a[i].ii]=d[a[i].jj];
			}
			else if (a[i].vv=='-')
			{
				d[a[i].ii]=Chan(d[a[i].jj]);
			}
			else
			{
				d[a[i].ii]=a[i].vv;
			}
		}
		
		if (CHec()) minn=min(s,minn);
		return ;
	}
	
	for (int i=1;i<=3;i++)
	{
		if (i==1)
		{
			b[x+1]='T';
			dfs(x+1,s);
		}
		else if (i==2)
		{
			b[x+1]='F';
			dfs(x+1,s);
		}
		else 
		{
			b[x+1]='U';
			dfs(x+1,s+1);
		}
	}
	
	return ;
}

int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	
	scanf("%d%d",&c,&t);
	
	if (c<=2)
	{
		for (int l=1;l<=t;l++)
		{
			minn=100010;
			scanf("%d%d",&n,&m);
			for (int i=1;i<=m;i++)
			{
				cin>>a[i].vv;
				if (a[i].vv=='+' || a[i].vv=='-')
				{
					scanf("%d%d",&a[i].ii,&a[i].jj);
				}
				else scanf("%d",&a[i].ii);
			}
			
			dfs(0,0);
			printf("%d\n",minn);
		}
			
		return 0;
	}
	if (c>=3 && c<=4)
	{
		for (int l=1;l<=t;l++)
		{
			scanf("%d%d",&n,&m);
			for (int i=1;i<=n;i++) b[i]='T';
			
			char ch;
			int iii;
			for (int i=1;i<=m;i++)
			{
				cin>>ch;
				scanf("%d",&iii);
				b[iii]=ch;
			}
			
			minn=0;
			for (int i=1;i<=n;i++)
			{
				if (b[i]=='U') minn++;
			}
			
			printf("%d\n",minn);
		}
		return 0;
	}
	if (c>=5)
	{
		for (int l=1;l<=t;l++)
		{
			minn=0;
			scanf("%d%d",&n,&m);
			for (int i=1;i<=m;i++)
			{
				cin>>a[i].vv;
				if (a[i].vv=='+' || a[i].vv=='-')
				{
					scanf("%d%d",&a[i].ii,&a[i].jj);
				}
				else scanf("%d",&a[i].ii);
			}
			for (int i=1;i<=n;i++)
			{
				b[i]='T';
			}
			for (int i=1;i<=m;i++)
			{
				if (a[i].vv=='+')
				{
					b[a[i].ii]=b[a[i].jj];
				}
				else if (a[i].vv=='-')
				{
					b[a[i].ii]=Chan(b[a[i].jj]);
				}
				else
				{
					b[a[i].ii]=a[i].vv;
				}
			}
			for (int i=1;i<=n;i++)
			{
				if (b[i]=='U') minn++;
			}
			
			printf("%d\n",minn);
		}
		return 0;
	}
	
	return 0;
}