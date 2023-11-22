#include <bits/stdc++.h>

using namespace std;

const int N = 3010;

bool Mbe;
int n, m;
string s[N];
int p[N];
bool Med;

int cmp(int x, int y) { return s[x] < s[y]; }

int main()
{
	freopen("dict.in", "r", stdin); freopen("dict.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i ++ ) cin >> s[i];
	for (int i = 1; i <= n; i ++ ) 
	{
		sort(s[i].begin(), s[i].end());
		reverse(s[i].begin(), s[i].end());
	}
	for (int i = 1; i <= n; i ++ ) p[i] = i; 
	sort(p + 1, p + 1 + n, cmp);
	if (n == 1) { putchar('1'); return 0; }
	for (int i = 1; i <= n; i ++ )
	{
		int pos = p[1];
		if (pos == i) pos = p[2];
		reverse(s[i].begin(), s[i].end());
		if (s[i] < s[pos]) putchar('1');
		else putchar('0');
		reverse(s[i].begin(), s[i].end());
	}
	return 0;
}
