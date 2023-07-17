#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#define int long long
#define endl "\n"

cc_hash_table<string,int> ht;

signed main(){
#ifndef ONLINE_JUDGE
	freopen("P2580.in","r",stdin);
	freopen("P2580.out","w",stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n;
	cin >> n;
	string s;
	for(int i=1;i<=n;i++){
		cin >> s;
		ht[s]++;
	}
	int m;
	cin >> m;
	for(int i=1;i<=m;i++){
		cin >> s;
		if(ht[s]==1){
			ht[s]++;
			cout << "OK" << endl;
		}
		else if(ht[s]==0){
			cout << "WRONG" << endl;
		}
		else{
			cout << "REPEAT" << endl;
		}
	}
	return 0;
	
}
