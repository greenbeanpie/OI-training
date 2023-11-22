#include <bits/stdc++.h>

using namespace std;

inline int read(){
	int x = 0, f = 1;
	char ch = getchar();
	while (! isdigit(ch)){
		if (ch == '-')
			f = - f;
		ch = getchar();
	}
	while (isdigit(ch)){
		x = x * 10 + ch - 48;
		ch = getchar();
	}
	return x * f;
}

void write(int x){
	if (x < 0){
		putchar('-');
		write(- x);
		return;
	}
	if (x >= 10)
		write(x / 10);
	putchar(x % 10 + 48);
	return;
}

inline void writesp(int x){
	write(x);
	putchar(' ');
	return;
}

inline void writeln(int x){
	write(x);
	puts("");
	return;
}

int c, T;
char ttttt;

namespace subForce{
	
	int n, m, ans;
	int a[30], x[30], y[30], tmp[30];
	char op[30];
	
	inline void prep(){
		for (int i = 0; i <= n + 5; ++ i){
			a[i] = -1;
			tmp[i] = -1;
			op[i] = ttttt;
			x[i] = 0;
			y[i] = 0;
		}
		ans = n + 3;
		return;
	}
	
	inline int NOt(int x){
		if (x == 1)
			return 0;
		if (x == 2)
			return 2;
		else
			return 1;
	}
	
	inline void pd(){
		int tot = 0;
		for (int i = 1; i <= n; ++ i){
			tmp[i] = a[i];
			if (a[i] == 2)
				tot ++;
		}
		for (int i = 1; i <= m; ++ i){
			if (op[i] == '+')
				tmp[x[i]] = tmp[y[i]];
			if (op[i] == '-')
				tmp[x[i]] = NOt(tmp[y[i]]);
			if (op[i] == 'T')
				tmp[x[i]] = 1;
			if (op[i] == 'F')
				tmp[x[i]] = 0;
			if (op[i] == 'U')
				tmp[x[i]] = 2;
		}
		for (int i = 1; i <= n; ++ i)
			if (tmp[i] != a[i])
				return;
//		for (int i = 1; i <= n; ++ i)
//			writesp(a[i]);
//		puts("");
		ans = min(ans, tot);
		return;
	}
	
	void dfs(int x){
		if (x >= n){
			pd();
			return;
		}
		x ++;
		a[x] = 0;
		dfs(x);
		a[x] = 1;
		dfs(x);
		a[x] = 2;
		dfs(x);
		a[x] = -1;
		return;
	}
	
	inline void work(){
		while (T --){
			prep();
			cin >> n >> m;
			for (int i = 1; i <= n; ++ i){
				cin >> op[i];
				while (op[i] != '-' && op[i] != '+' && op[i] != 'T' && op[i] != 'F' && op[i] != 'U')
					cin >> op[i];
				if (op[i] == '+' || op[i] == '-')
					cin >> x[i] >> y[i];
				else	
					cin >> x[i];
			}
//			puts("___________________");
//			for (int i = 1; i <= n; ++ i)
//				cout << op[i] << " | " << x[i] << " | " << y[i] << endl;
			dfs(0);
			writeln(ans);
		}
	}
}

namespace subNoJia{
	
	const int MAXN = (1e5 + 55);
	
	int n, m, ans;
	int a[MAXN];
	
	inline void prep(){
		for (int i = 0; i <= n + 5; ++ i)
			a[i] = 0;
		ans = 0;
	}
	
	inline void work(){
		while (T --){
			prep();
			n = read(), m = read();
			for (int i = 1; i <= m; ++ i){
				char op = getchar();
				int x = read();
				while (op != '-' && op != '+' && op != 'T' && op != 'F' && op != 'U')
					op = getchar();
				if (op == 'U')
					a[x] = 2;
				else
					a[x] = 0;
			}
			for (int i = 1; i <= n; ++ i)
				if (a[i] == 2)
					ans ++;
			writeln(ans);
		}
		return;
	}
}

namespace subNoBol{
	
	const int MAXN = (1e5 + 55);
	
	int n, m, ans;
	int a[MAXN];
	
	inline void prep(){
		for (int i = 0; i <= n + 5; ++ i)
			a[i] = 0;
		ans = 0;
		return;
	}
	
	inline void work(){
		while (T --){
			prep();
			n = read(), m = read();
			for (int i = 1; i <= m; ++ i){
				char op = getchar();
				int x = read();
				while (op != '-' && op != '+' && op != 'T' && op != 'F' && op != 'U')
					op = getchar();
				if (op == 'U')
					a[x] = 2;
				else{
					int y = read();
					a[x] = a[y];
				}
			}
			for (int i = 1; i <= n; ++ i)
				if (a[i] == 2)
					ans ++;
			writeln(ans);
		}
		return;
	}
}

signed main(){
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);

// gei ce shi dian bian hao de chu ti ren dou shi da hao ren !111
	c = read(), T = read();
	if (c == 1 || c == 2){
		subForce :: work();
		return 0;
	}
	if (c == 3 || c == 4){
		subNoJia :: work();
		return 0;
	}
	if (c == 5 || c == 6){
		subNoBol :: work();
		return 0;
	}
	puts("Good Luck & Have Fun !");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
