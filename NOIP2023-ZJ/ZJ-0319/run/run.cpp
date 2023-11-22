#include <bits/stdc++.h>
#define FL(i, a, b) for(int i = (a); i <= (b); ++i)
#define FR(i, a, b) for(int i = (a); i >= (b); --i)
using namespace std;
typedef long long ll;
constexpr int N = 1e5 + 10;
struct A{int x, y, v;} a[N];
int n, m, k, d;
namespace S1{
	constexpr int MaxN = 1e3 + 10;
	constexpr ll INF = 1e18;
	ll f[MaxN][MaxN], s[MaxN], ans;
	vector<int> v[MaxN];
	void Init(){
		FL(i, 1, n) vector<int>().swap(v[i]);
		FL(i, 0, n) FL(j, 0, n) f[i][j] = -INF;
		ans = f[0][0] = 0;
	}
	void Solve(){
		Init();
		FL(i, 1, m) if(a[i].y <= k) v[a[i].x].emplace_back(i);
		FL(i, 1, n){
			FL(j, 0, k) s[j] = 0;
			FL(j, 1, min(i, k)) f[i][j] = f[i - 1][j - 1] - d;
			for(int j: v[i]) s[a[j].y] += a[j].v;
			FL(j, 1, min(i, k)){
				s[j] += s[j - 1];
				f[i][j] += s[j];
			}
			FL(j, 0, min(i - 1, k)) f[i][0] = max(f[i][0], f[i - 1][j]);
		}
		FL(i, 0, min(n, k)) ans = max(ans, f[n][i]);
		printf("%lld\n", ans);
	}
}
int main(){
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	int C, T; scanf("%d%d", &C, &T);
	while(T--){
		scanf("%d%d%d%d", &n, &m, &k, &d);
		FL(i, 1, m) scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].v);
		S1::Solve();
	}
	return 0;
}