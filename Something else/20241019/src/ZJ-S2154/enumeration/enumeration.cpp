#include <bits/stdc++.h>
using namespace std;
#define int long long

namespace Main
{
	struct tup
	{
		int a, b, c;
		tup(int n1, int n2, int n3)
		{
			a = n1, b = n2, c = n3;
		}
	};
	bool operator<(tup t1, tup t2)
	{
		return t1.a == t2.a ? (t1.b == t2.b ? t1.c < t2.c : t1.b < t2.b) : t1.a < t2.a;
	}
	set<tup> res;
	int main()
	{
		int n, n3, p;
		cin >> n >> n3 >> p;
		int cnt = 0;
		for (int a = 1; a <= p; a++)
		{
			for (int c = n3 + 1; c <= p; c++)
			{
				int b = 0;
				if ((n * n + 1) % a % c > n3)
				{
					b = c - ((n * n + 1) % a % c - n3);
				}
				else
				{
					b = n3 - (n * n + 1) % a % c;
				}
				++cnt;
				res.insert({a, b, c});
				b += c;
				while (b <= p)
				{
					++cnt;
					res.insert({a, b, c});
					b += c;
				}
				while (res.size() > 100000)
				{
					res.erase(--res.end());
				}
			}
		}
		cout << cnt << endl;
		for (auto i : res)
		{
			cout << i.a << " " << i.b << " " << i.c << endl;
		}
		return 0;
	}
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("enumeration.in", "r", stdin);
	freopen("enumeration.out", "w", stdout);
	Main::main();
	return 0;
}
