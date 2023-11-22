// 不会正解，写个拼盘
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, k, d;
ll x[100005], y[100005], v[100005];
ll id[100005];
vector<pair<ll,ll>>vv[100005];
ll dp[100005], maxn;
void work1() {
    scanf("%lld%lld%lld%lld", &n, &m, &k, &d);
    dp[0] = 0;
    maxn = 0;
    for ( ll i = 1; i <= n; ++i ) {
        vv[i].clear();
        dp[i] = 0;
    }
    for ( ll i = 1, x, y, v; i <= m; ++i ) {
        scanf("%lld%lld%lld",&x,&y,&v);
        vv[x].emplace_back(y,v);
    }
    for ( ll i = 1; i <= n; ++i ) {
        sort(vv[i].begin(), vv[i].end());
        for ( ll j = 1; j < vv[i].size(); ++j ) {
            vv[i][j].second += vv[i][j-1].second;
        }
        ll j = vv[i].size()-1;
        for ( ll x = min(i,k); x >= 1; --x ) {
            while ( j >= 0 && vv[i][j].first > x ) --j;
            dp[x] = dp[x-1] - d;
            if ( j != -1 ) {
                dp[x] += vv[i][j].second;
            }
        }
        dp[0] = maxn;
        maxn = *max_element(dp,dp+min(i,k)+1);
    }
    printf("%lld\n",maxn);
}
void work_lsh() {
    scanf("%lld%lld%lld%lld", &n, &m, &k, &d);
    for ( ll i = 1; i <= m; ++i ) {
        scanf("%lld%lld%lld",x+i,y+i,v+i);
        id[i] = i;
    }
    for ( ll i = 0; i <= min(n,k); ++i ) {
        dp[i] = 0;
    }
    maxn = 0;
    sort(id+1,id+m+1,[](int a,int b){return x[a]<x[b];});
    for ( ll i = 1; i <= m; ++i ) {
        // cerr << i << endl;
        if ( x[id[i]] == x[id[i-1]] ) {
            for ( ll j = y[id[i]]; j <= min(k,x[id[i]]); ++j ) {
                dp[j] += v[id[i]];
            }
            dp[0] = maxn;
            maxn = *max_element(dp,dp+min(k,x[id[i]])+1);
            continue;
        }
        for ( ll j = min(k,x[id[i]]); j >= 1; --j ) {
            if ( j >= x[id[i]] - x[id[i-1]] ) {
                dp[j] = dp[j-(x[id[i]]-x[id[i-1]])] - d * (x[id[i]]-x[id[i-1]]);
            } else {
                dp[j] = maxn - d * j;
            }
            if ( j >= y[id[i]] ) {
                dp[j] += v[id[i]];
            }
        }
        dp[0] = maxn;
        maxn = *max_element(dp,dp+min(k,x[id[i]])+1);
    }
    printf("%lld\n",maxn);
}
void workB() {
    scanf("%lld%lld%lld%lld", &n, &m, &k, &d);
    ll ans = 0;
    for ( ll i = 1, x, y, v; i <= m; ++i ) {
        scanf("%lld%lld%lld",&x,&y,&v);
        if ( v - y * d > 0 && y <= k ) {
            ans += ( v - y * d );
        }
    }
    printf("%lld\n", ans);
}
int main() {
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    int c, t;
    scanf("%d%d", &c, &t);
    if ( c <= 9 )
        while (t--) work1();
    else if ( c == 15 || c == 16 || c == 10 || c == 11 )
        while (t--) work_lsh();
    else if ( c == 17 || c == 18 )
        while (t--) workB();
}