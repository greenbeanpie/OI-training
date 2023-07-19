#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#define int long long
#define endl "\n"



signed main(){
#ifndef ONLINE_JUDGE
	freopen("P1919.in","w",stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	sfmt11213_64 a(time(0));
	if(a()%2){
		cout << "-";
	}
	cout << a()%9+1;
	for(int i=1;i<1000000;i++){
		cout << a()%10;
	}
	cout << "\n";
	if(a()%2){
		cout << "-";
	}
	cout << a()%9+1;
	for(int i=1;i<1000000;i++){
		cout << a()%10;
	}
	return 0;
}