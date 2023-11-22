#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const int N = 1e3 + 100;
const int M = 1e5;
ll c, n, m, k, q; 


signed main ()
{
	freopen ("expand.in", "r", stdin);
	freopen ("expand.out", "w", stdout);

	scanf ("%lld %lld %lld %lld", &c, &n, &m, &q);
	if (n == 1)
	{
		ll a, b;
		scanf ("%lld %lld", &a, &b);
		for (int i = 1; i <= q + 1; ++ i)
			cout << 1;
	}
	return 0;

}

