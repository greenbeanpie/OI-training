#include <iostream>
#include <queue>
using namespace std;
int n, num, lc, rc, ans = 100000000;
struct city
{
    int pe,l,r,father,weight,step;
};
city a1[110];
int bfs(int aim)
{
    int vis[110] = {};
    int sum = 0;
    queue<city> q;
    vis[aim] = 1;
    q.push(a1[aim]);
    while (!q.empty())
    {
        city temp = q.front();
        if (temp.l && !vis[temp.l])
        {
            q.push(a1[temp.l]);
            a1[temp.l].step = temp.step + 1;
            sum += a1[temp.l].pe * a1[temp.l].step;
        }
        if (temp.r && !vis[temp.r])
        {
            q.push(a1[temp.r]);
            a1[temp.r].step = temp.step + 1;
            sum += a1[temp.r].pe * a1[temp.r].step;
        }
        if (temp.father && !vis[temp.father])
        {
            q.push(a1[temp.father]);
            a1[temp.father].step = temp.step + 1;
            sum += a1[temp.father].pe * a1[temp.father].step;
        }
        cout << temp.weight << " ";
        vis[temp.weight] = 1;
        q.pop();
    }
    return sum;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> num >> lc >> rc;
        a1[i].pe = num;
        a1[i].l = lc;
        a1[i].r = rc;
        a1[rc].father = i;
        a1[lc].father = i;
        a1[i].weight = i;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int i = 1; i <= n; i++)
        {
            a1[i].step = 0;}
        ans = min(ans, bfs(i));
    }
    cout << ans;
}