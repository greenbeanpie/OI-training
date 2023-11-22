#include <bits/stdc++.h>
#define LL long long
#define Fcin \
	ios :: sync_with_stdio(0); \
	cin.tie(0); cout.tie(0)
using namespace std;

// T = 1, F = -1, U = 0;

namespace Oxygen1_2{

	const LL N = 1e2 + 10;
	LL A[N], n, m, tmp[N];
	struct Oper{
		char opt;
		LL x, y;
	} oper[N];
	LL Ans = 1e18;
	void DFS(LL depth){
		if (depth > n){
			for (LL i = 1; i <= n; i ++) { tmp[i] = A[i]; }
			for (LL i = 1; i <= m; i ++){
				LL x = oper[i].x, y = oper[i].y;
				char opt = oper[i].opt;
				if (opt == 'T')
					tmp[x] = 1;
				else if (opt == 'F')
					tmp[x] = -1;
				else if (opt == 'U')
					tmp[x] = 0;
				else if (opt == '+')
					tmp[x] = tmp[y];
				else
					tmp[x] = -tmp[y];
			}
			for (LL i = 1; i <= n; i ++)
				if (tmp[i] != A[i])
					return ;
			LL cnt = 0;
			for (LL i = 1; i <= n; i ++)
				cnt += (A[i] == 0);
			Ans = min(Ans, cnt);
			return ;
		}
		A[depth] = -1;
		DFS(depth + 1);
		A[depth] = 0;
		DFS(depth + 1);
		A[depth] = 1;
		DFS(depth + 1);
	}

	void main(){
		Ans = 1e18;
		cin >> n >> m;
		char opt;
		LL x, y;
		for (LL i = 1; i <= m; i ++){
			cin >> opt >> x;
			y = -1;
			if (opt == '+') 
				cin >> y;
			else if (opt == '-')
				cin >> y;
			oper[i] = {opt, x, y};
		}

		DFS(1);
		cout << Ans << "\n";
		return ;
	}
}

namespace Oxygen3_4{

	const LL N = 1e5 + 10;
	LL A[N];
	struct Oper{
		char opt;
		LL x, y;
	} oper[N];
	LL n, m;
	void main(){
		cin >> n >> m;
		char opt;
		LL x, y;
		for (LL i = 1; i <= n; i ++){
			A[i] = -2;
		}
		for (LL i = 1; i <= m; i ++){
			y = -1;
			cin >> opt >> x;
			oper[i] = {opt, x, y};
			if (opt == '+') {
				cin >> y;
				if (A[y] != -2)
					A[x] = A[y];
			} else if (opt == '-') {
				cin >> y;
				if (A[y] != -2)
					A[x] = -A[y];
			} else if (opt == 'T') {
				A[x] = 1;
			} else if (opt == 'F') {
				A[x] = -1;
			} else {
				A[x] = 0;
			} 
		}
		LL Ans = 0;
		for (LL i = 1; i <= n; i ++)
			Ans += (A[i] == 0);
		cout << Ans << "\n";
		return ;
	}
}

namespace Oxygen7_8{

	const LL N = 1e5 + 10;
	struct Variable {
		LL type, key, id, nt;
	} Var[N];
	LL n, m;

	LL fa[N], cnt[N];
	LL Find(LL x){
		if (fa[x] == x)
			return x;
		return fa[x] = Find(fa[x]);
	}

	void main(){
		cin >> n >> m;
		char opt;
		LL x, y;
		memset(cnt, 0, sizeof cnt);
		for (LL i = 1; i <= n; i ++){
			Var[i] = {0, 0, i, 1};
			fa[i] = i;
		}

		for (LL i = 1; i <= m; i ++){
			cin >> opt >> x;
			if (opt == '+') {
				cin >> y;
				if (Var[y].type == 1)
					Var[x] = {1, Var[y].key, x, 0};
				else
					Var[x] = {0, 0, Var[y].id, Var[y].nt};
			} else if (opt == '-') {
				cin >> y;
				if (Var[y].type == 1)
					Var[x] = {1, -Var[y].key, x, 0};
				else
					Var[x] = {0, 0, Var[y].id, -Var[y].nt};
			} else if (opt == 'T') {
				Var[x] = {1, 1, x, 0};
			} else if (opt == 'F') {
				Var[x] = {1, -1, x, 0};
			} else {
				Var[x] = {1, 0, x, 0};
			} 
		}
		LL Ans = 0;
		for (LL i = 1; i <= n; i ++){
			// cout << Var[i].type << " " << Var[i].key << " " << Var[i].id << " " << Var[i].nt << "\n";
			fa[Find(i)] = Find(Var[i].id);
		}
		for (LL i = 1; i <= n; i ++){
			if (Var[i].type == 0) {
				if (Var[i].id == i){
					if (Var[i].nt != 1){
						Ans += cnt[i];
						// cout << i << " " << cnt[Find(i)] << "\n";
					}
				}
			} else if (Var[i].key == 0){
				// cout << i << " " << cnt[Find(i)]  << "\n";
				Ans += cnt[i];
			}
		}
		cout << Ans << "\n";
		return ;
	}
}

int main(){
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	Fcin;
	LL C, T;
	cin >> C >> T;
	while (T --){
		if (C <= 2)
			Oxygen1_2 :: main();
		else if (C <= 4)
			Oxygen3_4 :: main();
		else
			Oxygen7_8 :: main();
	}

	return 0;
}