#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN = 1e3 + 10;

typedef long long LL;
int n, m, k, d;
int x[MAXN], y[MAXN], v[MAXN];
LL f[MAXN][2];

struct Task
{
	int y, v;
	Task(int _y, int _v) : y(_y), v(_v){}
	bool operator < (const Task &r) const { return y < r.y;}
};

vector<Task> task[MAXN];

int main()
{
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	int c, T;
	cin >> c >> T;
	while (T--)
	{
		cin >> n >> m >> k >> d;
		for (int i = 1; i <= n; i++)
			task[i].clear();
		for (int i = 1; i <= m; i++)
		{
			cin >> x[i] >> y[i] >> v[i];
			task[x[i]].push_back(Task(y[i], v[i]));
		}
		for (int i = 1; i <= n; i++)
			sort(task[i].begin(), task[i].end());
		
		memset(f, 0xcf, sizeof(f));
		f[0][0] = f[0][1] = 0;
		for (int i = 1; i <= n; i++)
		{
			f[i][0] = max(f[i - 1][0], f[i - 1][1]);
			LL add = 0;
			int s = 0;
			for (int j = i - 1; j >= max(0, i - k); j--)
			{
				int len = i - j;
				if (s < task[i].size() && len >= task[i][s].y)
				{
					add += task[i][s++].v;
//					add = max(add, (LL)task[i][s++].v);
				}
				f[i][1] = max(f[i][1], f[j][0] - (LL)len * d + add);
			}
		}
		
		cout << max(f[n][0], f[n][1]) << endl;
	}
}
