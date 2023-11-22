#include <bits/stdc++.h>
using namespace std;
struct nd{
	long long xq , jl;
}tt;
long long as , c , t , n , m , k , d , t1 , t2 , t3 , dp[100010][2];
vector <nd> a[100010];
long long rd(){
	long long ta = 0 , tk = 1;
	char tb = getchar();
	while(tb > '9' || tb < '0'){
		if(tb == '-'){
			tk = -1;
		}
		tb = getchar();
	}
	while(tb <= '9' && tb >= '0'){
		ta = (ta << 1) + (ta << 3) + tb - 48;
		tb = getchar();
	}
	return ta * tk;
}
int main(){
	freopen("run.in" , "r" , stdin);
	freopen("run.out" , "w" , stdout);
	c = rd() , t = rd();
	while(t--){
		as = 0;
		n = rd() , m = rd() , k = rd() , d = rd();
		if(c == 17 || c == 18){
			for(long long i = 1;i <= m;i++){
				t1 = rd() , t2 = rd() , t3 = rd();
				if(t2 * d < t3){
					as += t3 - t2 * d;
				}
			}
		}else{
			for(long long i = 1;i <= n;i++){
				a[i].clear();
			}
			memset(dp , 0 , sizeof(dp));
			for(long long i = 1;i <= m;i++){
				t1 = rd() , t2 = rd() , t3 = rd();
				if(t2 <= t1 && t2 <= k){
					tt.xq = t2 , tt.jl = t3;
					a[t1].emplace_back(tt);
				}
			}
			for(long long i = 1;i <= n;i++){
				dp[0][i & 1] = dp[0][(i - 1) & 1];
				for(long long j = 1;j <= k;j++){
					dp[0][i & 1] = max(dp[0][i & 1] , dp[j][(i - 1) & 1]);
					dp[j][i & 1] = dp[j - 1][(i - 1) & 1] - d;
				}
				if(a[i].size()){
					for(long long j = k;j > 0;j--){
						dp[j][i & 1] -= dp[j - 1][i & 1];
					}
					for(long long j = 0;j < a[i].size();j++){
						dp[a[i][j].xq][i & 1] += a[i][j].jl;
					}
					for(long long j = 1;j <= k;j++){
						dp[j][i & 1] += dp[j - 1][i & 1];
					}
				}
			}
			for(long long i = 0;i <= k;i++){
				as = max(as , dp[i][n & 1]);
			}
		}
		printf("%lld\n" , as);
	}
	return 0;
}