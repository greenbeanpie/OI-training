#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
const int N=2e3+10;
int c,n,m,q;
int x[N],y[N];
int mx,my,nx=inf,ny=inf;
int doo() {
	if(x[1]==y[1])
		return 0;
	if(x[1]>y[1]) {
		if(nx>ny&&mx>my)
			return 1;
		return 0;
	} else {
		if(nx<ny&&mx<my)
			return 1;
		return 0;
	}
}
signed main() {
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	cin>>c>>n>>m>>q;
	for(int i=1; i<=n; i++) {
		cin>>x[i];
		mx=max(mx,x[i]);
		nx=min(nx,x[i]);
	}
	for(int i=1; i<=m; i++) {
		cin>>y[i];
		my=max(my,y[i]);
		ny=min(ny,y[i]);
	}
	cout<<doo();
	while(q--) {
		int kx,ky,a,b;
		int tx[n],ty[m];
		int tmx=mx,tmy=my,tnx=nx,tny=ny;
		for(int i=1; i<=n; i++) 	tx[i]=x[i];
		for(int i=1; i<=m; i++) 	ty[i]=y[i];
		cin>>kx>>ky;
		for(int i=1; i<=kx; i++) {
			cin>>a>>b;
			x[a]=b;
			mx=max(mx,b);
			nx=min(nx,b);
		}
		for(int i=1; i<=ky; i++) {
			cin>>a>>b;
			y[a]=b;
			my=max(my,b);
			ny=min(ny,b);
		}
		cout<<doo();
		mx=tmx,my=tmy,nx=tnx,ny=tny;
		for(int i=1; i<=n; i++) 	x[i]=tx[i];
		for(int i=1; i<=m; i++) 	y[i]=ty[i];
	}

	return 0;
}
/*
3 3 3 3
8 6 9
1 7 4
1 0
3 0
0 2
1 8
3 5
1 1
2 8
1 7

*/
