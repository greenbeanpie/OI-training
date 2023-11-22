#include <bits/stdc++.h>

using namespace std;

#define int long long

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

const int MAXN = (1e3 + 55);

int c, T, n, m, ans, k, d;
int f[MAXN][MAXN], x[MAXN], y[MAXN], v[MAXN];
vector < int > G[MAXN];

inline void Prep(){
	for (int i = 0; i <= m + 5; ++ i)
		x[i] = v[i] = y[i] = 0;
	for (int i = 0; i <= n + 5; ++ i){
		G[i].clear();
		for (int j = 0; j <= n + 5; ++ j)
			f[i][j] = -999999999999;
		f[0][0] = 0;
	}
	ans = 0;
	n = m = k = d = 0;
	return;
}

namespace subez{
	inline void work(){
		while (T --){
			int n = read(), m = read(), k = read(), d = read();
			int ans = 0;
			for (int i = 1; i <= m; ++ i){
				int xx = read(), yy = read(), vv = read();
				if (yy > k || xx - yy + 1 < 1)
					continue;
				int tmp = vv - d * yy;
				if (tmp > 0)
					ans += tmp;
			}
			writeln(ans);
		}
		return;
	}
}

signed main(){
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	c = read(), T = read();
	
	if (c == 17 || c == 18){
		subez::work();
		return 0;
	}
	
	while (T --){
		Prep();
		n = read(), m = read(), k = read(), d = read();
		for (int i = 1; i <= m; ++ i){
			x[i] = read(), y[i] = read(), v[i] = read();
			G[x[i]].push_back(i);
		}
		for (int i = 1; i <= n; ++ i){
			
			for (int j = 0; j <= min(i - 1, k); ++ j)
				f[i][0] = max(f[i][0], f[i - 1][j]);
				
			for (int j = 1; j <= min(i, k); ++ j)
				f[i][j] = f[i - 1][j - 1] - d;
//			
//			for (int kk = 0; kk < G[i].size(); ++ kk){
//				int to = G[i][kk];
//				for (int j = y[to]; j <= min(i, k); ++ j)
//					f[i][j] = max(f[i][j], f[i - y[to] + 1][j - y[to]] - d * y[to] + v[to]);
//			}

			for (int j = 1; j <= min(i, k); ++ j){
				if (i - j == 0)
					continue;
				int tmp = f[i - j][0] - d * j;
				f[i][j] = max(f[i][j], tmp);
				for (int kk = 0; kk < G[i].size(); ++ kk){
					int to = G[i][kk];
//					cout << to << " " << i << " " << j << " " << y[to] << "dsfsdfsdf\n ";
					if (y[to] <= j)
						tmp += v[to];
//					puts("");
				}
//				cout << i << " " << j << " ||||" << tmp << " " << f[i - j][0] - d * j << endl;
				f[i][j] = max(f[i][j], tmp);
			}
		}
//		for (int i = 1; i <= n; ++ i){
//			for (int j = 0; j <= k; ++ j)
//				writesp(f[i][j]);
//			puts("");
//		}
		for (int i = 0; i <= k; ++ i)
			ans = max(ans, f[n][i]);
		writeln(ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
Still have some time for writing?
That's good.
But this time,
Even ymj won't see this.
That's a little pity right?
I must say this one more time
If U find this code accidentally,
Do not put it in your blog for entertainment.
I'm not very happy.
*/
