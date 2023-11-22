#include <bits/stdc++.h>
#define F(i, l, r) for(int i = l; i < r ; ++ i)
#define Fe(i, l, r) for(int i = l; i <= r; ++ i)
#define reopen(A) { freopen(#A".in", "r", stdin); freopen(#A".out", "w", stdout); }
using namespace std;

constexpr int N = 3005;

int n, m;
char s[N][N];

signed main(){
	reopen(dict);
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	if(n == 1) {
		cout << 1 << endl;
		return 0;
	}
	
	Fe(i, 1, n) cin >> s[i];
	
//	Fe(i, 1, n) cout << s[i] << endl;

	
	Fe(i, 1, n){
		sort(s[i], s[i] + m);
		reverse(s[i], s[i] + m);
	}
	
//	Fe(i, 1, n) cout << s[i] << endl;
	
	Fe(i, 1, n){
//		reverse(s[i], s[i] + m);
		bool flag = 1;
		Fe(j, 1, n){
			if(i == j) continue;
			
			bool f2 = 1;
			F(k, 0, m) {
				if(s[i][m - k - 1] < s[j][k]){
					f2 = 0;
					break;
				}
			}
			if(f2) {
				flag = 0;
				cout << 0;
				break;	
			}
		}
		if(flag) cout << 1;
//		reverse(s[i], s[i] + m);
	}
	return 0;
}