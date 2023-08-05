#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#define int long long
#define double long double
#define endl "\n"

constexpr int N=10;
int num1[N],num2[N],cnt[N],sum[N];

signed main(){
#ifndef ONLINE_JUDGE
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,q;
	cin >> n >> q;
	int temp;
	for(int i=1;i<=n*n;i++){
		cin >> num1[i];
		num2[i]=num1[i];
	}
	sort(num2+1,num2+1+n*n);
	int size=unique(num2+1,num2+1+n*n)-num2;
	for(int i=1;i<=n*n;i++){
		++cnt[lower_bound(num2,num2+size,num1[i])-num2];
	}
	for(int i=1;i<=size;i++){
		sum[i]=sum[i-1]+cnt[i];
	}
	for(int i=1;i<=q;i++){
		cin >> temp;
		int pos=lower_bound(num2+1,num2+size,temp)-num2;
		cout << min(n,n*n-sum[pos-1]) << endl;
	}
	return 0;
}