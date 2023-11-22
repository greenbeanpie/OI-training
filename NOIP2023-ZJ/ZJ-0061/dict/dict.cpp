#include <bits/stdc++.h>
using namespace std;
int n, m;
char minn[3005], maxn[3005];
int main() {
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    scanf("%d%d", &n, &m);
    char s;
    for ( int i = 1; i <= n; ++i ) {
        minn[i] = 'z', maxn[i] = 'a';
        for ( int j = 1; j <= m; ++j ) {
            scanf(" %c",&s);
            minn[i] = min( minn[i], s );
            maxn[i] = max( maxn[i], s );
        }
    }
    for ( int i = 1; i <= n; ++i ) {
        bool flag = true;
        for ( int j = 1; j <= n; ++j ) {
            if ( i == j ) continue;
            if ( minn[i] >= maxn[j] ) {
                flag = false;
                break;
            }
        }
        putchar(flag?'1':'0');
    }
}