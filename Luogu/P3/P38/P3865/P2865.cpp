#include <bits/stdc++.h>
using namespace std;
#define int long long

int a_max[100005][21];

int rmq(int l, int r)
{ // op==0==>query maxinum op==1==>query mininum
    int t = floor(log2(r - l + 1));

    return max(a_max[l][t], a_max[r - (1 << t) + 1][t]);

}
signed main()
{
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a_max[i][0];
    }
    for (int j = 1; j <32; j++)
    {
        for (int i = 1; i+(1<<j)-1<=n; i++)
        {
            a_max[i][j] = max(a_max[i + (1 << (j - 1))][j - 1], a_max[i][j - 1]);
        }
    }
    for (int i = 1; i <= m; i++)
    {
        int l, r;
        cin >> l >> r;
        cout << rmq(l, r)<< endl;
    }
    return 0;
}