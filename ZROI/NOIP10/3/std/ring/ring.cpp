#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, ans = LLONG_MAX, dis[205][205], g[205][205][2];
bool vis[205][205][2];
struct mh
{
  int in, out;
  bool f;
};
void SPFA()
{
  memset(vis, 0, sizeof vis);
  memset(g, 0x3f, sizeof g);
  g[n][n][0] = 0;
  queue<mh> q;
  q.push({n, n, 0});
  while (q.size())
  {
    mh u = q.front();
    q.pop();
    vis[u.in][u.out][u.f] = 0;
    if (!u.f)
    {
      for (int v = 1; v <= n; v++)
      {
        int w = dis[u.out][v];
        if (g[u.in][v][1] > g[u.in][u.out][0] + w)
        {
          g[u.in][v][1] = g[u.in][u.out][0] + w;
          if (!vis[u.in][v][1])
            vis[u.in][v][1] = 1, q.push({u.in, v, 1});
        }
      }
    }
    else
    {
      for (int v = 1; v <= n; v++)
      {
        int w = dis[u.out][v] + dis[v][u.in];
        if (g[u.out][v][0] > g[u.in][u.out][1] + w)
        {
          g[u.out][v][0] = g[u.in][u.out][1] + w;
          if (u.out == 1)
            ans = min(ans, g[u.out][v][0]);
          if (!vis[u.out][v][0])
            vis[u.out][v][0] = 1, q.push({u.out, v, 0});
        }
      }
    }
  }
}
signed main()
{
	freopen("ring.in","r",stdin);
	freopen("ring.out","w",stdout);
  std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
    {
      cin >> dis[i][j];
      if (!dis[i][j])
        dis[i][j] = LLONG_MAX / 10;
      if (i == j)
        dis[i][j] = 0;
    }
  for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
  SPFA();
  cout << ans;
}
