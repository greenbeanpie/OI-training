#include<bits/stdc++.h>
#define rep(i,l,r) for(int i(l), i##end(r); i<=i##end; ++i)
using namespace std;
/*
4 3 2 1
4 5 6

*/
int arr[3010][3010];
int main() {
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	int n, m; cin >> n >> m;
	if(n == 1) {cout << 1;return 0;}
	rep(i, 1, n) {
		string str; cin >> str;
		rep(j, 0, str.length()-1) {
			arr[i][j] = str[j] - 'a';
		}
		sort(arr[i], arr[i]+str.length());
	}
	rep(i, 1, n) {
		bool bl = 1;
		rep(j, 1, n) {
			if(i == j) continue;
			if(arr[i][0] < arr[j][m-1]) {
				continue;
			}
			bl = 0;
		}
		if(bl) {
			cout << 1;
		} else {
			cout << 0;
		}
	}
	return 0;
}