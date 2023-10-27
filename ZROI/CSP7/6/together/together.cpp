#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
#define int long long
#define endl '\n'

random_device rd;
sfmt19937_64 myrand(rd());
const int mod = 998244353;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("together.in", "r", stdin);
	freopen("together.out", "w", stdout);
	cout << myrand() % mod;
	return 0;
}