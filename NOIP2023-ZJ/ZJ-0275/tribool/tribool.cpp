#include<bits/stdc++.h>
#define int long long
#define PII pair<char, pair<int, int> > 
#define x first
#define y second
using namespace std;
int num[100009], nu[100009];
int n, m, c, ans, T, cnt;
int t[100009], fa[100009], b[100009];
PII s[100009];
int find(int x) {return x == fa[x] ? x : fa[x] = find(fa[x]);}
void dfs(int pos){
	if(pos == n + 1){
		int sum = 0;
		for(int i = 1; i <= m; i ++ ){
			if(s[i].x == '+') num[s[i].y.x] = num[s[i].y.y];
			else if(s[i].x == '-') num[s[i].y.x] = - num[s[i].y.y];
			else if(s[i].x == 'U') num[s[i].y.x] = 0;
			else if(s[i].x == 'F') num[s[i].y.x] = -1;
			else if(s[i].x == 'T') num[s[i].y.x] = 1;
		}
		for(int i = 1;i <= n; i ++ ){
			if(num[i] == 0) sum ++;
			if(num[i] != nu[i]) sum = n;
		}
		ans = min(ans, sum);
		for(int i = 1; i <= n; i ++ ){
			num[i] = nu[i];
		}
		return  ;
	}
	for(int i = -1; i <= 1; i ++ ){
		num[pos] = i;
		nu[pos] = i;
		dfs(pos + 1);
	}
}
void solve(){
	cin >> n >> m;
	ans = n;
	if(c == 1 | c == 2){
		for(int i = 1; i <= m; i ++ ){
			cin >> s[i].x;
			if(s[i].x == '+' || s[i].x == '-'){
				cin >> s[i].y.x >> s[i].y.y;
			}else{
				cin >> s[i].y.x;
			}
		}
		dfs(1);
		cout << ans << '\n';
		return ;
	}
	if(c == 3 || c == 4){
		for(int i = 1; i <= m; i ++ ){
			char op;
			int x;
			cin >> op;
			cin >> x;
			if(op == 'U') num[x] = 2;
			else num[x] = 0;
		}
		int sum = 0;
		for(int i = 1; i <= n; i++ ){
			if(num[i] == 2){
				sum ++;
			}
		}
		cout << sum << '\n';
		return ;
	}
	if(c == 5 || c == 6){
		char op;
			cin >> op;
			if(op == '+'){
				int x, y;
				cin >> x >> y;
				num[x] = num[y];
			}
			if(op == 'U'){
				int x;
				cin >> x;
				num[x] = 2;
			}
		int sum = 0;
		for(int i = 1; i <= n; i ++ ){
		}
		cout << sum << '\n';
		return ;
	}
	for(int i = 1; i <= n; i ++){
		t[i] = i;
		fa[i] = i;
	}
	cnt = n;
	for(int i = 1; i <= m; i ++ ){
		char op;
		cin >> op;
		if(op == '+'){
			int x, y;
			cin >> x >> y;
			t[x] = ++ cnt;
			fa[cnt] = y;
		}
		if(op == '-'){
			int x, y;
			cin >> x >> y;
			t[x] = ++cnt;
			b[y] = cnt;
		}
	}
}
signed main(){
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c >> T;
	while(T -- ){
		solve();
	}
	return 0;
}
