#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int p, T;
int n, m;
int f[40];
int ff[40];
char c[40];
int cc[40];
int ans = 0;
void work1() {
	while(T--) {
		memset(f, 0, sizeof f);
		scanf("%d%d", &n, &m);
		ans = n;
		int idx1 = 0, idx2 = 0;
		for(int i = 1; i <= m; i++) {
			char op; scanf("%s", &op); c[++idx1] = op;
			if(op == '-' || op == '+') {
				int a, b; scanf("%d%d", &a, &b);
				cc[++idx2] = a, cc[++idx2] = b;
			}
			else {
				int a; scanf("%d", &a); cc[++idx2] = a;
			}
		}
//		cout << idx1 << endl;
//		for(int i = 1; i <= idx1; i++) cout << c[i] << " ";
//		for(int i = 1; i <= idx2; i++) cout << cc[i] << " ";
		for(int i = 0; i < pow(3, n); i++) {
			int j = i;
			int cnt = 0;
			while(j) {
				f[++cnt] = j % 3;
				j /= 3;
			}
//			for(int j = 1; j <= n; j++) cout << f[j];
//			cout << endl;
			for(int j = 1; j <= n; j++) ff[j] = f[j];
			int idx = 0;
			for(int j = 1; j <= m; j++) {
				if(c[j] == '-') {
					if(f[cc[idx + 2]] == 2) f[cc[idx + 1]] = 2;
					else f[cc[idx + 1]] = 1 - f[cc[idx + 2]];
					idx += 2;
				}
				else if(c[j] == '+') {
					f[cc[idx + 1]] = f[cc[idx + 2]];
					idx += 2;
				}
				else if(c[j] == 'T') {
					f[cc[++idx]] = 0;
				}
				else if(c[j] == 'F') {
					f[cc[++idx]] = 1;
				}
				else {
					f[cc[++idx]] = 2;
				}
			}
			bool flag = 1;
			for(int j = 1; j <= n; j++) {
				if(f[j] != ff[j]) {
					flag = 0;
					break;
				}
			}
			if(flag) {
				int sum = 0;
				for(int j = 1; j <= n; j++) {
					if(ff[j] == 2) sum++;
				}
				ans = min(ans, sum);
			}
		}
		printf("%d\n", ans);
	}
}
int main() {
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	scanf("%d%d", &p, &T);
	if(p == 1 || p == 2) work1();
	return 0;
}