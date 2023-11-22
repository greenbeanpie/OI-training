#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<bitset>
#include<cstdio>
#include<queue>
#include<stack>
#include<cmath>
#include<set>
#include<map>

//#define int long long

using namespace std;

inline int read() {
	char c = 0;
	int r = 0, f = 1;
	while(!isdigit(c)) if((c = getchar()) == '-') f = -f;
	while(isdigit(c)) r = (r << 3) + (r << 1) + (c ^ '0'), c = getchar();
	return r * f;
}
bool bg;

const int N = 1e5 + 5;
int TP;

int fa[N << 1];//1~n:cur n+1~2n:y 2n+1~3:TFU
bool ty[N << 1];//0t1e
inline int find(int x) {
	if(x == fa[x]) return x;
	int t = find(fa[x]);
	ty[x] ^= ty[fa[x]];
	return fa[x] = t;
}

inline void insert(int x, int y, bool mode) {//0t1e
	int fy = find(y), t = ty[y];
	fa[x] = fy, ty[x] = t ^ mode;
}//x->y

int n, q;

inline void solve() {
	static char op[3];
	
	n = read(), q = read();
	for(int i = 1;i <= n;i++) fa[i] = i + n;
	for(int i = n + 1;i <= 2 * n;i++) fa[i] = i;
	fa[2 * n + 1] = 2 * n + 1, fa[2 * n + 2] = 2 * n + 2, fa[2 * n + 3] = 2 * n + 3;
	memset(ty, 0, sizeof ty);
	
	for(int i = 1, x, y;i <= q;i++) {
		scanf("%s", op);
		if(op[0] == '+') {
			x = read(), y = read();
			insert(x, y, 0);
		}
		else if(op[0] == '-') {
			x = read(), y = read();
			insert(x, y, 1);
		}
		else if(op[0] == 'T') insert(read(), 2 * n + 1, 0);
		else if(op[0] == 'F') insert(read(), 2 * n + 2, 0);
		else if(op[0] == 'U') insert(read(), 2 * n + 3, 0);
	}
	
	for(int i = 1;i <= n;i++) if(find(i) != i + n) fa[i + n] = i;
	for(int i = 1;i <= n;i++) if(find(i) == find(i + n) && ty[i] != ty[i + n]) fa[find(i)] = 2 * n + 3;
	int ans = 0;
	for(int i = 1;i <= n;i++) if(find(i) == 2 * n + 3) ans++;
	printf("%d\n", ans);
}

bool ed;
signed main() {
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	
	TP = read();
	for(int CAS = read();CAS--;) solve();
	return 0;
}//made by luogu:734497 star_of_cloud
