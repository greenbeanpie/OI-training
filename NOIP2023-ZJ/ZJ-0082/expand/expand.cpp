#include<bits/stdc++.h>
#define For(i,j,k) for(int i=(j);i<=(k);++i)
#define ForD(i,j,k) for(int i=(j);i>=(k);--i)
#define int long long
using namespace std;
int x[500005],y[500005];
const int inf=1e9+1;
int c,n,m,q;
bool chk(){
	if(n==1) return 1;
//	cout<<x[1]<<" "<<y[1]<<" "<<x[n]<<" "<<y[m]<<endl;
//	cout<<mnf<<" "<<mxf<<" "<<mng<<" "<<mxg<<endl;
//	int mnf=inf,mxf=-1,mng=inf,mxg=-1;
//	For(i,1,min(n,m)){
//		mnf=min(mnf,x[i]),mxf=max(mxf,x[i]);
//		mng=min(mng,y[i]),mxg=max(mxg,y[i]);
//		if(mxf<mxg&&x[1]>y[1]) return 0;
//		if(mxf>mxg&&x[1]<y[1]) return 0;
//	}
//	mnf=inf,mxf=-1,mng=inf,mxg=-1;
//	For(i,0,min(n,m)-1){
//		mnf=min(mnf,x[n-i]),mxf=max(mxf,x[n-i]);
//		mng=min(mng,y[m-i]),mxg=max(mxg,y[m-i]);
//		if(mxf<mxg&&x[1]>y[1]) return 0;
//		if(mxf>mxg&&x[1]<y[1]) return 0;
//	}
	int mnf=inf,mxf=-1,mng=inf,mxg=-1;
	For(i,1,n) mnf=min(mnf,x[i]),mxf=max(mxf,x[i]);
	For(i,1,m) mng=min(mng,y[i]),mxg=max(mxg,y[i]);
	if(x[1]>y[1]){
		if(x[n]<=y[m]) return 0;
		if(mnf<=mng) return 0;
		if(mxf<=mxg) return 0;
		return 1;
	}else if(x[1]<y[1]){
		if(x[n]>=y[m]) return 0;
		if(mnf>=mng) return 0;
		if(mxf>=mxg) return 0;
		return 1;
	} return 0;
}
int ox[500005],oy[500005];
void solve(){
	 cin>>c>>n>>m>>q;
	For(i,1,n) cin>>ox[i];
	For(i,1,m) cin>>oy[i];
	memcpy(x,ox,sizeof x),memcpy(y,oy,sizeof y);
	cout<<chk();
	For(i,1,q){
		int kx,ky; cin>>kx>>ky;
		memcpy(x,ox,sizeof x),memcpy(y,oy,sizeof y);
		For(j,1,kx){
			int p,v; cin>>p>>v;
			x[p]=v;
		}
		For(j,1,ky){
			int p,v; cin>>p>>v;
			y[p]=v;
		}
		cout<<chk();
	}
}
signed main(){
	freopen("expand.in","r",stdin); freopen("expand.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(0),cout.tie(0);
	solve();
	return 0;
}