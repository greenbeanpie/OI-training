#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define endl "\n"
using namespace std;
const int N=5;
int c,n,m,q;
int a[N],b[N];
int aa[N],bb[N];
void pd(){
	int x,y,z,w;
	if(n==1&&m==1) x=y=z=w=1;
	else if(n==1&&m==2) x=z=1,y=1,w=2;
	else if(n==2&&m==1) y=w=1,x=1,z=2;
	else x=y=1,w=z=2;
	if((a[x]-b[y])*(a[z]-b[w])>0) cout<<1;
	else cout<<0;
}
void sub1(){
	FOR(i,1,n) cin>>a[i],aa[i]=a[i];
	FOR(i,1,m) cin>>b[i],bb[i]=b[i];
	pd();
	while(q--){
		int kx,ky;
		cin>>kx>>ky;
		FOR(i,1,kx){
			int x,y;
			cin>>x>>y;
			a[x]=y;
		}
		FOR(i,1,ky){
			int x,y;
			cin>>x>>y;
			b[x]=y;
		}
		pd();
		FOR(i,1,n) a[i]=aa[i];
		FOR(i,1,m) b[i]=bb[i];
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	cin>>c>>n>>m>>q;
	if(c==1||c==2){
		sub1();
		return 0;
	}
	return (0-0);
}

