#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int b=0,c=0;
	for(int i=0;i<n;i++){
		cin >> b;
		c^=b;
	}
	cout << c;
	return 0;
}