#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3010;
int n, m;
char a[MAXN][MAXN];
int cnt[MAXN][500];
int L[MAXN], R[MAXN];
signed main()
{
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> (a[i] + 1);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
			cnt[i][int(a[i][j])]++;
		int l = int('a'), r = int('z');
		while (cnt[i][l] == 0 && l <= int('z')) l++;
		while (cnt[i][r] == 0 && r >= int('a')) r--;
		L[i] = l, R[i] = r;
	}
	for (int i = 1; i <= n; i++)
	{
		int flag = 1;
		for (int j = 1; j <= n; j++)
		{
			if (j == i) continue;
			if (L[i] >= R[j]) {flag = 0; break;}
		}
		cout << flag;
	}
	return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3010;
int n, m;
char a[MAXN][MAXN];
int cnt[MAXN][500];
int pos[MAXN];
signed main()
{
//	freopen("dict.in", "r", stdin);
//	freopen("dict.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> (a[i] + 1);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
			cnt[i][int(a[i][j])]++;
			
	}
	for (int i = 1; i <= n; i++)
	{
		int flag = 1;
		for (int j = 1; j <= n; j++)
		{
			if (!flag) break;
			if (j == i) continue;
			int l = int('a'), r = int('z');
			while (cnt[i][l] == 0 && l <= int('z')) l++;
			while (cnt[j][r] == 0 && r >= int('a')) r--;
			if (l < r) continue;
			if (l > r) {flag = 0; break;}
			flag = 0; break;
			// l == r
//			if (cnt[i][l] < cnt[j][r]) continue;
//			if (cnt[i][l] > cnt[j][r]) {flag = 0; break;}
//			if (cnt[i][l] == cnt[j][r]) {flag = 0; break;}
		}
		cout << flag;
	}
	return 0;
}
*/