#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
#pragma GCC optimize("Ofast")
#define int long long
#define double long double
#define endl "\n"
#define problemname "lucky"
#define const constexpr

namespace Main{
	bool vis[10];
	int len(int x){
		return log10(x)+1;
	}
	bool check(int x){
		int cnt = 0,length=len(x);
		while(x&&cnt<3){
			if(!vis[x%10]){
				vis[x % 10]=1;
				++cnt;
			}
			x /= 10;
			--length;
		}
		if(length){
			++cnt;
		}
		vis[0]=vis[1]=vis[2]=vis[3]=vis[4]=vis[5]=vis[6]=vis[7]=vis[8]=vis[9]=0;
		return cnt < 3;
	}
	int main(){
		int cnt = 0;
		for (int i = 1; i <= 1e9; i++)
		{
			if(check(i)){
				++cnt;
			}
			if(i%1000000==0){
				cout << cnt << ",";
			}
		}
		// cout << cnt << endl;
		return 0;
	}
};

signed main(){
#ifndef ONLINE_JUDGE
	freopen(problemname".in","r",stdin);
	freopen(problemname"_dabiao.out","w",stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	Main::main();
	return 0;
}