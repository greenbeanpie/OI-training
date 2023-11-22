#include <bits/stdc++.h>
using namespace std;
int f[5000000];

void add(int x, int y, int t) {
	if (t == 1) {
		f[y * 3] = f[x * 3];
		f[y * 3 + 1] = f[x * 3 + 1];
		f[y * 3 + 2] = f[x * 3 + 2];
	}
	else
		if (x != y) {
			f[y * 3] = f[x * 3 + 1];
			f[y * 3 + 1] = f[x * 3];
			f[y * 3 + 2] = f[x * 3 + 2];
		}
		else
			swap(f[x * 3], f[x * 3 + 1]);
}

char ch;

bool need() {
	if (ch == 'T' || ch == 'F' || ch == 'U' || ch == '+' || ch == '-')
		return true;
	
	return false;
}

int vis[5000000], ans, n, m, c, T;
bool fans;

void solve(int x, int res);

void fundeal(int res) {
	fans = true;
	ans = res;
	
	for (int i = 1; i <= n; i++)
		if (vis[i] == 3) {
			fans = false;
	
			for (int j = 0; j <= 2; j++) {
				vis[i] = j;
				solve(i * 3 + j, res + (j == 2 ? 1 : 0));
				vis[i] = 3;
		
				if (fans)
					return;
			}
		}
}

void solve(int x, int res) {
//	printf("solve:(%2d, %2d) %d\n", x / 3, x % 3, res);
	
	if (f[x] / 3 != x / 3) {
		if (vis[f[x] / 3] != 3 && vis[f[x] / 3] != f[x] % 3)
			return;
		
		if (vis[f[x] / 3] == 3) {
			vis[f[x] / 3] = f[x] % 3;
			solve(f[x], res + (f[x] % 3 == 2 ? 1 : 0));
			vis[f[x] / 3] = 3;
		}
		else
			fundeal(res);
	}
	else
		if (f[x] % 3 == x % 3)
			fundeal(res);
}

int u, v;

int main() {
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	for (scanf("%d %d", &c, &T); T; T--) {
		scanf("%d %d", &n, &m);
		
		for (int i = 1; i <= n + 3; i++)
			for (int j = 0; j <= 2; j++)
				f[i * 3 + j] = i * 3 + j;
		
		for (int i = 1; i <= m; i++) {
			for (ch = getchar(); !need(); ch = getchar())
				;
			
			switch (ch) {
				case 'T': {
					scanf("%d", &v);
					add(n + 1, v, 1);
					break;
				}
				
				case 'F' : {
					scanf("%d", &v);
					add(n + 2, v, 1);
					break;
				}
				
				case 'U': {
					scanf("%d", &v);
					add(n + 3, v, 1);
					break;
				}
				
				case '+': {
					scanf("%d %d", &v, &u);
					add(u, v, 1);
					break;
				}
				
				case '-': {
					scanf("%d %d", &v, &u);
					add(u, v, 2);
					break;
				}
			}
		}
		
//		printf("edge:\n");
//		for (int i = 1; i <= n; i++) {
//			for (int j = 0; j <= 2; j++)
//				printf("(%2d, %2d) ", f[i * 3 + j] / 3, f[i * 3 + j] % 3);
//			
//			printf("\n");
//		}
		
		for (int i = 1; i <= n; i++)
			vis[i] = 3;
		
		vis[n + 1] = 0;
		vis[n + 2] = 1;
		vis[n + 3] = 2;
		fans = false;
		
		for (int i = 0; i <= 2; i++) {
			vis[1] = i;
			solve(3 + i, i == 2 ? 1 : 0);
			
			if (fans) {
				printf("%d\n", ans);
				break;
			}
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}