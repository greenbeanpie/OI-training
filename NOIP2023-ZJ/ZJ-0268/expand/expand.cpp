#include <bits/stdc++.h>
#define LL long long
#define Fcin \
	ios :: sync_with_stdio(0); \
	cin.tie(0); cout.tie(0)
using namespace std;

namespace Oxygen35{
	const LL N = 2e3 + 10;
	LL C, n, m, Q, A[N], B[N], tmp1[N], tmp2[N];

	bool DP[N][N];
	LL check(LL* A1, LL* A2){
		memset(DP, 0, sizeof DP);
		DP[0][0] = 1;
		for (LL i = 1; i <= n; i ++){
			for (LL j = 1; j <= m; j ++){
				if (A1[i] > A2[j])
					DP[i][j] |= DP[i - 1][j] | DP[i][j - 1] | DP[i - 1][j - 1];
			}
		}
		return DP[n][m];
	}

	void main(){
		cin >> C >> n >> m >> Q;
		for (LL i = 1; i <= n; i ++)
			cin >> A[i];
		for (LL i = 1; i <= m; i ++)
			cin >> B[i];
		cout << max(check(A, B), check(B, A));
		for (LL i = 1; i <= Q; i ++){
			for (LL j = 1; j <= n; j ++)
				tmp1[j] = A[j];
			for (LL j = 1; j <= m; j ++)
				tmp2[j] = B[j];
			LL k1, k2, x, y;
			cin >> k1 >> k2;
			while (k1 --){ cin >> x >> y; tmp1[x] = y; }
			while (k2 --){ cin >> x >> y; tmp2[x] = y; }
			cout << max(check(tmp1, tmp2), check(tmp2, tmp1));
		}
		cout << "\n";
		return ;
	}
}


int main(){
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	Fcin;
	Oxygen35 :: main();

	return 0;
}