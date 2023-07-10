#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
const int N = 1e5 + 10;
double a[N], c[N];
int n, k;
int check(int x)
{
	int cnt = 0;
	vector<int> v = vector<int>(1);
	for (int i = 1; i <= n; i++)
	{
		v.push_back(a[i] * (c[i] - x));
		if (a[i] * (c[i] - x) >= 0)
		{
			cnt--;
		}
	}
	sort(v.begin() + 1, v.end(), less<double>());
	int r = v.size();
	for (int i = 1; i <= n; i++)
	{
		while (v[i] >= -v[r] && r)
		{
			r--;
		}
		cnt += n - r;
	}
	return cnt / 2;
}

signed main()
{

	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i] >> c[i];
	}

	return 0;
}