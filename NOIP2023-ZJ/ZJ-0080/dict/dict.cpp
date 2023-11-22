#include <bits/stdc++.h>

#define i64 long long
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define per(i, a, b) for(int i = (a); i >= (b); i--)

using namespace std;

const int N = 3e3 + 5;

int n, m;
int mx[N], mn[N];
string s[N];

int main() {
	
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0); 
	
	cin >> n >> m;
	rep(i, 1, n) {
		cin >> s[i];
		
		mx[i] = -1, mn[i] = 26;
		rep(j, 0, m - 1) {
			mx[i] = max(mx[i], s[i][j] - 'a');
			mn[i] = min(mn[i], s[i][j] - 'a');
		}
	}
	
	rep(i, 1, n) {
		bool ok = true;
		rep(j, 1, n) {
			if(i == j) continue;
			if(mn[i] >= mx[j]) ok = false;
			
			if(!ok) break;
		}
		
		if(ok) cout << "1";
		else cout << "0";
	}
	
	return 0;
}
