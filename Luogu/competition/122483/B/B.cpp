#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
int t, n;
string a, b;
int ans, cnt, cne;
int id[N];

int main()
{
#ifndef ONLINE_JUDGE
	freopen(problemname ".in", "r", stdin);
	freopen(problemname ".out", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	while (t--)
	{
		cin >> n >> a;
		ans = 0, cnt = 0, cne = 0;
		if (n <= 5)
		{
			for (int i = 0; i < n; i++)
			{
				if (a[i] == 'T')
					cnt++;
				else
					ans = max(ans, cnt), cnt = 0;
			}
			ans = max(ans, cnt);
			cout << ans << '\n';
			continue;
		}
		for (int j = 0; j < n; j++)
		{
			if (a[j] == 'T')
				cnt++;
			else
			{
				if (ans < cnt)
				{
					ans = cnt;
					cne = 0;
					id[++cne] = j - ans;
				}
				else if (ans == cnt)
				{
					id[++cne] = j - ans;
				}
				cnt = 0;
			}
		}
		if (cnt > ans)
		{
			ans = cnt;
			cne = 0;
			id[++cne] = n - ans;
		}
		else if (cnt == ans)
			id[++cne] = n - cnt;
		ans = max(ans, cnt);
		int len = ans;
		cnt = 0;
		for (int u = 1; u <= cne; u++)
		{
			int j = id[u] + len - 1;
			int cnq = len;
			if (id[u] - 4 >= 0 &&
				a[id[u] - 1] == 'B' && a[id[u] - 2] == 'T' && a[id[u] - 3] == 'T' && a[id[u] - 4] == 'B')
				cnq++;
			if (j + 4 < n &&
				a[j + 1] == 'B' && a[j + 2] == 'T' && a[j + 3] == 'T' && a[j + 4] == 'B')
				cnq++;
			ans = max(cnq, ans);
		}
		int i = 0;
		while (1)
		{
			if (i + 3 >= n)
				break;
			if (a[i] == 'B' && a[i + 1] == 'T' && a[i + 2] == 'T' && a[i + 3] == 'B')
			{
				a[i] = 'T';
				a[i + 1] = 'B';
				a[i + 2] = 'B';
				a[i + 3] = 'T';
				if (i - 2 >= 0)
					i -= 2;
				else
					i += 2;
				continue;
			}
			i++;
		}
		for (int j = 0; j < n; j++)
		{
			if (a[j] == 'T')
				cnt++;
			else
				ans = max(ans, cnt), cnt = 0;
		}
		ans = max(ans, cnt);
		cout << ans << '\n';
	}
	return 0;
}
