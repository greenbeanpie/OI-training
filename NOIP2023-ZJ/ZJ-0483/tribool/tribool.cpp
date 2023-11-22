#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int t,n,m,ind,ans,a[N],f[N],f2[N],cnt[N],col[N];
bool flg,vis[N],vis2[N];
vector<int> e[N],e2[N];
queue<int> q;
void dfs1(int s,int num)
{
	int x;
	while(!q.empty())
	{
		q.pop();
	}
	vis[s]=1;
	f[s]=num;
	q.push(s);
	while(!q.empty())
	{
		x=q.front();
		q.pop();
		for(auto y:e[x])
		{
			if(!vis[y])
			{
				vis[y]=1;
				f[y]=f[x];
				q.push(y);
			}
		}
		if(x<=n&&!vis[x+n])
		{
			vis[x+n]=1;
			f[x+n]=-f[x];
			q.push(x+n);
		}
		if(x>n&&!vis[x-n])
		{
			vis[x-n]=1;
			f[x-n]=-f[x];
			q.push(x-n);
		}
	}
}
void dfs2(int s)
{
	int x;
	while(!q.empty())
	{
		q.pop();
	}
	vis[s]=1;
	cnt[s]=ind;
	q.push(s);
	while(!q.empty())
	{
		x=q.front();
		q.pop();
		for(auto y:e[x])
		{
			if(!vis[y])
			{
				vis[y]=1;
				cnt[y]=ind;
				q.push(y);
			}
		}
	}
}
void dfs3(int s)
{
	int x;
	while(!q.empty())
	{
		q.pop();
	}
	col[s]=1;
	q.push(s);
	while(!q.empty())
	{
		x=q.front();
		q.pop();
		for(auto y:e2[x])
		{
			if(!col[y])
			{
				col[y]=3-col[x];
				q.push(y);
			}else if(col[y]+col[x]!=3)
			{
				flg=0;
			}
		}
	}
}
void dfs4(int s)
{
	int x;
	while(!q.empty())
	{
		q.pop();
	}
	vis2[s]=1;
	f2[s]=0;
	q.push(s);
	while(!q.empty())
	{
		x=q.front();
		q.pop();
		for(auto y:e2[x])
		{
			if(!vis2[y])
			{
				vis2[y]=1;
				f2[y]=0;
				q.push(y);
			}
		}
	}
}
signed main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int x,y;
	char c;
	cin>>x>>t;
	while(t--)
	{
		cin>>n>>m;
		ans=0;
		for(int i=1;i<=n;i++)
		{
			a[i]=i+1;
		}
		while(m--)
		{
			cin>>c;
			if(c=='+')
			{
				cin>>x>>y;
				a[x]=a[y];
			}else if(c=='-')
			{
				cin>>x>>y;
				a[x]=-a[y];
			}else if(c=='U')
			{
				cin>>x;
				a[x]=0;
			}else if(c=='T')
			{
				cin>>x;
				a[x]=1;
			}else
			{
				cin>>x;
				a[x]=-1;
			}
		}
//		for(int i=1;i<=n;i++)
//		{
//			cout<<a[i]<<" ";
//		}
//		cout<<endl;
		ind=0;
		for(int i=1;i<=n*2;i++)
		{
			e[i].clear();
			vis[i]=0;
			cnt[i]=0;
			f[i]=2e18;
		}
		for(int i=1;i<=n;i++)
		{
			if(a[i]==0||a[i]==1||a[i]==-1)
			{
				continue;
			}
			if(a[i]>0)
			{
				e[a[i]-1].push_back(i);
				e[i].push_back(a[i]-1);
				e[a[i]-1+n].push_back(i+n);
				e[i+n].push_back(a[i]-1+n);
			}else
			{
				e[-a[i]-1+n].push_back(i);
				e[i].push_back(-a[i]-1+n);
				e[-a[i]-1].push_back(i+n);
				e[i+n].push_back(-a[i]-1);
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(a[i]==0||a[i]==1||a[i]==-1)
			{
				if(!vis[i])
				{
					dfs1(i,a[i]);
				}
				if(!vis[i+n])
				{
					dfs1(i+n,-a[i]);
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(f[i]==0||f[i+n]==0)
			{
				ans++;
			}
		}
//		cout<<ans<<endl;
		for(int i=1;i<=n*2;i++)
		{
			if(!vis[i])
			{
				ind++;
				dfs2(i);
			}
		}
		for(int i=1;i<=ind;i++)
		{
			e2[i].clear();
			col[i]=0;
			f2[i]=2e18;
			vis2[i]=0;
		}
		for(int i=1;i<=n;i++)
		{
			if(!cnt[i])
			{
				continue;
			}
			if(cnt[i]==cnt[i+n])
			{
				f2[cnt[i]]=0;
			}else
			{
				e2[cnt[i]].push_back(cnt[i+n]);
				e2[cnt[i+n]].push_back(cnt[i]);
			}
		}
		for(int i=1;i<=ind;i++)
		{
			if(!col[i])
			{
				flg=1;
				dfs3(i);
				if(!flg)
				{
					dfs4(i);
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(!cnt[i])
			{
				continue;
			}
			if(f2[cnt[i]]==0||f2[cnt[i+n]]==0)
			{
				ans++;
			}
		}
		cout<<ans<<"\n";
	}
}