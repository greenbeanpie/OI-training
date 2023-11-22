#include <bits/stdc++.h>
#define int long long 
using namespace std;
const int N=100005;
int n,m,a[N],b[N],pa[N],pb[N],ka,kb,qwq,T;
bool pd(int xa,int xb,int ya,int yb) {
	if (xa<xb&&ya>yb) return 0;
	if (xa>xb&&ya<yb) return 0;
	if (xa<ya&&xb>yb||xa>ya&&xb<yb) return 0;
	if (xa==ya||xb==yb) return 0;
	if (xa==xb&&ya==yb) {
		if (xa==ya) return 0;
				else return 1;
	}
	if (ya==yb) {
		int t=ya;
		ya=xa,yb=xb; xa=t,xb=t;
	} 
	if (xa==xb){
		if (ya<yb) {
			if (ya>xa||yb<xa) return 1;
						else return 0;
		}
		else {
			if (ya<xa||yb>xa) return 1;
						else return 0;
		}
	}
	return 1;
}
signed main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>qwq>>n>>m>>T;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=m;i++) cin>>b[i];
	for (int i=1;i<=n;i++) pa[i]=a[i];
	for (int i=1;i<=m;i++) pb[i]=b[i];
	if (n==1&&m==1) {
		if (a[1]==b[1]) cout<<0;
					else cout<<1;
		while (T--) {
			a[1]=pa[1],b[1]=pb[1];
			cin>>ka>>kb;
			for (int i=1;i<=ka;i++) {
				int x,y; cin>>x>>y;
				a[x]=y;
			}
			for (int i=1;i<=kb;i++) {
				int x,y; cin>>x>>y;
				b[x]=y;
			}
			if (a[1]==b[1]) cout<<0;
						else cout<<1;
		}
		return 0;
	}
	else if (n==1&&m==2){
		if (pd(a[1],a[1],b[1],b[2])) cout<<1;
								else cout<<0;
		while (T--) {
			for (int i=1;i<=n;i++) a[i]=pa[i];
			for (int i=1;i<=m;i++) b[i]=pb[i];
			cin>>ka>>kb;
			for (int i=1;i<=ka;i++) {
				int x,y; cin>>x>>y;
				a[x]=y;
			}
			for (int i=1;i<=kb;i++) {
				int x,y; cin>>x>>y;
				b[x]=y;
			}
			if (pd(a[1],a[1],b[1],b[2])) cout<<1;
								else  cout<<0;
		}
		return 0;
	}
	else if (n==2&&m==1) {
		if (pd(a[1],a[2],b[1],b[1])) cout<<1;
								else cout<<0;
		while (T--) {
			for (int i=1;i<=n;i++) a[i]=pa[i];
			for (int i=1;i<=m;i++) b[i]=pb[i];
			cin>>ka>>kb;
			for (int i=1;i<=ka;i++) {
				int x,y; cin>>x>>y;
				a[x]=y;
			}
			for (int i=1;i<=kb;i++) {
				int x,y; cin>>x>>y;
				b[x]=y;
			}
			if (pd(a[1],a[2],b[1],b[1])) cout<<1;
								else  cout<<0;
		}		
	}
	else if (n==2&&m==2) {
		if (pd(a[1],a[2],b[1],b[2])) cout<<1;
								else cout<<0;
		while (T--) {
			for (int i=1;i<=n;i++) a[i]=pa[i];
			for (int i=1;i<=m;i++) b[i]=pb[i];
			cin>>ka>>kb;
			for (int i=1;i<=ka;i++) {
				int x,y; cin>>x>>y;
				a[x]=y;
			}
			for (int i=1;i<=kb;i++) {
				int x,y; cin>>x>>y;
				b[x]=y;
			}
			if (pd(a[1],a[2],b[1],b[2])) cout<<1;
								else  cout<<0;			
		}
		return 0;
	}
	
	
	
	
	return 0;
}

/*
1 1 1 2
5
5
1 1
1 6
1 8
2 1
1 7
1 8
1 8

010


2 2 2 3
1 5
2 6
1 1 
1 5
1 3
0 1
2 3
1 0
2 2

1001


*/
