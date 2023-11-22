#include<bits/stdc++.h>
#define M 3100
using namespace std;
int read(){
	int w = 1, s = 0;
	char ch = getchar();
	while(!isdigit(ch)){
		if(ch == '-') w = -w;
		ch = getchar();
	}
	while(isdigit(ch)){
		s = (s << 3) + (s << 1) + (ch ^ 48);
		ch = getchar();
	}
	return w * s;
}
int n, m, id[M << 1];
char mp[M << 1][M];
bool ok[M];
bool cmp1(char x, char y){
	return x > y;
}
bool check(int x, int y){
	for(int i = 1; i <= m; ++ i)
		if(mp[x][i] < mp[y][i]) return 1;
		else if(mp[x][i] > mp[y][i]) return 0;
	return 0;
}
bool cmp(int x, int y){
//	printf("%d %d %d\n", x, y, check(x, y) ? 1 : 0);
	if(check(x, y)) return 1;
	if(check(y, x)) return 0;
	return x > y;
}
int main(){
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	n = read(), m = read();
	if(n == 1){
		printf("1\n");
		return 0;
	}
	for(int i = 1; i <= n; ++ i){
		id[i] = i; id[i + n] = i + n;
		scanf("%s", mp[i] + 1);
		for(int j = 1; j <= m; ++ j)
			mp[i + n][j] = mp[i][j];
		sort(mp[i] + 1, mp[i] + m + 1);
		sort(mp[i + n] + 1, mp[i + n] + m + 1, cmp1);
	}
//	printf("check : 2 1 %d\n", check(2, 1) ? 1 : 0);
//	for(int i = 1; i <= 2 * n; ++ i){
//		for(int j = 1 ; j <= m; ++ j)
//			printf("%c", mp[i][j]);
//		printf("\n");
//	}
	sort(id + 1, id + n * 2 + 1, cmp);
//	for(int i = 1; i <= n * 2; ++ i) printf("%d\n", id[i]);
	for(int i = 1; i <= n  * 2; ++ i)
		if(id[i] > n){
			for(int j = i + 1; j <= n * 2; ++ j)
				if(id[j] == id[i] - n){
					ok[id[j]] = (!check(id[i], id[j]));
					break;
				}
			break;
		}
		else ok[id[i]] = 1;
	for(int i = 1; i <= n; ++ i) printf("%d", ok[i] ? 1 : 0); printf("\n");
	return 0;
}