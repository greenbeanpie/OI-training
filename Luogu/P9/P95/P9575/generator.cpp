#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#define int long long
#define double long double
#define endl "\n"
#define problemname "P9575"
#define const constexpr

namespace Main{
	
	
	
	int main(){
		mt19937 random(time(0));
		int n=random()%10;
		cout << n << endl;
		for(int i=1;i<=n;i++){
			cout << (random()%10+1)*2 << " ";
		}
		return 0;
	}
};

signed main(){
#ifndef ONLINE_JUDGE
	freopen(problemname".in","w",stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	Main::main();
	return 0;
}