#include <bits/stdc++.h>
#define rep(i, l, r) for(int i=l, _=r; i<=_; ++i)
using namespace std;
typedef long long ll;
const int mN=14+3;
int n, m, q;

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