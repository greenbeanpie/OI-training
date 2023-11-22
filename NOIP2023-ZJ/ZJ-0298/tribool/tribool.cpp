#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <deque>
#define BLACK 1
#define WHITE 0
#define UKE -1
#define N 100005

using namespace std;

bool vis[N];
int ver[N];
int nxt[N];
int tag[N];
int node[N];
int head[N];
int tot = 0;
deque<int> waitNode;

void add(int u, int v, int t)
{
    nxt[++tot] = head[u];
    ver[tot] = v;
    tag[tot] = t;
    head[u] = tot;
}

namespace case1
{
    void solve()
    {
        while (!waitNode.empty())
        {
            int u = waitNode.front();
            vis[u] = true;
            waitNode.pop_front();
            for (int i = head[u]; i; i = nxt[i])
            {
                int v = ver[i];
                if (node[u] == -1)
                {
                    if (node[v] != -1)
                    {
                        node[v] = -1;
                        waitNode.push_back(v);
                    }
                }
                else
                {
                    if (tag[i])
                    {
                        if (node[v] != node[u])
                        {
                            node[v] = node[u];
                            if (vis[v])
                                node[v] = -1;
                            waitNode.push_back(v);
                        }
                    }
                    else
                    {
                        if (node[v] == -1 || (node[v] ^ 1) != node[u])
                        {
                            node[v] = node[u] ^ 1;
                            if (vis[v])
                                node[v] = -1;
                            waitNode.push_back(v);
                        }
                    }
                }
            }
        }
    }
}

int main()
{
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    int c, T;
    scanf("%d%d", &c, &T);
    while (T--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        int sp = 0;
        bool op_1 = false,
             op_2 = false,
             op_3 = false,
             op_4 = false,
             op_5 = false;
        while (m--)
        {
            char v;
            // scanf("%c", &v);
            cin >> v;
            if (v == 'T')
            {
                int i;
                scanf("%d", &i);
                node[i] = BLACK;
                waitNode.push_back(i);
                op_1 = true;
            }
            else if (v == 'F')
            {
                int i;
                scanf("%d", &i);
                node[i] = WHITE;
                waitNode.push_back(i);
                op_2 = true;
            }
            else if (v == 'U')
            {
                int i;
                scanf("%d", &i);
                node[i] = UKE;
                waitNode.push_back(i);
                op_3 = true;
                sp++;
            }
            else if (v == '+')
            {
                int i, j;
                scanf("%d%d", &i, &j);
                add(j, i, 1);
                op_4 = true;
            }
            else if (v == '-')
            {
                int i, j;
                scanf("%d%d", &i, &j);
                add(j, i, 0);
                op_5 = true;
            }
        }
        if ((c == 3 || c == 4) || (!op_4 && !op_5))
            printf("%d\n", sp);
        else if ((c == 5 || c == 6) || (!op_1 && !op_2 && op_3 && op_4 && !op_5))
        {
            case1::solve();
            int ans = 0;
            for (int i = 1; i <= n; i++)
            {
                if (node[i] == UKE)
                    ans++;
            }
            printf("%d\n", ans);
        }
        else if ((c == 7 || c == 8) || (!op_1 && !op_2 && !op_3 && (op_4 || op_5)))
        {
            for (int i = 1; i <= n; i++)
                waitNode.push_back(i);
            case1::solve();
            int ans = 0;
            for (int i = 1; i <= n; i++)
            {
                if (node[i] == UKE)
                    ans++;
            }
            printf("%d\n", ans);
        }
        else
        {
            for (int i = 1; i <= n; i++)
                waitNode.push_back(i);
            case1::solve();
            int ans = 0;
            for (int i = 1; i <= n; i++)
            {
                if (node[i] == UKE)
                    ans++;
            }
            printf("%d\n", ans);
        }

        // clear
        waitNode.clear();
        for (int i = 0; i <= tot; i++)
        {
            ver[i] = 0;
            nxt[i] = 0;
            tag[i] = 0;
            head[i] = 0;
        }
        for (int i = 0; i <= n; i++)
        {
            node[i] = 0;
        }
        tot = 0;
    }
    return 0;
}