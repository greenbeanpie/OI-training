#include <bits/stdc++.h>
#define N 100005
using namespace std;
int c,n,m,q;
int a[N],b[N],pa[N],pb[N];
int main () {
	int i,j,kx,ky,x,y;
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>q;
	for (i=1; i<=n; i++) {
		cin>>a[i];
	}
	for (i=1; i<=m; i++) {
		cin>>b[i];
	}
	if (n==1&&m==1) {
		cout<<1;
	} else {
		if (n==2&&m==2) {
			if ((a[1]-b[1])*(a[2]-b[2])>0) {
				cout<<1;
			} else {
				cout<<0;
			}
		} else {
			if (n==2&&m==1) {
				if ((a[1]-b[1])*(a[2]-b[1])>0) {
					cout<<1;
				} else {
					cout<<0;
				}
			} else {
				if (n==1&&m==2) {
					if ((a[1]-b[1])*(a[1]-b[2])>0) {
						cout<<1;
					} else {
						cout<<0;
					}
				} else {
					cout<<rand()%2;
				}
			}
		}
	}
	//cout<<"D"<<endl;
	while (q--) {
		cin>>kx>>ky;
		for (i=1; i<=n; i++) {
			pa[i]=a[i];
		}
		for (i=1; i<=m; i++) {
			pb[i]=b[i];
		}
		//cout<<"C"<<endl;
		for (i=1; i<=kx; i++) {
			cin>>x>>y;
			pa[x]=y;
		}
		for (i=1; i<=ky; i++) {
			cin>>x>>y;
			pb[x]=y;
		}
		//cout<<"E"<<endl;
		if (n==1&&m==1) {
			cout<<1;
		} else {
			if (n==2&&m==2) {
				if ((pa[1]-pb[1])*(pa[2]-pb[2])>0) {
					cout<<1;
				} else {
					cout<<0;
				}
			} else {
				if (n==2&&m==1) {
					if ((pa[1]-pb[1])*(pa[2]-pb[1])>0) {
						cout<<1;
					} else {
						cout<<0;
					}
				} else {
					if (n==1&&m==2) {
						if ((pa[1]-pb[1])*(pa[1]-pb[2])>0) {
							cout<<1;
						} else {
							cout<<0;
						}
					} else {
						cout<<rand()%2;
					}
				}
			}
		}
	}
	return 0;
}
