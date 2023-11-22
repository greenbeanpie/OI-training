#include <bits/stdc++.h>
#define FOR(i, l, r) for(int i = (l); i <= (r); i++)
#define ROF(i, r, l) for(int i = (r); i >= (l); i--)
#define sz(a) int((a).size())
#define ll long long
using namespace std;
const int N = 3000 + 10;
int n, m;
int a[N], b[N], cnt[26];
int main() {
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    FOR(i, 1, n) {
        string s;
        cin >> s;
        int mx = s[0] - 'a', mn = s[0] - 'a';
        FOR(j, 1, m - 1) {
            mx = max(mx, int(s[j] - 'a'));
            mn = min(mn, int(s[j] - 'a'));
        }
        a[i] = mx, b[i] = mn;
        cnt[mx]++;
    }
    FOR(i, 1, n) {
        int all = 0;
        FOR(j, b[i] + 1, 25) all += cnt[j];
        if(a[i] <= b[i]) all += 1;
        cout << (all == n);
    }
    cout << "\n";
}