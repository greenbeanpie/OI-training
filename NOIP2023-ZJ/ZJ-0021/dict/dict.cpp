#include <bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define MP make_pair
#define MT make_tuple
#define IT iterator
#define fi first
#define se second
#define For(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
#define Rep(i, a, b) for (int i = (int)(a); i >= (int)(b); --i)
#define CLR(a, v) memset(a, v, sizeof(a))
#define CPY(a, b) memcpy(a, b, sizeof(a))
#define debug cout << "ztxakking\n"
#define y0 ztxakioi
#define y1 ztxaknoi
using namespace std;
using ll = long long;
using ull = unsigned ll;
using uint = unsigned;
using pii = pair <int, int>;
using pll = pair <ll, ll>;
using vi = vector <int>;
template <typename T>
using V = vector <T>;
mt19937 gen(time(0));
const int N = 3e3 + 7;
int n, m;
struct node {
    string s;
    int id;
} a[N << 1];
bool ans[N], vis[N];
int main() {
    // double start = clock();
    freopen("dict.in", "r", stdin), freopen("dict.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    For(i, 1, n) {
        string s; cin >> s;
        sort(s.begin(), s.end());
        a[i * 2 - 1].s = s, a[i * 2 - 1].id = i;
        reverse(s.begin(), s.end());
        a[i * 2].s = s, a[i * 2].id = i;
    }
    sort(a + 1, a + n * 2 + 1, [&] (node x, node y) {
        return x.s > y.s;
    });
    CLR(vis, 0), CLR(ans, 0);
    int p = 1, num = 0;
    For(i, 1, n * 2) {
        while (p <= n * 2 && a[p].s > a[i].s) {
            if (!vis[a[p].id]) vis[a[p].id] = 1, ++num;
            ++p;
        }
        if (!vis[a[i].id]) ++num;
        if (num == n) ans[a[i].id] = 1;
        if (!vis[a[i].id]) --num;
    }
    For(i, 1, n) if (ans[i]) cout << 1; else cout << 0;
    // cerr << (clock() - start) / CLOCKS_PER_SEC << '\n';
    return 0;
}