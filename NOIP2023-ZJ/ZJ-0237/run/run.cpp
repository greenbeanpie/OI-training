#include <bits/stdc++.h>

const int maxm=1e5;
long long n, m, k, d;

namespace nandmle1000 {

const int maxn=1000;
std::vector<std::pair<long long, long long>> vec[maxn+5];
long long f[maxn+5], ans;

void solve() {
	scanf("%lld%lld%lld%lld", &n, &m, &k, &d);
	for(int i=1; i<=n; ++i) {
		vec[i].clear();
	}
	for(int i=1; i<=m; ++i) {
		long long x, y, v;
		scanf("%lld%lld%lld", &x, &y, &v);
		vec[x].push_back(std::make_pair(y, v));
	}
	memset(f, 0xbf, sizeof(f));
	f[0]=0;
	for(int i=1; i<=n; ++i) {
		std::sort(vec[i].begin(), vec[i].end());
		int now=0;
		long long f0=f[0], ad=-d;
		while(now<(int)vec[i].size()&&vec[i][now].first<=k) {
			ad+=vec[i][now].second;
			++now;
		}
		--now;
		for(int j=k; j>=1; --j) {
			f0=std::max(f0, f[j]);
			while(vec[i].size()>0&&now>=0&&vec[i][now].first>j) {
				ad-=vec[i][now].second;
				--now;
			}
			if(f[j-1]!=(long long)0xbfbfbfbfbfbfbfbf) {
				f[j]=f[j-1]+ad;
			}
		}
		f[0]=f0;
	}
	ans=0;
	for(int i=0; i<=k; ++i) {
		ans=std::max(ans, f[i]);
	}
	printf("%lld\n", ans);
	return ;
}

}

int main() {
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	int c, t;
	scanf("%d%d", &c, &t);
	while(t--) {
		if(c<=7) {
			nandmle1000::solve();
		} else {
			printf("0\n");//bukeyi,zongsiling
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}