#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
	freopen("genshin.in", "r", stdin);
	freopen("genshin.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	priority_queue<int,vector<int>,greater<int> > q1;
	queue<int> q2;
	for (int i = 1, temp; i <= n; i++)
	{
		cin >> temp;
		if (temp % 2 == 0)
		{
			q1.push(temp);
		}
	}
	int m;
	cin >> m;
	for (int i = 1, temp; i <= m; i++)
	{
		cin >> temp;
		if (temp % 2)
		{
			q2.push(temp);
		}
	}
	int sum = 0;
	int a = q1.size() - q2.size();
	for (int i = 1; i <= a; i++)
	{
		sum += q1.top();
		q1.pop();
	}
	cout << sum;
	return 0;
}