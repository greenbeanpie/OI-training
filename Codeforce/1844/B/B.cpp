#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	#ifndef ONLINE_JUDGE
		freopen("B.in","r",stdin);
		freopen("B.out","w",stdout);
	#endif
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		if(n==1){
			cout << 1 << endl;
		}
		else if(n==2){
			cout << "1 2" << endl;
		}
		else{
			cout << "2 " ;
			for(int i=4;i<=(n+3)/2;i++){
				cout << i << " ";
			}
			cout << "1 ";
			for(int i=(n+5)/2;i<=n;i++){
				cout << i << " ";
			}
			cout << 3 << endl;
		}
	}
	return 0;
}