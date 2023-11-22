#include<cstdio>
#include<algorithm>
using namespace std;

const int MAXN = 3005;

int n, m, cnt;
char mn[MAXN], t[MAXN];
char s[MAXN][MAXN];

inline void Init() {
	for (int i = 1; i <= m; ++ i)
		mn[i] = 'z';
	for (int i = 1; i <= n; ++ i) {
		bool fg = true;
		for (int j = 1; j <= m; ++ j) {
			if (s[i][j] < mn[j]) {
				cnt = 0;
				for (int k = 1; k <= m; ++ k)
					mn[k] = s[i][k];
			}
			if (s[i][j] != mn[j]) {
				fg = false;
				break;
			}
		}
		if (fg) ++ cnt;
	}
}

int ct[35];
inline void Opsort(int x) {
	for (int i = 0; i <= 30; ++ i)
		ct[i] = 0;
	for (int i = 1; i <= m; ++ i)
		++ ct[s[x][i] - 'a'];
	for (int i = 28, j = 0; i >= 0; -- i) {
		for (int k = 1; k <= ct[i]; ++ k)
			s[x][++ j] = 'a' + i;
	}
}
inline void Tsort() {
	for (int i = 0; i <= 30; ++ i)
		ct[i] = 0;
	for (int i = 1; i <= m; ++ i)
		++ ct[t[i] - 'a'];
	for (int i = 0, j = 0; i <= 28; ++ i) {
		for (int k = 1; k <= ct[i]; ++ k)
			t[++ j] = 'a' + i;
	}
}


int main()
{
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	
	scanf ("%d%d", &n, &m);
	for (int i = 1; i <= n; ++ i)
		scanf ("%s", s[i] + 1), 
		Opsort(i);
	Init();	
	for (int i = 1; i <= n; ++ i) {
		for (int j = 1; j <= m; ++ j)
			t[j] = s[i][j];
		Tsort();
		int tmp = 1;
		for (int j = 1; j <= m; ++ j)
			if (t[j] != s[i][j])
				tmp = 0;
		bool fg = true, sm = true;
		for (int j = 1; j <= m; ++ j) {
			if (mn[j] < t[j])
				fg = false;
			if (t[j] != mn[j]) {
				sm = false;
				break;
			}
		}
		if (sm && cnt > tmp) fg = false;
		if (fg) printf("1");
		else printf("0");
	}
	
	return puts(""), 0;
}