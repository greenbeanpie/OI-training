#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define mpr make_pair
const int SIZE = 500005;
const int mod = 998244353;
int ID, n, m, T;
int a[SIZE], b[SIZE];
int ppx[SIZE], vvx[SIZE], ppy[SIZE], vvy[SIZE];

inline int rd(){
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9'){
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		x = (x<<1)+(x<<3)+(ch^48);
		ch = getchar();
	}
	return x*f;
}

namespace solve1{
	bool dp[2005][2005];
	bool check(int x, int y){
		if(a[1] == b[1]) return false;
		if((a[x]>b[y]) && (a[1]>b[1])) return true;
		if((a[x]<b[y]) && (a[1]<b[1])) return true;
		return false;
	}
	void Main(){
		memset(dp, 0, sizeof(dp));
		for(int i = 1; i <= m; i++){
			if(check(1, i)) dp[1][i] = 1;
			else break;
		}
		for(int i = 2; i <= n; i++){
			int jl = 0;
			for(int j = 1; j <= m; j++){
				if(check(i, j)) jl |= dp[i-1][j] | dp[i-1][j-1];
				else jl = 0;
				dp[i][j] = jl;
//				for(int k = j; k >= 1; k--){
//					if(!check(i, k)) break;
//					dp[i][j] |= dp[i-1][k] | dp[i-1][k-1];
//				}
			}
		}
		printf("%d", dp[n][m]);
	}	
}

int main(){
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	ID = rd(), n = rd(), m = rd(), T = rd();
	for(int i = 1; i <= n; i++) a[i] = rd();
	for(int i = 1; i <= m; i++) b[i] = rd();
	if(ID <= 7) solve1::Main();
	while(T--){
		int kx = rd(), ky = rd();
		for(int i = 1; i <= kx; i++){
			int px = rd(), vx = rd();
			ppx[i] = px; vvx[i] = a[px];
			a[px] = vx;
		}
		for(int i = 1; i <= ky; i++){
			int py = rd(), vy = rd();
			ppy[i] = py; vvy[i] = b[py];
			b[py] = vy;
		}
//		for(int i = 1; i <= n; i++) cout << a[i] << " ";
//		cout << endl;
//		for(int i = 1; i <= m; i++) cout << b[i] << " ";
//		cout << endl;
		if(ID <= 7) solve1::Main();
		for(int i = 1; i <= kx; i++) a[ppx[i]] = vvx[i];
		for(int i = 1; i <= ky; i++) b[ppy[i]] = vvy[i];
	}
	return 0;
}

/*
4 6 6 1
195982977 303897138 437154869 81559605 365511323 302808478
342942401 297976421 445071632 83871721 304067809 427239638
6 6
1 588505924
3 600919013
4 587707447
2 572576439
6 591139329
5 573288617
1 578277016
5 591213504
2 598714107
4 587825836
6 564344344
3 557004829
*/

