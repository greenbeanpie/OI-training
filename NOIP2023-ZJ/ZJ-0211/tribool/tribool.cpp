#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+5;
const int CAL = 1e9;
int c,t;
int n,m;
map<int,int> mp;
/*
first i * 1e9 + j means when you have operate for i round,the xj equals
second 1~n = x1~xn n+1~2n = !x1~!xn 2n+1 = T 2n+2 = F 2n+3=U
*/
int lst[N];
int fa[N];
int ans;
bool vis[N];
int col[N];
int w[N];
bool sp[N];
vector<int> G[N];
int siz;
bool flag;
queue<int> q;
void init()
{
	int i,j;
	for(i=1;i<=N-5;i++)
	fa[i]=i,G[i].clear();
}
int find(int x)
{
//	cerr<<x<<"\n";
	if(fa[x]!=x)
	fa[x]=find(fa[x]);
	return fa[x];
}
void merge(int x,int y)
{
	int fx=find(x),fy=find(y);
	if(fx==fy)return;
	fa[fx]=fy;
}
void bfs(int st)
{
	while(!q.empty())q.pop();
	q.push(st);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		if(sp[u])flag=true;
		siz+=w[u];
		vector<int>::iterator it;
		for(it=G[u].begin();it!=G[u].end();it++)
		{
			int v=*it;
			if(!vis[v])
			{
				col[v]=col[u]^1;
				vis[v]=true;
				q.push(v);
			}
			else
			{
				if(col[u]==col[v])
				flag=true;
			}
		}
	}
}
signed main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	int i,j;
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
//		cerr<<t<<"\n";
		ans=0;
		init();
		memset(sp,0,sizeof sp);
		memset(vis,0,sizeof vis);
		memset(lst,-1,sizeof lst);
		memset(w,0,sizeof w);
		memset(col,-1,sizeof col);
		mp.clear();
		cin>>n>>m;
		for(i=1;i<=m;i++)
		{
			char v;
			cin>>v;
			if(v=='T'||v=='F'||v=='U')
			{
				int x;
				cin>>x;
				if(v=='T')
				mp[i*CAL+x]=2*n+1;
				else if(v=='F')
				mp[i*CAL+x]=2*n+2;
				else
				mp[i*CAL+x]=2*n+3;
				lst[x]=i;
			}
			else if(v=='+')
			{
				int x,y;
				cin>>x>>y;
				if(lst[y]==-1)
				mp[i*CAL+x]=y;
				else
				mp[i*CAL+x]=mp[lst[y]*CAL+y];
				lst[x]=i;
			}
			else
			{
				int x,y;
				cin>>x>>y;
				if(lst[y]==-1)
				mp[i*CAL+x]=n+y;
				else
				{
					int val=mp[lst[y]*CAL+y];
					if(val==2*n+1)
					mp[i*CAL+x]=2*n+2;
					else if(val==2*n+2)
					mp[i*CAL+x]=2*n+1;
					else if(val==2*n+3)
					mp[i*CAL+x]=2*n+3;
					else if(1<=val&&val<=n)
					mp[i*CAL+x]=val+n;
					else
					mp[i*CAL+x]=val-n;
//					lst[x]=
				}
				lst[x]=i;
			}
		}
//		cerr<<"ARE YOU OK?\n";
		for(i=1;i<=n;i++)
		{
			if(lst[i]==-1)
			{
				continue;
			}
			else
			{
				int val=mp[CAL*lst[i]+i];
				if(1<=val&&val<=n)
				{
					merge(val,i);
				}
			}
		}
//		cerr<<"THANK YOU\n";
		for(i=1;i<=n;i++)
		{
			w[find(i)]++;
			if(mp[CAL*lst[i]+i]==2*n+3)
			sp[find(i)]=true;
		}
//		cerr<<"katomegumi\n";
//		w[find(i)]++;
//		cout<<find(i)<<" ";
//		cout<<"\n";
		for(i=1;i<=n;i++)
		{
			if(lst[i]==-1)
			{
				continue;
			}
			else
			{
				int val=mp[CAL*lst[i]+i];
				if(n+1<=val&&val<=2*n)
				{
					G[find(i)].push_back(find(val-n));
					G[find(val-n)].push_back(find(i));
//					cout<<find(i)<<" "<<find(val-n)<<"\n";
//					merge(val,i);
				}
			}
		}
//		cerr<<"nagisa\n";
		for(i=1;i<=n;i++)
		{
//			cerr<<i<<" "<<find(i)<<"\n";
//			if(find(i)<1||find(i)>1e5)
//			cerr<<i<<" "<<find(i)<<"\n";
			if(!vis[find(i)])
			{
				siz=0;
				flag=false;
				vis[find(i)]=true;
				col[find(i)]=0;
				bfs(find(i));
				if(flag)
				ans+=siz;
			}
		}
		cout<<ans<<"\n";
	}
}
