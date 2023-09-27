#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
#define int long long
#define double long double
#define endl "\n"
#define problemname "encode"
#define const constexpr

namespace Main
{
	set<char> cs;
	char ans[27];
	int in[27], out[27];
	int cnt = 0;
	bool check(char c, char res)
	{
		if (c == res)
		{
			return 0;
		}
		if (cnt == 0)
		{
			return 1;
		}
		if (cnt >= 25)
		{
			return 1;
		}
		if (ans[res - 'a'] == c)
		{
			return 0;
		}
		if (in[res - 'a'] != 0 || out[c - 'a'] != 0)
		{
			return 0;
		}
		char start = res;
		while (ans[start - 'a'])
		{
			start = ans[start - 'a'];
		}
		if (start == c)
		{
			return 0;
		}
		return 1;
	}
	int main()
	{
		for (auto i = 'a'; i <= 'z'; i++)
		{
			cs.insert(i);
		}
		int T;
		cin >> T;
		while (T--)
		{
			int len;
			cin >> len;
			set<char> temp = cs;
			fill(ans, ans + 27, 0);
			fill(in, in + 27, 0);
			fill(out, out + 27, 0);
			string s;
			cin >> s;
			cnt = 0;
			for (auto i : s)
			{
				if (!ans[i - 'a'])
				{
					auto now = temp.begin();
					while (!check(i, *now))
					{
						++now;
					}
					++in[*now - 'a'];
					++out[i - 'a'];
					ans[i - 'a'] = *now;
					temp.erase(now);
					++cnt;
				}
				cout << ans[i - 'a'];
			}
			cout << endl;
		}
		return 0;
	}
};

signed main()
{
#ifndef ONLINE_JUDGE
	freopen(problemname ".in", "r", stdin);
	freopen(problemname ".out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	Main::main();
	return 0;
}