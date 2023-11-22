#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e5+5;

int f[N],n,m,ans,c,t,lim,cur,a[N];
struct node{
	int l,val;
	inline node(int l=0,int val=0):
		l(l),val(val){}
	inline bool operator<(const node& x)const{
		return l<x.l;
	}
};vector<node> g[N];

priority_queue<node>q;

inline void solve(void)//36
{
	ans=-1;
	for(int i=0;i<=n;i++) 
		g[i].clear(),f[i]=a[i]=0;
	cin>>n>>m>>lim>>cur;
	for(int i=1,x,y,z;i<=m;i++)
	{
		cin>>x>>y>>z;
		g[x].push_back(node(x-y+1,z));
	}
	for(int r=1;r<=n;r++)
	{
		int sum=0;
		f[r]=max(f[r],f[r-1]);
		for(auto it:g[r]) a[it.l]+=it.val;
		for(int l=r;l>=1&&(r-l+1)<=lim;l--)
		{
			sum+=a[l]-cur;
			if(l-2<0) f[r]=max(f[r],sum);
			else f[r]=max(f[r],f[l-2]+sum);
		}
	}
	for(int i=1;i<=n;i++)
		ans=max(ans,f[i]);
	cout<<ans<<endl;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	cin>>c>>t;
	while(t--) solve();
    return 0;
}