#include<bits/stdc++.h>
#define ll long long
using namespace std;

signed main() {
	ios::sync_with_stdio(false),cin.tie(0);
	cout.precision(10),cout.setf(ios::fixed);
	
	ifstream fin("seed.txt");
	int seed; fin>>seed;
	mt19937 rnd(seed);
	
	int V=1e9;
	int c=0,n=200,m=200,Q=60;
	cout<<c<<' '<<n<<' '<<m<<' '<<Q<<"\n";
	for (int i=1;i<=n;i++) {
		cout<<rnd()%V<<" \n"[i==n];
	}
	for (int i=1;i<=m;i++) {
		cout<<rnd()%V<<" \n"[i==m];
	}
	while (Q--) {
		cout<<n<<' '<<m<<"\n";
		for (int i=1;i<=n;i++) {
			cout<<i<<' '<<rnd()%V<<"\n";
		}
		for (int i=1;i<=m;i++) {
			cout<<i<<' '<<rnd()%V<<"\n";
		}
	}
	
	ofstream fout("seed.txt");
	fout<<rnd()%int(1e9);
	return 0;
}
