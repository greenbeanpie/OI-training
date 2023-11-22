#include <bits/stdc++.h>
using namespace std;

int n, m, a[100005], b[100005], ans;
char op[100005][5], arr[15];

bool check(){
	char arr1[15];
	for (int i = 1; i <= n; i++)
		arr1[i] = arr[i];
	for (int i = 1; i <= m; i++){
		if (op[i][0] == 'T' || op[i][0] == 'U' || op[i][0] == 'F')
			arr1[a[i]] = op[i][0];
		if (op[i][0] == '+')
			arr1[a[i]] = arr1[b[i]];
		if (op[i][0] == '-')
			arr1[a[i]] = arr1[b[i]] == 'T' ? 'F' : (arr1[b[i]] == 'U' ? 'U' : 'T');
	}
	for (int i = 1; i <= n; i++)
		if (arr1[i] != arr[i])
			return 0;
	return 1;
}

void dfs1(int step, int cnt){
	if (cnt >= ans)
		return ;
	if (step > n){
		if (check())
			ans = min(ans, cnt);
		return ;
	}
	arr[step] = 'T';
	dfs1(step + 1, cnt);
	arr[step] = 'F';
	dfs1(step + 1, cnt);
	arr[step] = 'U';
	dfs1(step + 1, cnt + 1);
}

void solve1(){
	ans = 20;
	dfs1(1, 0);
	printf("%d\n", ans);
}
void solve2(){
	ans = 0;
	int arr2[100005];
	for (int i = 1; i <= n; i++)
		arr2[i] = 0;
	for (int i = 1; i <= m; i++){
		if (op[i][0] == 'T')
			arr2[a[i]] = 1;
		if (op[i][0] == 'F')
			arr2[a[i]] = 2;
		if (op[i][0] == 'U')
			arr2[a[i]] = 3;
	}
	for (int i = 1; i <= n; i++)
		if (arr2[i] == 3)
			ans++;
	printf("%d\n", ans);
}

int main(){
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);

	int c, T;
	scanf("%d%d", &c, &T);
	while (T--){
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= m; i++){
			scanf("%s", op[i]);
			if (op[i][0] == 'T' || op[i][0] == 'U' || op[i][0] == 'F')
				scanf("%d", &a[i]);
			if (op[i][0] == '+' || op[i][0] == '-')
				scanf("%d%d", &a[i], &b[i]);
		}
		if (c <= 2)
			solve1();
		if (c == 3 || c == 4)
			solve2();
		if (c == 5 || c == 6)
			solve3();
		if (c == 7 || c == 8)
			solve4();
	}

	return 0;
}

