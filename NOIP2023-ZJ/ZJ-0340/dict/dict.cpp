#include <stdio.h>
#include <string>
#include <string.h>
#include <iostream>
#define N 3005
using namespace std;

string a[N], mn[N], mx[N];
int n, m, cnt[30];

void to_min(int i){
	int j;
	for(j = 0; j < m; j++){
		cnt[a[i][j] - 'a']++;
	}
	j = 0;
	for(char ch = 'a'; ch <= 'z'; ch++){
		while(cnt[ch - 'a']){
			cnt[ch - 'a']--;
			mn[i] += ch;
		}
	}
}

void to_max(int i){
	int j;
	for(j = 0; j < m; j++){
		cnt[a[i][j] - 'a']++;
	}
	j = 0;
	for(char ch = 'z'; ch >= 'a'; ch--){
		while(cnt[ch - 'a']){
			cnt[ch - 'a']--;
			mx[i] += ch;
		}
	}
}

bool ok(int i, int j){
	for(int k = 0; k < m; k++){
		if(mn[i][k] < mx[j][k]) return 1;
		if(mn[i][k] > mx[j][k]) return 0;
	}
	return 0;
}

int check(int i){
	for(int j = 1; j <= n; j++){
		if(j != i){
			if(!ok(i, j)){
				return 0;
			}
		}
	}
	return 1;
}

int main(){
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		to_min(i);
		to_max(i);
	}
	for(int i = 1; i <= n; i++){
		printf("%d", check(i));
	}
	return 0;
}
