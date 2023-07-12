#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace std;
#define itn long long
#define int long long
const int N = 1e5 + 10;
int n, k;
struct node
{
	int a = 0, b = 0, c = 0;
} num[N];
bool cmp1(node a, node b)
{
	if (a.a == b.a)
	{
		if (a.b == b.b)
		{
			return a.c < b.c;
		}
		return a.b < b.b;
	}
	return a.a < b.a;
}
bool cmp2(node a, node b)
{
	if (a.b == b.b)
	{
		if (a.c == b.c)
		{
			return a.a < b.a;
		}
		return a.c < b.c;
	}
	return a.b < b.b;
}
bool cmp3(node a, node b)
{
	return a.c < b.c;
}
bool operator==(node a, node b)
{
	return a.a == b.a && a.b == b.b && a.c == b.c;
}
struct SegTree
{
	vector<int> tree;
};

int tot = 0;
signed main()
{
	cin >> n >> k;
	set<int> s;
	for (int i = 1; i <= n; i++)
	{
		cin >> num[i].a >> num[i].b >> num[i].c;
		s.insert(num[i].b);
		s.insert(num[i].c);
	}
	cc_hash_table<int, int> ht;
	unique(num + 1, num + 1 + n);
	sort(num + 1, num + 1 + n, cmp3);
	for (int i : s)
	{
		ht[i] = ++tot;
	}
	for (int i = 1; i <= n; i++)
	{
		num[i].b = ht[num[i].b];
		num[i].c = ht[num[i].c];
	}
}