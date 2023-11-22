#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int c,n,m,q,x[500005],y[500005],kx,ky,px,py,v1,v2,tmpx[500005],tmpy[500005];
void solve(){
	for(int i=1;i<=n;i++) x[i]=tmpx[i];
	for(int i=1;i<=m;i++) y[i]=tmpy[i];
}
void init(){
	for(int i=1;i<=n;i++) tmpx[i]=x[i];
	for(int i=1;i<=m;i++) tmpy[i]=y[i];
}
bool ck(){
	if(n==1) x[2]=x[1];
	if(m==1) y[2]=y[1];
	if(x[1]>y[1]&&x[2]>y[2]) return true;
	else if(x[1]<y[1]&&x[2]<y[2]) return true;
	else return false;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	cin>>c;
	if(c==1){
		cin>>n>>m>>q;
		int xx,yy;
		cin>>xx>>yy;
		if(xx==yy) cout<<0;
		else cout<<1;
		while(q--){
			int tmpx=xx,tmpy=yy;
			cin>>kx>>ky;
			if(kx==1) cin>>px>>v1,xx=v1;
			if(ky==1) cin>>py>>v2,yy=v2;
			if(xx==yy) cout<<0;
			else cout<<1;
			xx=tmpx; yy=tmpy;
		}
	}
	if(c==2){
		cin>>n>>m>>q;
	    for(int i=1;i<=n;i++) cin>>x[i];
		for(int i=1;i<=m;i++) cin>>y[i];
		init();
		if(ck()) cout<<1;
		else cout<<0;
		while(q--){
			solve();
			cin>>kx>>ky;
			for(int i=1;i<=kx;i++) cin>>px>>v1,x[px]=v1;
			for(int i=1;i<=ky;i++) cin>>py>>v2,y[py]=v2;
			if(ck()) cout<<1;
		    else cout<<0;
		}
	}
	return 0;
}
