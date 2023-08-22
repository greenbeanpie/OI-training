#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#define int long long
#define double long double
#define endl "\n"
#define problemname "change"
#define const constexpr

set<int> s;

signed main(){
#ifndef ONLINE_JUDGE
	freopen(problemname"2.in","r",stdin);
	freopen(problemname".out","w",stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n;
	cin >> n;
	int right=n+1;
	int num;
	for(int i=1;i<=n;i++){
		cin >> num;
		if(num==right-1){
			--right;
			while(s.size()&&*s.rbegin()==right-1){
				--right;
				s.erase(--s.end());
			}
		}
		else{
			s.insert(num);
		}
		cout << s.size() << " ";
	}
	return 0;
}