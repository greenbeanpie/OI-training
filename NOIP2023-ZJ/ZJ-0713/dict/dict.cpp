#include<bits/stdc++.h>
using namespace std;

int n, m, tmp1, tmp2, t[3030], a[3030][30], t1[3030], t2[3030];

char ch; string str;

bool check(int x, int y){
	int cnt = 0;
	for(int i = 26; i >= 1; i--){
		for(int j = 1; j <= a[x][i]; j++){
			t1[++cnt] = 'a' + i - 1;
		}
	}
	
	cnt = 0;
	for(int i = 26; i >= 1; i--){
		for(int j = 1; j <= a[y][i]; j++){
			tmp2 = 'a' + i - 1;
			if(tmp2 < t1[++cnt]) return 1;
			if(tmp2 > t1[++cnt]) return 0;
		}
	}
}

bool check2(int x){
	int cnt = 0;
	for(int i = 1; i <= 26; i++){
		int len = a[x][i];
		for(int j = 1; j <= len; j++){
			tmp2 = 'a' + i - 1;
			if(tmp2 < t[++cnt]) return 1;
			if(tmp2 > t[++cnt]) return 0;
		}
	}
}

signed main(){
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> str;
		for(int j = 0; j < m; j++){
			a[i][str[j] - 'a' + 1]++;
		}
	}
	int minid = 1;
	for(int i = 2; i <= n; i++){
		if(check(minid, i)){
			minid = i;
		}
	}
	int cnt = 0;
	for(int i = 26; i >= 1; i--){
		for(int j = 1; j <= a[minid][i]; j++){
			t[++cnt] = 'a' + i - 1;
		}
	}
	for(int i = 1; i <= n; i++){
		if(i == minid){
			printf("%d", 1); continue;
		}
		if(check2(i)){
			printf("%d", 1);
		}
		else printf("%d", 0);
	}
	return 0;
}
