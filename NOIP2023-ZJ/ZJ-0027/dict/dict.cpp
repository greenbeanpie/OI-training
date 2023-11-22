#include <bits/stdc++.h>
using namespace std;

template <class T>
void read(T &r) {
    r = 0; int ch = getchar(), f = 0;
    while (!isdigit(ch)) f ^= (ch == 45), ch = getchar();
    while (isdigit(ch)) (r *= 10) += ch - 48, ch = getchar();
    if (f) r = -r;
}

const int maxn = 3e3 + 5;
int n, m;
char s[maxn][maxn], tmp[maxn], mins[maxn];
bool ans[maxn];

bool compare(char a[], char b[]) {
    for (int i = 1; i <= m; i++) {
        if (a[i] < b[i]) return true;
        if (a[i] > b[i]) return false;
    }
    return false;
}

void solve(int l, int r) {
    if (l == r) {
        memcpy(tmp, s[l], sizeof tmp);
        sort(tmp + 1, tmp + m + 1);
        ans[l] = compare(tmp, mins);
        return;
    }
    char tmins[maxn];
    memcpy(tmins, mins, sizeof tmins);
    
    int mid = (l + r) >> 1;
    for (int i = l; i <= mid; i++) {
        if (compare(s[i], mins)) memcpy(mins, s[i], sizeof mins);
    }
    solve(mid + 1, r);

    memcpy(mins, tmins, sizeof mins);
    for (int i = mid + 1; i <= r; i++) {
        if (compare(s[i], mins)) memcpy(mins, s[i], sizeof mins);
    }
    solve(l, mid);
}

int main() {
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    read(n); read(m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            s[i][j] = getchar();
            while (!isalpha(s[i][j])) s[i][j] = getchar();
        }
        sort(s[i] + 1, s[i] + m + 1, greater<>());
    }
    for (int i = 1; i <= m; i++) mins[i] = 'z';
    solve(1, n);
    for (int i = 1; i <= n; i++) putchar(ans[i] ? '1' : '0');
    putchar('\n');
    return 0;
}