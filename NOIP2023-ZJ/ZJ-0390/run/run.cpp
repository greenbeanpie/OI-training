/*
//freopen("run.in", "w", stdin);
//feropen("run.ans", "r", stdout);
zhao huan mi huo xing wei da shang ren

dian nao mei you shu ru fa, xi wang you ren neng kan dong wo de zhe xie xian hua.

kai xue hou ting ke ji xun le liang ge yue, gan jue zi ji te bui niu bi.
yi kao csp jiu xiao chou le, s zhi you 2=.

liang ge yue xia lai, chu le xian duan shu ban zi da de shu lian le dian, 
hui le dian mei sha yong chu de suan fa zhi wai hao wu zhang jin.
bu guo xiang dui yu zhi qian pj 2= de shui ping huo xu que shi shi you dian jin bu ba.

csp kao wan zhi jie dao xin po sui, xian zai yi jing hui qu xue le liang zhou wen hua ke le.
qi zhong kao li ke quan bu bao zha, wen ke fan er shi fen jian ting, ying yu shen zhi 114/120.
kai shi huai yi zi ji yi kai shi wei she me yao gao OI le.

liang zhou mei peng jian pan le, da ge que shen yuan cuo le si wu chu, guo ran gai tui yi le.
zhe ci noip ye jiu suan tu yi le ba.

T1 yan xu le csp-s de you liang feng ge, pj nan du. (dan shi zong gan jue hui jia ...)
T2, T3, T4 dou shi fen you shui ping, wo yi ge dou bu hui.

jin hou jiu ban AFO le.
xie xie ni kan dao zhe li, zhu ni de OI sheng ya yi fan feng shun.

luogu 542876.
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

#define int long long

struct seg { 
	int x, y, k;
	bool operator < (const seg &other) const {
		return x < other.x;
	} 
} a[N];

int c, t, n, m, d, k, ans, s[N], f[N], g[N];

void calc() {
	int sum = 0;
	for(int i = 1; i <= m; ++ i) 
		if(s[a[i].x] - s[a[i].x - a[i].y] == a[i].y)
			sum += a[i].k;
	sum -= s[n] * d;
	ans = max(ans, sum);
}

void dfs(int dep, int pre) {
	if(dep == n + 1) {
		calc();
		return ;
	}
	
	s[dep] = s[dep - 1];
	dfs(dep + 1, 0);
	if(pre == k) return ;
	s[dep] = s[dep - 1] + 1;
	dfs(dep + 1, pre + 1);
}

void clear() { 
	ans = 0; 
	memset(f, 0, sizeof f);
	memset(g, 0, sizeof g);
}

void slove1() {
	cin >> n >> m >> k >> d;
	for(int i = 1; i <= m; ++ i) 
		cin >> a[i].x >> a[i].y >> a[i].k;
	dfs(1, 0);
	cout << ans << endl;
}

void slove2() {
	cin >> n >> m >> k >> d;
	for(int i = 1; i <= m; ++ i) {
		int x, y, v; cin >> x >> y >> v;
		a[i] = {x, y, v - y * d};
	}
	sort(a + 1, a + 1 + m);
	a[0] = {0, 0, 0};
	for(int i = 1; i <= m; ++ i) {
		for(int j = 0; j < i; ++ j) {
			if(a[j].x >= a[i].x - a[i].y) {
				if(g[j] + (a[i].x - a[j].x) <= k) {
					if(f[j] + a[i].k > f[i]) {
						f[i] = f[j] + a[i].k;
						g[i] = g[j] + (a[i].x - a[j].x);
					}
				}
			} else {
				if(f[j] + a[i].k > f[i]) {
					f[i] = f[j] + a[i].k;
					g[i] = a[i].y;
				}
			}
		}	
		ans = max(ans, f[i]);
	}
	cout << ans << endl;
}

void slove3() {
	cin >> n >> m >> k >> d;
	for(int i = 1; i <= m; ++ i) {
		int x, y, v; cin >> x >> y >> v;
		if(y <= k && y * d < v) ans += v - y * d;
	}
	cout << ans << endl;
}

signed main() {
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	cin >> c >> t;
	
	while(t --> 0) {
		clear();
		if(c <= 2) slove1();
		else if(c <= 11) slove2();
		else slove3();
	}
	return 0;
}