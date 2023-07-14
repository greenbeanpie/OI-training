#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, x;
ll a[150];

int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n >> x;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	map<ll, ll> dict;
	ll mid = n / 2;
	for (ll mask = 0; mask < (1 << mid); mask++)
	{
		ll sum = 0;
		for (int i = 0; i < mid; i++)
			if ((mask >> i) & 1)
				sum += a[i];
		dict[x - sum]++;
	}
	ll ans = 0;
	for (ll mask = 0; mask < (1 << (n - mid)); mask++)
	{
		ll sum = 0;
		for (int i = 0; i < n - mid; i++)
			if ((mask >> i) & 1)
				sum += a[i + mid];
		if (dict.find(sum) != dict.end())
			ans = ans + dict[sum];
	}
	cout << ans << "\n";
	return 0;
}
