#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int c, t;
int n, m;
int op[N], u[N], v[N], val[N];

int check(int id){
	int chu[15], a[15];
	for (int i = 1;i <= n; ++ i){
		chu[i] = id % 3;
		id /= 3;a[i] = chu[i];
	}
	for (int i = 1;i <= m; ++ i){
		if (op[i] == 1) a[u[i]] = 1;
		if (op[i] == 2) a[u[i]] = 2;
		if (op[i] == 3) a[u[i]] = 0;
		if (op[i] == 4) a[u[i]] = a[v[i]];
		if (op[i] == 5) a[u[i]] = (3 - a[v[i]]) % 3;
	}int tot = 0;
	for (int i = 1;i <= n; ++ i){
		if (chu[i]!=a[i]) return 10;
		if (!a[i]) tot ++;
	}return tot;
}

int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	scanf("%d%d", &c, &t);
	while (t --){
		scanf("%d%d", &n, &m);
		for (int i = 1;i <= m; ++ i){
			char opt[2];int a, b;
			scanf("%s%d", opt, &a);
			if (opt[0] == 'T'){
				op[i] = 1;
				u[i] = a;
			}
			if (opt[0] == 'F'){
				op[i] = 2;
				u[i] = a;
			}
			if (opt[0] == 'U'){
				op[i] = 3;
				u[i] = a;
			}
			if (opt[0] == '+'){
				op[i] = 4;
				scanf("%d", &b);
				u[i] = a, v[i] = b;
			}
			if (opt[0] == '-'){
				op[i] = 5;
				scanf("%d", &b);
				u[i] = a, v[i] = b;
			}
		}
		if (c <= 2){
			int ans = 10;
			for (int i = 0;i < pow(3, n); ++ i)
				ans = min(ans, check(i));
			printf("%d\n", ans);
		}
		if (c == 3 || c == 4){
			for (int i = 1;i <= n; ++ i)
				val[i] = 0;
			for (int i = 1;i <= m; ++ i)
				val[u[i]] = op[i];
			int tot = 0;
			for (int i = 1;i <= n; ++ i)
				if (val[i] == 3) tot ++;
			printf("%d\n", tot); 
		}
		if (c == 5 || c == 6){
			for (int i = 1;i <= n; ++ i)
				val[i] = 0;
			for (int i = 1;i <= m; ++ i){
				if (op[i] == 3) val[u[i]] = 3;
				if (op[i] == 4) val[u[i]] = val[v[i]];
			}int tot = 0;
			for (int i = 1;i <= n; ++ i)
				if (val[i] == 3) tot ++;
			int sum = 0;
			while (sum != tot){
				tot = sum;
				for (int i = 1;i <= m; ++ i){
					if (op[i] == 3) val[u[i]] = 3;
					if (op[i] == 4) val[u[i]] = val[v[i]];
				}sum = 0;
				for (int i = 1;i <= n; ++ i)
					if (val[i] == 3) sum ++;
			}
			printf("%d\n", tot);
 		}
	}
	return 0;
}