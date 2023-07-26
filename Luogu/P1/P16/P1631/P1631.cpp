#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#define int long long
#define endl "\n"

int num1[100005],num2[100005];

signed main(){
#ifndef ONLINE_JUDGE
	freopen("P1631.in","r",stdin);
	freopen("P1631.out","w",stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> num1[i];
	}
	for(int i=1;i<=n;i++){
		cin >> num2[i];
	}
	std::priority_queue<int,vector<int>,greater<int> > pq;
	for(int i=1;i<=n;i++){
		for(int j=1;j*i<=n;j++){
			pq.push(num1[i]+num2[j]);
		}
	}
	for(int i=1;i<=n;i++){
		cout << pq.top() << ' ';
		pq.pop();
	}
	return 0;
}