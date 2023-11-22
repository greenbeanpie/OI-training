#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, m, a[3010][3010];
string s[3010];

void close_flow(){
	ios :: sync_with_stdio (false);
	cin.tie(0);
	cout.tie(0);
	return;
}
void init(){
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			a[i][j] = s[i][j-1] - 'a' + 1;
		}
	}
}
bool compare(int i, int j){
	//(s[i])min < (s[j])max?
	for(int k = 1; k <= n; ++k){
		int x = a[i][k],
			y = a[j][m-k+1];
		if(x < y)
			return true;
		if(x > y)
			return false;
	}
	return false;
}
signed main(){//90 point
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	close_flow();
	cin >> n >> m;
	for(int i = 1; i <= n; ++i){
		cin >> s[i];
	}
	if(n == 1){
		cout << 1 << endl;
		return 0;
	}
	init();
	for(int i = 1; i <= n; ++i){
		sort(a[i] + 1, a[i] + m + 1);
	}
//	for(int i = 1; i <= n; ++i){
//		for(int j = 1; j <= m; ++j){
//			cout << char(a[i][j] + 'a' -1);
//		}
//		cout << endl;
//	}
	for(int i = 1; i <= n; ++i){
		bool flag = true;
		for(int j = 1; j <= n; ++j){
			if(i == j)
				continue;
			if(!compare(i ,j)){
				cout << 0;
				flag = false;
				break;
			}
		}
		if(flag)
			cout << 1;
	}
	return 0;
}
