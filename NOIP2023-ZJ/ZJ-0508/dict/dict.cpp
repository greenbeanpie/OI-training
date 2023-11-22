#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 3e3 + 10;
string str[MAXN], str1[MAXN];
char minn[MAXN], maxn[MAXN];
int cnt = 0;
int main(){
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++){
		cin >> str[i];
		str1[i] = str[i];
	}
	if(m == 1){
		for(int i = 0; i < n; i++){
		int flag = 1;
			for(int j = 0; j < n; j++){
				if(i == j) continue;
				if(str[i] > str[j]){
					flag = 0;
				}
			}
			printf("%d", flag);
		}
		return 0;
	}
	
	if(m == 2){
		for(int i = 0; i < n; i++){
			reverse(str1[i].begin(), str1[i].end());
		}
		for(int i = 0; i < n; i++){
			int flag = 1;
			for(int j = 0; j < n; j++){
				if(i == j) continue;
				if(str[i] > str[j] && str1[i] > str1[j] && str1[i] > str[j] &&
				   str[i] > str1[j]){
				   	flag = 0;
				}
			}
			printf("%d", flag);
		}
		return 0;
	}
	for(int i = 0; i < n; i++){
		minn[i] = 'z', maxn[i] = 'a';
		for(int j = 0; j < m; j++){
			minn[i] = min(minn[i], str[i][j]);
			maxn[i] = max(maxn[i], str[i][j]);
		}
	}
	for(int i = 0; i < n; i++){
		int flag = 1;
		for(int j = 0; j < n; j++){
			if(minn[i] >= maxn[j]){
				flag = 0;
			}
		}
		printf("%d", flag);
	}
	return 0;
}