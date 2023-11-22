#include<bits/stdc++.h>
using namespace std;
int c,n,m,q;
int a[500009],b[500009],a1[500009],b1[500009];
int ans[500009];
int main() {
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	cin>>c>>n>>m>>q;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		a1[i]=a[i];
	}
	for(int i=1; i<=m; i++) {
		cin>>b[i];
		b1[i]=b[i];
	}
	int kx,ky,l,r,maxx=0,maxxp,maxyp,maxy=0,lx=1,ly=1,rx=n,ry=m;
	int cnt=1;
	if(n==2&&m==1) {
		if(a1[1]>b1[1]&&a1[2]>b1[1]) ans[cnt++]=1;
		else ans[cnt++]=0;
	} else if(n==2&&m==2) {
		if(a1[1]>b1[1]&&a1[2]>b1[2]) ans[cnt++]=1;
		else ans[cnt++]=0;
	} else if(n==1&&m==1) {
		if(a1[1]>b1[1]) ans[cnt++]=1;
		else ans[cnt++]=0;
	} else if(n==1&&m==2) {
		if(a1[1]>b1[1]&&a1[1]>b1[2]) ans[cnt++]=1;
		else ans[cnt++]=0;
	} else {
			int flagl=1,flagr=1,flagans=1;
			if(maxx<=maxy) flagans=0;
			if(a1[1]<=b1[1]) flagans=0;
			if(a1[n]<=b1[m]) flagans=0;
			if(flagans) ans[cnt++]=1;
			else ans[cnt++]=0;
	}
	while(q--) {
		for(int i=1; i<=n; i++) {
			a1[i]=a[i];
		}
		for(int i=1; i<=m; i++) {
			b1[i]=b[i];
		}
		maxx=0,maxy=0,lx=1,ly=1,rx=n,ry=m;
		cin>>kx>>ky;
		while(kx--) {
			cin>>l>>r;
			a1[l]=r;
		}
		while(ky--) {
			cin>>l>>r;
			b1[l]=r;
		}
		for(int i=1; i<=n; i++) {
			if(maxx<a1[i]) {
				maxx=a1[i];
				maxxp=i;
			}
		}
		for(int i=1; i<=n; i++) {
			if(maxy<b1[i]) {
				maxy=b1[i];
				maxyp=i;
			}
		}

		if(n==2&&m==1) {
			if(a1[1]>b1[1]&&a1[2]>b1[1]) ans[cnt++]=1;
			else ans[cnt++]=0;
		} else if(n==2&&m==2) {
			if(a1[1]>b1[1]&&a1[2]>b1[2]) ans[cnt++]=1;
			else ans[cnt++]=0;
		} else if(n==1&&m==1) {
			if(a1[1]>b1[1]) ans[cnt++]=1;
			else ans[cnt++]=0;
		} else if(n==1&&m==2) {
			if(a1[1]>b1[1]&&a1[1]>b1[2]) ans[cnt++]=1;
			else ans[cnt++]=0;
		} else {
			int flagl=1,flagr=1,flagans=1;
			if(maxx<=maxy) flagans=0;
			if(a1[1]<=b1[1]) flagans=0;
			if(a1[n]<=b1[m]) flagans=0;
			if(flagans) ans[cnt++]=1;
			else ans[cnt++]=0;
		}
	}
	for(int i=1; i<cnt; i++) {
		cout<<ans[i];
	}
}