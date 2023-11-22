#include <iostream>
#include <cstdio>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define ssz(x) (int((x).size()))

auto chmin = [](auto& x, auto y) { if (x > y) x = y; };
auto chmax = [](auto& x, auto y) { if (x < y) x = y; };

using ll = long long;
const int max_n = 3000;

char s[max_n + 1], l[max_n], r[max_n];

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);  
	
	int n, m;
	
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		l[i] = 'z', r[i] = 'a';
		for (int j = 0; j < m; j++)
		{
			chmin(l[i], s[j]);
			chmax(r[i], s[j]);
		}
	}
	
	for (int i = 0; i < n; i++)
	{
		bool hans = 1;
		for (int j = 0; j < n; j++)
			if (i != j && r[j] <= l[i])
			{
				hans = 0;
				break;
			}
		cout << hans;
	}
	
	return 0;
}