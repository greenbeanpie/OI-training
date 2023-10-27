#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
#define int long long
#define endl '\n'

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("poly.in", "r", stdin);
	freopen("poly.out", "w", stdout);
#endif
	random_device rd;
	sfmt19937_64 myrand(rd());
	int T;
	cin >> T;
	while (T--)
	{
		int ans = 0;
		unsigned int a, b, c;
		cin >> a >> b >> c;
		if (a == b && b == c)
		{
			if (c == 1)
			{
				cout << -1 << endl;
			}
			else
			{
				cout << 2 << endl;
			}
			continue;
		}
		if(a==b&&b!=c){
			cout << 0 << endl;
			continue;
		}
		if(a>b||b>c){
			cout << (b==c) << endl;
			continue;
		}
		if(a==b&&b==0){
			cout << 0 << endl;
		}
		if(a){
			int temp = c;
			while(!(temp%b)){
				temp /= b;
			}
			ans += (temp == 1);
		}
		int cnt = 0;
		cc_hash_table<int, int> p;
		while(c){
			p[++cnt]=c%b,c/=b;
		}
		int v = 0, B = 1;
		for (int i = 1; i <= cnt;i++){
			v += B * p[i];
			B = B * a;
		}
		ans += (v == b);
		cout << ans << endl;
	}
	return 0;
}
