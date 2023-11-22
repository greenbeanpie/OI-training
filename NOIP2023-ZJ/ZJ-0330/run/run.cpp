#include <bits/stdc++.h>
#define F(i, l, r) for(int i = l; i < r ; ++ i)
#define Fe(i, l, r) for(int i = l; i <= r; ++ i)
#define reopen(A) { freopen(#A".in", "r", stdin); freopen(#A".out", "w", stdout); }
using namespace std;
typedef long long ll;

constexpr int N = 100005;

int c, t, n, m, k, d;

struct clg{
	int x, y, v;
	bool operator < (const clg & o) const{
		return v > o.v;
	}
} a[N];

void solve(){
	cin >> n >> m >> k >> d;
//	Fe(i, 1, m) a[i].x = a[i].y = a[i].v = 0;
	Fe(i, 1, m) cin >> a[i].x >> a[i].y >> a[i].v;
	Fe(i, 1, m) {
		int l = a[i].x - a[i].y + 1;
		a[i].y = a[i].x;
		a[i].x = l;
	}
	if(n <= 22){
		ll ans = 0;
		ll now = 0;
		static bool st[20];
		F(i, 0, (1 << n)){
			Fe(i, 1, n) st[i] = 0;
			ll anow = 0;
			F(j, 0, n){
				if((i >> j) & 1){
					st[j + 1] = 1;
					anow -= d;
				} 
			}
			int fl = 1, cnt = 0;
			Fe(i, 1, n){
//				cout << st[i] << ' ';
				if(st[i]) cnt ++;
				else cnt = 0;
				if(cnt > k) {
					fl = 0;
					break;
				}
			}
//			cout << fl << endl;
			if(!fl) continue;
			Fe(i, 1, m){
				fl = 1;
				Fe(j, a[i].x, a[i].y){
					if(!st[j]){
						fl = 0;
						break; 
					}
				}
				if(fl) anow += a[i].v;
			}
			
//			cout << "ans: " << anow << endl;
			ans = max(ans, anow);
		}
		cout << ans << endl;
	} else if(c == 17 || c == 18){
		ll ans = 0;
		Fe(i, 1, m){
			if(1ll * (a[i].y - a[i].x + 1) * d < a[i].v && (a[i].y - a[i].x + 1) <= k){
				ans += 1ll * a[i].v - 1ll * (a[i].y - a[i].x + 1) * d;
			}
		}
		cout << ans << endl;
	} else {
		sort(a + 1, a + 1 + m);
		ll ans = 0;
		Fe(i, 1, m){
			if((a[i].y - a[i].x + 1) > k) continue;
			ans += max(0ll, 1ll * a[i].v - 1ll * (a[i].y - a[i].x + 1) * d);
		}
		cout << ans << endl;
	}
	
}

signed main(){
	reopen(run);
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> c >> t;
	
	while(t--) solve();	
	
	return 0;
}