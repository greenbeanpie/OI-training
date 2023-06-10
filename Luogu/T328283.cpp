#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5;
vector<int> e[N];
bool vis[N];
int n, max_reduce = 0, dis1[N];
struct node
{
    int cur, dis;
};
node find_nearest(int start)
{
    queue<node> q;
    q.push({start, 0});
    while (!vis[q.front().cur])
    {
        int cur = q.front().cur;
        q.pop();
        for (auto i = e[cur].begin(); i != e[cur].end(); i++)
        {
            q.push({*i, q.front().dis + 1});
        }
    }
    max_reduce = max(max_reduce, q.front().dis - dis1[start]);
    return q.front();
}
void init()
{
    queue<int> q;
    q.push(1);
    int cur = q.front();
    q.pop();
    for (auto i = e[cur].begin(); i != e[cur].end(); i++)
    {
        q.push(*i);
        dis1[*i] = dis1[cur] + 1;
    }
}
signed main()
{

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    init();
    cout << 0 << endl;
    if (n >= 1)
    {
        cout << 1 << endl;
    }
    if (n >= 2)
    {
        cout << 2 << endl;
    }
    if (n >= 3)
    {
        if (e[1].size() == 2)
        {
            cout << 3 << endl;
        }
        else
        {
            cout << 4 << endl;
        }
    }
    for (int i = 4; i <= n; i++)
    {
        int sum = 0;
        int cur = 1;
        for (int j = 0; j < i; j++)
        {
            node temp = find_nearest(cur);
            cur = temp.cur;
            sum += temp.dis;
        }
        cout << sum - max_reduce << endl;
    }
    return 0;
}