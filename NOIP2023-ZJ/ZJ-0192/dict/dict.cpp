#include <bits/stdc++.h>
#define file(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout); 
using namespace std;
const int N = 3000 + 5;
char s[N][N];
char mx[N], mn[N];
int sx[N], sn[N];
int main(){
	file("dict");
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++){
		scanf("%s", s[i] + 1);
		for (int j = 1; j <= m; j++) {
			if(mn[i] == 0 || s[i][j] < mn[i]) mn[i] = s[i][j], sn[i] = 0;
			if(s[i][j] == mn[i]) sn[i]++;
			if(mx[i] == 0 || s[i][j] > mx[i]) mx[i] = s[i][j], sx[i] = 0;
			if(s[i][j] == mx[i]) sx[i]++;
		}
	}
	for (int i = 1; i <= n; i++){
		int ans = 1;
		for (int j = 1; j <= n; j++) {
			if(j == i) continue;
			if(mx[j] > mn[i]) continue;
			if(mx[j] <= mn[i]) {
				ans = 0;
				break;
			}
		}
		printf("%d", ans);
	}
	return 0;
}