#include<bits/stdc++.h>
#define ll long long
using namespace std;

signed main() {
	ios::sync_with_stdio(false),cin.tie(0);
	cout.precision(10),cout.setf(ios::fixed);
	
	ifstream fin("seed.txt");
	int seed; fin>>seed;
	mt19937 rnd(seed);
	
	int n=3000,m=3000;
	cout<<n<<' '<<m<<"\n";
	for (int i=1;i<=n;i++) {
		for (int i=1;i<=m;i++) {
			cout<<char('a'+rnd()%26);
		}
		cout<<"\n";
	}
	
	ofstream fout("seed.txt");
	fout<<rnd()%int(1e9);
	return 0;
}
