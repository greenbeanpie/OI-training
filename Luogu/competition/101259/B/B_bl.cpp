#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
#define int long long
#define double long double
#define endl "\n"
#define problemname "B"
#define const constexpr
#pragma GCC optimize("Ofast")

namespace Main{
	int step(int n){
		int ans = 1;
		for (int i = 2;i<=n;i++){
			ans *= i;
		}
		return ans;
	}

	int f(vector<int>& num){
		int last =*num.rbegin();
		int mininum = INT_MAX, maxinum = -1;
		for (int i : num)
		{
			mininum = min(mininum, last + i);
			maxinum = max(maxinum, last + i);
			last = i;
		}
		return maxinum - mininum;
	}

	int main(){
		vector<int> num;
		int n;
		cin >> n;
		int mininum = INT_MAX;
		for(int i=1;i<=n;i++){
			num.push_back(i);
		}
		vector<int> minv;
		for (int i = 1; i <=step(n);i++){
			next_permutation(num.begin(),num.end());
			if(f(num)<mininum){
				mininum = f(num);
				minv = num;
			}
		}
		for(int i:minv){
			cout << i << " ";
		}
		cout << endl;
		cerr << mininum;

		return 0;
	}
};

signed main(){
#ifndef ONLINE_JUDGE
	freopen(problemname".in","r",stdin);
	freopen(problemname".out","w",stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	Main::main();
	return 0;
}