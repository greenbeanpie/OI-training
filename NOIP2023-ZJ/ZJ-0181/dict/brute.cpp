#include <bits/stdc++.h>
using namespace std;
int n, m;
char s[3030][3030];
char d[3030][3030];
bool ans[3030];
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf(" %c", s[i] + j);
            d[i][j] = s[i][j];
        }
        sort(s[i] + 1, s[i] + m + 1);
        sort(d[i] + 1, d[i] + m + 1, [](char a, char b) {
            return a > b;
        });
        // printf("%s\n%s\n", s[i] + 1, d[i] + 1);
        ans[i] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            if (i != j) {
                bool hexu = 0;
                for (int k = 1; k <= m; k++)
                    if (s[i][k] < d[j][k]) {
                        hexu = 1;
                        break;
                    } else if (s[i][k] > d[j][k])
                        break;
                ans[i] &= hexu;
            }
    }
    for (int i = 1; i <= n; i++) {
        printf("%d", ans[i]);
    }
    printf("\n");
    return 0;
}