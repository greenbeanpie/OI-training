#include <bits/stdc++.h>
using namespace std;
const int N = 3010;
int n, m, c[30], cnt;
char a[N][N], b[N][N],  s1[N], s2[N];
int main () {
	freopen ("dict.in", "r", stdin);
	freopen ("dict.out", "w", stdout);
	scanf ("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf ("%s", a[i] + 1);
		cnt = 0;
		for (int j = 1; j <= m; j++) {
			c[a[i][j] - 'a' + 1]++;
		}
		cnt = 0;
		for (int j = 26; j >= 1; j--) {
			for (int k = 1; k <= c[j]; k++) {
				a[i][++cnt] = j + 'a' - 1;
			}
		}
		cnt = 0;
		for (int j = 1; j <= 26; j++) {
			for (int k = 1; k <= c[j]; k++) {
				b[i][++cnt] = j + 'a' - 1;
			}
		}
		for (int i = 1; i <= 26; i++) {
			c[i] = 0;
		}
	}
	if (n == 1) {
		printf ("1\n");
		return 0;
	}
	strcpy (s1 + 1, a[1] + 1);
	for (int i = 2; i <= n; i++) {
		if (strcmp (a[i] + 1, s1 + 1) == -1) {
			strcpy (s2 + 1, s1 + 1);
			strcpy (s1 + 1, a[i] + 1);
		} else if (s2[1] == '\0' || strcmp (a[i] + 1, s2 + 1) == -1) {
			strcpy (s2 + 1, a[i] + 1);
		}
	}
	cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (strcmp (a[i] + 1, s1 + 1) == 0) {
			cnt++;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (cnt == 1 && strcmp (a[i] + 1, s1 + 1) == 0) {
			printf ("%d", strcmp (b[i] + 1, s2 + 1) == -1);
		} else {
			printf ("%d", strcmp (b[i] + 1, s1 + 1) == -1);
		}
	}
	printf ("\n");
	return 0;
}