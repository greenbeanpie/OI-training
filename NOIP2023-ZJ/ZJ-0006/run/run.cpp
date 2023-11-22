#include <bits/stdc++.h>
#define FOR(i, l, r) for(int i = (l); i <= (r); i++)
#define ROF(i, r, l) for(int i = (r); i >= (l); i--)
#define sz(a) int((a).size())
#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define x first
#define y second
#define tii tuple<int, int, int>
using namespace std;
const int N = 1e5 + 10;
const ll oo = 0x3f3f3f3f3f3f3f3f;
int n, m, k, d;
tii a[N];
ll dp[N], sum[N];
void Main() {
    cin >> n >> m >> k >> d;
    FOR(i, 1, m) {
        int x, y, v;
        cin >> x >> y >> v;
        a[i] = {x, y, v};
    }
    sort(a + 1, a + m + 1);
    int st = 0;
    int p0 = 0;
    FOR(i, 1, k) dp[i] = -oo;
    dp[0] = 0;
    for(int l = 1, r; l <= m; l = r + 1) {
        // FOR(j, 0, k) cout << dp[(p0 + j) % (k + 1)] << " ";
        // cout << endl;
        auto [x, y, v] = a[l];
        r = l;
        while(r + 1 <= m && get<0>(a[r + 1]) == x) r++;
        int dt = x - st;
        dt = min(dt, k + 1);
        st = x;
        ll tag = 0;
        ll mx = -oo;
        FOR(j, 0, k) mx = max(mx, dp[j]);
        FOR(j, 1, dt) {
            p0 = (p0 + k) % (k + 1);
            tag -= d;
            dp[p0] = mx - tag;
        }
        FOR(j, 0, k) dp[j] += tag;
        FOR(j, 0, k) sum[j] = 0;
        FOR(j, l, r) {
            auto [x, y, v] = a[j];
            if(y > k) continue;
            sum[y] += v;
        }
        FOR(j, 0, k) {
            if(j) sum[j] += sum[j - 1];
            dp[(p0 + j) % (k + 1)] += sum[j];
        }
    }
    ll ans = 0;
    FOR(i, 0, k) ans = max(ans, dp[i]);
    cout << ans << "\n";
}
int nn;
struct fwt {
    ll mx[N];
    void clear() {
        FOR(i, 1, nn) mx[i] = 0;
    }
    void add(int x, ll v) {
        for(int i = x; i <= nn; i += i & (-i)) mx[i] = max(mx[i], v);
    }
    ll qry(int x) {
        ll res = -oo;
        for(int i = x; i > 0; i -= i & (-i)) res = max(res, mx[i]);
        return res;
    }
}T;
tii b[N];
ll solve(int l, int r) {
    nn = 0;
    FOR(i, l, r) b[++nn] = a[i], sum[nn] = get<2>(a[i]);
    T.clear();
    FOR(i, 0, nn) dp[i] = 0;
    FOR(i, 1, nn) sum[i] += sum[i - 1];
    FOR(i, 1, nn) {
        auto [l, r, v] = b[i];
        dp[i] = dp[i - 1];
        int pos = lower_bound(b + 1, b + nn + 1, tii{r - k + 1, 0, 0}) - b;
        if(r - l + 1 > k) continue;
        dp[i] = max(dp[i], T.qry(nn + 1 - pos) + sum[i]);
        if(i + 1 <= nn) T.add(nn + 1 - (i + 1), dp[i] - sum[i + 1]);
    }
    ll ans = 0;
    FOR(i, 1, nn) ans = max(ans, dp[i]);
    return ans;
}
void Main2() {
    cin >> n >> m >> k >> d;
    int tot = 0;
    FOR(i, 1, m) {
        int x, y;
        ll v;
        cin >> x >> y >> v;
        int l = x - y + 1, r = x;
        v -= (ll)y * d;
        if(v > 0) a[++tot] = {l, r, v};
    }
    m = tot;
    if(m == 0) {
        cout << "0\n";
        return;
    }
    sort(a + 1, a + m + 1);
    int lst = 1;
    ll ans = 0;
    FOR(i, 2, m) {
        if(get<1>(a[i - 1]) + 1 < get<0>(a[i])) {
            ans += solve(lst, i - 1);
            lst = i;
        }
    }
    ans += solve(lst, m);
    cout << ans << "\n";
}
int main() {
    freopen("run.in", "r", stdin);
    freopen("run.out", "w", stdout);
    ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int c, t;
    cin >> c >> t;
    FOR(C, 1, t) {
        if(c == 17 || c == 18) Main2();
        else Main();
    }
}