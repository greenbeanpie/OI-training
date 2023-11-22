#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;

int id,n,m,Q,a[N],b[N];
namespace bf {
	const int NN=2e3+5;
	bool f[NN][NN];
	bool solve() {
		for (int i=0;i<=n;i++) {
			for (int j=0;j<=m;j++) {
				f[i][j]=0;
			}
		}
		f[0][0]=1;
		for (int i=1;i<=n;i++) {
			for (int j=1;j<=m;j++) {
				if (a[i]<=b[j]) {
					continue;
				}
				f[i][j]=f[i-1][j]||f[i][j-1]||f[i-1][j-1];
			}
		}
		return f[n][m];
	}
}
int getans() {
	if (bf::solve()) {
		return 1;
	}
	for (int i=1;i<=max(n,m);i++) {
		swap(a[i],b[i]);
	}
	swap(n,m);
	bool res=bf::solve();
	for (int i=1;i<=max(n,m);i++) {
		swap(a[i],b[i]);
	}
	swap(n,m);
	return res;
}

signed main() {
	ios::sync_with_stdio(false),cin.tie(0);
	cout.precision(10),cout.setf(ios::fixed);
	
	cin>>id>>n>>m>>Q;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
	}
	for (int i=1;i<=m;i++) {
		cin>>b[i];
	}
	cout<<getans();
	while (Q--) {
		int k1,k2;
		cin>>k1>>k2;
		vector<pair<int,int>>p1(k1),p2(k2);
		for (int i=0;i<k1;i++) {
			int x,y;
			cin>>x>>y;
			swap(a[x],y);
			p1[i]=make_pair(x,y);
		}
		for (int i=0;i<k2;i++) {
			int x,y;
			cin>>x>>y;
			swap(b[x],y);
			p2[i]=make_pair(x,y);
		}
		cout<<getans();
		for (int i=0;i<k1;i++) {
			swap(a[p1[i].first],p1[i].second);
		}
		for (int i=0;i<k2;i++) {
			swap(b[p2[i].first],p2[i].second);
		}
	}
	
	return 0;
}
