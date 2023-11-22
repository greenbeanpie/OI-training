#include <bits/stdc++.h>

using namespace std;

int n, m;
char a[3010][3010];
char Min[3010][3010], Max[3010][3010];
unsigned long long Min_pre[3010][3010], Max_pre[3010][3010];
char tmp[3010];

inline bool check(int x, int y) {
    int h = 0, l = 1, r = m;
    while (l <= r) {
        int mid = l + r >> 1;
        if (Min_pre[x][mid] == Max_pre[y][mid])
            h = mid, l = mid + 1;
        else
            r = mid - 1;
    }
    if (h == m) return 0;
    return Min[x][h + 1] < Max[y][h + 1];
}

int main() {
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            tmp[j] = a[i][j];
        sort(tmp + 1, tmp + m + 1);
        Min_pre[i][0] = Max_pre[i][0] = 0;
        for (int j = 1; j <= m; j++) {
            Min[i][j] = tmp[j];
            Max[i][j] = tmp[m - j + 1];
            Min_pre[i][j] = Min_pre[i][j - 1] * 31 + Min[i][j];
            Max_pre[i][j] = Max_pre[i][j - 1] * 31 + Max[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        int flag = 1;
        for (int j = 1; j <= n; j++)
            if (j != i && !check(i, j)) {
                flag = 0;
                break;
            }
        cout << flag;
    }
    cout << endl;
    return 0;
}