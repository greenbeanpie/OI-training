#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#define int long long
#define double long double
#define endl "\n"
#define problemname "P3566"
#define const constexpr

constexpr int N = 1000000;
set<std::pair<long long, long long>, std::greater<std::pair<long long, long long> >, std::allocator<std::pair<long long, long long> > > cnt;
vector<int> num;
signed main()
{
#ifndef ONLINE_JUDGE
	freopen(problemname ".in", "r", stdin);
	freopen(problemname ".out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int k, p, q;
	cin >> k >> p >> q;
	int qnum, max2;
	int temp;
	for (int i = 1; i <= k; i++)
	{
		cin >> temp;
		if (i == p)
			--temp;
		if (i != q)
			cnt.insert({temp, i});
		else
			qnum = --temp;
	}
	num.push_back(p);
	max2 = ((++cnt.begin())->first);
	if (p != q)
	{
		num.push_back(q);
		--qnum;
	}
	int m1cnt = 0;
	for (int i = 1; i <= cnt.begin()->first - max2 && qnum; i++)
	{
		++m1cnt;
		--qnum;
		num.push_back(cnt.begin()->first);
		num.push_back(q);
	}
	while (qnum)
	{
		if (qnum >= cnt.rbegin()->first)
		{
			for (int i = 1; i <= cnt.rbegin()->first; i++)
			{
				num.push_back(cnt.rbegin()->second);
				num.push_back(q);
			}
			qnum -= cnt.rbegin()->first;
			cnt.erase(--cnt.end());
		}
		else
		{
			for (int i = 1; i <= qnum; i++)
			{
				num.push_back(cnt.rbegin()->second);
				num.push_back(q);
			}
			auto temp = *cnt.rbegin();
			temp.first -= qnum;
			qnum = 0;
			cnt.erase(--cnt.end());
		}
		if (cnt.empty())
		{
			cout << 0;
			return 0;
		}
	}
	while (cnt.size() - 2 && cnt.begin()->first - m1cnt > max2)
	{
		if (cnt.size() <=2)
		{
			break;
		}
		else if (cnt.rbegin()->first > cnt.begin()->first - m1cnt - max2)
		{
			auto temp = *--cnt.end();
			cnt.erase(--cnt.end());
			cnt.insert({temp.first - (cnt.begin()->first - m1cnt - max2), temp.second});
			for (; cnt.begin()->first - m1cnt - max2; ++m1cnt)
			{
				num.push_back(cnt.rbegin()->second);
				num.push_back((--cnt.end())->second);
			}
			break;
		}
		else
		{
			for (int i = 1; i <= (--cnt.end())->first; i++)
			{
				num.push_back(cnt.rbegin()->second);
				num.push_back((--cnt.end())->second);
			}
			m1cnt += (--cnt.end())->first;
			num.erase(--num.end());
		}
	}
	if(cnt.size()==2){
		if(cnt.begin()->first-cnt.rbegin()->first>1){
			cout << 0;
			return 0;
		}
	}
	if (cnt.size() == 1)
	{
		if (cnt.begin()->first > 1)
		{
			cout << 0;
			return 0;
		}
		else
		{
			num.push_back(cnt.begin()->second);
			num.erase(num.begin());
		}
	}
	if (cnt.empty())
	{
		if (*num.rbegin() == q)
		{
			cout << 0;
			return 0;
		}
	}
	int add = 0;
	while (cnt.size())
	{
		for (auto i : cnt)
		{
			num.push_back(i.second);
		}
		++add;
		while (cnt.size() && (cnt.rbegin()->first) <= add)
		{
			cnt.erase(--cnt.end());
		}
	}
	num.push_back(q);
	cout << *num.begin();
	num.erase(num.begin());
	for (int i : num)
	{
		cout << " " << i;
	}
	return 0;
}