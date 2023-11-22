#include <bits/stdc++.h>
#define rep(i, l, r) for(int i=l, _=r; i<=_; ++i)
using namespace std;
typedef long long ll;
const int mN=14+3;
int n, m;
char opt[mN];
int pos[mN][2];

int a[mN], b[mN], ans;
void dfs(int stp) {
	if(stp>n) {
		memcpy(b, a, sizeof a);
		rep(__, 1, m) {
			char opt=::opt[__];
			int x=pos[__][0], y=pos[__][1];
			if(opt=='+' || opt=='-') {
				b[x]=opt=='+'? b[y]: -b[y];
			} else {
				b[x]=opt=='U'? 0: opt=='T'? 1: -1;
			}
		}
		int nans=0;
		rep(i, 1, n) {
			if(a[i]!=b[i]) {
				return;
			}
			nans+=!a[i];
		}
		if(nans<ans) ans=nans;
		return;
	}
	rep(i, -1, 1) {
		a[stp]=i;
		dfs(stp+1);
	}
}

int main() {

	int T_T;
	scanf("%*d%d", &T_T);
	while(T_T--) {
		ans=114514;

		scanf("%d%d", &n, &m);
		rep(i, 1, m) {
			scanf("\n%c%d", opt+i, pos[i]);
			if(opt[i]=='+' || opt[i]=='-') {
				scanf("%d", pos[i]+1);
			}
		}
		dfs(1);
		if(ans>n) {
			puts("-1");
		} else {
			printf("%d\n", ans);
		}
	}
	return 0;
}
/*
- no solution
*/