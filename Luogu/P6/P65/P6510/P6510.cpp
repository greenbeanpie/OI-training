#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#define int long long
#define endl "\n"

signed main()
{
#ifndef ONLINE_JUDGE
	freopen("P6510.in", "r", stdin);
	freopen("P6510.out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	int ans = 0, num[n + 1];
	for (int i = 1; i <= n; i++)
	{
		cin >> num[i];
	}
	stack<int> s1, s2;
	int l[n + 1], r[n + 1];
	for (int i = 1; i <= n; i++)
	{
		while (s1.size() && num[s1.top()] < num[i])
		{
			s1.pop();
		}
		if (s1.size())
		{
			l[i] = s1.top();
		}
		else
		{
			l[i] = 0;
		}
		s1.push(i);
	} // 记l_i为num_i左侧第一个大于这个数的下标，若不存在则为0
	for (int i = n; i >= 1; i--)
	{
		while (s2.size() && num[s2.top()] > num[i])
		{
			s2.pop();
		}
		if (s2.size())
		{
			r[i] = s2.top();
		}
		else
		{
			r[i] = n + 1;
		}
		s2.push(i);
	}							 // 记r_i为num_i右侧第一个小于这个数的下表，若不存在则为n+1
	for (int i = n; i >= 1; i--) // 枚举区间的右端点，从右到左枚举更方便进行最后的剪枝
	{
		for (int j = l[i] + 1; j < i; j++) // 从l_i开始寻找第一个num_j使得中间的数均大于num_j
		{
			if (r[j] > i) // num_j右侧的第一个小于num_i的端点在i的右侧
			{
				ans = max(ans, i - j + 1);
				break;
			}
		}
		if (i < ans) // 答案最大为i
		{
			break;
		}
	}
	cout << ans;
	return 0;
}