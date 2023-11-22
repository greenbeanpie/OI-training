#include<bits/stdc++.h>
#define M 100100
using namespace std;
int read(){
	int w = 1, s = 0;
	char ch = getchar();
	while(!isdigit(ch)){
		if(ch == '-') w = -w;
		ch = getchar();
	}
	while(isdigit(ch)){
		s = (s << 3) + (s << 1) + (ch ^ 48);
		ch = getchar();
	}
	return w * s;
}
int c, t, n, m;
int trans[300], cnt[10];
struct optn{
	int opt, x, y;
}in[M];
namespace subtask1{
	int num[30], suf[30], ans;
	void dfs(int h){
		if(h == n + 1){
			for(int i = 1; i <= n; ++ i) suf[i] = num[i];
			for(int i = 1; i <= m; ++ i)
				if(in[i].opt < 4) suf[in[i].x] = in[i].opt;
				else if(in[i].opt == 4) suf[in[i].x] = suf[in[i].y];
				else{
					if(suf[in[i].y] == 3) suf[in[i].x] = 3;
					else suf[in[i].x] = 3 - suf[in[i].y];
				}
			bool flag = 1; int tot = 0;
			for(int i = 1; i <= n; ++ i)
				if(suf[i] != num[i]){
					flag = 0;
					break;
				}
				else tot += (num[i] == 3);
			if(flag) ans = min(ans, tot);
			return ;
		}
		for(int i = 1; i < 4; ++ i){
			num[h] = i;
			subtask1 :: dfs(h + 1);
		}
	}
	void solve(){
		ans = n;
		subtask1 :: dfs(1);
		printf("%d\n", ans);
	}
}
namespace subtask2{
	int val[M], tot;
	void solve(){
		tot = 0;
		for(int i = 1; i <= n; ++ i) val[i] = 0;
		for(int i = 1; i <= m; ++ i) val[in[i].x] = in[i].opt;
		for(int i = 1; i <= n; ++ i) if(val[i] == 3) ++ tot;
		printf("%d\n", tot);
	}
}
namespace elsetask{
	set <int> son[M * 3], edge[M * 3];
	int tot, val[M * 3], fat[M * 3];
	bool vis[M * 3], vis1[M * 3];
	void dfs(int x, int fa){
		vis[x] = 1;
		for(int to : edge[x])
			if(to != fa && !vis[to]){
				val[to] = val[x] == 3 ? 3 : 3 - val[x];
				elsetask :: dfs(to, x);
			}
	}
	bool dfs1(int x, int fa){
		vis1[x] = 1;
		for(int to : edge[x])
			if(to != fa){
				if(!vis1[to]){
					val[to] = 3 - val[x];
					if(! elsetask :: dfs1(to, x)) return 0;
				}
				else if(3 - val[x] != val[to]) return 0;
			}
		return 1;
	}
	void solve(){
		tot = n;
		for(int i = 1; i <= 300000; ++ i){
			fat[i] = val[i] = vis[i] = vis1[i] = 0;
			son[i].clear();
			edge[i].clear();
		}
		for(int i = 1; i <= m; ++ i)
			if(in[i].opt < 4){
				val[in[i].x] = in[i].opt;
				if(fat[in[i].x]){
					edge[fat[in[i].x]].erase(in[i].x); edge[in[i].x].erase(fat[in[i].x]);
					son[fat[in[i].x]].erase(in[i].x); fat[in[i].x] = 0;
				}
			}
			else{
				val[in[i].x] = 0;
				++ tot; fat[tot] = fat[in[i].x];
				son[tot] = son[in[i].x]; edge[tot] = edge[in[i].x];
				for(int x : edge[in[i].x]){
					edge[x].erase(in[i].x); edge[x].insert(tot);
					if(x == fat[in[i].x]) son[x].erase(in[i].x);
					else fat[x] = tot;
				}
				son[in[i].x].clear(); edge[in[i].x].clear();
				if(in[i].opt == 5){
					edge[in[i].x].insert(in[i].y); edge[in[i].y].insert(in[i].x);
					son[in[i].y].insert(in[i].x); fat[in[i].x] = in[i].y;
				}
				else{
					++ tot;
					edge[in[i].x].insert(tot); edge[tot].insert(in[i].x);
					son[tot].insert(in[i].x); fat[in[i].x] = tot;
					edge[tot].insert(in[i].y); edge[in[i].y].insert(tot);
					son[in[i].y].insert(tot); fat[tot] = in[i].y;
				}
			}
		for(int i = 1; i <= n; ++ i)
			if(val[i] && !vis[i])
				elsetask :: dfs(i, 0);
		for(int i = 1; i <= n; ++ i)
			if(!vis[i]){
				val[i] = 1;
				if(!(elsetask :: dfs1(i, 0))) val[i] = 3;
				elsetask :: dfs(i, 0);
			}
		int ans = 0;
		for(int i = 1; i <= n; ++ i) if(val[i] == 3) ++ ans;
		printf("%d\n", ans);
	}
}
int main(){
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	trans['F'] = 1; trans['T'] = 2; trans['U'] = 3; trans['+'] = 4; trans['-'] = 5;
	c = read(), t = read();
	for(int T = 1; T <= t; ++ T){
		n = read(), m = read();
		for(int i = 1; i < 6; ++ i) cnt[i] = 0;
		for(int i = 1; i <= m; ++ i){
			char ch; cin >> ch;
			in[i].opt = trans[ch]; in[i].x = read();
			if(in[i].opt > 3) in[i].y = read();
			cnt[trans[ch]] ++;
		}
		if(n <= 10 && m <= 10) subtask1 :: solve();
		else if(cnt[1] + cnt[2] + cnt[3] == m) subtask2 :: solve();
		else if(cnt[3] + cnt[4] == m) elsetask :: solve();
	}
	return 0;
}