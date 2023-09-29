#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
// #pragma GCC optimize(3, "Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
#define int long long
#define double long double
#define endl "\n"
#define problemname "sign"
#define const constexpr

int n;

namespace Subtask1
{
	vector<unordered_set<int>> v;
	void solve()
	{
		v.clear();
		for(int i=1;i<=n;i++){
			unordered_set<int> temp;
			int m;
			cin >> m;
			
			for(int i=1,t;i<=m;i++){
				cin >> t;
				temp.insert(t);
			}if(m==0||m==1){
				continue;
			}
			v.push_back(temp);
		}
		bool ans=1;
		for(auto i=v.begin();i!=v.end()&&ans;i++){
			for(auto j=i;j!=v.end()&&ans;j++){
				if(j==i){
					continue;
				}
				int res=0;
				for(auto k:*j){
					if(i->count(k)){
						++res;
					}
				}
				if(res&&res<min(j->size(),i->size())){
					ans=0;
				}
			}
		}
		cout << (ans?"NO":"YES") << endl;
	}
}

namespace Subtask2
{
	const int N = 1e5 + 5;
	vector<unordered_set<int>> v;
	int block[N];
	int tot = 0;
	// vector<int> v[N];
	// vector<int> temp[N];
	// random_device rd;
	// sfmt216091_64 myrd(rd());
	int solve()
	{
		v.clear();
		fill(block, block + 1 + n, -1);
		tot = 0;
		bool ans = 1;
		for (int i = 1; i <= n; i++)
		{
			int m;
			cin >> m;
			unordered_set<int> temp;
			for (int i = 1, t; i <= m; i++)
			{
				cin >> t;
				if (ans)
				{
					temp.insert(t);
				}
			}
			if(m==1){
				continue;
			}
			if (ans && m)
			{
				int minans = -1;
				bool update = 0;
				if (block[*temp.begin()] != -1 && v[block[*temp.begin()]].size() > temp.size())
				{
					update = 1;
				}
				for (auto i : temp)
				{
					if (minans != block[i])
					{
						if (minans == -1)
						{
							minans = block[i];
						}
						else if (block[i] != -1)
						{
							ans = 0;
						}
					}
				}
				if (ans)
				{
					if (minans != -1)
					{
						int res = 0;
						for (auto i : temp)
						{
							if (v[minans].count(i))
								++res;
						}
						if (res < min(v[minans].size(), temp.size()) && res)
						{
							ans = 0;
						}
						for (auto i : temp)
						{
							block[i] = minans;
						}
						if (update)
						{
							v[minans] = temp;
						}
					}
					else
					{
						for (auto i : temp)
						{
							block[i] = v.size();
						}
						v.push_back(temp);
					}
				}
			}

			
		}
		cout << (ans ? "NO" : "YES") << endl;
		return 0;
	}
};

namespace Main
{
	int main()
	{
		int T;
		cin >> T;
		while (T--)
		{
			cin >> n;
			if (n > 10000)
			{
				Subtask2::solve();
			}
			else
			{
				Subtask1::solve();
			}
		}
		return 0;
	}
}

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