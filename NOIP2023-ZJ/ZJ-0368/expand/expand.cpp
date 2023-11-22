#include<bits/stdc++.h>
using namespace std;
#define fq(i,l,r) for(int i=(l);i<=(r);i++)
#define ffq(i,r,l) for(int i=(r);i>=(l);i--)
#define int long long
const int N=3e3+10;
int c,n,m,q,x[N],y[N],kx,ky,p,v,bx[N],by[N];
bool f[N][N],g[N][N];
bool solve(){
	memset(f,0,sizeof(f));memset(g,0,sizeof(g));
	fq(i,1,n) fq(j,1,n){
		if(x[i]<=y[j]) continue;
		if(i-1) f[i][j]|=f[i-1][j];
		if(j-1) f[i][j]|=f[i][j-1];
		if(i==1&&j==1) f[1][1]=x[1]>y[1];
	}
	fq(i,1,n) fq(j,1,n){
		if(x[i]>=y[j]) continue;
		if(i-1) g[i][j]|=g[i-1][j];
		if(j-1) g[i][j]|=g[i][j-1];
		if(i==1&&j==1) g[1][1]=x[1]<y[1];
	}
	return f[n][n]|g[n][n];
}
signed main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);	
	cin>>c>>n>>m>>q;
	fq(i,1,n) cin>>x[i];
	fq(i,1,n) cin>>y[i];
	memcpy(bx,x,sizeof(x));
	memcpy(by,y,sizeof(y));
	cout<<solve();
	while(q--){
		cin>>kx>>ky;
		fq(i,1,kx) cin>>p>>v,x[p]=v;
		fq(i,1,ky) cin>>p>>v,y[p]=v;
		cout<<solve();
		memcpy(x,bx,sizeof(x));
		memcpy(y,by,sizeof(y));
	}
	return 0;
}