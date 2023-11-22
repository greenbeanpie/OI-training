#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
int c, t, n, m;
struct node
{
    int u, v, w;
};
bool vis[MAXN];
char v;
int x, y, ans;
// vector<int> path[MAXN];
//  3,4
void deal1()
{
    while (t--)
    {
        ans = 0;
        memset(vis, 0, sizeof(vis));
        scanf("%d %d", &n, &m);
        for (int i = 0; i < m; i++)
        {
            cin >> v;
            if (v == 'U')
            {
                scanf("%d", &x);
                vis[x] = 1;
            }
            else
            {
                scanf("%d", &x);
                vis[x] = 0;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if (vis[i])
            {
                ans++;
            }
        }
        printf("%d\n", ans);
    }
}
// 5,6
int fa[MAXN];
bool op[MAXN];
bool dfs(int x)
{
    if (op[x])
    {
        return true;
    }
    if (fa[x] == 0) {
        return false;
    }
    return fa[x];
}
void deal2()
{

    while (t--)
    {
        ans = 0;
        memset(vis, 0, sizeof(vis));
        memset(op, 0, sizeof(op));
        memset(fa, 0, sizeof(fa));
        scanf("%d %d", &n, &m);
        for (int i = 0; i < m; i++)
        {
            cin >> v;
            if (v == 'U')
            {
                scanf("%d", &x);
                op[x] = 1;
                fa[x] = 0;
            }
            else
            {
                scanf("%d %d", &x, &y);
                op[x] = 0;
                fa[x] = y;
            }
        }

        for (int i = 1; i <= n; i++)
        {

            if (dfs(i))
            {	
                ans++;
            };
        }
        printf("%d\n", ans);
    }
    /*
    bool f[MAXN];
    while (t--) {
        ans = 0;
        memset(vis, 0, sizeof(vis));
        memset(f, 0, sizeof(f));
        scanf("%d %d", &n, &m);

        for (int i = 0; i < m; i++) {
            cin >> v;
            if (v == 'U') {
                scanf("%d", &x);
                vis[x] = 1;
                f[x] = 1;
            }else{
                scanf("%d %d", &x, &y);
                path[y].push_back(x);
                if (vis[y]) {
                    vis[x] = 1;
                    for (auto j : path[x]) {
                        vis[j] = 1;
                    }
                }else{
                    vis[x] = 0;
                    f[x] = 0;
                    for (auto j : path[x]) {
                        if (!f[j]) {
                            vis[j] = 0;
                        }
                    }
                }
            }
        }


        for (int i = 0; i < n; i++) {
            if (vis[i]) {
                ans++;
            }
        }
        printf("%d\n", ans);

    }
    */
}
// 7,8
void deal3()
{
}
int main()
{
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    scanf("%d %d", &c, &t);
	//cout << c << " " << t << endl;
    if (c == 3 || c == 4)
    {
        deal1();
        return 0;
    }
    if (c == 5 || c == 6)
    {
        deal2();
        return 0;
    }
    if (c == 7 || c == 8)
    {
        deal3();
        return 0;
    }
    /*
    char v;
    int x, y;
    while (t--) {
        scanf("%d %d", &n, &m);

        for (int i = 0; i < m; i++) {
            cin >> v;
            if (v == 'T' || v == 'F' || v == 'U') {
                scanf("%d", &x);
            }else if (v == '+') {
                scanf("%d %d", &x, &y);
            }else{
                scanf("%d %d", &x, &y);
            }
        }
    }
    */

    return 0;
}