#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    freopen("run.in", "r", stdin);
    freopen("run.out", "w", stdout);
    int c, t;
    scanf("%d%d", &c, &t);
    while (t--){
        ll n, m, k, d;
        scanf("%lld%lld%lld%lld", &n, &m, &k, &d);
        ll ans = 0;
        while (m--){
            ll x, y, v;
            scanf("%lld%lld%lld", &x, &y, &v);
            if (y * d < v) ans += v - y * d;
        }
    }
    return 0;
}