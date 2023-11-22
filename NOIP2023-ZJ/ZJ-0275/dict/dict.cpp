#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, m;
char s[3009][3009];
string mi;
bool cmp(char x, char y){
	return x > y;
}
int c(string x, char y[]){
	for(int i = 0; i < x.size(); i ++ ){
		if(x[i] > y[i]) return 1;
		if(x[i] < y[i]) return 2;
	}
	return 3;
}
bool flag = false;
signed main(){
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	if(n == 1){
		for(int i = 1; i <= n; i ++ ){
			cout << 1;
		}
		return 0;
	}
	for(int i = 0; i < n; i ++ ){
		for(int j = 0 ; j < m; j ++ ){
			cin >> s[i][j];
		}
	}
	for(int i = 0; i < n; i ++ ){
		sort(s[i], s[i] + m, cmp);
		if(i == 0) mi = s[i]; 
		else{
			int num = c(mi, s[i]);
			if(num == 1) { mi = s[i]; flag = false;}
			if(num == 3) flag = true;
		}
	}
	for(int i = 0; i < n; i ++ ){
		sort(s[i], s[i] + m);
		int num = c(mi, s[i]);
		if(num == 3 && !flag) cout << !flag;
		else{
			if(num == 1) cout << 1;
			else cout << 0;
		}
	}
	return 0;
}