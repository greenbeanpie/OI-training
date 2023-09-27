// #include <bits/stdc++.h>
// #include <bits/extc++.h>
// using namespace __gnu_pbds;
// using namespace __gnu_cxx;
#include <iostream>

using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
#define int long long
#define double long double
#define endl "\n"
#define problemname "B"
#define const constexpr

namespace Main{
	const int N = 5e5 + 5;
	int num[N];
	int first, last;

	int main(){
		int T;
		cin >> T;
		while(T--){
			int n;
			cin >> n;
			cin >> num[1] >> num[2];
			for(int i=3;i<=n;i++){
				cin >> num[i];
				num[i]-=num[i-1];
			}
			bool ans=1;
			if(n%2==1){
				if(num[n]>num[1]||(num[1]-num[n])%2){
					ans=0;
				}
				int x=(num[1]-num[n])>>1;
				for(int i=2;i<=n&&ans;i++){
					if(num[i]+((i&1)?x:-x)<0){
						ans=0;
					}
				}
			
			}else{
				if(num[1]!=num[n]){
					ans=0;
				}
				int l=0,r=LLONG_MAX;
				for(int i=2;i<=n;i++){
					if(i%2){
						l=max(l,-num[i]);
					}
					else{
						r=min(r,num[i]);
					}
				}
				if(r<l){
					ans=0;
				}
			}

			cout << ans << endl;
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