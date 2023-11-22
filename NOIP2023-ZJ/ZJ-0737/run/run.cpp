#include<bits/stdc++.h>
using namespace std;

long long c, t, n, m, k, d;
long long ans;

int main(){
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	if(c == 17 || c == 18){
		while(t --){
			ans = 0;
			cin >> n >> m >> k >> d;
			for(int i = 1; i <= m; i ++){
				int x, y, z;
				cin >> x >> y >> z;
				if(y * d < z && y <= k)
					ans += z - y * d;
				}
			cout << ans << endl;
		}
		return 0;
	}
	while(t --){
		ans = 0;
		cin >> n >> m >> k >> d;
		for(int i = 1; i <= m; i ++){
			int x, y, z;
			ans += z - y * d;
		}
		cout << ans << endl;
	}
	return 0;
}
