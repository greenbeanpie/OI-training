#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, k;
int a[100010];
int b[100010];
int c[100010];

int fun(int k)  // c数组里有多少个数 <= k
{
    int l = 1, r = n;
    int res = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (c[mid] <= k) {
            res = mid;
            l = mid + 1;
        } else
            r = mid - 1;
    }
    return res;
}

int check(int x) {
    int res = 0;
    for (int i = 1; i <= n; i++) {
        res += fun((x - a[i]) / b[i]);
    }
    return res;
}

signed main() {
    freopen("plant.in", "r", stdin);
    freopen("plant.out", "w", stdout);
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    for (int i = 1; i <= n; i++) scanf("%lld", &b[i]);
    for (int i = 1; i <= n; i++) scanf("%lld", &c[i]);
    sort(c + 1, c + n + 1);
    scanf("%lld", &k);
    int l = 0, r = 2e18;
    int res = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid) >= k) {
            res = mid;
            r = mid - 1;
        } else
            l = mid + 1;
    }
    printf("%lld\n", res);
    return 0;
}
