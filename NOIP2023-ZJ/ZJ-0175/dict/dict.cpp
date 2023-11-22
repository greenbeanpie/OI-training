#include<bits/stdc++.h>
#define rep(i, l, r) for(int i(l), i##end(r); i <= i##end; ++ i)
#define per(i, r, l) for(int i(r), i##end(l); i >= i##end; -- i)
#define ci const int
#define mem(a, var) memset(a, var, sizeof(a))
using namespace std;

namespace SkyMaths {

template <class node> void rd(node &x) {
    x = 0; bool f = 0; char ch = getchar();
    while(ch < '0' || ch > '9') f ^= ch == '-', ch = getchar();
    while(ch <= '9' && ch >= '0') x = x * 10 + ch - '0', ch = getchar();
    if(f) x = -x;
}

template <class Tx, class ...Ty> void rd(Tx &x, Ty &... y) {
    rd(x);
    rd(y...);
}

bool _st;

ci N = 3009;

int n, m;
char str[N][N];

int buc[26];

string st0[N], st1[N];

multiset<string> st;

int solve() {
    rd(n, m);
    if(n == 1) {
        printf("1\n");
        return 0;
    }
    rep(i, 1, n) {
    	scanf(" %s", str[i] + 1);
		mem(buc, 0);
		rep(j, 1, m) {
			++ buc[str[i][j] - 'a'];
		}
		per(j, 25, 0) {
			rep(k, 1, buc[j]) {
				st0[i] += char(j + 'a');
			}
		}
		rep(j, 0, 25) {
			rep(k, 1, buc[j]) {
				st1[i] += char(j + 'a');
			}
		}
		st.insert(st0[i]);
	}
	rep(i, 1, n) {
    	st.erase(st.find(st0[i]));
    	if(st.upper_bound(st1[i]) != st.begin()) {
    		printf("0");
		}
		else {
			printf("1");
		}
    	st.insert(st0[i]);
	}
	puts("");
	return 0;
}

bool _ed;

}

int main() {
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
    SkyMaths :: solve();
    return 0;
}

//    rep(i, 1, n) {
//    	mem(buc, 0);
//    	char ch;
//    	rep(j, 1, m) {
//    		scanf(" %c", &ch);
//    		++ buc[ch - 'a'];
//		}
//		int p = 0;
//		per(j, 25, 0) {
//			rep(k, 1, buc[j]) {
//				st0[i][++ p] = j + 'a';
//			}
//		}
//		p = 0;
//		rep(j, 0, 25) {
//			rep(k, 1, buc[j]) {
//				st1[i][++ p] = j + 'a';
//			}
//		}
//		o[i] = i;
//	}
//	sort(o + 1, o + n + 1);
//	return 0;
//	qsort();
//    rep(i, 1, n) {
//    	if(o[1] == i) ans[i] = 1;
//    	else {
//    		if(cmp(st1[i], st0[o[1]])) {
//    			ans[i] = 1;
//			}
//			else ans[i] = 0;
//		}
//	}
//	rep(i, 1, n) printf("%d", ans[i]);
//	printf("\n");
//    return 0;
    
//void qsort(int i, int opt = 0) {
//	mem(buc, 0);
//	rep(j, 1, m) {
//		++ buc[str[i][j] - 'a'];
//	}
//	int p = 0;
//	if(opt == 0) {
//		per(j, 25, 0) {
//			rep(k, 1, buc[j]) {
//				str[i][++ p] = j + 'a';
//			}
//		}
//	}
//	else {
//		rep(j, 0, 25) {
//			rep(k, 1, buc[j]) {
//				str[i][++ p] = j + 'a';
//			}
//		}
//	}
//}

//struct Trie {
//	int cnt;
//	int sz[N * N];
//	map<int, int> ch[N * N];
////	int ch[N * N][26];
//	void insert(int &u, int i, char *str) {
//		if(!u) u = ++ cnt;
//		++ sz[u];
//		if(i > m) return;
//		insert(ch[u][str[i] - 'a'], i + 1, str);
//	}
//	void erase(int &u, int i, char *str) {
//		-- sz[u];
//		if(i > m) return;
//		erase(ch[u][str[i] - 'a'], i + 1, str);
//	}
//	int query(int u, int i, char *str) {
//		if(!u) return 0;
//		if(i > m) return sz[u];
//		int res = 0;
//		rep(j, 0, str[i] - 'a' - 1) {
//			res += sz[ch[u][i]];
//		}
//		return res + query(ch[u][str[i] - 'a'], i + 1, str);
//	}
//} trie;

//    rep(i, 1, n) {
//    	scanf(" %s", str[i] + 1);
//    	qsort(i);
//    	trie.insert(rt, 1, str[i]);
//	}
//	rep(i, 1, n) {
//		trie.erase(rt, 1, str[i]);
//		qsort(i, 1);
//		if(trie.query(rt, 1, str[i])) printf("0");
//		else printf("1");
//		qsort(i);
//		trie.insert(rt, 1, str[i]);
//	}
