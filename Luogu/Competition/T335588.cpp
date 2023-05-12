#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, sum[1000005], minsum[1000005], minnum = 0, cr = 0;
int a_min[1000005][21];

int rmq(int l, int r)
{
    int t = floor(log2(r - l + 1));
    return min(a_min[l][t], a_min[r - (1 << t) + 1][t]);
}

void st_sheet(int n) {
    for (int i = 1; i <= n; i++)
    {
        a_min[i][0] = sum[i];
    }
    for (int j = 1; j <= 21; j++)
    {
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
        {
            a_min[i][j] = min(a_min[i + (1 << (j - 1))][j - 1], a_min[i][j - 1]);
        }
    }
}
signed main() {
#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
#endif
    cin >> n;
    sum[0] = minsum[0] = 0;
    for (int i = 1;i <= n;i++) {
        int t;
        cin >> t;
        sum[i] = sum[i - 1] + t;
    }
    st_sheet(n);
    int cnt = 0;
    if (rmq(1, n) >= 0) {
        cnt ++;
    }

    for (int k = 1;k < n;k++) {

        if (sum[k] <= rmq(k + 1, n) && sum[n] - sum[k] >= -rmq(1, k)) {
            cnt++;
        }
    }
    cout << cnt;
}