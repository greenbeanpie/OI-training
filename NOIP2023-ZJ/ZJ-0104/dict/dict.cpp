#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pr pair<int, int>
#define Pr pair<string, pr>
#define pb push_back
#define mid (l + r) / 2
#define ls num << 1
#define rs num << 1 | 1

const int N = 3e3 + 5;

vector<Pr> res;
char a[N][N];
string b[N][2];
int ans[N];

inline int read() {
    int x = 0, m = 1;
    char ch = getchar();

    while (!isdigit(ch)) {
        if (ch == '-') m = -1;
        ch = getchar();
    }

    while (isdigit(ch)) {
        x = x * 10 + ch - 48;
        ch = getchar();
    }

    return x * m;
}

inline void write(int x) {
    if (x < 0) {
        putchar('-');
        write(-x);
        return;
    }

    if (x >= 10) write(x / 10);
    putchar(x % 10 + '0');
}

char get() {
    char ch = getchar();
    while (ch < 'a' || ch > 'z') ch = getchar();
    return ch;
}

signed main() {
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);

    int n = read(), m = read();

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            a[i][j] = get();
        }

        sort(a[i] + 1, a[i] + m + 1);

        string s = "";

        for (int j = 1; j <= m; j++) {
            s += a[i][j];
        }

        res.pb({s, {1, i}});
        b[i][0] = s;

        reverse(s.begin(), s.end());

        res.pb({s, {0, i}});
        b[i][1] = s;
        ans[i] = 0;
    }

    sort(res.begin(), res.end());
    reverse(res.begin(), res.end());

    int cnt = 0;

    for (auto u : res) {
        if (u.second.first == 0) cnt++;
        else {
            int id = u.second.second;
            int now = cnt;
            if (b[id][0] < b[id][1]) now--;
            if (now == n - 1) ans[id] = 1;
        }
    }

    for (int i = 1; i <= n; i++) {
        write(ans[i]);
    }
}