#include<bits/stdc++.h>
using namespace std;
int f[200005], sure[200005], sons[200005];
bool vist[200005];
inline int read() {
	int f = 1, x = 0;
	char ch = getchar();
	while ((ch < '0' || ch > '9') && ch != '-') {
		ch = getchar();
	}
	if (ch == '-') {
		f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		x = (x << 1) + (x << 3) + int(ch) - 48;
		ch = getchar();
	}
	return x * f;
}
inline int find(int x) {
	if (f[x] == x)
		return x;
	else
		return (f[x] = find(f[x]));
}
int main() {
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	int C = read(), T = read();
	while (T --) {
		memset(sure, 0, sizeof(sure));
		int n = read(), m = read();
		for (int i = 1; i <= 2 * n; ++ i) {
			f[i] = i, sons[i] = (i <= n) ? 1 : 0;
		}
		for (int i = 1; i <= m; ++ i) {
			char ch = getchar();
			if (ch == '+') {
				int u = read(), v = read();
				int fu = find(u), fv = find(v);
				int fnu = find(n + u), fnv = find(n + v);
				if (fu != u) {
					sons[fu] -= sons[u];
				}
				//cout << "sons[" << fu << "]=" << sons[fu] << endl;
				f[u] = fv;
				sons[fv] += sons[u];
				//cout << "sons[" << fv << "]=" << sons[fv] << endl;
				if ((fu + n == fnu || fnu + n == fu || fnv + n == fv || fv + n == fnv)) {
					if (fnu != n + u) {
						sons[fnu] -= sons[n + u];
					}
					//cout << "sons[" << fnu << "]=" << sons[fnu] << endl;
					f[n + u] = fnv;
					sons[fnv] += sons[n + u];
					//cout << "sons[" << fnv << "]=" << sons[fnv] << endl;
				}
			}
			else if(ch == '-') {
				int u = read(), v = read();
				int fu = find(u), fv = find(v);
				int fnu = find(n + u), fnv = find(n + v);
				if (fu != u) {
					sons[fu] -= sons[u];
				}
				//cout << "sons[" << fu << "]=" << sons[fu] << endl;
				f[u] = fnv;
				sons[fnv] += sons[u];
				//cout << "sons[" << fnv << "]=" << sons[fnv] << endl;
				if (!(fu + n == fnv || fnu + n == fv || fnv + n == fu || fv + n == fnu)) {
					if (fnu != n + u) {
			 			sons[fnu] -= sons[n + u];
		 			}
					//cout << "sons[" << fnu << "]=" << sons[fnu] << endl;
					f[n + u] = fv;
					sons[fv] += sons[n + u];
					//cout << "sons[" << fv << "]=" << sons[fv] << endl;
				}
			}
			else if (ch == 'T') {
				int u = read();
				int fu = find(u), fnu = find(n + u);
				if (fu != u) {
					sons[fu] -= sons[u];
				}
				f[u] = u;
				if (fnu != n + u) {
					sons[fnu] -= sons[n + u];
				}
				f[n + u] = n + u;
				sure[u] = 1;
				sure[n + u] = 2;
			}
			else if (ch == 'F') {
				int u = read();
				int fu = find(u), fnu = find(n + u);
				if (fu != u) {
					sons[fu] -= sons[u];
				}
				f[u] = u;
				if (fnu != n + u) {
					sons[fnu] -= sons[n + u];
				}
				f[n + u] = n + u;
				sure[u] = 2;
				sure[n + u] = 1;
			}
			else if (ch == 'U') {
				int u = read();
				int fu = find(u), fnu = find(n + u);
				if (fu != u) {
					sons[fu] -= sons[u];
				}
				f[u] = u;
				if (fnu != n + u) {
					sons[fnu] -= sons[n + u];
				}
				f[n + u] = n + u;
				sure[u] = 3;
				sure[n + u] = 3;
			}
		}
		int ans = 0;
		memset(vist, 0, sizeof(0));
		for (int i = 1; i <= n; ++ i) {
			if (sure[find(i)] == 3)
				++ ans;
			else if (!vist[find(i)] && find(i) == find(n + i)) {
				ans += sons[find(i)];
				vist[find(i)] = 1;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
/*
1 3
3 3
- 2 1
- 3 2
+ 1 3
3 3
- 2 1
- 3 2
- 1 3
2 2
T 2
U 2


*/
