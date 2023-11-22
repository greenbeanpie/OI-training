#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
int n, m, ans;
int typ[N], write[N], fa[N], data[N];

struct node{
	int op, x, y;
} a[N];

inline void dfs(int now){
	if( now == n + 1 ){
		int num = 0;
		for(int i = 1; i <= n; i++){
			typ[i] = write[i];
			num += (write[i] == 0);
		}
		for(int i = 1; i <= m; i++){
			if( a[i].op == 1 )
				typ[a[i].y] = a[i].x;
			else{
				if( a[i].op == 2 )
					typ[a[i].x] = typ[a[i].y];
				else{
					if( typ[a[i].y] == 0 )
						typ[a[i].x] = 0;
					else if( typ[a[i].y] == 1 )
						typ[a[i].x] = 2;
					else
						typ[a[i].x] = 1;
				}
			}
		}
		for(int i = 1; i <= n; i++)
			if( write[i] != typ[i] )
				return;
		ans = min(ans, num);
		return;
	}
	write[now] = 0;
	dfs(now + 1);
	write[now] = 1;
	dfs(now + 1);
	write[now] = 2;
	dfs(now + 1);
	return;
}

inline int find(int x){
	if( x == fa[x] )
		return x;
	return fa[x] = find(fa[x]);
}

inline void solve1(){
	ans = 1e9;
	for(int i = 1; i <= m; i++){
		char c;
		cin >> c;
		if( c == 'U' || c == 'T' || c == 'F' ){
			a[i].op = 1;
			if( c == 'U' )
				a[i].x = 0;
			else if( c == 'T' )
				a[i].x = 1;
			else
				a[i].x = 2;
			cin >> a[i].y;
		}
		else{
			cin >> a[i].x >> a[i].y;
			if( c == '+' )
				a[i].op = 2;
			else
				a[i].op = 3;
		}
	}
	dfs(1);
	cout << ans << "\n";
	return;
}

inline void solve2(){
	ans = 0;
	for(int i = 1; i <= n; i++)
		typ[i] = -1;
	for(int i = 1; i <= m; i++){
		char c;
		int x;
		cin >> c >> x;
		if( c == 'U' ){
			if( typ[x] != 0){
				ans++;
				typ[x] = 0;
			}
		}
		else if( typ[x] == 0 ){
			ans--;
			typ[x] = -1;
		}
	}
	cout << ans << "\n";
	return;
}

inline void solve3(){
	ans = 0;
	for(int i = 1; i <= n; i++)
		typ[i] = 0, fa[i] = i, data[i] = i;
	for(int i = 1; i <= m; i++){
		char c;
		cin >> c;
		if( c == 'U' ){
			int x;
			cin >> x;
			typ[x] = 1;
		}
		else{
			int x, y;
			cin >> x >> y;
			data[x] = y;
		}
	}
	for(int i = 1; i <= n; i++){
		int fax = find(i), fay = find(data[i]);
		fa[fax] = fay;
		typ[fax] = typ[fay];
	}
	for(int i = 1; i <= n; i++)
		ans += typ[find(i)];
	cout << ans << "\n";
	return;
}

signed main(){
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	
	int c, T;
	cin >> c >> T;
	while( T-- ){
		cin >> n >> m;
		if( c <= 2 )
			solve1();
		else if( c <= 4 )
			solve2();
		else if( c <= 6 )
			solve3();
	}
	return 0;
}