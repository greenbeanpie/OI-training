#include <bits/stdc++.h>
#define int long long
#define vector std::vector
#define cin std::cin
#define cout std::cout
struct node
{
    int l, w;
};

bool operator<(node a, node b)
{
    return a.l < b.l && a.w < b.w;
}
bool cmp(node a, node b)
{
    if (a.l == b.l)
    {
        return a.w > b.w;
    }
    return a.l > b.l;
}
vector<node> end;
signed main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("B.in", "r", stdin);
#endif
    int n;
    cin >> n;
    node wood[n];
    for (int i = 0; i < n; i++)
    {
        cin >> wood[i].l >> wood[i].w;
    }
    std::sort(wood, wood + n, cmp);
    end.push_back(wood[0]);
    for (int i = 1; i < n; i++)
    {
        bool flag = false;
        for (int j=0;j<end.size();j++)
        {
            if (wood[i].l <= end[j].l && wood[i].w <= end[j].w)
            {
                end[j] = wood[i];
                flag = true;
                break;
            }
        }
        if(!flag)
        {
            end.push_back(wood[i]);
        }
    }
    cout << end.size();
    return 0;
}