#ifndef ONLINE_JUDGE
#pragma GCC target("avx,sse2,sse3,sse4,mmx,avx512f,sse4.1,sse4.2")
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#endif
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 9999973
int dp[101][101][101];
int zuhe(int x) { return x * (x - 1) / 2 % mod; }
signed main() {
#ifndef ONLINE_JUDGE
	freopen("D.in", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m, ans = 0;
	cin >> n >> m;
	dp[0][0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			for (int k = 0; k <= m - j;k++) {
				dp[i][j][k] = dp[i - 1][j][k];
				if (k >= 1) {
					dp[i][j][k] += dp[i - 1][j + 1][k - 1] * (j + 1);

				}

				if (j >= 1) {
					dp[i][j][k] += dp[i - 1][j - 1][k] * (m - j - k + 1);

				}
				if (k >= 2) {
					dp[i][j][k] += dp[i - 1][i + 2][k - 2] * (j + 2) * (j + 1) / 2;
				}
				if (k >= 1) {
					dp[i][j][k] += dp[i - 1][j][k - 1] * j * (m - j - k + 1);
				}
				if (j >= 2) {
					dp[i][j][k] += dp[i - 1][j - 2][k] * zuhe(m - j - k + 2);
				}
				dp[i][j][k] %= mod;
			}
		}
	}
	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= m; j++) {
			ans += dp[n][i][j];
			ans %= mod;
		}
	}
	cout << ans;
	return 0;
}