#include <bits/stdc++.h>
using namespace std;
int read() {
	char ch;
	
	for (ch = getchar(); ch < '0' || ch > '9'; ch = getchar())
		;
	
	int res = 0;
	
	for (; ch >= '0' && ch <= '9'; ch = getchar())
		res = (res << 1) + (res << 3) + (ch - 48);
	
	return res;
}

struct Type {
	int l, r;
	long long v;
}a[500000];

inline bool cmp(const Type &x, const Type &y) {
	return x.l < y.l || x.l == y.l && x.r > y.r;
}

int n, m, k, c, T;
long long d;
int main() {
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	
	scanf("%d %d", &c, &T);
	
	for (; T; T--) {
		scanf("%d %d %d %lld", &n, &m, &k, &d);
		
		for (int i = 1; i <= m; i++) {
			a[i].r = read();
			a[i].l = a[i].r - read() + 1;
			a[i].v = read();
		}
		
		sort(a + 1, a + m + 1, cmp);
		
		for (int i = 1; i < m; i++)
			if (a[i].r >= a[i + 1].l - 1) {
				a[++m].l = a[i].l;
				a[m].r = a[i + 1].r;
				a[m].v = a[i].v + a[i + 1].v;
			}

		sort(a + 1, a + m + 1, cmp);
		
		int nowr = -1;
		long long ans = 0;
		
		for (int j = 1; j <= m; j++)
			if (a[j].l >= nowr + 1 && a[j].r - a[j].l + 1 <= k) {
				if (a[j].v - d * (a[j].r - a[j].l + 1) > 0) 
				{
					ans += a[j].v - d * (a[j].r - a[j].l + 1);
					nowr = a[j].r;
				}
			}
		
		printf("%lld\n", ans);
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}