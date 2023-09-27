#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
#define int long long
#define double long double
#define endl "\n"
#define problemname "D"
#define const constexpr

namespace Main
{
	deque<int> q;
	double st = clock();
	int num[300005], minans = 1e9;
	int n;
	void dfs(int now, int mindt)
	{
		if(1.0*(clock()-st)/CLOCKS_PER_SEC>=0.98){
			cout << minans;
			exit(0);
		}
		if (now == n + 1)
		{
			minans = min(minans, mindt);
			return;
		}
		int front = abs(num[now] - q.front()), back = abs(num[now] - q.back());
		if (front <= back)
		{
			q.push_front(num[now]);
			dfs(now + 1, max(mindt, front));
			q.pop_front();
			q.push_back(num[now]);
			dfs(now + 1, max(mindt, back));
			q.pop_back();
		}
		else
		{
			q.push_back(num[now]);
			dfs(now + 1, max(mindt, back));
			q.pop_back();
			q.push_front(num[now]);
			dfs(now + 1, max(mindt, front));
			q.pop_front();
		}
	}

	int main()
	{

		cin >> n;
		if (n == 1)
		{
			cout << 0;
			return 0;
		}
		for (int i = 1; i <= n; i++)
		{
			cin >> num[i];
		}
		q.push_back(num[1]);
		q.push_back(num[2]);
		dfs(3, abs(num[1] - num[2]));
		cout << minans;
		return 0;
	}
};

signed main()
{
#ifndef ONLINE_JUDGE
	freopen(problemname "2.in", "r", stdin);
	freopen(problemname ".out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	Main::main();
	return 0;
}