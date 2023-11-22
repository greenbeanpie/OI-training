#include <bits/stdc++.h>
using namespace std;

int dic[3005][28], n, m;

bool cmp(int x, int y){
	int p1 = 0, p2 = 0;
	for (int i = 0; i <= 25; i++)
		if (dic[x][i]){
			p1 = i;
			break;
		}
	for (int i = 25; i >= 0; i--)
		if (dic[y][i]){
			p2 = i;
			break;
		}
	if (p1 > p2)
		return 1;
	if (p1 < p2)
		return 0;
	return 1;
}

int main(){
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++){
		char s[3005];
		scanf("%s", s);
		for (int j = 0; j < m; j++)
			dic[i][s[j] - 'a']++;
	}
	for (int i = 1; i <= n; i++){
		bool flag = 0;
		for (int j = 1; j <= n; j++)
			if (i != j){
				//printf(cmp(i, j) ? "1\n" : "0\n");
				if(cmp(i, j)){
					flag = 1;
					break;
				}
			}
		printf(flag ? "0" : "1");
	}
	
	return 0;
}
