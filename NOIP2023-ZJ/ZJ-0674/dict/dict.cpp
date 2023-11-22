#include <bits/stdc++.h>
using namespace std;
const int N = 3e3 + 10;

int n, m; string w[N]; char Ymq[N], Jkx[N];
inline int check(int pos) {
	char Yy = Ymq[pos];
	for (int i = 1; i <= n; i++) {
		if (i == pos) continue;
		if (Yy >= Jkx[i]) return 0;
	} return 1;
}
int main () {
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	cin >> n >> m;
	memset(Ymq, '{', sizeof(Ymq));
	memset(Jkx, '`', sizeof(Jkx));
	for (int i = 1; i <= n; i++) {
		cin >> w[i]; string Cfq = w[i];
		for (int j = 0; j < m; j++) {
			if (Cfq[j] > Jkx[i]) {
				Jkx[i] = Cfq[j];
			} if (Cfq[j] < Ymq[i]) {
				Ymq[i] = Cfq[j];
			} 
		}
	} if (n == 1) {
		cout << 1;
		return 0;
	} for (int i = 1; i <= n; i++) {
		cout << check(i);
 	}
	return 0;
}