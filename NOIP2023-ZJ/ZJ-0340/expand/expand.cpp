#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#define N 500005
using namespace std;

inline int read(){
	int ans = 0;
	char ch = getchar();
	while(!isdigit(ch)){
		ch = getchar();
	}
	while(isdigit(ch)){
		ans *= 10;
		ans += ch - 48;
		ch = getchar();
	}
	return ans;
}

int c, n, m, q, a[N], b[N], x[N], y[N], k1, k2, pos, val, nxt[N], minn[N];
bool dp[2005][2005];

int check_more(){
	dp[0][0] = 1;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(a[i] > b[j]){
				dp[i][j] = dp[i - 1][j] | dp[i][j - 1] | dp[i - 1][j - 1];
			} else {
				dp[i][j] = 0;
			}
		}
	}
	return dp[n][m] ? 1 : 0;
}

int check_less(){
	dp[0][0] = 1;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(a[i] < b[j]){
				dp[i][j] = dp[i - 1][j] | dp[i][j - 1] | dp[i - 1][j - 1];
			} else {
				dp[i][j] = 0;
			}
		}
	}
	return dp[n][m] ? 1 : 0;
}

int check_sp(){
	// nxt[m] = m;
	// for(int i = m - 1; i >= 1; i--){
	// 	if(b[i] < b[i + 1]){
	// 		nxt[i] = i + 1;
	// 	} else {
	// 		nxt[i] = nxt[i + 1];
	// 	}
	// }
	// for(int i = 1; i < m; i = nxt[i]){
	// 	minn[i] = 1000000000;
	// 	for(int j = i + 1; j <= nxt[i]; j++){
	// 		minn[i] = min(minn[i], a[j]);
	// 	}
	// }

	// int pos = 1;
	// for(int i = 1; i <= n; i++){
	// 	if(pos == m){
	// 		return 1;
	// 	}
	// 	if(a[i] < minn[pos]){
	// 		pos = nxt[pos];
	// 	} else if(a[i] < b[pos]){
	// 		;
	// 	} else {
	// 		return 0;
	// 	}
	// }
	int maxa = 0, minb = 1000000000;
	for(int i = 2; i <= n; i++){
		maxa = max(maxa, a[i]);
	}
	for(int i = 1; i < m; i++){
		minb = min(minb, b[i]);
	}
	if(maxa < b[m] || minb > a[n]) return 1;
	return 0;
}

int main(){
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	c = read(), n = read(), m = read(), q = read();
	for(int i = 1; i <= n; i++){
		x[i] = read();
	}
	for(int i = 1; i <= m; i++){
		y[i] = read();
	}
	if(c <= 7){
		memcpy(a, x, sizeof(x));
		memcpy(b, y, sizeof(y));
		if(a[1] > b[1]) printf("%d", check_more());
		else if(a[1] < b[1]) printf("%d", check_less());
		else printf("0");
		while(q--){
			memcpy(a, x, sizeof(x));
			memcpy(b, y, sizeof(y));
			k1 = read(), k2 = read();
			while(k1--){
				pos = read(), val = read();
				a[pos] = val;
			}
			while(k2--){
				pos = read(), val = read();
				b[pos] = val;
			}
			if(a[1] > b[1]) printf("%d", check_more());
			else if(a[1] < b[1]) printf("%d", check_less());
			else printf("0");
		}
	} else if(c <= 14){
		memcpy(a, x, sizeof(x));
		memcpy(b, y, sizeof(y));
		printf("%d", check_sp());
		while(q--){
			memcpy(a, x, sizeof(x));
			memcpy(b, y, sizeof(y));
			k1 = read(), k2 = read();
			while(k1--){
				pos = read(), val = read();
				a[pos] = val;
			}
			while(k2--){
				pos = read(), val = read();
				b[pos] = val;
			}
			printf("%d", check_sp());
		}
	}
	return 0;
}
