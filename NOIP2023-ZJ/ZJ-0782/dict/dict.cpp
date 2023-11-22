#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int n, l;
int a[3010][3010], id;
int mi[3010][3010], ma[3010][3010];
int ind[3010];
char c;

bool check(int x) {
	for (register int i=1; i<=n; i++) {
		if (i == x)
			continue;
		for (register int j=1; j<=l; j++) {
			if (mi[x][j] > ma[i][j])
				return false;
			if (mi[x][j] < ma[i][j])
				break;
			if (j == l)
				return false;
		}
	}
	return true;
}

bool cmp(int x, int y) {
	return a[id][x] < a[id][y];
}

int main() {
 	freopen("dict.in", "r", stdin);
 	freopen("dict.out", "w", stdout);
	scanf("%d%d", &n, &l);
	for (register int i=1; i<=n; i++)
		ind[i] = i;
	for (id=1; id<=n; id++) {
		for (register int j=1; j<=l; j++) {
			c = getchar();
			while (c < 'a' || c > 'z') c = getchar();
			a[id][j] = c - 'a' + 1;
			mi[id][j] = ma[id][j] = a[id][j];
		}
		sort(ind+1, ind+n+1, cmp);
		for (register int j=1; j<l; j++)
			if (ind[j] > ind[j+1] && (a[ind[j]] != a[ind[j+1]])) {
				swap(mi[id][ind[j]], mi[id][ind[j+1]]);
				break;
			}
		for (register int j=1; j<=l; j++)
			if (ind[n-j+1] != j) {
				swap(ma[id][ind[n-j+1]], ma[id][ind[1]]);
				break;
			}
	}
	if (n == 1) {
		printf("1");
		return 0;
	}
	for (register int i=1; i<=n; i++) {
		if (check(i))
			printf("1");
		else
			printf("0");
	}
 	return 0;
}
