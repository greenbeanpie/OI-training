#include <bits/stdc++.h>

using namespace std;

const int maxn = 3005;

int n, m;

char str[maxn];

struct node
{
	string s;
	int id;
	bool operator<(const node& rhs) const
	{
		return s < rhs.s;
	}
} a[maxn];

string s[maxn];

int read()
{
	int res = 0, ch = getchar();
	for (; !isdigit(ch); ch = getchar())
		;
	for (; isdigit(ch); ch = getchar())
		res = (res << 3) + (res << 1) + (ch & 15);
	return res;
}

int main()
{
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	n = read(), m = read();
	if (n == 1)
	{
		printf("1\n");
		return 0;
	}
	for (int i = 1; i <= n; ++i)
	{
		scanf("%s", str);
		s[i] = str;
		sort(s[i].begin(), s[i].end());
		a[i].s = s[i], a[i].id = i;
		reverse(a[i].s.begin(), a[i].s.end());
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++i)
		printf("%d", s[i] < a[1 + (a[1].id == i)].s);
	return 0;
}