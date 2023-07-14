#include <bits/stdc++.h>
using namespace std;

const int maxn = 200000;
int n;
int a[maxn + 50];
int inv[maxn + 50];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T = 1;
	//	cin >> T;
	for (; T--;)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		for (int i = 0; i < n; i++)
			inv[a[i]] = i;
		long long ans = 1;
		int l = inv[0], r = inv[0];
		for (int i = 0; i + 1 < n; i++)
		{
			l = min(l, inv[i]);
			r = max(r, inv[i]);
			int pos = inv[i + 1];
			if (l <= pos && pos <= r)
				continue;
			int len = 2 * (i + 1);

			if (pos < l)
			{
				for (int i = pos + 1; i <= l; i++)
					ans += max(0, min(n, i + len) - r);
			}
			else if (pos > r)
			{
				for (int i = r; i < pos; i++)
					ans += max(0, l - max(-1, i - len));
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
