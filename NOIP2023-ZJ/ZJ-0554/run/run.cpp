#include<bits/stdc++.h>
#define int long long
#define IL inline
using namespace std;
const int M = 1e5 + 10,D = 1e2 + 10;
bool _u;
struct node {
	int l,r,v;
	#define l(i) num[i].l
	#define r(i) num[i].r
	#define v(i) num[i].v
}num[M];
int id,T,n,m,k,d,ans;
int dp[M][2];
bool vis[M],bk[D];
bool _v;
IL int read() {
	int x = 0,f = 1;
	char c = getchar();
	while(c < '0' || c > '9') {if(c == '-')	f = -1;c = getchar();}
	while(c >= '0' && c <= '9') {x = (x << 1) + (x << 3) + (c ^ 48);c = getchar();}
	return x * f;
}
IL void dfs(int x) {
	if(x > n) {
		int sum = 0,len = 0,st = 0;
		memset(bk,0,sizeof(bk));
		for(int i = 1;i <= n;i ++) {
			if(vis[i]) {
				sum -= d;
				if(!len)	st = i;
				len ++;if(len > k)	return;
				int ed = st + len - 1;
				for(int j = 1;j <= m;j ++)	if(st <= l(j) && ed >= r(j) && !bk[j])	sum += v(j),bk[j] = 1;
			}
			else	st = len = 0;
		}
		ans = max(ans,sum);return;
	}
	vis[x] = 1,dfs(x + 1);
	vis[x] = 0,dfs(x + 1);
	return;
}
signed main() {
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	//cerr << abs(&_u - &_v) / 1048576.0 << "MB" << endl;
	id = read(),T = read();
	while(T --) {
		n = read(),m = read(),k = read(),d = read();
		for(int i = 1;i <= m;i ++) {
			int x = read(),y = read();v(i) = read();
			l(i) = x - y + 1,r(i) = x;
		}
		if(id >= 1 && id <= 2) {ans = 0,dfs(1),printf("%lld\n",ans);continue;}
		if(id >= 3 && id <= 14) {
			int mx = 0;
			memset(dp,0,sizeof(dp));
			for(int i = 1;i <= n;i ++) {
				dp[i][0] = mx;
				for(int j = max(0ll,i - k);j < i;j ++) {
						int val = 0;
						for(int l = 1;l <= m;l ++)	if(j + 1 <= l(l) && r(l) <= i)	val += v(l);
						dp[i][1] = max(dp[i][1],dp[j][0] + val - d * (i - j));
					}
				mx = max(mx,max(dp[i][0],dp[i][1]));
			}
			printf("%lld\n",mx);continue;
		}
		if(id >= 17 && id <= 18) {
			int sum = 0;
			for(int i = 1;i <= m;i ++) {
				int len = r(i) - l(i) + 1;
				if(len > k)	continue;
				sum += max(0ll,v(i) - len * d);
			}
			printf("%lld\n",sum);continue;
		}
	}
	return 0;
}
