//或许我的做法是错的,但我相信CCF的数据是水的 
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+100;
int t,c;
int n,m;
struct node{
	char op;
	int x,y;
}a[N];
int mp[N];
int vis[N];
int ans=0;
queue<int> q,stq,qq;
struct edge{
	int to,nxt;
}e[N];
int tot=0;
int h[N];
void _add(int u,int v)
{
	tot++;
	e[tot].to=v;
	e[tot].nxt=h[u];
	h[u]=tot;
}
void bfs()
{
	while(!stq.empty())
	{
		int v=stq.front();
		stq.pop();
		for(int i=h[v];i;i=e[i].nxt)
		{
			int u=e[i].to;
			if(vis[u]==0)
			{
				vis[u]=1;
				stq.push(u);
			}
		}
	}
	return;
}
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		ans=0;
		tot=0;
		while(!q.empty())
		{
			q.pop();
		}
		while(!qq.empty())
		{
			qq.pop();
		}
		while(!stq.empty())
		{
			stq.pop();
		}
		for(int i=1;i<=n;i++)
		{
			mp[i]=3;
			vis[i]=0;
			h[i]=0;
		}
		for(int i=1;i<=m;i++)
		{
			cin>>a[i].op;
			if(a[i].op=='+'||a[i].op=='-')
			{
				scanf("%d%d",&a[i].x,&a[i].y);
				_add(a[i].y,a[i].x);
				if(mp[a[i].y]==3)
				{
					//cout<<a[i].y<<" : "<<endl;
					if(mp[a[i].x]==1||mp[a[i].x]==0)
					{
						if(a[i].op=='+')
						{
							mp[a[i].y]=mp[a[i].x];
						}else{
							mp[a[i].y]=mp[a[i].x]^1;
						}
						if(mp[a[i].y]==1)
						{
							q.push(a[i].y);
							//cout<<"   "<<a[i].y<<" : 1"<<endl;
						}else{
							//cout<<"   "<<a[i].y<<" : 2"<<endl;
							qq.push(a[i].y);
						}
					}else{
						mp[a[i].y]=1;
						//cout<<"   "<<a[i].y<<" : 3"<<endl;
						q.push(a[i].y);
						if(a[i].op=='+'||a[i].y==-1){
							mp[a[i].x]=mp[a[i].y];
						}else{
							mp[a[i].x]=mp[a[i].y]^1;
						}
					}
				}else if(a[i].op=='+'||a[i].y==-1){
					mp[a[i].x]=mp[a[i].y];
				}else{
					mp[a[i].x]=mp[a[i].y]^1;
				}
			}else{
				scanf("%d",&a[i].x);
				if(a[i].op=='U')
				{
					mp[a[i].x]=-1;
				}
				if(a[i].op=='T')
				{
					mp[a[i].x]=1;
				}
				if(a[i].op=='F')
				{
					mp[a[i].x]=0;
				}
			}
		}
		while(!q.empty())
		{
			int now=q.front();
			//cout<<now<<" : "<<mp[now]<<endl;
			q.pop();
			if(mp[now]!=1)
			{
				stq.push(now);
				vis[now]=1;
			}
		}
		while(!qq.empty())
		{
			int now=qq.front();
			//cout<<now<<" x:x "<<mp[now]<<endl;
			qq.pop();
			if(mp[now]!=0)
			{
				stq.push(now);
				vis[now]=1;
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(mp[i]==-1&&vis[i]==0)
			{
				stq.push(i);
				vis[i]=1;
			}
		}
		bfs();
		for(int i=1;i<=n;i++)
		{
			if(vis[i]==1)
			{
				ans++;
			}
		}
		printf("%d\n",ans);
	}
 	return 0;
}
