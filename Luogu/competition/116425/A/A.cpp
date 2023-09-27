#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
#define int long long
#define double long double
#define endl "\n"
#define problemname "A"
#define const constexpr

namespace Main{
	
	
	
	int main(){
		int q;
		cin >> q;
		while(q--){
			int op,n,x;
			cin >> op >> n >> x;
			if(x<n-1){
				cout << -1 << endl;
				continue;
			}
			for(int i=1;i<=n-2;i++){
				cout << 1 << " ";
			}
			int last=x-n+2;
			if(op==1){
				cout << last << " ";
			}
			else{
				cout << 1 << " ";
			}
			cout << last << endl;
		}
		
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