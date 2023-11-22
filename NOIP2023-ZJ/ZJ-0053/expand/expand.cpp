#include <bits/stdc++.h>
using namespace std;
#define fo(v, a, b) for(int v = a; v <= b; v++)
#define fr(v, a, b) for(int v = a; v >= b; v--)
#define cl(a, v) memset(a, v, sizeof(a))

const int INF = 1e9 + 7;
const int N = 5e5 + 10;

int TID, n, m, Q, Arec[N], Brec[N];
int A[N], B[N], a[N], b[N];

// namespace BF {
//     const int N = 2010;
//     bool dp[N][N];
//     bool Solve() {
//         cl(dp, 0); if(a[1] < b[1]) dp[1][1] = true;
//         fo(i, 1, n) fo(j, 1, m) if(a[i] < b[j])
//             dp[i][j] |= (dp[i - 1][j] | dp[i][j - 1]);
//         return dp[n][m];
//     }
// }

namespace Sol {
    int st[N], top, gap[N];
    void reset() {
        cl(st, 0), top = 0, cl(gap, 0);
    }
    int Solve() {
        reset();
        fo(i, 1, n) if(i == 1 || a[i] < a[st[top]])
            st[++top] = i;
        fo(i, 1, top) {
            gap[i] = -1;
            fo(j, st[i - 1] + 1, st[i])
                gap[i] = max(gap[i], a[j]);
        }
        // printf("top = %d\n", top);
        // fo(i, 1, top) printf("%d ", st[i]);
        // puts("");
        // fo(i, 1, top) printf("%d ", gap[i]);
        // puts("");
        int p = 1;
        fo(i, 1, m) {
            if(a[st[p]] > b[i]) return -1;
            while(p < top && gap[p + 1] < b[i])
                p++;
            // printf("i = %d p = %d\n", i, p);
            if(p == top) return i;
        }
        return -1;
    }
}

bool Solve() {
    fo(i, 1, n) a[i] = A[i];
    fo(i, 1, m) b[i] = B[i];
    if(a[1] > b[1]) {
        fo(i, 1, n) a[i] = 1e9 - a[i];
        fo(i, 1, m) b[i] = 1e9 - b[i];
    }
    
    if(a[1] >= b[1] || a[n] >= b[m]) return false;
    int mna = INF, mnb = INF;
    fo(i, 1, n) mna = min(mna, a[i]);
    fo(i, 1, m) mnb = min(mnb, b[i]);
    if(mna >= mnb) return false;

    // cerr << "test" << endl;
    // fo(i, 1, n) printf("%d ", a[i]);
    // puts("");
    // fo(i, 1, m) printf("%d ", b[i]);
    // puts("");
    // if(TID <= 7) return BF :: Solve();
    // printf("lb = %d rb = %d\n", lb, rb);
    int lb = Sol :: Solve(); if(lb == -1) return false;
    reverse(a + 1, a + n + 1), reverse(b + 1, b + m + 1);
    int rb = Sol :: Solve(); if(rb == -1) return false;
    return lb + rb - 1 <= m;
}

char ans[N];
int main()
{
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);

    scanf("%d%d%d%d", &TID, &n, &m, &Q);
    fo(i, 1, n) scanf("%d", &A[i]), Arec[i] = A[i];
    fo(i, 1, m) scanf("%d", &B[i]), Brec[i] = B[i];

    ans[0] = Solve() + '0';
    fo(id, 1, Q) {
        fo(i, 1, n) A[i] = Arec[i];
        fo(i, 1, m) B[i] = Brec[i];

        int kx, ky; scanf("%d%d", &kx, &ky);
        fo(i, 1, kx) {
            int px, vx; scanf("%d%d", &px, &vx);
            A[px] = vx;
        }
        fo(i, 1, ky) {
            int py, vy; scanf("%d%d", &py, &vy);
            B[py] = vy;
        }
        // if(id == 8) {
        //     fo(i, 1, n) printf("%d ", A[i]);
        //     puts("");
        //     fo(i, 1, m) printf("%d ", B[i]);
        //     puts("");
        // }
        ans[id] = Solve() + '0';
    }

    puts(ans);

    return 0;
}
// Thank you yyandy!