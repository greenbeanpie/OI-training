#include <bits/stdc++.h>
using namespace std;
#define int long long

namespace Main{
	int main(){
		int T;
		cin >> T;
		while(T--){
			int n, m;
			cin >> n >> m;
			if((m+1)/n>=2 || m==n){
				cout << "Yes" << endl;
			}
			else{
				cout << "No" << endl;
			}
		}
		return 0;
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("A.in", "r", stdin);
	freopen("A.out","w",stdout);
#endif
	Main::main();
	return 0;
}
