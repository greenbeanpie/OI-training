#include<bits/stdc++.h>
using namespace std;
int const N=1e5+10;
int n,m,k,d,x[N],y[N],v[N],id[N];
long long qz[N],f[2][N],g[N];
vector< pair<int,int> >a[N];
void solvea(){
	cin>>n>>m>>k>>d;
}
void solveaa(){
	cin>>n>>m>>k>>d;
	long long ans=0;
	for (int i=1;i<=m;++i) cin>>x[i]>>y[i]>>v[i];
	for (int i=1;i<=m;++i) id[i]=i;
	sort(id+1,id+m+1,[](int xx,int yy){return x[xx]<y[xx];});
		qz[0]=g[0]=0;
		for (int i=1;i<=m;++i) qz[i]=qz[i-1]+v[i],g[i]=-1e18;
		for (int i=1;i<=m;++i){
			int j=id[i];
			if (x[id[i-1]]==x[j]-y[j]){
				int s=x[j];
				for (int p=i;~p;--p){
					int j=id[p];
					if (s-x[j]+1>k) break;
					g[i]=max(g[i],g[max(0,j-2)]+max(0ll,qz[i]-qz[j]-1ll*(s-x[j]+1)*d));
				}
			}
			else{
				g[i]=max(0ll,g[i-1])+max(0ll,v[j]-1ll*y[j]*d);
			}
			ans=max(ans,g[i]);
		}
	cout<<ans<<'\n';
}
void solveb(){
	cin>>n>>m>>k>>d;
	long long ans=0;
	for (int i=1;i<=m;++i) cin>>x[i]>>y[i]>>v[i];
	for (int i=1;i<=m;++i) id[i]=i;
	sort(id+1,id+m+1,[](int xx,int yy){return x[xx]<y[xx];});
	qz[0]=g[0]=0;
	for (int i=1;i<=m;++i) qz[i]=qz[i-1]+v[i],g[i]=-1e18;
	for (int i=1;i<=m;++i){
		int j=id[i];
		if (x[id[i-1]]==x[j]-y[j]){
			int s=x[j];
			for (int p=i;~p;--p){
				int j=id[p];
				if (s-x[j]+1>k) break;
				g[i]=max(g[i],g[max(0,j-2)]+max(0ll,qz[i]-qz[j]-1ll*(s-x[j]+1)*d));
			}
		}
		else{
			g[i]=max(0ll,g[i-1])+max(0ll,v[j]-1ll*y[j]*d);
		}
		ans=max(ans,g[i]);
	}
	cout<<ans<<'\n';
}
inline void solve(){
	cin>>n>>m>>k>>d;
	for (int j=0;j<=m;++j) f[0][j]=-1e18;
	f[0][0]=g[0]=0;
	for (int i=1;i<=n;++i) a[i].clear();
	vector<int>vec;
	vec.push_back(0);
	while (m--){
		int x,y,z;cin>>x>>y>>z;
		a[x].push_back({y,z});
		vec.push_back(x-y+1);
	}
	sort(vec.begin(),vec.end());
	vec.erase(unique(vec.begin(),vec.end()),vec.end());
	for (int i=1;i<=n;++i){
		int jj=0,rr=0;
		for (auto j:a[i]) rr+=j.second;
		sort(a[i].begin(),a[i].end());
		reverse(a[i].begin(),a[i].end());
		for (int j=0;j<(int)vec.size();++j) f[i&1][j]=-1e18;
		for (int j=0;j<(int)vec.size();++j){
			f[i&1][0]=max(f[i&1][0],f[(i-1)&1][j]);
			if (j==0) continue;
			if (i-vec[j]+1>k) continue;
			if (vec[j]>i) break;
			while (jj<(int)a[i].size() && a[i][jj].first>i-vec[j]+1) rr-=a[i][jj].second,++jj;
			int bas=rr;
			f[i&1][j]=max(f[i&1][j],f[(i-1)&1][j]+bas-d);
			if (vec[j]) f[i&1][j]=max(f[i&1][j],g[vec[j]-1]+bas-1ll*d*(i-vec[j]+1));
		}
		g[i]=f[i&1][0];
	}
	long long ans=0;
	for (int j=0;j<(int)vec.size();++j) ans=max(ans,f[n&1][j]);
	cout<<ans<<'\n';
}
signed main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int c,t;cin>>c>>t;
	while (t--){
		if ((c==17) || (c==18)) solveb();
		else if (c<=11) solve();
		else solveaa();
	}
	return 0;
}