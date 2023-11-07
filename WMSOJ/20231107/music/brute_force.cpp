#include <bits/stdc++.h>
using namespace std;
#ifdef CODESPACE
#pragma GCC optimize("Ofast")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("-funsafe-math-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")

#endif
vector<int> ans, temp;

int maxans = 0;

int d[] = {0, 2, 4, 5, 7, 9, 11};

int check()
{
	int ans = 0;
	for (int i = 0; i <= 11; i++)
	{
		bool flag = 1;
		set<int> s;
		for (int j = i; j <= i + 6; j++)
		{
			s.insert(temp[j % 12]);
		}
		for (int i : s)
		{
			int t = 1;
			flag = 1;
			set<int> tmp = s;
			int last = i;
			tmp.erase(i);
			// last = i;
			// tmp.erase(i);
			while (*tmp.begin() < last)
			{
				tmp.insert(*tmp.begin() + 12);
				tmp.erase(tmp.begin());
			}
			for (int j : tmp)
			{
				if (j - last != d[t] - d[t - 1])
				{
					flag = 0;
					break;
				}
				last = j;
				++t;
			}
			if (flag)
			{
				break;
			}
		}
		// if (!flag)
		// {
		// 	return 0;
		// }
		ans += flag;
		if(12-i+ans<maxans){
			return 0;
		}
	}
	return ans;
}

signed main()
{
	freopen("music.out", "w", stdout);
	for (int i = 0; i <= 11; i++)
	{
		temp.push_back(i);
	}
	int last = 1;
	while (next_permutation(temp.begin(), temp.end()) && temp[0] == 0)
	{
		if(temp[1]!=last){
			cerr << temp[1] << endl;
			last = temp[1];
		}
		// if (temp[2] == 3)
		// {
		// 	cerr << "Honkai" << endl;
		// 	assert(1);
		// }
		// if (temp[3] == 5)
		// {
		// 	cerr << "Start" << endl;
		// 	assert(1);
		// }
		// if(temp[4]==6){
		// 	cerr << "Arknight" << endl;
		// 	assert(1);
		// }
		// if(temp[5]==8){
		// 	cerr << "Star Rail" << endl;
		// 	assert(1);
		// }
		// if(temp[6]==10){
		// 	cerr << "?" << endl;
		// 	assert(1);
		// }
		// if (temp[0 + 1] == 1 && temp[1 + 1] == 3 && temp[2 + 1] == 5 && temp[3 + 1] == 6 && temp[4 + 1] == 8 && temp[5 + 1] == 10 && temp[6 + 1] == 0)
		// {
		// 	cerr << "Genshin" << endl;
		// 	assert(1);
		// }
		int res = check();
		if (res > maxans)
		{
			maxans = res;
			ans = temp;
			for (int i : ans)
			{
				cerr << i << " ";
			}
			cerr << endl;
		}
		cerr << maxans << '\r';
	}
	for (int i : ans)
	{
		cout << i << " ";
	}
	return 0;
}
