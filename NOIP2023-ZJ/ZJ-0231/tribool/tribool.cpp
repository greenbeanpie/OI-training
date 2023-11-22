#include <bits/stdc++.h>
const int N = 1e5+10;

using namespace std;
namespace Sub1{
	int ans = 1e9;
	int n,m;
	struct Node{
		char op;
		int x, y;
	}dir[N];
	char val[N];
	char tmp[N];
	bool check(){
		for(int i =1;i <= n; i++){
			tmp[i] = val[i];
		}
		for(int i = 1; i <= m; i++){
			char op = dir[i].op;
			int x = dir[i].x,y = dir[i].y;
			if(op == 'T' || op == 'U' || op == 'F'){
				tmp[x] =  op;
			}
			if(op == '-'){
				if(x == y && tmp[x] != 'U') return 0;
				if(tmp[y] == 'T') tmp[x] = 'F';
				else if(tmp[y] == 'F') tmp[x] = 'T';
				else tmp[x] = tmp[y];
			}
			if(op == '+') tmp[x] = tmp[y];
		}
		for(int i = 1;i <= n; i++){
			if(tmp[i] != val[i]) return 0;
		}
		// for(int i =1;i <= n; i++){
		// 	cout << val[i] << " ";
		// }
		// cout << endl;
		return 1;
	}
	void dfs(int dep,int cnt){
		if(cnt > ans) return;
		if(dep == n+1){
			if(check()) ans = min(ans,cnt);
			return;
		}
		val[dep] = 'T';
		dfs(dep+1,cnt);
		val[dep] = 'F';
		dfs(dep+1,cnt);
		val[dep] = 'U';
		dfs(dep+1,cnt+1);
	}
	void calc(){
		ans = 1e9;
		scanf("%d%d",&n,&m);
		for(int i = 1; i <= m; i++){
			char op;
			int x, y;
			cin >> op;
			if( op == '+' || op == '-'){
				// cin >> x >> y;
				scanf("%d%d",&x,&y);
				dir[i] = {op,x,y};
			}else{
				// cin >> x;
				scanf("%d",&x);
				dir[i] = {op,x,0};
			}
		}
		dfs(1,0);
		printf("%d\n",ans);
	}
	void solve(int t){
		while(t--) calc();
	}
}
namespace Sub2{
	int n,m;
	int ans = 0;
	char val[N];
	void calc(){
		ans = 0;
		scanf("%d%d",&n,&m);
		for(int i = 1; i <= m; i++){
			char op ;
			int x;
			cin >> op;
			scanf("%d",&x);
			val[x] = op;
		}
		for(int i = 1; i <= n; i++) if(val[i] == 'U') ans++;
		printf("%d\n",ans);
	}	
	void solve(int t){
		while(t--) calc();
	}
}
namespace Sub3{
	int n, m;
	int fa[N*2];
	int val[N*2];
	int now[N*2];
	int ans;
	int find(int x){
		return x == fa[x] ? x : fa[x] = find(fa[x]);
	}
	void calc(){
		ans = 0;
		scanf("%d%d",&n,&m);
		for(int i = 1; i <= n*2; i++) fa[i] = i,val[i] = 'T';
		for(int i = 1;i <= m; i++){
			char op;
			int x, y;
			cin >> op;
			if(op == '+'){
				scanf("%d%d",&x,&y);
				now[x] = y;
				now[x+n] = y+n;
			}
			if(op == '-'){
				scanf("%d%d",&x,&y);
				if(x == y){
					fa[find(x)] = find(x+n);
					continue;
				}
				now[x] = y+n;
				now[x+n] = y;
			}
		}
		for(int i = 1;i <= n*2; i++){
			if(now[i]){
				fa[find(i)] = find(now[i]);
			}
		}
		for(int i = 1 ;i <= n; i++){
			if(find(i) == find(i+n)) val[find(i)] = 'U';
		}
		for(int i = 1; i <= n; i++){
			if(val[find(i)] == 'U') ans++;
		}
		printf("%d\n",ans);

	}
	void solve(int t){
		while(t--) calc();
	}
}
namespace Sub4{
	int n, m;
	char val[N];
	int ans;

	void calc(){
		ans = 0;
		scanf("%d%d",&n,&m);
		for(int i = 1;i <= n; i++) val[i] = 'T';
		for(int i = 1;i <= m; i++){
			char op;
			int x,y;
			cin >> op;
			if(op == 'U'){
				scanf("%d",&x);
				val[x] = op;
			}
			if(op == '+'){
				scanf("%d%d",&x,&y);
				val[x] = val[y];
			}
		}
		for(int i = 1; i <= n; i++){
			if(val[i] == 'U') ans++;
		}
		printf("%d\n",ans);
	}
	void solve(int t){
		while(t--) calc();
	}
}
int c,t;
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	cin >> c >> t;
	if(c == 1 || c == 2 || c == 9 || c == 10) Sub1::solve(t);
	if(c == 3 || c == 4) Sub2::solve(t);
	if(c == 7 || c == 8) Sub3::solve(t);
	if(c == 5 || c == 6) Sub4::solve(t);

	return 0;
}
/*
I'm so sad that I can't get all the score,maybe I will miss all the score.
This is my first jounery to NOIP, but it's also the last.
Good bye my 285 days OIer career.
Complie succefully for the last time.
*/