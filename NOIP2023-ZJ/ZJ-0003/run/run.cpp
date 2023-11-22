#include <bits/stdc++.h>
#define rep(i, l, r) for(int i=l, _=r; i<=_; ++i)
using namespace std;
typedef long long ll;
const int mN=1e5+9;
namespace Main {
	inline void toMax(ll &x, ll y) {
		if(y>x) x=y;
	}
	int n, m, k, d;
	vector<pair<int, int> > v[mN];
	ll sum[mN], dp[mN];
	ll main(int Cas, int T_T) {
		while(T_T--) {
			rep(i, 1, n) v[i].clear(), sum[i]=0;
			memset(dp, 0, sizeof dp);

			scanf("%d%d%d%d", &n, &m, &k, &d);
			rep(i, 1, m) {
				int x, y, z;
				scanf("%d%d%d", &x, &y, &z);
				v[x].emplace_back(x-y+1, z);
			}
			dp[0]=0;
			rep(i, 1, n) {
				for(auto tmp: v[i]) {
					sum[tmp.first]+=tmp.second;
				}
				ll z=0;
				toMax(dp[i+1], dp[i]);
				for(int j=i, _=max(1, j-k+1); j>=_; --j) {
					z+=sum[j]-d;
					toMax(dp[i+1], dp[j-1]+z);
				}
			}
			if(T_T) {
				printf("%lld\n", dp[n+1]);
			} else {
				return dp[n+1];
			}
		}
	}
}

int main() {
	freopen("run.in", "r", stdin), freopen("run.out", "w", stdout);
	unsigned long long czq, ljc, kcz;
	cin>>czq>>ljc;
	kcz=Main::main(czq, ljc);
	cout<<kcz;
	cout<<endl;
	fclose(stdin), fclose(stdout);
}

/*
11:00 ~ 11:43
某次连续跑步的开始节点一定是某个奖励的开始，结束一定是某个奖励的结束，
可以离散化。

网络流？不会刻画“不能连续超过 k 天”！

m 按右端点排序。O(mn) 容易，但是此时离散化没有意义。
怎么没有一道树论（
- long long
*/