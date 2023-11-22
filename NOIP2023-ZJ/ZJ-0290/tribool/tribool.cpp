#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int MAXN = 1e5 + 10;

int n, m, a[MAXN * 2];
int cnt, num[MAXN * 2];
int T, F, U;
vector<int> G[MAXN * 2];
bool flag[MAXN * 2];

void dfs(int u)
{
	if (num[u]) return ;
	num[u] = cnt;
	for (int v : G[u]) dfs(v);
}

int NOT(int i)
{
	if (i <= n) return i + n;
	else if (i <= 2 * n) return i - n;
	else if (i == T) return F;
	else if (i == F) return T;
	else return U;
}

int main()
{
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	int c, text, x, y;
	char v;
	cin >> c >> text;
	while (text--)
	{
		cin >> n >> m;
		memset(a, 0, sizeof(a));
		for (int i = 1; i <= n * 2; i++)
			a[i] = i;
		
		T = 2 * n + 1, F = 2 * n + 2, U = 2 * n + 3;
		while (m--)
		{
			cin >> v;
			if (v == '+')
			{
				scanf("%d %d", &x, &y);
				a[x] = a[y];
			}
			else if (v == '-')
			{
				scanf("%d %d", &x, &y);
				a[x] = NOT(a[y]);
			}
			else
			{
				scanf("%d", &x);
				if (v == 'T') a[x] = T;
				else if (v == 'F') a[x] = F;
				else a[x] = U;
			}
		}
		
		for (int i = 1; i <= n * 2 + 3; i++)
			G[i].clear();
		for (int i = 1; i <= n; i++)
		{
			G[i].push_back(a[i]);
			G[a[i]].push_back(i);
		}
		
		cnt = 0;
		memset(num, 0, sizeof(num));
		for (int i = 1; i <= n * 2; i++)
			if (!num[i])
			{
				cnt++;
				dfs(i);
			}
		
		memset(flag, 0, sizeof(flag));
		for (int i = 1; i <= n; i++)
			if (num[i] == num[i + n] || num[i] == num[U])
				flag[num[i]] = 1;
		
		int ans = 0;
		for (int i = 1; i <= n; i++)
			ans += flag[num[i]];
		cout << ans << endl;
	}
}
