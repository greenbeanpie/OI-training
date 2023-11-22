#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
int c, t, n, m, lv[MAXN], rv[MAXN];
char op[MAXN], val[MAXN], lasval[MAXN], REV[128];
int gans;
void dfs(int idx){
	if(idx > n){
		for(int i = 1; i <= n; ++i)
			lasval[i] = val[i];
		for(int i = 0; i < m; ++i){
			if(op[i] == '+'){
				val[lv[i]] = val[rv[i]];
			}else{
				if(op[i] == '-'){
					val[lv[i]] = REV[val[rv[i]]];
				}else{
					val[lv[i]] = op[i];
				}
			}
		}
		bool sm = true;
		for(int i = 1; i <= n; ++i)
			if(val[i] != lasval[i]){
				sm = false;
				break;
			}
		for(int i = 1; i <= n; ++i)
			val[i] = lasval[i];
		if(!sm)
			return;
		int ansn = 0;
		for(int i = 1; i <= n; ++i)
			ansn += val[i] == 'U';
		gans = min(gans, ansn);
		return;
	}
	val[idx] = 'T';
	dfs(idx + 1);
	val[idx] = 'F';
	dfs(idx + 1);
	val[idx] = 'U';
	dfs(idx + 1);
}
inline void solD(){
	gans = n;
	dfs(1);
	cout << gans << endl;
}
inline void solA(){
	for(int i = 1; i <= n; ++i)
		val[i] = 0;
	for(int i = 0; i < m; ++i)
		val[lv[i]] = op[i];
	int ans = 0;
	for(int i = 1; i <= n; ++i)
		if(val[i] == 'U')
			++ans;
	cout << ans << endl;
}
inline void solB(){
	for(int i = 1; i <= n; ++i)
		val[i] = 0;
	int ans = 0;
	bool chd = true;
	while(chd){
		chd = false;
		for(int i = 1; i <= n; ++i)
			lasval[i] = val[i];
		for(int i = 0; i < m; ++i)
			if(op[i] == 'U'){
				if(!val[lv[i]]){
					val[lv[i]] = 'U';
					++ans;
				}
			}else{
				if(val[rv[i]] == 'U' && val[lv[i]] != 'U'){
					val[lv[i]] = 'U';
					++ans;
				}
				if(!val[rv[i]] && val[lv[i]] == 'U'){
					val[lv[i]] = 0;
					--ans;
				}
			}
		for(int i = 1; i <= n; ++i)
			if(lasval[i] != val[i])
				chd = true;
	}		
	cout << ans << endl;
}
//vector<int>to[MAXN << 1];
//inline void edge(int u, int v){
//	to[u].push_back(v);
//	to[v].push_back(u);
//}
//int dfn[MAXN << 1], low[MAXN << 1], st[MAXN << 1], stl, tt, scc[MAXN << 1], sccl, sccs[MAXN << 1];
//bool inst[MAXN << 1];
//void tarjan(int idx){
//	dfn[idx] = low[idx] = ++tt;
//	inst[idx] = true;
//	st[++stl] = idx;
//	int nn;
//	for(int i = 0; i < to[idx].size(); ++i){
//		nn = to[idx][i];
//		if(!dfn[nn]){
//			tarjan(nn);
//			low[idx] = min(low[idx], low[nn]);
//		}else{
//			if(inst[nn])
//				low[idx] = min(low[idx], dfn[nn]);
//		}
//	}
//	if(low[idx] == dfn[idx]){
//		++sccl;
//		do{
//			nn = st[stl--];
//			inst[nn] = false;
//			scc[nn] = sccl;
//		}while(nn != idx);
//	}
//}
int nxt[MAXN << 1], gsiz[MAXN << 1];
int find_nxt(int idx){
	if(nxt[idx] == idx)
		return idx;
	return nxt[idx] = find_nxt(nxt[idx]);
}
bool book[MAXN << 1];
inline void solC(){
//	for(int i = 1; i <= (n << 1); ++i)
//		nxt[i] = i;
//	for(int i = 0; i < m; ++i){
//		if(op[i] == '+'){
//			nxt[find_nxt(lv[i])] = find_nxt(rv[i]);
//			nxt[find_nxt(lv[i] + n)] = find_nxt(rv[i] + n);
//		}else{
//			nxt[find_nxt(lv[i])] = find_nxt(rv[i] + n);
//			nxt[find_nxt(lv[i] + n)] = find_nxt(rv[i]);
//		}
//	}
//	for(int i = 1; i <= (n << 1); ++i)
//		gsiz[i] = 0;
//	for(int i = 1; i <= n; ++i)
//		++gsiz[find_nxt(i)];
//	int ans = 0;
//	for(int i = 1; i <= n; ++i){
////		cerr << find_nxt(i) << ' ';
//		if(find_nxt(i) == find_nxt(i + n)){
//			if(!book[find_nxt(i)]){
//				book[find_nxt(i)] = true;
//				ans += gsiz[find_nxt(i)];
//			}
//		}
//		
//	}
//	cerr << endl;
//	cout << ans << endl;
	
//	cerr << "START SOL" << endl;
//	tt = 0;
//	for(int i = 1; i <= (n << 1); ++i)
//		to[i].clear();
//	for(int i = 0; i < m; ++i)
//		if(op[i] == '+'){
//			edge(lv[i], rv[i]);
//			edge(lv[i] + n, rv[i] + n);
//		}else{
//			edge(lv[i], rv[i] + n);
//			edge(lv[i] + n, rv[i]);
//		}
//	cerr << "FIN BUILD" << endl;
//	for(int i = 1; i <= (n << 1); ++i)
//		dfn[i] = low[i] = inst[i] = 0;
//	stl = sccl = 0;
//	cerr << "START TARJAN" << endl;
//	for(int i = 1; i <= (n << 1); ++i)
//		if(!dfn[i])
//			tarjan(i);
//	for(int i = 1; i <= (n << 1); ++i)
//		inst[i] = false;
//	cerr << "tt:" << tt << endl;
//	cerr << "sccl:" << sccl << endl;
//	for(int i = 1; i <= (n << 1); ++i)
//		sccs[i] = 0;
//	for(int i = 1; i <= (n << 1); ++i)
//		++sccs[scc[i]];
//	int ans = 0;
//	for(int i = 1; i <= n; ++i)
//		if(scc[i] == scc[i + n]){
//			if(!inst[scc[i]]){
//				inst[scc[i]] = true;
//				ans += sccs[scc[i]];
//			}
//		}
//	cout << ans << endl;
}
inline void solve(){
	cin >> n >> m;
	for(int i = 0; i < m; ++i){
		cin >> op[i];
		if(op[i] == '+' || op[i] == '-'){
			cin >> lv[i] >> rv[i];
		}else{
			cin >> lv[i];
		}
	}
	if(c == 1 || c == 2)
		solD();
	if(c == 3 || c == 4)
		solA();
	if(c == 5 || c == 6)
		solB();
//	if(c == 7 || c == 8)
//		solC();
}
int main(){
	ios::sync_with_stdio(false);
	REV['T'] = 'F';
	REV['F'] = 'T';
	REV['U'] = 'U';
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	cin >> c >> t;
	while(t--)
		solve();
	return 0;
}