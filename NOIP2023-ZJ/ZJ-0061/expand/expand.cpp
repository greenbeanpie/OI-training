// 感觉要T
#include <bits/stdc++.h>
using namespace std;
int n, m, q;
int x[500005], y[500005];
int le[500005][19], ge[500005][19];
int kx, ky;
int px[500005], vx[500005];
int py[500005], vy[500005];
bool flag = true;
inline bool cmp( int a, int b ) {
    if ( flag ) return a > b;
    else return a < b;
}
bool work() {
    if ( x[1] > y[1] && x[n] > y[m] ) {
        flag = true;
    } else if ( x[1] < y[1] && x[n] < y[m] ) {
        flag = false;
    } else return false;
    for ( int i = 1; i <= m; ++i ) {
        ge[i][0] = le[i][0] = y[i];
    }
    for ( int j = 1; j <= 18; ++j ) {
        for ( int i = (1<<j); i <= m; ++i ) {
            if ( flag ) {
                le[i][j] = min( le[i][j-1], le[i-(1<<(j-1))][j-1] );
            } else {
                le[i][j] = max( le[i][j-1], le[i-(1<<(j-1))][j-1] );
            }
        }
        for ( int i = 1; i+(1<<j) <= m ; ++i ) {
            if ( flag ) {
                ge[i][j] = max( ge[i][j-1], ge[i+(1<<(j-1))][j-1] );
            } else {
                ge[i][j] = min( ge[i][j-1], ge[i+(1<<(j-1))][j-1] );
            }
        }
    }
    int l = 1, r = 1;
    while ( r < m && cmp(x[1], y[r+1]) ) ++r;
    for ( int i = 2; i <= n; ++i ) {
        if ( x[i] == x[i-1] ) continue;
        if ( cmp(x[i], x[i-1]) ) {
            while ( l <= m && !cmp(x[i], y[l]) ) ++l;
            for ( int j = 18; j >= 0; --j ) {
                if ( r + (1<<j) <= m && cmp(x[i], ge[r][j]) ) {
                    r += (1<<j);
                }
            }
        } else {
            while ( l <= m && !cmp(x[i],y[l]) ) ++l;
            for ( int j = 18; j >= 0 && !cmp(x[i],y[r]); --j ) {
                if ( r-(1<<j) >= l && !cmp(x[i],le[r][j]) ) {
                    r -= (1<<j);
                }
            }
        }
        if ( l > r ) return false;
    }
    return r>=m;
}
int main() {
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    scanf("%*d%d%d%d", &n, &m, &q);
    for ( int i = 1; i <= n; ++i ) {
        scanf("%d", x+i);
    }
    for ( int i = 1; i <= m; ++i ) {
        scanf("%d", y+i);
    }
    putchar('0'+work());
    while ( q-- ) {
        scanf("%d%d", &kx, &ky);
        for ( int i = 1; i <= kx; ++i ) {
            scanf("%d%d", px+i, vx+i);
            swap(vx[i],x[px[i]]);
        }
        for ( int i = 1; i <= ky; ++i ) {
            scanf("%d%d", py+i, vy+i);
            swap(vy[i],y[py[i]]);
        }
        putchar('0'+work());
        for ( int i = 1; i <= kx; ++i ) {
            swap(vx[i],x[px[i]]);
        }
        for ( int i = 1; i <= ky; ++i ) {
            swap(vy[i],y[py[i]]);
        }
    }
    puts("");
}