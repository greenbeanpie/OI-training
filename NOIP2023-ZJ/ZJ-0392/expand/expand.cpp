#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=500005;
int c,n,m,q;
int a[N],b[N];
const int inf=1e9+5;
queue<pair<int,int> > qu;
queue<pair<int,int> > qu1;
void check() {
	int a_mx=0;
	int b_mx=0;
	int state;
	if(a[1]<b[1]) {
		if(a[n]<b[m]) {
			state=0;
		} else {
			cout<<0;
			return;
		}
	}
	if(a[1]==b[1]) {
		cout<<0;
		return;
	}
	if(a[1]>b[1]) {
		if(a[n]>b[m]) {
			state=1;
		} else {
			cout<<0;
			return;
		}
	}
	for(int i=1; i<=n; i++) {
		a_mx=max(a_mx,a[i]);
		b_mx=max(b_mx,b[i]);
		if(state==0) {
			if(a_mx>=b_mx) {
				cout<<0;
				return;
			}
		}
		if(state==1) {
			if(a_mx<=b_mx) {
				cout<<0;
				return;
			}
		}
	}
	for(int i=1;i<=n;i++){
		a_mx=max(a_mx,a[i]);
	}
	for(int j=1;j<=m;j++){
		b_mx=max(b_mx,b[j]);
	}
	if(state==0&&a_mx>=b_mx) {
		cout<<0;
		return;
	}
	if(state==1&&a_mx<=b_mx){
		cout<<0;
		return;
	}
	cout<<1;
}
void spe() {
	int idx1=1,idx2=1;
	int a_mx=0,b_mx=0;
	while(true){
		if(idx1==n){
			cout<<1;
			return;
		}
		if(b[idx2+1]>a[idx1+1]){
			idx2++;
			idx1++;
		}
		else{
			if(b[idx2]>a[idx1+1]){
				idx1++;
			}
			else{
				cout<<0;
				return;
			}
		}
	}
}
signed main() {
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>c>>n>>m>>q;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	for(int i=1; i<=m; i++) {
		cin>>b[i];
	}
	if(a[1]<b[1]) {
		int mn=inf;
		bool ok=false;
		for(int i=1; i<=n; i++) {
			if(a[i]<mn) {
				if(i==n) {
					ok=true;
				}
				mn=a[i];
			}
		}
		if(ok) {
			int mx=0;
			ok=false;
			for(int i=1; i<=m; i++) {
				if(a[i]>mx) {
					if(i==m) {
						ok=true;
					}
					mx=a[i];
				}
			}
			if(ok) {
				spe();
			}
		}
		if(!ok) check();
	}
	else check();
	while(q--) {
		int kx,ky;
		cin>>kx>>ky;
		for(int i=1; i<=kx; i++) {
			int p,v;
			cin>>p>>v;
			qu.push(make_pair(p,a[p]));
			a[p]=v;
		}
		for(int i=1; i<=ky; i++) {
			int p,v;
			cin>>p>>v;
			qu1.push(make_pair(p,a[p]));
			b[p]=v;
		}
		if(a[1]<b[1]) {
			int mn=inf;
			bool ok=false;
			for(int i=1; i<=n; i++) {
				if(a[i]<mn) {
					if(i==n) {
						ok=true;
					}
					mn=a[i];
				}
			}
			if(ok) {
				int mx=0;
				ok=false;
				for(int i=1; i<=m; i++) {
					if(a[i]>mx) {
						if(i==m) {
							ok=true;
						}
						mx=a[i];
					}
				}
				if(ok) spe();
			}
			if(!ok) check();
		}
		else check();
		while(!qu.empty()) {
			a[qu.front().first]=qu.front().second;
			qu.pop();
		}
		while(!qu1.empty()) {
			a[qu1.front().first]=qu1.front().second;
			qu1.pop();
		}
	}
	return 0;
}
