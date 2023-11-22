#include <bits/stdc++.h>
using namespace std;
// #define int long long
void file()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
}
// it's simple to know that the node's val is depend the last change
// And We can...?
const int N = 1e5 + 10;
int v[N], head[N];
struct edge
{
    int nxt, to = -1, w;
} edge[N];
int cnt = 0;
int d[N];
void addedge(int u, int v, int w)
{
    edge[cnt].w = w;
    edge[cnt].nxt = u;
    edge[cnt].to = v;
    head[u] = cnt++;
}
signed main()
{
    // 在所有大样例中，有6个文件出现了114514 共计33次
    // 在所有大样例中，有3个文件出现了1919810 共计4次
    file();
    int ui, T;
    memset(head, -1, sizeof(head));
    cin >> ui >> T;
    if (ui == 3 || ui == 4)
    {
        memset(v, 0, sizeof(v));
        int n, m;
        while (T--)
        {
            cin >> n >> m;
            for (int i = 1; i <= m; i++)
            {

                char opt;
                int op;
                cin >> opt >> op;
                if (opt == 'T')
                    v[op] = 1;
                if (opt == 'F')
                    v[op] = 0;
                if (opt == 'U')
                    v[op] = 2;
            }
            int cnt = 0;
            for (int i = 1; i <= n; i++)
            {
                if (v[i] == 2)
                {
                    cnt++;
                }
            }
            cout << cnt << endl;
        }
    }
    else if (ui == 5 || ui == 6)
    {
        while (T--)
        {
            int n, m;
            cin >> n >> m;
            memset(v, 0, sizeof(v));
            for (int i = 1; i <= m; i++)
            {
                char opt;
                int o, p;
                cin >> opt;
                if (opt == 'U')
                {
                    cin >> o;
                    v[o] = 2;
                    // cerr<<v[o]<<endl;
                    // cout<<T<<endl;
                }
                else
                {
                    cin >> o >> p;
                    v[o] = v[p];
                    // cerr<<v[o]<<' '<<v[p]<<endl;
                }
            }
            int cnt = 0;
            for (int i = 1; i <= n; i++)
            {
                if (v[i] != 0)
                {
                    // cerr<<v[i]<<' ';
                    cnt++;
                }
            }
            cout << cnt << endl;
        }
    }
    else if (ui == 7 || ui == 8)
    {
        while (T--)
        {
            int n, m;
            cin >> n >> m;
            memset(v, 0, sizeof(v));
            for (int i = 1; i <= m; i++)
            {
                char opt;
                int o, p;
                cin >> opt >> o >> p;
                if (opt == '+')
                {
                    d[o]++;
                    d[p]++;
                }
                else
                {
                    d[o]--;
                    d[p]--;
                }
                if (d[o] % 2 == 0)
                {
                    cnt--;
                }
                else
                {
                    cnt++;
                }
            }
            cout << (cnt%2==n%2?0:cnt) << endl;
            cnt=0;
        }
    }
}