#include <bits/stdc++.h>
#define file(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout); 
using namespace std;
const int N = 500000 + 5, M = 2000 + 5;
int a[N], b[N];
int t1[N], t2[N];
int n, m, q;
namespace sub1{
	int dp[M][M];
	bool get(int x, int y, int tmp){
		if(x == y) return 0;
		return (x > y) ^ tmp;
	}
	bool check(){
		memset(dp, 0, sizeof(dp));
		if(a[1] == b[1]) return 0;
		int tmp = (a[1] < b[1]);
		int j = 1;
		dp[0][0] = 1;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++){
				if(get(a[i], b[j], tmp))
					dp[i][j] = dp[i - 1][j - 1] | dp[i][j - 1] | dp[i - 1][j];
			}
		return dp[n][m];
	}
	void solve(){
		printf("%d", check());
		for (int i = 1; i <= n; i++) t1[i] = a[i];
		for (int i = 1; i <= m; i++) t2[i] = b[i];
		for (int i = 1; i <= q; i++){
			for (int i = 1; i <= n; i++) a[i] = t1[i];
			for (int i = 1; i <= m; i++) b[i] = t2[i];
			int ka, kb;
			scanf("%d%d", &ka, &kb);
			for (int i = 1; i <= ka; i++) {
				int p, v;
				scanf("%d%d", &p, &v);
				a[p] = v;
			}
			for (int i = 1; i <= kb; i++) {
				int p, v;
				scanf("%d%d", &p, &v);
				b[p] = v;
			}
			printf("%d", check());
		}
	}
}
namespace sub2{
//	bool get(int x, int y, int tmp){
//		if(x == y) return 0;
//		return (x > y) ^ tmp;
//	}
//	bool check(){
//		int i = 1, j = 1, tmp = (a[1] < b[1]);
//		while(i <= n && j <= m){
//			
//		}
//	}
//	void solve(){
//		printf("%d", check());
//		for (int i = 1; i <= n; i++) t1[i] = a[i];
//		for (int i = 1; i <= m; i++) t2[i] = b[i];
//		for (int i = 1; i <= q; i++){
//			for (int i = 1; i <= n; i++) a[i] = t1[i];
//			for (int i = 1; i <= m; i++) b[i] = t2[i];
//			int ka, kb;
//			scanf("%d%d", &ka, &kb);
//			for (int i = 1; i <= ka; i++) {
//				int p, v;
//				scanf("%d%d", &p, &v);
//				a[p] = v;
//			}
//			for (int i = 1; i <= kb; i++) {
//				int p, v;
//				scanf("%d%d", &p, &v);
//				b[p] = v;
//			}
//			printf("%d", check());
//		}
//	}
}
int main(){
	file("expand");
	int id;
	scanf("%d%d%d%d", &id, &n, &m, &q);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= m; i++) scanf("%d", &b[i]);
	sub1::solve();
	return 0;
}
/*

*/