#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mkp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define ls(x) ((x)<<1)
#define rs(x) ((x)<<1|1)
void rd(int &x) {
	x = 0; int tp = 0;
	char c = getchar();
	while(c < '0' || c > '9') {
		if(c == '-') tp = 1;
		c = getchar();
	}
	while(c >= '0' && c <= '9') {
		x = x * 10 + c - '0';
		c = getchar();
	}
	if(tp) x = -x;
}
const int N = 1e5 + 10;
int n, m, x[N], y[N], lst[N], ans, fa[N];
char bg[N], ed[N];
char v[N][5];
inline char qf(char emm) {
	if(emm == 'T') return 'F';
	if(emm == 'F') return 'T';
	return 'U';
}
bool check() {
	for(int i = 1; i <= n; i++)
		ed[i] = bg[i];
	for(int i = 1; i <= m; i++) {
		if(v[i][0] == '+') {
			ed[x[i]] = ed[y[i]];
		} else if(v[i][0] == '-') {
			ed[x[i]] = qf(ed[y[i]]);
		} else {
			ed[x[i]] = v[i][0];
		}
	}
	for(int i = 1; i <= n; i++)
		if(ed[i] != bg[i]) return 0;
	return 1;
}
void dfs(int nw, int gsu) {
	if(nw == n + 1) {
		if(check()) ans = min(ans, gsu);
		return;
	}
	bg[nw] = 'T'; dfs(nw + 1, gsu);
	bg[nw] = 'F'; dfs(nw + 1, gsu);
	bg[nw] = 'U'; dfs(nw + 1, gsu + 1);
}
int find(int x) {
//	cout<<x<<" "<<fa[x]<<endl;
	return (x == fa[x]) ? x : fa[x] = find(fa[x]);
}
void merge(int x, int y) {
	x = find(x); y = find(y);
	if(x != y) fa[x] = y;
}
int main() {
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	int csd, T;
	rd(csd); rd(T);
	if(csd <= 2) {
		while(T--) {
			rd(n); rd(m);
			ans = n + 1;
			for(int i = 1; i <= m; i++) {
				scanf("%s", v[i]);
				if(v[i][0] == '+' || v[i][0] == '-') {
					rd(x[i]); rd(y[i]);
				} else {
					rd(x[i]);
				}
			}
			dfs(1, 0);
			printf("%d\n", ans);
		}
	} else if(csd == 3 || csd == 4) {
		while(T--) {
			rd(n); rd(m);
			for(int i = 1; i<= n; i++)
				bg[i] = '*';
			for(int i = 1; i <= m; i++) {
				scanf("%s", v[i]);
				if(v[i][0] == '+' || v[i][0] == '-') {
					rd(x[i]); rd(y[i]);
				} else {
					rd(x[i]);
					bg[x[i]] = v[i][0];
				}
			}
			ans = 0;
			for(int i = 1; i <= n; i++)
				if(bg[i] == 'U') ans++;
			printf("%d\n", ans);
		}
	} else if(csd == 5 || csd == 6) {
		while(T--) {
			rd(n); rd(m);
			for(int i = 1; i <= m; i++) {
				scanf("%s", v[i]);
				if(v[i][0] == '+' || v[i][0] == '-') {
					rd(x[i]); rd(y[i]);
				} else {
					rd(x[i]);
				}
			}
			//n+1个点！！ 树顶从未被赋值 
			//成环？
			for(int i = 1; i <= n + 1; i++)
				fa[i] = i;
			for(int i = 1; i <= m; i++) {
				if(v[i][0] == 'U') {
					fa[x[i]] = n + 1;
				} else {
					fa[x[i]] = find(y[i]);
				} 
			}
			ans = 0;
			for(int i = 1; i <= n; i++) {
		//	cout<<"devin's watching"<<endl;
				fa[i] = find(i);
				if(fa[i] == n + 1) ans++;
			} 
			printf("%d\n", ans);
		}
	}
	return 0;
}

