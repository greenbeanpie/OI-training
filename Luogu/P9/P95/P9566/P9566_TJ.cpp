#include <iostream>
#include <cstring>
#include <algorithm>

#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)

using namespace std;

const int N = 1e6 + 10;

char a[N];
char b[N];
bool tag[N];
int n, m;

int solve(char k, char b)
{
	tag[1] = tag[n] = false;

	a[1] = k, a[n] = b;
	int sum = 0;

	rep(i, 1, n) if (tag[i]) a[i] = '0';
	rep(i, 1, n - 1) if (a[i] != a[i + 1]) sum++;

	int tmp = (sum & 1) ^ (m & 1);
	if (tmp)
	{
		return -1;
	}

	if (sum > m)
	{
		bool f = true;
		int l, r;
		per(i, n - 1, 1)
		{
			if (sum == m)
				break;

			if (f && tag[i])
			{
				f = false;
				r = i;
			}

			if (!tag[i] && !f)
			{
				f = true;
				l = i + 1;

				if (a[r + 1] == '1' && a[l - 1] == '1')
				{
					sum -= 2;
					rep(i, l, r) a[i] = '1';
				}
			}
		}
	}
	else
	{
		per(i, n - 1, 2)
		{
			if (sum == m)
				break;

			if (tag[i])
			{
				if (a[i + 1] == a[i] && a[i - 1] == a[i])
				{
					a[i] = '1';
					sum += 2;
				}
			}
		}
	}

	if (sum != m)
		return -1;
	return 1;
}

int main()
{

	int T;
	cin >> T;
	while (T--)
	{
		cin >> n >> m;

		cin >> (a + 1);

		rep(i, 1, n)
		{
			if (a[i] == '?')
				tag[i] = true;
			else
				tag[i] = 0;
		}

		for (int i = 1; i <= n; i++)
			b[i] = a[i];

		if (a[1] == '?' && a[n] == '?')
		{
			int t = solve('0', '0');
			if (t > 0)
			{
				cout << a + 1 << '\n';
				continue;
			}
			for (int i = 1; i <= n; i++)
				a[i] = b[i];
			t = solve('0', '1');
			if (t > 0)
			{
				cout << a + 1 << '\n';
				continue;
			}
			for (int i = 1; i <= n; i++)
				a[i] = b[i];
			t = solve('1', '0');
			if (t > 0)
			{
				cout << a + 1 << '\n';
				continue;
			}
			for (int i = 1; i <= n; i++)
				a[i] = b[i];
			t = solve('1', '1');
			if (t > 0)
			{
				cout << a + 1 << '\n';
				continue;
			}
			puts("Impossible");
			continue;
		}

		if (a[1] == '?')
		{
			int t = solve('0', a[n]);
			if (t > 0)
			{
				cout << a + 1 << '\n';
				continue;
			}
			for (int i = 1; i <= n; i++)
				a[i] = b[i];
			t = solve('1', a[n]);
			if (t > 0)
			{
				cout << a + 1 << '\n';
				continue;
			}
			puts("Impossible");
			continue;
		}

		if (a[n] == '?')
		{
			int t = solve(a[1], '0');
			if (t > 0)
			{
				cout << a + 1 << '\n';
				continue;
			}
			for (int i = 1; i <= n; i++)
				a[i] = b[i];
			t = solve(a[1], '1');
			if (t > 0)
			{
				cout << a + 1 << '\n';
				continue;
			}
			puts("Impossible");
			continue;
		}

		int t = solve(a[1], a[n]);
		if (t < 0)
			puts("Impossible");
		else
			cout << a + 1 << '\n';
	}
	return 0;
}