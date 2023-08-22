#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#define int long long
#define double long double
#define endl "\n"
#define problemname "train"
#define const constexpr

namespace Main{
	int n,m;
	int isfront[6],target[6],ans;
	bool empty[6];
	bool check(){
		memset(empty,0,sizeof(empty));
		for(int i=1;i<=m;i++){
			if(isfront[i]){
				bool flag=false;
				for(int j=target[i];j<=n;j++){
					if(!empty[j]){
						empty[j]=1;
						flag=true;
						break;
					}
				}
				if(!flag){
					return 0;
				}
			}
			else{
				bool flag=false;
				for(int j=target[i];j>=1;j--){
					if(!empty[j]){
						empty[j]=1;
						flag=true;
						break;
					}
				}
				if(!flag){
					return 0;
				}
			}
		}
		return 1;
	}
	void meiju(int now){
		if(now==m+1){
			ans+=check();
			return;
		}
		else{
			for(int i=1;i<=n;i++){
				for(int j=0;j<2;j++){
					target[now]=i;
					isfront[now]=j;
					meiju(now+1);
				}
			}
		}
	}
	int main(){
		cin >> n >> m;
		meiju(1);
		cout << ans;
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