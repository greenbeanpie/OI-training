#include<bits/stdc++.h>
using namespace std;

const int N = 3e3 + 10;

int n, m;

int a[N][N];

int main(){
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++){
		string s;
		cin >> s;
		for(int j = 0; j < s.size(); j ++)
			a[i][j + 1] = s[j] - 'a' + 1;
	}
	for(int i = 1; i <= n; i ++)
		sort(a[i] + 1, a[i] + 1 + m);
	bool flag = true;
	for(int i = 1; i <= n; i ++){
		flag = true;
		for(int j = 1; j <= n; j ++){
			if(j == i) continue;
			if(a[i][1] >= a[j][m]) flag = false; 
		}
		if(flag) cout << "1";
		else cout << "0";
	}
	return 0;
}
