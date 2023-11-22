#include <bits/stdc++.h>
using namespace std;
#define fo(v, a, b) for(int v = a; v <= b; v++)
#define fr(v, a, b) for(int v = a; v >= b; v--)
#define cl(a, v) memset(a, v, sizeof(a))

const int N = 3010;

int n, m; char s[N][N], ans[N], mn[N], mx[N];

int main()
{
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);

    scanf("%d%d", &n, &m);
    fo(i, 1, n) scanf("%s", s[i] + 1);

    fo(i, 1, n) {
        mn[i] = 'z', mx[i] = 'a';
        fo(j, 1, m) {
            mn[i] = min(mn[i], s[i][j]);
            mx[i] = max(mx[i], s[i][j]);
        }
    }
    fo(i, 1, n) {
        ans[i] = '1';
        fo(j, 1, n) if(i != j && mn[i] >= mx[j]) {
            ans[i] = '0'; break;
        }
    }
    puts(ans + 1);

    return 0;
}