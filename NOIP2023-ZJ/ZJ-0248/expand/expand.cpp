#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
int t,n,m,q,a[maxn],b[maxn],c[maxn],d[maxn],kx,ky,px[65],vx[65],py[65],vy[65];
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> t >> n >> m >> q ;
	for(int i=1;i<=n;i++) cin >> a[i] ;
	for(int i=1;i<=m;i++) cin >> b[i] ;
	if(n==1 && m==1){
		cout << (a[1]!=b[1]) ;
		while(q--){
			for(int i=1;i<=n;i++) c[i]=a[i];
			for(int i=1;i<=m;i++) d[i]=b[i];
			cin >> kx >> ky ;
			for(int i=1;i<=kx;i++) cin >> px[i] >> vx[i] ,c[px[i]]=vx[i];
			for(int i=1;i<=ky;i++) cin >> py[i] >> vy[i] ,d[py[i]]=vy[i];
			cout << (c[1]!=d[1]) ;
		}
	}else if(n==1 && m==2){
		int mn=min(b[1],b[2]),mx=max(b[1],b[2]);
		cout << (a[1]<mn || a[1]>mx) ;
		while(q--){
			for(int i=1;i<=n;i++) c[i]=a[i];
			for(int i=1;i<=m;i++) d[i]=b[i];
			cin >> kx >> ky ;
			for(int i=1;i<=kx;i++) cin >> px[i] >> vx[i] ,c[px[i]]=vx[i];
			for(int i=1;i<=ky;i++) cin >> py[i] >> vy[i] ,d[py[i]]=vy[i];
			mn=min(d[1],d[2]),mx=max(d[1],d[2]);
			cout << (c[1]<mn || c[1]>mx) ;
		}
	}else if(n==2 && m==1){
		int mn=min(a[1],a[2]),mx=max(a[1],a[2]);
		cout << (b[1]<mn || b[1]>mx) ;
		while(q--){
			for(int i=1;i<=n;i++) c[i]=a[i];
			for(int i=1;i<=m;i++) d[i]=b[i];
			cin >> kx >> ky ;
			for(int i=1;i<=kx;i++) cin >> px[i] >> vx[i] ,c[px[i]]=vx[i];
			for(int i=1;i<=ky;i++) cin >> py[i] >> vy[i] ,d[py[i]]=vy[i];
			mn=min(a[1],a[2]),mx=max(a[1],a[2]);
			cout << (b[1]<mn || b[1]>mx) ;
		}
	}else{
		cout << ((a[1]>b[1] && a[2]>b[2]) || (a[1]<b[1] && a[2]<b[2])) ;
		while(q--){
			for(int i=1;i<=n;i++) c[i]=a[i];
			for(int i=1;i<=m;i++) d[i]=b[i];
			cin >> kx >> ky ;
			for(int i=1;i<=kx;i++) cin >> px[i] >> vx[i] ,c[px[i]]=vx[i];
			for(int i=1;i<=ky;i++) cin >> py[i] >> vy[i] ,d[py[i]]=vy[i];
			cout << ((c[1]>d[1] && c[2]>d[2]) || (c[1]<d[1] && c[2]<d[2])) ;
		}
	}return 0;
}