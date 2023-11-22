#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1010;
int f[N][N];
int c,n,m,k,d;
struct bot{
	int y,v;
};
bool cmp(bot q,bot w){
	return q.y<w.y;
}
vector<bot> a[N];
void solve(){
	int i,j;
	cin>>n>>m>>k>>d;
	for(i=1;i<=n;i++) a[i].clear();
	for(i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		a[x].push_back({y,z});
	}
	for(i=1;i<=n;i++) sort(a[i].begin(),a[i].end(),cmp);
	for(i=1;i<=n;i++) for(j=0;j<=n;j++) f[i][j]=-1e9;
	f[0][0]=0;
	for(i=1;i<=n;i++){
		int cnt=0,s=0;
		int sum=0;
		for(auto w:a[i]) if(w.y==0) sum+=w.v;
		for(j=0;j<=min(i-1,k);j++){
			while(cnt<a[i].size()&&a[i][cnt].y<=j+1){
				s=s+a[i][cnt].v;
				cnt++;
			}
			if(j<k) f[i][j+1]=max(f[i][j+1],f[i-1][j]-d+s);
			f[i][0]=max(f[i][0],f[i-1][j]+sum);
		}
	}
	int ans=-1e9;
	for(i=0;i<=min(n,k);i++) ans=max(ans,f[n][i]);
	//for(i=0;i<=min())
	cout<<ans<<"\n";
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	int i,j,k;
	int T;
	cin>>c>>T;
	while(T--) solve();
}
