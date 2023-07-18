#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#define int long long
#define endl "\n"

set<int> s;
cc_hash_table<int,int> mp;

signed main(){
#ifndef ONLINE_JUDGE
	freopen("P1496.in","r",stdin);
	freopen("P1496.out","w",stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n;
	cin >> n;
	int l,r;
	for(int i=1;i<=n;i++){
		cin >> l >> r;
		s.insert(l);
		s.insert(r);
		mp[l]++;
		mp[r]--;
	}
	int now=0,sum=0,last=0;
	for(int i:s){
		if(now<=0){
			last=i;
		}
		now+=mp[i];
		if(now<=0){
			sum+=i-last;
		}
	}
	cout << sum;
	return 0;
}