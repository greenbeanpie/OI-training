#include <bits/stdc++.h>
using namespace std;
#define int long long
int father[1000];

int find(int a)
{
    int fa = a;
    if (father[a] != a)
    {
        fa = find(father[a]);
    }
    return fa;
}

void fusion(int a, int b)
{
    int faa = find(a);
    int fab = find(b);
    father[faa] = fab;
}

signed main()
{
    int n, m;
    while (cin >> n)
    {
        if (!n)
        {
            break;
        }
        cin >> m;
        for (int i = 0; i < n; i++)
        {
            father[i] = i;
        }
        int begin, end, t = 0;
        for (int i = 0; i < m; i++)
        {
            cin >> begin >> end;
            if (begin == end)
            {
                continue;
            }
            fusion(end - 1, begin - 1);
        }
        for (int i = 0; i < n; i++)
        {

            if (father[i] == i)
            {
                t++;
            }
        }
        cout << t-1 << endl;
    }
    return 0;
}