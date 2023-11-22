#include<bits/stdc++.h>
#define fr(s) freopen(s".in","r",stdin)
#define fw(s) freopen(s".out","w",stdout)
using namespace std;
const int N=5e5+10,M=5e5+10,inf=1e9+7;
int c,n,m,q;
int x[N],y[M],xx[N],yy[M];
bool check(){
	if((xx[1]-yy[1])*(xx[n]-yy[m])<=0)return 0;
	return 1;
}
signed main(){
	fr("expand");
	fw("expand");
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>q;
	for(int i=1;i<=n;i++){
		cin>>x[i];
		xx[i]=x[i];
	}
	for(int i=1;i<=m;i++){
		cin>>y[i];
		yy[i]=y[i];
	}
	if(c==1)cout<<(xx[1]!=yy[1]);
	else if(c==2)cout<<check();
	else cout<<1;
	while(q--){
		int kx,ky;
		cin>>kx>>ky;
		for(int i=1;i<=n;i++){
			xx[i]=x[i];
		}
		for(int i=1;i<=m;i++){
			yy[i]=y[i];
		}
		for(int i=1;i<=kx;i++){
			int pos,val;
			cin>>pos>>val;
			xx[pos]=val;
		}
		for(int i=1;i<=ky;i++){
			int pos,val;
			cin>>pos>>val;
			yy[pos]=val;
		}
		if(c==1)cout<<(x[1]!=y[1]);
		else if(c==2)cout<<check();
		else cout<<0;
	}
	return 0;
}
