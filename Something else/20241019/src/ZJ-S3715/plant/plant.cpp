#include<bits/stdc++.h>
#define maxn 100010
using namespace std;
typedef long long ll;
ll n, l, r, mid, ans, a[maxn], b[maxn], c[maxn], k;
ll l2, r2, mid2, pos;
ll check(ll x){
	ll ret = 0;
	for(int i = 1; i <= n; i++){
		l2 = 1; r2 = n; pos = 0;
		while(l2 <= r2){
			mid2 = (l2 + r2) >> 1;
			if(c[mid2] * b[i] + a[i] < x) pos = mid2, l2 = mid2 + 1;
			else r2 = mid2 - 1;
		}
		ret += pos;
	}
	return ret;
}
int main(){
	freopen("plant.in", "r", stdin);
	freopen("plant.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) cin >> b[i];
	for(int i = 1; i <= n; i++) cin >> c[i];
	sort(c + 1, c + 1 + n); cin >> k;
	l = 0; r = 2e18;
	while(l <= r){
		ll mid = (l + r) >> 1;
		if(check(mid) <= k - 1) ans = mid, l = mid + 1;
		else r = mid - 1;
	}
	cout << ans << '\n';
	return 0;
}
