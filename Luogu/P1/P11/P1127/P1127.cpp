#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#define int long long
#define endl "\n"

char start, last;
int pos[205];
deque<string> q;
bool vis[1005];
int t;
string str[1005];
extern void dfs();
signed main()
{
#ifndef ONLINE_JUDGE
	freopen("P1127.in", "r", stdin);
	freopen("P1127.out","w",stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		cin >> str[i];
	}
	sort(str, str + t);
	int in[205];
	memset(in, 0, sizeof(in));
	for (int i = 0; i < t; i++)
	{
		++in[str[i][0]];
		--in[str[i][str[i].size() - 1]];
	}
	int a = 0, b = 0;
	for (int i = 'z'; i >= 'a'; i--)
	{
		if (in[i] > 0)
		{
			start = i;
			a++;
		}
		else if (in[i] < 0)
		{
			last = i;
			b++;
		}
	}
	pos[str[0][0]] = 0;
	for (int i = 1; i < t; i++)
	{
		while (i < t - 1 && str[i][0] == str[i - 1][0])
		{
			i++;
		}
		if (i != t - 1 || str[i][0] != str[i - 1][0])
		{
			pos[str[i][0]] = i;
		}
	}
	for (int i = pos[start]; str[i][0] == start; i++)
	{
		vis[i] = true;
		q.push_front(str[i]);
		dfs();
		vis[i] = false;
		q.pop_front();
	}
	q.push_front(str[0]);
	dfs();
	cout << "***";
	return 0;
}
void dfs()
{
	if (q.size() == t)
	{
		cout << q.back();
		q.pop_back();
		while (q.size())
		{
			cout << "." << q.back();
			q.pop_back();
		}
		exit(0);
	}
	for (int i = pos[q.front()[q.front().size() - 1]]; str[i][0] == q.front()[q.front().size() - 1]; i++)
	{
		if (!vis[i])
		{
			q.push_front(str[i]);
			vis[i] = true;
			dfs();
			vis[i] = false;
			q.pop_front();
		}
	}
}