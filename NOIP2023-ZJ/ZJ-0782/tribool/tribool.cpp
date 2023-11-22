#include<iostream>
#include<cstdio>
using namespace std;

int c, t;
int n, m;
int eq[100010], to[100010], from[100010];
char op;
int sum;

int v[100010];
int v_[100010];
bool f[100010];
int x;

int main() {
 	freopen("tribool.in", "r", stdin);
 	freopen("tribool.out", "w", stdout);
	scanf("%d %d", &c, &t);
	if (c <= 2) {
		while (t--) {
			sum = 10;
			scanf("%d %d", &n, &m);
			for (register int i=1; i<=m; i++) {
				op = getchar();
				while (op != 'T' && op != 'F' && op != 'U' && op != '-' && op != '+')
					op = getchar();
				if (op == '-' || op == '+') {
					scanf("%d %d", &to[i], &from[i]);
					eq[i] = (op=='-' ? 1 : 2);
				}
				else {
					scanf("%d", &to[i]);
					eq[i] = (op=='U' ? 5 : (op=='T' ? 3 : 4));
				}
			}
			for (register int i=0; i<(1<<(n<<1)); i++) {
				int tmp = 0;
				bool p = false;
				for (register int d=(n<<1)-1; ~d; d-=2) {
					int now = (i>>(d-1)) & 3;
					if (now == 0) {
						p = true;
						break;
					}
					v_[(d+1)>>1] = v[(d+1)>>1] = now + 2;
				}
				if (p)
					continue;
				for (register int i=1; i<=m; i++) {
					if (eq[i] <= 2) {
						if (v_[from[i]] == 5)
							v_[to[i]] = 5;
						else if (eq[i] == 1)
							v_[to[i]] = (v_[from[i]]==3 ? 4 : 3);
						else
							v_[to[i]] = (v_[from[i]]==3 ? 3 : 4);
					}
					else
						v_[to[i]] = eq[i];
				}
				p = true;
				for (register int i=1; i<=n; i++) {
					if (v[i] != v_[i]) {
						p = false;
						break;
					}
					if (v[i] == 5)
						++tmp;
				}
				if (p)
					sum = min(sum, tmp);
			}
			printf("%d\n", sum);
		}
		return 0;
	}
	else if (c <= 4) {
		while (t--) {
			sum = 0;
			scanf("%d %d", &n, &m);
			while (m--) {
				op = getchar();
				while (op != 'T' && op != 'F' && op != 'U')
					op = getchar();
				scanf("%d", x);
				if (op == 5)
					if (! f[x]) {
						f[x] = true;
						sum++;
					}
				else
					if (f[x]) {
						f[x] = false;
						sum--;
					}
			}
			printf("%d\n", sum);
		}
		return 0;
	}
	else {
		while (t--) {
			sum = 0;
			scanf("%d %d", &n, &m);
			for (register int i=1; i<=n; i++)
				eq[i] = 2, v[i] = i;
			for (register int i=1; i<=m; i++) {
				op = getchar();
				while (op != 'T' && op != 'F' && op != 'U' && op != '-' && op != '+')
					op = getchar();
				if (op == '-' || op == '+') {
					scanf("%d %d", &to[i], &from[i]);
					if (op == '-') {
						if (eq[from[i]] == 5)
							eq[to[i]] = 5;
						else if (eq[from[i]] > 2)
							eq[to[i]] = (eq[from[i]]==3 ? 4 : 3);
						else
							eq[to[i]] = (eq[from[i]]==1 ? 2 : 1), v[to[i]] = v[from[to[i]]];
					}
					else {
						if (eq[from[i]] == 5)
							eq[to[i]] = 5;
						else if (eq[from[i]] > 2)
							eq[to[i]] = (eq[from[i]]==3 ? 3 : 4);
						else
							eq[to[i]] = (eq[from[i]]==1 ? 1 : 2), v[to[i]] = v[from[to[i]]];
					}
				}
				else {
					scanf("%d", &to[i]);
					eq[to[i]] = (op=='U' ? 5 : (op=='T' ? 3 : 4));
				}
			}
			for (register int i=1; i<=n; i++) {
				if (eq[i] > 2) {
					if (eq[i] == 5)
						++sum;
					continue;
				}
				if (eq[i] == 1 && v[i] == i) {
					++sum;
					continue;
				}
				if (eq[v[i]] == 1 && v[v[i]] == v[i]) {
					++sum;
					continue;
				}
			}
			printf("%d\n", sum);
		}
	}
 	return 0;
}
