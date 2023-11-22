#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 10;
const int INF = 1e9 + 7;

struct node{
	char op;
	int u, v;
};

int n, q, a[N], _a[N], ans = INF;//_a is the copy of a;
node opt[N];

void close_flow(){
	ios :: sync_with_stdio (false);
	cin.tie(0);
	cout.tie(0);
	return;
}

void revise(){
	for(int i = 1; i <= q; ++i){
		char op = opt[i].op;
		int u = opt[i].u, v = opt[i].v;
		switch(op){
			case 'T': {
				a[u] = 1;
				break;
			}
			case 'F': {
				a[u] = -1;
				break;
			}
			case 'U':{
				a[u] = 0;
				break;
			}
			case '+':{
				a[u] = a[v];
				break;
			}
			case '-':{
				a[u] = a[v] * -1;
				break;
			}
		}
	}
}

bool check(){
	revise();
	for(int i = 1; i <= n; ++i){
		if(a[i] != _a[i])
			return false;
	}
	return true;
}

void dfs(int pos, int cnt){
	if(pos > n){
		if(check()){
			ans = min(ans, cnt);
			
//			for(int i = 1; i <= n; ++i){
//				cout << a[i] << " ";
//			}
//			cout << endl;
//			for(int i = 1; i <= n; ++i){
//				cout << _a[i] << " ";
//			}
//			cout << endl << cnt << endl << endl;
			
		}
		for(int i = 1; i <= n; ++i){
			a[i] = _a[i];
		}
		return;
	}
	for(int i = -1; i <= 1; ++i){
		a[pos] = _a[pos] = i;
		dfs(pos + 1, cnt + (i == 0));
	}
	return;
}

signed main(){
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	close_flow();
	int GG, t;
	cin >> GG >> t;
	if(GG == 1 || GG == 2){//more 20 point!!!
		while(t--){
			cin >> n >> q;
			ans = INF;
			for(int i = 1; i <= q; ++i){
				cin >> opt[i].op;
				if(opt[i].op == '+' || opt[i].op == '-')
					cin >> opt[i].u >> opt[i].v;
				else
					cin >> opt[i].u;
			}
			dfs(1, 0);
			cout << ans << endl;
//			cout << "---------------------" <<endl;
		}
	}
	else if(GG == 3 || GG == 4){//more 20 point!!!
		while(t--){
			cin >> n >> q;
			ans = 0;
			memset(a, 0x3f, sizeof(a));
			for(int i = 1; i <= q; ++i){
				cin >> opt[i].op;
				if(opt[i].op == '+' || opt[i].op == '-')
					cin >> opt[i].u >> opt[i].v;
				else
					cin >> opt[i].u;
			}
			revise();
			for(int i = 1; i <= n; ++i){
				if(a[i] == 0)
					++ans;
//				cout << a[i] << " ";
			}
			cout << ans << endl;
		}
	}
	return 0;
}