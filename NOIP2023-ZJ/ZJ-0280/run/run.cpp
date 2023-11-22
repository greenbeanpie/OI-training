#include <bits/stdc++.h>
using namespace std;

long long ans;
int c, t, n, m, k, d, Max;
struct node{
	int x, y, v;
}bon[100005];

void dfs1(int step, int cont, long long power, int b){
	if (step > Max){
		ans = max(ans, power);
		return ;
	}
	long long p = power, _old = b;
	while (step > bon[_old].x){
		if (cont >= bon[_old].y)
			p += bon[_old].v;
		_old++;
	}
	if (cont < k)
		dfs1(step + 1, cont + 1, p - d, _old);
	dfs1(step + 1, 0, p, _old);
}

void solve1(){
	ans = 0, Max = 0;
	for (int i = 1; i <= m; i++)
		Max = max(Max, bon[i].x);
	dfs1(1, 0, 0, 1);
	printf("%lld\n", ans);
}

bool cmp(node x, node y){
	return x.x < y.x;
}

void solve2(){
	ans = 0;
	int cal[100005];
	bool val[100005];
	memset(val, 0, sizeof(val));
	for (int i = 1; i <= m; i++){
		cal[i] = bon[i].v - bon[i].y * d;
		if (bon[i].y > k)
			val[i] = 1;
	}
	int f[100005][2], j = 0;
	for (int i = 1; i <= m; i++)
		if (!val[i]){
			j++;
			f[j][0] = max(max(f[j - 1][1], f[j - 1][0]), max(f[j - 2][1], f[j - 2][0]));
			f[j][1] = max(max(f[j - 2][0], f[j - 1][1]), f[j - 1][0]) + cal[i];
			if (bon[i].x != bon[i + 1].x - bon[i + 1].y){
				ans += max(f[j][0], f[j][1]);
				//printf("%lld\n",ans);
				f[0][0] = f[0][1] = f[1][1] = f[1][0] = 0;
				j = 0;
			}
		}
	printf("%lld\n", ans);
}

int main(){
	//freopen("run.in", "r", stdin); get stick bugged LOL
	//One Last OI from Senmo
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	
	scanf("%d%d", &c, &t);
	while (t--){
		scanf("%d%d%d%d", &n, &m, &k, &d);
		for (int i = 1; i <= m; i++)
			scanf("%d%d%d", &bon[i].x, &bon[i].y, &bon[i].v);
		sort(bon + 1, bon + m + 1, cmp);
		if (c == 1 || c == 2)
			solve1();
		if (c == 17 || c == 18)
			solve2();
	}

	return 0;
}

