#include <vector>
#include <stdio.h>
using namespace std;
char get()
{
    char c(getchar());
    while (c != '-' && c != '+' && c != 'U' && c != 'T' && c != 'F')
        c = getchar();
    return c;
}
char d[200005];
int g[200005];
vector<pair<int, int>> e[200005];
void color(const int p, const char c)
{
    if (d[p] == 'T' || d[p] == 'U' || d[p] == 'F')
        return;
    d[p] = c;
    for (pair<int, int> i : e[p])
        if (c == 'T')
            color(i.first, i.second ? 'F' : 'T');
        else if (c == 'F')
            color(i.first, i.second ? 'T' : 'F');
        else
            color(i.first, 'U');
}
bool check(const int p)
{
    for (pair<int, int> i : e[p])
        if (d[i.first])
        {
            if (i.second && d[i.first] == d[p])
                return false;
            if (!i.second && d[i.first] != d[p])
                return false;
        }
        else
        {
            if (d[p] == 't')
                d[i.first] = i.second ? 'f' : 't';
            else
                d[i.first] = i.second ? 't' : 'f';
            if (!check(i.first))
                return false;
        }
    return true;
}
void add(const int x, const int y, const bool t)
{
    e[x].emplace_back(y, t);
    e[y].emplace_back(x, t);
}
int main()
{
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    // Glorious Purpose --Loki
    int t;
    scanf("%d%d", &t, &t);
    while (t--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        int k(n), at(n + m + 1), af(n + m + 2), au(n + m + 3);
        for (int i(1); i <= n; ++i)
            g[i] = i;
        while (m--)
        {
            const char c(get());
            if (c == '+' || c == '-')
            {
                int i, j;
                scanf("%d%d", &i, &j);
                const int p(g[j]);
                g[i] = ++k;
                add(p, k, c ^ '-' ? false : true);
            }
            else
            {
                int i;
                scanf("%d", &i);
                g[i] = ++k;
                if (c == 'T')
                    add(at, k, false);
                else if (c == 'F')
                    add(af, k, false);
                else if (c == 'U')
                    add(au, k, false);
            }
        }
        for (int i(1); i <= n; ++i)
            if (g[i] ^ i)
            {
                e[i].emplace_back(g[i], false);
                e[g[i]].emplace_back(i, false);
            }
        for (int i(1); i <= k; ++i)
            if (!d[i])
                if (!check(i))
                    color(i, 'U');
        int w(0);
        color(au, 'U');
        for (int i(1); i <= n; ++i)
            if (d[i] == 'U')
                ++w;
        for (int i(1); i <= k; ++i)
            d[i] = 0, e[i].clear();
        d[at] = d[af] = d[au] = 0;
        e[at].clear();
        e[af].clear();
        e[au].clear();
        printf("%d\n", w);
    }
    return 0;
}