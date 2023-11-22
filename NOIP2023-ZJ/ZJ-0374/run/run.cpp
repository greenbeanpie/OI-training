#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define int long long
const int N=1e5+5;
const int inf=1e9;
inline void fre()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
}
int c,t;
int n,m,k,d;
struct node
{
	int y,z;
};
vector<node> a[N];
int x,y,z,ans;
inline void dfs(int x,int num,int sum)
{
//	cout<<x<<' '<<num<<' '<<sum<<'\n';
	if(x>n)
	{
		ans=max(ans,sum);
		return;
	}
	if(num<k)
	{
		int s=0;
		for(int i=0;i<a[x].size();i++)
		{
			if(num+1>=a[x][i].y) s+=a[x][i].z;
		}
		dfs(x+1,num+1,sum+s-d);
	}
	dfs(x+1,num,sum);
}
inline void solve1()
{
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y>>z;
		a[x].push_back((node){y,z});
	}
	ans=0;
	dfs(1,0,0);
	cout<<ans<<'\n';
}
struct Node
{
	int x,y,z;
}b[N];
inline bool cmp(Node a,Node b)
{
	return a.x<b.x;
}
signed main()
{
	fre();
	IOS;
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>m>>k>>d;
		solve1();
	}
	return 0;
}
