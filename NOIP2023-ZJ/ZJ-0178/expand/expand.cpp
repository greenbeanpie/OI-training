#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=500005;
int f[2050][2050];
void ssolve(int*a,int*b,int n,int m){
//check if a>b
	memset(f,0,sizeof(f));
	f[1][1]=1;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(!f[i][j]) continue;
			if(j<m&&a[i]>b[j+1]) f[i][j+1]=1;// v 
			if(i<n&&a[i+1]>b[j]) f[i+1][j]=1;// > 
			if(i<n&&j<m&&a[i+1]>b[j+1]) f[i+1][j+1]=1;
		}
	}
	cout << f[n][m];
}
void solve(int*a,int*b,int n,int m){
	if(1ll*(a[1]-b[1])*(a[n]-b[m])<=0){cout << 0;return ;}
	if(a[1]>b[1]) ssolve(a,b,n,m);
	else ssolve(b,a,m,n);
}
int C,n,m,q,tA[N],A[N],tB[N],B[N],px[N],py[N];
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> C >> n >> m >> q;
	for(int i=1;i<=n;++i) cin >> tA[i],A[i]=tA[i];
	for(int i=1;i<=m;++i) cin >> tB[i],B[i]=tB[i];
	// n=1,m=1 ; n=2,m=2
	solve(tA,tB,n,m);
	while(q--){
		int kx,ky; cin >> kx >> ky;
		for(int i=1;i<=kx;++i){
			int x; cin >> px[i] >> x;
			A[px[i]]=x;
		}
		for(int i=1;i<=ky;++i){
			int x; cin >> py[i] >> x;
			B[py[i]]=x;
		}
		solve(A,B,n,m);
		for(int i=1;i<=kx;++i) A[px[i]]=tA[px[i]];
		for(int i=1;i<=ky;++i) B[py[i]]=tB[py[i]];
	}
	return 0;
}
