#include<bits/stdc++.h>
using namespace std;
#define INF 0x7fffffff
const int N(1e5+5);
int C,n[2],Q;
int a[2][N];
int nowd=0;//0:a[0]<a[1]        1:a[0]>a[1]
int kx,ky,px[N],py[N],vx[N],vy[N];
int mn[2],mx[2];
int d;
int ti[N],tj[N];
void init(){
	int t,i=1,j=1;
	while(i<n[d]&&a[d][i]>=a[d][i+1]) ++i;
	ti[0]=i;
	while(i<n[d]){
		t=i+1;
		while(t<n[d]&&a[d][t]>=a[d][t+1]) t++;
		ti[i]=t;i=t;
	}
	ti[n[d]]=n[d]+1;
	
	while(j<n[d^1]&&a[d^1][j]<=a[d^1][j+1]) ++j;
	tj[0]=j;
	while(j<n[d^1]){
		t=j+1;
		while(t<n[d^1]&&a[d^1][t]<=a[d^1][t+1]) t++;
		tj[j]=t;j=t;
	}
	tj[n[d^1]]=n[d^1]+1;
}
//long long seed,P(998244353);
//int rd(){
//	seed=seed*a[seed&1][seed%[n[0]]]%P;
//}
bool dfs(int i,int j){
//	cout<<i<<' '<<j<<endl;
	if(i==n[d]&&j==n[d^1]) return 1;
	if(i<n[d]&&a[d][i]>=a[d][ti[i]]&&a[d][i+1]<a[d^1][j]){
		while(i<n[d]&&a[d][i]>=a[d][ti[i]]&&a[d][i+1]<a[d^1][j]){
			i=ti[i];
		}
		return dfs(i,j);
	}
	if(j<n[d^1]&&a[d^1][j]<=a[d^1][tj[j]]&&a[d^1][j+1]>a[d][i]){
		while(j<n[d^1]&&a[d^1][j]<=a[d^1][tj[j]]&&a[d^1][j+1]>a[d][i]){
			j=tj[j];
		}
		return dfs(i,j);
	}
	if(rand()&1){
		if(i<n[d]&&a[d][i+1]<a[d^1][j]){
			if(dfs(ti[i],j)) return 1;
		}
		if(j<n[d^1]&&a[d^1][j+1]>a[d][i]){
			if(dfs(i,tj[j])) return 1;
		}
	}
	else {
		if(j<n[d^1]&&a[d^1][j+1]>a[d][i]){
			if(dfs(i,tj[j])) return 1;
		}
		if(i<n[d]&&a[d][i+1]<a[d^1][j]){
			if(dfs(ti[i],j)) return 1;
		}
	}

	return 0;
}
int solve(){
	d=0;
	if(a[0][1]>a[1][1]) d=1;//a[d][i]<a[d^1][i]
	if(a[d][n[d]]>=a[d^1][n[d^1]]||a[0][1]==a[1][1]) return 0;
	mx[0]=mn[0]=a[0][1];mx[1]=mn[1]=a[1][1];
	for(int i=2;i<=n[0];++i) {
		mx[0]=max(mx[0],a[0][i]);
		mn[0]=min(mn[0],a[0][i]);
	}
	for(int i=2;i<=n[1];++i) {
		mx[1]=max(mx[1],a[1][i]);
		mn[1]=min(mn[1],a[1][i]);
	}
	if(mx[d]>mx[d^1]||mn[d]>mn[d^1]) return 0;
	init();
	return dfs(ti[0],tj[0]);
}
int main(){
srand(time(0));
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>C>>n[0]>>n[1]>>Q;
	for(int i=1;i<=n[0];++i) cin>>a[0][i];
	for(int i=1;i<=n[1];++i) cin>>a[1][i];
	cout<<solve();
	while(Q--){
		cin>>kx>>ky;
		for(int i=1;i<=kx;++i) {
			cin>>px[i]>>vx[i];
			swap(vx[i],a[0][px[i]]);
		}
		for(int i=1;i<=ky;++i){
			cin>>py[i]>>vy[i];
			swap(vy[i],a[1][py[i]]);
		}
		cout<<solve();
		for(int i=1;i<=kx;++i) {
			swap(vx[i],a[0][px[i]]);
		}
		for(int i=1;i<=ky;++i){
			swap(vy[i],a[1][py[i]]);
		}
	}
}