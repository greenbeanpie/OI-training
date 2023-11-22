//Goodbye OI, I will miss you
//龙潜月十五
//2023.11.18
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
int c, t, n, m, x[N], tmp[N], ans;
struct operation{
	char v;
	int i, j;
}op[N];

void init() {
	cin >> n >> m;
	for(int i = 1; i <= m; ++i) {
		cin >> op[i].v >> op[i].i;
		if(op[i].v == '+' || op[i].v == '-')
			cin >> op[i].j;
	}
	for(int i = 1; i <= n; ++i)
		x[i] = 0;
}

void dfs(int now, int u) {
	if(u >= ans)
		return;
	if(now > n) {
		for(int i = 1; i <= n; ++i)
			tmp[i] = x[i];
		for(int i = 1; i <= m; ++i)
			if(op[i].v == 'T')
				tmp[op[i].i] = 1;
			else if(op[i].v == 'F')
				tmp[op[i].i] = 2;
			else if(op[i].v == 'U')
				tmp[op[i].i] = 3;
			else if(op[i].v == '+')
				tmp[op[i].i] = tmp[op[i].j];
			else {
				if(tmp[op[i].j] == 1)
					tmp[op[i].i] = 2;
				else if(tmp[op[i].j] == 2)
					tmp[op[i].i] = 1;
				else	
					tmp[op[i].i] = 3;	
			}
		bool flag = true;
		for(int i = 1; i <= n; ++i)
			if(tmp[i] != x[i]) {
				flag = false;
				break;
			}
		if(flag)
			ans = min(ans, u);
		return;
	}
	for(int i = 1; i <= 3; ++i)
		x[now] = i, dfs(now + 1, u + (i == 3));
	return;
}

int main() {
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> c >> t;
	if(c== 1 || c == 2) {
		while(t--) {
			init();
			ans = 1e5 + 1;
			dfs(1, 0);
			cout << ans << '\n';
		}
	}	
	else if(c == 3 || c == 4) {
		while(t--) {
			init();
			ans = 0;
			for(int i = 1; i <= m; ++i)
				if(op[i].v == 'T')
					x[op[i].i] = 1;
				else if(op[i].v == 'F')
					x[op[i].i] = 2;
				else
					x[op[i].i] = 3;
			for(int i = 1; i <= n; ++i)
				ans += (x[i] == 3);	
			cout << ans << '\n';	
		}
	}
	return 0;
}