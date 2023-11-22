#include<bits/stdc++.h>
#define M 5100
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
int c, n, m, q, x[M], y[M], rex[M], rey[M];
bool okx[M][M], oky[M][M], dp[M][M], print[100];
int main(){
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	c = read(), n = read(), m = read(), q = read();
	for(int i = 1; i <= n; ++ i) rex[i] = x[i] = read();
	for(int j = 1; j <= m; ++ j) rey[j] = y[j] = read();
	for(int Q = 0; Q <= q; ++ Q){
		for(int i = 1; i <= n; ++ i)
			for(int j = 1; j <= m; ++ j)
				if(x[i] > y[j]) okx[i][j] = 1, oky[i][j] = 0;
				else if(x[i] < y[j]) oky[i][j] = 1, okx[i][j] = 0;
				else okx[i][j] = oky[i][j] = 0;
//		printf("\n");
//		for(int i = 1; i <= n; ++ i){
//			for(int j = 1; j <= m; ++ j) printf("%d ", okx[i][j]);
//			printf("\n");
//		}
//		for(int i = 1; i <= n; ++ i){
//			for(int j = 1; j <= m; ++ j) printf("%d ", oky[i][j]);
//			printf("\n");
//		}
//		for(int i = 1; i <= n; ++ i) printf("%d ", x[i]); puts("");
//		for(int j = 1; j <= m; ++ j) printf("%d ", y[j]); puts("");
//		printf("\n");
		if(x[1] > y[1]){
			for(int i = 1; i <= n; ++ i) for(int j = 1; j <= m; ++ j) dp[i][j] = 0;
			dp[1][1] = 1;
			for(int i = 1; i <= n; ++ i)
				for(int j = 1; j <= m; ++ j){
					if(okx[i][j + 1]) dp[i][j + 1] |= dp[i][j];
					if(okx[i + 1][j]) dp[i + 1][j] |= dp[i][j];
					if(okx[i + 1][j + 1]) dp[i + 1][j + 1] |= dp[i][j];
				}
			if(dp[n][m]) print[Q] = 1;
		}
//		for(int i = 1; i <= n; ++ i){
//			for(int j = 1; j <= m; ++ j) printf("%d ", dp[i][j]);
//			printf("\n");
//		}
		if(x[1] < y[1] && !print[Q]){
			for(int i = 1; i <= n; ++ i) for(int j = 1; j <= m; ++ j) dp[i][j] = 0;
			dp[1][1] = 1;
			for(int i = 1; i <= n; ++ i)
				for(int j = 1; j <= m; ++ j){
					if(oky[i][j + 1]) dp[i][j + 1] |= dp[i][j];
					if(oky[i + 1][j]) dp[i + 1][j] |= dp[i][j];
					if(oky[i + 1][j + 1]) dp[i + 1][j + 1] |= dp[i][j];
				}
			if(dp[n][m]) print[Q] = 1;
		}
		if(Q != q){
			int kx = read(), ky = read(), p, v;
			for(int i = 1; i <= n; ++ i) x[i] = rex[i];
			for(int j = 1; j <= m; ++ j) y[j] = rey[j];
			for(int i = 1; i <= kx; ++ i){
				p = read(), v = read();
				x[p] = v;
			}
			for(int i = 1; i <= ky; ++ i){
				p = read(), v = read();
				y[p] = v;
			}
		}
	}
	for(int i = 0; i <= q; ++ i) printf("%d", print[i]); printf("\n");
	return 0;
}