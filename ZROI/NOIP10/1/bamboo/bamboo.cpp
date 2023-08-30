#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
#define int long long
#define double long double
#define endl "\n"
#define problemname "bamboo"
#define const constexpr

namespace Main{

	queue<int> q;

	int main(){
		int n;
		cin >> n;
		string str;
		cin >> str;
		int now = 0,ans=0,idx=-1,idx2=-1;
		while(idx2<n-1){
			while(idx<n&&now>=0){
				if(str[++idx]=='('){
					++now;
				}
				else{
					--now;
				}
			}
			if(idx2<idx){
				idx2 = idx + 1;
			}
			while(idx2<n&&str[idx2]==')'){
				if(str[++idx2]=='('){
					break;
				}
			}
			ans += idx2 - idx;
			swap(str[idx], str[idx2]);
			++idx;
			++now;
		}
		cout << ans << endl;
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