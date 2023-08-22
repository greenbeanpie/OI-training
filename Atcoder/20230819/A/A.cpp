#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#define int long long
#define double long double
#define endl "\n"
#define problemname "A"
#define const constexpr



signed main(){
#ifndef ONLINE_JUDGE
	freopen(problemname".in","r",stdin);
	freopen(problemname".out","w",stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	string s;
	cin >> s;
	for(char c:s){
		if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'){
			;
		}
		else{
			cout << c;
		}
	}	
	return 0;
}