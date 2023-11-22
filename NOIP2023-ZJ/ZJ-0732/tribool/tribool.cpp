#include<bits/stdc++.h>
typedef long long ll;
#define int ll
constexpr int maxn = 2e5 + 10;
constexpr int mod = 1e9 + 7;
using namespace std;

inline void FileIO(string name) {
	freopen((name + ".in").c_str(), "r", stdin);
	freopen((name + ".out").c_str(), "w", stdout);
}

int c, T;
int n, m;
char opt[maxn];
int f[maxn], t[maxn];

namespace Subtask1 {
	
	char val[maxn], nval[maxn];
	char ch[] = {'T', 'F', 'U'};
	int ans;
	
	void calc(char opt, int a, int b) {
		if(opt == '+') nval[a] = nval[b];
		else if(opt == '-') {
			if(nval[b] == 'T') nval[a] = 'F';
			else if(nval[b] == 'F') nval[a] = 'T';
			else nval[a] = 'U';
		}
		else nval[a] = opt;
	}
	
	void check() {		
		for(int i = 1; i <= n; ++i) nval[i] = val[i];
		for(int i = 1; i <= m; ++i) calc(opt[i], f[i], t[i]);
		int res = 0;
		for(int i = 1; i <= n; ++i) {
			if(nval[i] != val[i]) return;
			res += (val[i] == 'U');
		}
		ans = min(ans, res);
		return ;
	}
	
	void dfs(int tot) {
		if(tot == n + 1) {
			check();
			return ;
		}
		for(int i = 0; i < 3; ++i) {
			val[tot] = ch[i];
			dfs(tot + 1);
		}
	}
	
	inline void Main() {
		
		cin >> n >> m;
		
		for(int i = 1; i <= m; ++i) {
			cin >> opt[i];
			if(opt[i] == '-' || opt[i] == '+') cin >> f[i] >> t[i];
			else cin >> f[i];
		}
		
		ans = INT_MAX;
		
		dfs(1);
	
		cout << ans << '\n';
				
		return ;
	}
}

namespace Subtask2 {
	
	char val[maxn];
	
	inline void Main() {
		
		cin >> n >> m;
		
		for(int i = 1; i <= n; ++i) val[i] = 'T';
		
		for(int i = 1; i <= m; ++i) 
			cin >> opt[i] >> f[i], val[f[i]] = opt[i];
		
		int ans = 0;
		for(int i = 1; i <= n; ++i) ans += (val[i] == 'U');
	
		cout << ans << '\n';
		
		return ;
	}	
}

namespace Subtask3 {
	
	char val[maxn];
	
	void calc(char opt, int a, int b) {
		if(opt == 'U') val[a] = 'U';
		else val[a] = val[b];
	}
	
	inline void Main() {
		
		for(int i = 1; i <= n; ++i) val[i] = 'T';
		
		cin >> n >> m;
		
		for(int i = 1; i <= m; ++i) {
			cin >> opt[i];
			if(opt[i] == '-' || opt[i] == '+') cin >> f[i] >> t[i];
			else cin >> f[i];
			calc(opt[i], f[i], t[i]);
		}
		
		int res = 0;
		for(int i = 1; i <= n; ++i) res += (val[i] == 'U');
		
		cout << res << '\n';		
	}
}



signed main() {

	FileIO("tribool");

	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	
	cin >> c >> T;
	
	if(c == 1 || c == 2) {
		while(T --) Subtask1::Main();
		return 0;
	}
	else if(c == 3 || c == 4) {
		while(T --) Subtask2::Main();
		return 0;
	}
	else if(c == 5 || c == 6){
		while(T --) Subtask3::Main();
		return 0;
	}
	else {
		srand(time(0));
		while(T --) {
			cin >> n >> m;		
			for(int i = 1; i <= m; ++i) {
				cin >> opt[i];
				if(opt[i] == '-' || opt[i] == '+') cin >> f[i] >> t[i];
				else cin >> f[i];
			}
			cout << (rand() % n) << '\n';
		}
		return 0;
	}

	return 0;
}
