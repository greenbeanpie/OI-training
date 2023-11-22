#include<bits/stdc++.h>
using namespace std;
struct val{
	int opt,x,t;
	char c;
};
vector<val> ans[100005];
vector<int> vis[100005],wat[100005];
int id,t,n,m;
char solve(int x,int y)
{
	// cerr<<"visited:"<<x<<" "<<y<<"\n";
	if(ans[x][y].opt==3) return ans[x][y].c;
	ans[x][y].opt=3;
	ans[x][y].c=solve(ans[x][y].x,ans[x][y].t);
	return ans[x][y].c;	
}
void jump(int x,int y,int d,int rt)
{
	// if(x==479)
	// cerr<<x<<" "<<y<<" "<<ans[x].size()<<" "<<wat[x].size()<<" "<<vis[x].size()<<" "<<ans[x][y].x<<" "<<ans[x][y].t<<"\n";
	// assert(y<(int)ans[x].size());
	if(wat[x][y]&&wat[x][y]!=rt) return ;
	wat[x][y]=rt;
	if(ans[x][y].opt==3) return ;
	if(vis[x][y])
	{
		if(vis[x][y]!=d) ans[x][y]={3,0,0,'U'};
		return ;
	}
	// cerr<<"genshin:\n";
	vis[x][y]=d;
	wat[x][y]=rt;
	jump(ans[x][y].x,ans[x][y].t,d^(ans[x][y].opt==2),rt);
}
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>id>>t;
	while(t--)
	{
		// cerr<<"count:"<<t<<"\n";
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		{
			vector<val> t;
			t.push_back({1,i,0,0});
			t.swap(ans[i]);
			vector<int> _,__;
			_.emplace_back();
			__.emplace_back();
			_.swap(vis[i]);
			__.swap(wat[i]);
		}
		for(int i=1;i<=m;i++)
		{
			char opt;
			cin>>opt;
			if(opt=='U'||opt=='F'||opt=='T')
			{
				int x;
				cin>>x;
				// if(x==3) cerr<<ans[x].size()<<" "<<opt<<"\n";
				ans[x].push_back({3,0,0,opt});
				vis[x].emplace_back();
				wat[x].emplace_back();
			}
			if(opt=='+')
			{
				int u,v;
				cin>>u>>v;
				// if(u==3) cerr<<v<<" "<<ans[u].size()<<" "<<ans[v].size()<<"\n";
				ans[u].push_back({1,v,(int)ans[v].size()-1,0});
				vis[u].emplace_back();
				wat[u].emplace_back();
			}
			if(opt=='-')
			{
				int u,v;
				cin>>u>>v;
				// if(u==3) cerr<<v<<" "<<ans[u].size()<<" "<<ans[v].size()<<"\n";
				ans[u].push_back({2,v,(int)ans[v].size()-1,0});
				vis[u].emplace_back();
				wat[u].emplace_back();
			}
		}
			for(int i=1;i<=n;i++)
			{
				ans[i][0].t=(int)ans[i].size()-1;
			}
			int idx=0;
			for(int i=1;i<=n;i++)
			{
				for(int j=0;j<ans[i].size();j++)
				{
					jump(i,j,2,++idx);
				}
			}
			for(int i=1;i<=n;i++)
			{
				// cerr<<"???"<<i<<" "<<n<<" "<<ans[i].size()<<"\n";
				for(int j=0;j<ans[i].size();j++)
				{
					solve(i,j);
				}
			}
			int sum=0;
			for(int i=1;i<=n;i++)
			{
				sum+=ans[i].back().c=='U';
				// for(auto [_1,_2,_3,_4]:ans[i])
				// {
				// 	cerr<<i<<" "<<_1<<" "<<_2<<" "<<_3<<" "<<_4<<"\n";
				// }
			}
			cout<<sum<<"\n";
	}
}