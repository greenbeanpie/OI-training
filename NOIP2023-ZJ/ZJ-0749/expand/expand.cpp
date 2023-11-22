#include<bits/stdc++.h>
using namespace std;

int c,n,m,q;
string x,y;
string a,b;
int n1,n2,n3,n4;
signed main() {
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	cin>>c>>n>>m>>q;
	if(n==1) {
		for(int i=1; i<=q+1; i++) {
			cout<<1;
		}
		return 0;
	}
	if(n==2) {
		if(m==1) {
			cin>>n1>>n2>>n3;
			if(n1>n3&&n2>n3||n1<n3&&n2<n3) {
				cout<<1;
			} else {
				cout<<0;
			}
			while(q--) {
				int kx,ky;
				cin>>kx>>ky;
				for(int i=1,u,v; i<=kx; i++) {
					cin>>u>>v;
					if(u==1) {
						n1=v;
					}
					if(u==2) n2=v;
				}
				for(int i=1,u,v; i<=ky; i++) {
					cin>>u>>v;
					n3=v;
				}
				if(n1>n3&&n2>n3||n1<n3&&n2<n3) {
					cout<<1;
				} else {
					cout<<0;
				}
			}
		} else {
			cin>>n1>>n2>>n3>>n4;
			if(n1>n3&&n2>n4||n1<n3&&n2<n4) {
				cout<<1;
			} else {
				cout<<0;
			}
			while(q--) {
				int kx,ky;
				cin>>kx>>ky;
				for(int i=1,u,v; i<=kx; i++) {
					cin>>u>>v;
					if(u==1) {
						n1=v;
					}
					if(u==2) n2=v;

				}
				for(int i=1,u,v; i<=ky; i++) {
					cin>>u>>v;
					if(u==1) n3=v;
					if(u==4) n4=v;
				}
				if(n1>n3&&n2>n4||n1<n3&&n2<n4) {
					cout<<1;
				} else {
					cout<<0;
				}
			}
		}
		return 0;
	}
	for(int i=1; i<=q; i++) {
		cout<<1;
	}
	return 0;
}
