#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define fi first
#define se second
#define deb(var) cerr << #var << '=' << (var) << "; "
namespace Loser
{
	int n, A, B;
	char s[500010], a[55], b[55];
	int f[500010][55];
	void main()
	{
		memset(f[0], 0, sizeof f[0]);
		cin >> (s + 1) >> a >> b;
		n = strlen(s + 1), A = strlen(a), B = strlen(b);
		memset(f[0], 0, sizeof f[0]);
		f[0][A - 1] = 1ll << (B - 1);
		for (int i = 1; i <= n; i++)
		{
			memset(f[i], 0, sizeof f[i]);
			int bt = 0;
			for (int y = 0; y < B; y++)
				bt |= (long long)(s[i] == b[y]) << y;
			for (int x = 0; x < A; x++)
			{
				if (a[x] == s[i])
				{
					f[i][x] |= f[i - 1][(x + A - 1) % A];
				}
				int S = (f[i - 1][x] << 1ll | (f[i - 1][x] >> (B - 1))) % (1ll << B);
				f[i][x] |= S & bt;
				//				for(int y=0;y<B;y++)
				//					if(f[i][x]>>y&1)deb(i),deb(x),deb(y),deb(f[i][x]>>y&1)<<'\n';
			}
		}
		cout << ((f[n][A - 1] >> (B - 1)) ? "Yes\n" : "No\n");
	}
}
signed main()
{
#ifndef ONLINE_JUDGE
	freopen("geometry.in", "r", stdin);
	freopen("geometry.out", "w", stdout);
#endif
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T = 1;
	cin >> T;
	while (T--)
		Loser::main();
	return 0;
}