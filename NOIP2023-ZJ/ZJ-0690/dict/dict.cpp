#include <bits/stdc++.h>
using namespace std;
#define elif else if

int n, m, a[3005][350], b[3005][350];
char ch;

int check(int x){
	for(int i = 1; i <= n; i++){
		if(i == x)
			continue;
		int l = 'a', r = 'z';
		for(; !a[x][l]; l++);
		for(; !a[i][r]; r--);
		if(r > l)
			continue;
		if(r < l)
			return 0;
		if(a[x][l] < a[i][r])
			continue;
		if(a[x][l] >= a[i][r])
			return 0;
	}
	return 1;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++){
			cin >> ch;
			a[i][ch]++;
		}
	for(int i = 1; i <= n; i++)
		cout << check(i);
	return 0;
}
