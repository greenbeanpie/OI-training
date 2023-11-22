#include <bits/stdc++.h>

#define rep(i, a, b) for(int i = (a); i <= (b); i++)

using namespace std;

const int N = 3e5 + 10, M = 2 * N;

int h[N], e[M], ne[M], idx;
int dfn[N], low[N], cnt, timetamp, stk[N], top, siz[N], id[N];
int cz[N], val[N];
bool st[N];

void add(int a, int b)
{
	ne[idx] = h[a], e[idx] = b, h[a] = idx++;
}

void tarjan(int u, int from)
{
	dfn[u] = low[u] = ++timetamp;
	stk[++top] = u;
	
	for(int i = h[u]; ~i; i = ne[i])
	{
		int j = e[i];
		if(!dfn[j])
		{
			tarjan(j, i);
			low[u] = min(low[u], low[j]);
		}
		else if(i != (from ^ 1)) low[u] = min(low[u], dfn[j]);
	}
	
	if(low[u] == dfn[u])
	{
		int y;
		cnt++;
		do
		{
			y = stk[top--];
			id[y] = cnt;
			siz[cnt]++;
		}while(y != u);
	}
}

int main()
{
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	
	int c, T;
	cin >> c >> T;
	while(T--)
	{
		memset(h, -1, sizeof h);
	
		int n, m;
		cin >> n >> m;
		
		rep(i, 1, 2 * n) cz[i] = i;
		
		rep(i, 1, m)
		{
			char c;
			cin >> c;
			if(c == '+')
			{
				int x, y;
				cin >> x >> y;
				cz[2 * x] = cz[2 * y];
				cz[2 * x - 1] = cz[2 * y - 1];
			}
			if(c == '-')
			{
				int x, y;
				cin >> x >> y;
				if(x == y) cz[2 * x] = cz[2 * x - 1] = 2 * n + 1; 
				else
				{
					cz[2 * x] = cz[2 * y - 1];
					cz[2 * x - 1] = cz[2 * y];
				}
			}
			if(c == 'U')
			{
				int x;
				cin >> x;
				cz[2 * x] = 2 * n + 1;
				cz[2 * x - 1] = 2 * n + 1;
			}
			if(c == 'T')
			{
				int x;
				cin >> x;
				val[2 * x] = 1;
				val[2 * x - 1] = 1;
			}
			if(c == 'F')
			{
				int x;
				cin >> x;
				val[2 * x] = 0;
				val[2 * x - 1] = 0;
			}
		}
		
		rep(i, 1, 2 * n)
		{
			if(cz[i] == i) continue;
			if(cz[i] <= 2 * n && cz[i] > 0)
			{
				add(i, cz[i]);
				add(cz[i], i);
			}
		}
		
		rep(i, 1, 2 * n)  if(!dfn[i]) tarjan(i, -1);
		rep(i, 1, n) if(id[2 * i] == id[2 * i - 1]) st[id[2 * i]] = true;
		rep(i, 1, 2 * n) if(cz[i] == 2 * n + 1) st[id[i]] = true;
		
		rep(i, 1, 2 * n)
		{
			for(int j = h[i]; ~j; j = ne[j])
			{
				int k = e[j];
				st[id[i]] |= st[id[k]];
				st[id[k]] |= st[id[i]];
			}
		}
		
		int ans = 0;
		rep(i, 1, cnt) if(st[i]) ans += siz[i];
		cout << ans / 2 << '\n';
		
		rep(i, 1, 2 * n) h[i] = -1, dfn[i] = 0, low[i] = 0, id[i] = 0, val[i] = 0;
		rep(i, 1, cnt) siz[i] = 0;
		rep(i, 1, cnt) st[i] = 0;
		timetamp = 0, idx = 0; cnt = 0; top = 0;
	}
	
	
}