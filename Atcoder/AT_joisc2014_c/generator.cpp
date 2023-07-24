#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#define int long long
#define endl "\n"



signed main(){
	freopen("AT_joisc2014_c.in","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	sfmt11213_64 random(time(0));
	int n=random()%100000+1,q=random()%100000+1;
	cout << n << " " << q << endl;
	for(int i=1;i<=n;i++){
		cout << random()%1000000 << " ";
	}
	cout << endl;
	for(int i=1;i<=q;i++){
		int l=random()%n+1,r=random()%n+1;
		cout << min(l,r) << " " << max(l,r) << endl;
	}
	return 0;
}