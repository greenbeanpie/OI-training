#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 2;

int n, k;
int a[N], b[N], c[N];

bool check(int x){
	int res = 0;
	for(int i = 1; i <= n; i ++){
		int t = (x - a[i] - 1) / b[i];
		res += upper_bound(c + 1, c + n + 1, t) - c - 1;
	}
	return res < k;
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);  cout.tie(0);
	freopen("plant.in", "r", stdin);
	freopen("plant.out", "w", stdout);

	cin >> n;
	for(int i = 1; i <= n; i ++)  cin >> a[i];
	for(int i = 1; i <= n; i ++)  cin >> b[i];
	for(int i = 1; i <= n; i ++)  cin >> c[i];
	sort(c + 1, c + n + 1);  cin >> k;
	int l = 0, r = 2e18, ans = 0;
	while(l <= r){
		int mid = l + r >> 1;
		if(check(mid)){
			l = mid + 1;
			ans = mid;
		}else{
			r = mid - 1;
		}
//		cerr << l << ' ' << r << '\n';
	}
	cout << ans;
	
	return 0;
}
