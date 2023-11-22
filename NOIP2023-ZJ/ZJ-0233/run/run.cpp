#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
ll f[1002][1002];
vector<pair<int,int>> q[1002];
void get() {
	memset(f,0xaf,sizeof(f));
	int n,m,k,i,j,pos; ll d;
	int x,y,z;
	cin>>n>>m>>k>>d;
	for(i=1;i<=m;i++) q[i].clear();
	for(i=1;i<=m;i++) {
		cin>>x>>y>>z;
		q[x].push_back({y,z});
	} f[0][0]=0;
	for(i=1;i<=n;i++) sort(q[i].begin(),q[i].end());
	for(i=1;i<=n;i++) {
		f[i][0]=f[i-1][0];
		pos=0; ll sum=0, sz=q[i].size();
		for(j=1;j<=k&&j<=i;j++) {
			while(pos<sz&&q[i][pos].first<=j) sum+=q[i][pos].second,pos++;
			f[i][0]=max(f[i][0],f[i-1][j]);
			f[i][j]=max(f[i][j],f[i-1][j-1]-d+sum);
		}
	} ll ans=0;
	for(j=0;j<=k;j++) ans=max(ans,f[n][j]);
	cout<<ans<<endl;
}
signed main() {
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	int c,T; cin>>c>>T;
	while(T--) get();
	return 0;
}