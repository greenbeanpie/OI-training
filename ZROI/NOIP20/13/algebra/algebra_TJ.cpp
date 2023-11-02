#include <bits/stdc++.h>
using namespace std;
#define N 100025
const int p = 1e9 + 7;
int n, k, i, j, l, a[N], S[22][22], jc[N], iv[N], inv[N], g[22], sum, ans;
int main()
{
#ifndef CODESPACE
#ifndef ONLIND_JUDGE
	freopen("algebra.in", "r", stdin);
	freopen("algebra.out", "w", stdout);
#endif
#endif
	scanf("%d%d", &n, &k);
	for (i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	S[0][0] = jc[0] = inv[0] = 1;
	for (i = 1; i <= n + k; i++)
	{
		jc[i] = 1ll * jc[i - 1] * i % p;
		iv[i] = i == 1 ? 1 : 1ll * iv[p % i] * (p - p / i) % p;
		inv[i] = 1ll * inv[i - 1] * iv[i] % p;
	}
	for (i = 1; i <= k; i++)
		for (j = 1; j <= i; j++)
			S[i][j] = (S[i - 1][j - 1] + 1ll * j * S[i - 1][j]) % p;
	for (i = 1; i <= n; ans = (ans + 1ll * sum * a[i]) % p, i++)
		for (j = g[0] = 1, sum = 0; j <= k && i + j <= n + 1; j++)
		{
			g[j] = 1ll * g[j - 1] * iv[i + j - 1] % p * (n - i - j + 1) % p;
			sum = (sum + 1ll * (g[j - 1] + g[j]) * S[k][j] % p * jc[j]) % p;
		}
	printf("%d", ans);
	return 0;
}