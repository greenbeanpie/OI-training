#include <bits/stdc++.h>
using namespace std;
int n;
pair<int, int> a[100050];
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i].first >> a[i].second;
	}
	sort(a + 1, a + n + 1);
	for (int i = 1, j = 1; i <= n; i = j)
	{
		int l = a[i].first;
		int r = a[i].second;
		for (; j <= n && a[j].first <= r; j++)
		{
			r = max(r, a[j].second);
		}
		cout << l << " " << r << "\n";
	}
	return 0;
}
