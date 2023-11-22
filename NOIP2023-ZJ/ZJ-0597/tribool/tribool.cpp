#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
#define maxm 100005

struct node
{
	int u,v;
	int next;
}edge[maxn*4];
int head[maxn],cnt=0;


bool num[maxn],vis[maxn];

int C,t;


void add(int u,int v)
{
	edge[++cnt].next=head[u];
	edge[cnt].u=u;
	edge[cnt].v=v;
	head[u]=cnt;
}

int dfs(int u)
{
	
	int sum=0;
	
	for(int i=head[u];i;i=edge[i].next)
	{
		int v=edge[i].v;
		if(vis[v]==0)vis[u]=1,sum+=dfs(v);
	}
	if(num[u]==0)
	{
		num[u]=1;
		return sum+1;
	}
	if(num[u]==1)return sum;
}

int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	scanf("%d%d",&C,&t);
	if(C==5||C==6)
	{
		while(t--)
		{
			memset(head,0,sizeof(head));
			memset(num,0,sizeof(num));
			
			cnt=0;
			
			int n,m;
			int ans=0;
			scanf("%d%d",&n,&m);
			char absorb=getchar();
			for(int i=1;i<=m;i++)
			{
				char tmp=getchar();
				absorb=getchar();
				int x,y;
				if(tmp=='+')
				{
					scanf("%d%d",&x,&y);
					add(x,y);
					add(y,x);
				}
				else if(tmp=='U')
				{
					memset(vis,0,sizeof(vis));
					scanf("%d",&x);
					ans+=dfs(x);
				}
				absorb=getchar();
			}
			printf("%d\n",ans);
		}
	}
	if(C==7||C==8)
	{
//		while(t--)
//		{
//			int n,m;
//			scanf("%d%d",&n,&m);
//			char absorb=getchar();
//			for(int i=1;i<=m;i++)
//			{
//				char tmp=getchar();
//				absorb=getchar();
//				int x,y;
//				if(tmp=='+')
//				{
//					scanf("%d%d",&x,&y);
//					int xfa=findfa(x);
//					int yfa=findfa(y+n);
//					if(xfa==yfa)
//					{
//						ans+=cnt_num(xfa);
//					}
//					else
//					{
//						fa[x]=y;
//						fa[x+n]=y+n;
//					}
//				}
//				else if(tmp=='-')
//				{
//					scanf("%d%d",&x,&y);
//					int xfa=findfa(x);
//					int yfa=findfa(y);
//					if(xfa==yfa)
//					{
//						ans+=cnt_num(xfa);
//					}
//					else
//					{
//						fa[x+n]=y;
//						fa[x]=y+n;
//					}
//				}
//			}
//		}
	}
	
	
	
	return 0;
}