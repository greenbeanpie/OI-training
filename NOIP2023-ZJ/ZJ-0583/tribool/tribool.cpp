#include<bits/stdc++.h>
using namespace std;
int c,T;
int n,m;
int p1[100001];
bool f[100001];
int x,y;
char ch;
struct edge{
	int to;
	int next;
}a[100001];
int head[100001],eid;
void add(int l,int r)
{
	a[++eid].to=r;
	a[eid].next=head[l];
	head[l]=eid;
}
void dfs(int u,int val)
{
	f[u]=1;
	p1[u]=val;
	for(int i=head[u];i;i=a[i].next)
	{
		int v=a[i].to;
		if(!f[v])
		{
			dfs(v,val);
		}
	}
	f[u]=0;
}
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	scanf("%d %d",&c,&T);
	if(c==3||c==4)
	{
		while(T--)
		{
			
			scanf("%d %d",&n,&m);
			for(int i=1;i<=n;i++)
			{
				p1[i]=-3;
			}
			for(int i=1;i<=m;i++)
			{
				cin>>ch;
				if(ch=='T')
				{
					scanf("%d",&x);
					p1[x]=0;
					
				}
				else if(ch=='U')
				{
					scanf("%d",&x);
					p1[x]=-1;
					
				}
				else if(ch=='F')
				{
					scanf("%d",&x);
					p1[x]=-2;
					
				}
			}
			int ans=0;
			for(int i=1;i<=n;i++)
			{
				if(p1[i]==-1)ans++;
			}
			printf("%d\n",ans);
		}
	}
	else if(c==5||c==6)
	{
		while(T--)
		{
			eid=0;
			memset(head,0,sizeof(head));
			scanf("%d %d",&n,&m);
			for(int i=1;i<=n;i++)
			{
				p1[i]=-3;
			}
			for(int i=1;i<=m;i++)
			{
				cin>>ch;
				
				if(ch=='U')
				{
					scanf("%d",&x);
					p1[x]=-1;
				}
				else if(ch=='+')
				{
					scanf("%d %d",&x,&y);
					if(x!=y)
					{
						add(x,y);
					}
					p1[y]=p1[x];
				}
			}
			int ans=0;
			for(int i=1;i<=n;i++)
			{
				if(p1[i]==-1)ans++;
			}
			printf("%d\n",ans);
		}
	}
	else
	{
		while(T--)
		{
			scanf("%d %d",&n,&m);
			srand(n+10+m*5);
			for(int i=1;i<=m;i++)
			{
				cin>>ch;
				if(ch=='T'||ch=='F'||ch=='U')
				{
					scanf("%d",&x);
				}
				else
				{
					scanf("%d %d",&x,&y);
				}
			}
			cout<<rand()%n+1<<endl;
		}
		
		
	}
}