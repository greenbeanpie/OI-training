#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int a[N],b[N];
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	int c,n,m,q;
	cin >> c >> n >> m >> q;
	for(int i=0;i<n;++i) cin >> a[i];
	for(int i=0;i<m;++i) cin >> b[i];
	if(n==1){
		if(m==1){
			cout << '1';
			while(q--) cout << '1';
			return 0;
		}else{
			cout << ((a[0]<b[0])==(a[0]<b[1]));
			while(q--){
				int kx,ky;
				cin >> kx >> ky;
				while(kx--){
					int p,v;
					cin >> p >> v;
					a[--p]=v;
				}
				while(ky--){
					int p,v;
					cin >> p >> v;
					b[--p]=v;
				}
				cout << ((a[0]<b[0])==(a[0]<b[1]));
			}
		}
	}else{
		if(m==1){
			cout << ((a[0]<b[0])==(a[1]<b[0]));
			while(q--){
				int kx,ky;
				cin >> kx >> ky;
				while(kx--){
					int p,v;
					cin >> p >> v;
					a[--p]=v;
				}
				while(ky--){
					int p,v;
					cin >> p >> v;
					b[--p]=v;
				}
				cout << ((a[0]<b[0])==(a[1]<b[0]));
			}
		}else{
			cout << ((a[0]<b[0])==(a[1]<b[1]));
			while(q--){
				int kx,ky;
				cin >> kx >> ky;
				while(kx--){
					int p,v;
					cin >> p >> v;
					a[--p]=v;
				}
				while(ky--){
					int p,v;
					cin >> p >> v;
					b[--p]=v;
				}
				cout << ((a[0]<b[0])==(a[1]<b[1]));
			}
		}
	}
	return 0;
}