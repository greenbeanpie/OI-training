//lyxhsx
#include <bits/stdc++.h>

using namespace std;

const int N = 6007;

int n, m, p[N], res[N];

char ch[N][N / 2];

string s[N];

bool cmp (int x, int y)
{
	if (s[x] == s[y])
		return x > y;
	return s[x] < s[y];
}
bool cmp1 (char x, char y)
{
	return x < y;
}

int main ()
{
	freopen ("dict.in", "r", stdin);
	freopen ("dict.out", "w", stdout);
	cin >> n >> m;
	if (n <= 1000)
		for (int i = 1; i <= n; ++ i)
			cin >> s[i];
	else
		for (int i = 1; i <= n; ++ i)
			scanf ("%s", ch[i]), s[i] = ch[i];
	for (int i = 1; i <= n; ++ i)
	{
		sort (s[i].begin (), s[i].end (), cmp1);
		for (int j = 0; j < m; ++ j)
			s[i + n] += s[i][m - j - 1];
	}
	for (int i = 1; i <= 2 * n; ++ i)
		p[i] = i;
	sort (p + 1, p + n * 2 + 1, cmp);
	for (int i = 1; i <= 2 * n; ++ i)
		if (p[i] <= n)
			res[p[i]] = 1;
		else
		{
			res[p[i] - n] = 1;
			break;
		}
	for (int i = 1; i <= n; ++ i)
		cout << res[i];
	return 0;
}