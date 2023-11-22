#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int M = 1e7 + 10;
const int N = 5e3 + 10;
ll f[3][M];
int c, t;
int n, m, k, d;
struct node{
	ll x, y, v;
}a[M];

bool cmp(node n1, node n2){
	return n1.x < n2.x;
}

ll check(int i, int j){
	ll ans = 0;
	ll t = 1;
	for(int tt = t; tt <= m; tt ++){
		if(a[tt].x == i and a[tt].y <= j)
			ans += a[tt].v;
		if(a[tt].x > i)
			break;
	}
	return ans;
}

int main(){
	freopen("run1.in", "r", stdin);
	freopen("run.out", "w", stdout);
	scanf("%d%d", &c, &t);
	while(t --){
		memset(f, 0, sizeof f);
		scanf("%d%d%d%d", &n, &m, &k, &d);
		for(int i = 1; i <= m; i ++){
			scanf("%lld%lld%lld", &a[i].x, &a[i].y, &a[i].v);
		}
		sort(a + 1, a + m + 1, cmp);
		
		for(int i = 1; i <= k; i ++){
			f[i % 2][0] = f[(i + 1) % 2][0];
			for(int j = 1; j <= i; j ++){
				f[i % 2][j] = f[(i + 1) % 2][j - 1] + check(i, j) - d;
				f[i % 2][0] = max(f[(i + 1) % 2][j], f[i % 2][0]);
			}
		}
		for(int i = k + 1; i <= n; i ++){
			f[i % 2][0] = f[(i + 1) % 2][0];
			for(int j = 0; j <= k; j ++){
				f[i % 2][j] = f[(i + 1) % 2][j - 1] + check(i, j) - d;
				f[i % 2][0] = max(f[(i + 1) % 2][j], f[i % 2][0]);
			}
		}
		ll ans = 0;
		for(int i = 0; i <= k; i ++)
			ans = max(f[n % 2][i], ans);
		printf("%lld\n", ans);
	}
	return 0;
}