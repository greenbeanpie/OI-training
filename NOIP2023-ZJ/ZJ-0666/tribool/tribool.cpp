#include <bits/stdc++.h>
using namespace std;
#define N int(1e5+1)

void file() {
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
}

void desync() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);std::cout.tie(0);
}

int C,T,n,m;
char op;
int val0[N], val[N];
bool flag;

struct option{
	char c; int x, y;
} opt[N];

void init() {
	memset(val0,0,sizeof(val0));
	memset(val,0,sizeof(val));
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> opt[i].c >> opt[i].x;
		if (opt[i].c=='+'||opt[i].c=='-') cin >> opt[i].y;
		else opt[i].y = 0;
	}
}

void change() {
	for (int i = 1; i <= n; i++) val[i] = val0[i];
	for (int i = 1; i <= m; i++) {
		char c = opt[i].c; int x = opt[i].x, y = opt[i].y;
		switch (c) {
			case 'T': {
				val[x] = 1;
				break;
			}
			case 'F': {
				val[x] = 0;
				break;
			}
			case 'U': {
				val[x] = -1;
				break;
			}
			case '+': {
				val[x] = val[y];
				break;
			}
			case '-': {
				val[x] = val[y]==-1?-1:1-val[y];
				break;
			}
		}
	}
}

bool check() {
	for (int i = 1; i <= n; i++) {
		if (val0[i]!=val[i]) return false;
	}
	return true;
}

void make_val0(int cur, int cur_u, int need_u) {
	if (flag) return;
	if (cur==n+1) {
		change();
		if (check()) {
			flag = 1; cout << cur_u << "\n";
		}
		return;
	}
	val0[cur] = 1;
	make_val0(cur+1,cur_u,need_u);
	val0[cur] = 0;
	make_val0(cur+1,cur_u,need_u);
	if (cur_u<need_u) val0[cur] = -1, make_val0(cur+1,cur_u+1, need_u);
}

void solve() {
	init();
	flag = 0;
	make_val0(1,0,n);
}

int main() {
	file();
	desync();
	cin >> C >> T;
	while (T--) solve();
	return 0;
}
