#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

bool Mbe;
int n, m;
int c, res;
char op[N];
int L[N], R[N];
int path[N];
int S[N];	
int s[N][3];
int p[N];
vector<int> w[N];
bool Med;

void dfs(int u)
{
	if (u == n + 1)
	{
		for (int i = 1; i <= n; i ++ ) S[i] = path[i];
		for (int i = 1; i <= m; i ++ )
		{
			if (op[i] == '+') S[L[i]] = S[R[i]];
			else if (op[i] == '-')
			{
				if (S[R[i]] == 1) S[L[i]] = 2;
				else if (S[R[i]] == 2) S[L[i]] = 1;
				else S[L[i]] = 3;
			}
			else
			{
				if (op[i] == 'U') S[L[i]] = 3;
				if (op[i] == 'T') S[L[i]] = 1;
				if (op[i] == 'F') S[L[i]] = 2;
			}
		}
		bool flag = 1;
		for (int i = 1; i <= n; i ++ ) if (S[i] != path[i]) flag = 0;
		if (flag)
		{
			int cnt = 0;
			for (int i = 1; i <= n; i ++ ) if (path[i] == 3) cnt ++ ;
			res = min(res, cnt);
		}
		return ;
	}
	
	path[u] = -1;
	for (int i = 1; i <= 3; i ++ )
	{
		path[u] = i;
		dfs(u + 1);	
	}	
}	

void work_1()
{
	for (int i = 1; i <= m; i ++ )
	{
		scanf(" %c", &op[i]);
		if (op[i] == '+' || op[i] == '-') scanf("%d%d", &L[i], &R[i]);
		else scanf("%d", &L[i]);
	}
	res = n;
	dfs(1);	
	printf("%d\n", res);
}	

void work_2()
{
	while (m -- )
	{
		char v; int x;
		scanf(" %c%d", &v, &x);
		if (v == 'U') path[x] = 3;
		else if (v == 'T') path[x] = 1;
		else path[x] = 2;
	}
	res = 0;
	for (int i = 1; i <= n; i ++ )
		if (path[i] == 3) res ++ ;
	printf("%d\n", res);
}

int rev(int x)
{
	if (x == 0) return 1;
	if (x == 1) return 0;
	return 2;
}

int find(int x)
{
	if (p[x] != x) p[x] = find(p[x]);
	return p[x];
}

void work_4()
{
	for (int i = 1; i <= n; i ++ ) 
		for (int j = 0; j < 3; j ++ ) s[i][j] = j;
	for (int i = 1; i <= n; i ++ ) p[i] = i;
	while (m -- )
	{
		char v; int x, y;
		scanf(" %c%d%d", &v, &x, &y);
		if (v == '+')
		{
			for (int i = 0; i < 3; i ++ ) s[x][i] = s[y][i];
			if (find(x) != find(y)) p[x] = p[y];
		}
		else 
		{
			for (int i = 0; i < 3; i ++ ) s[x][i] = rev(s[y][i]);
			if (find(x) != find(y)) p[x] = p[y];
		}
	}
	
	for (int i = 1; i <= n; i ++ ) w[i].clear();
	for (int i = 1; i <= n; i ++ ) w[find(i)].push_back(i);
	int res = 0;
	for (int i = 1; i <= n; i ++ )
		if (p[i] == i)
		{
			int cnt = n;
			for (int j = 0; j < 3; j ++ )
			{
				int ct = 0;
				for (int v : w[i])
					ct += (s[v][j] == 2);
				cnt = min(cnt, ct);
			}
			res += cnt;
		}
	printf("%d\n", res);
}

int main()
{
	freopen("tribool.in", "r", stdin); freopen("tribool.out", "w", stdout);
	int T; scanf("%d%d", &c, &T);
	while (T -- )
	{
		scanf("%d%d", &n, &m);
		fill(path + 1, path + 1 + n, -1);
		if (c <= 2) work_1();
		else if (c >= 3 && c <= 4) work_2();
		else if (c >= 7 && c <= 8) work_4();
		else puts("0");
	}
	
	return 0;
}
