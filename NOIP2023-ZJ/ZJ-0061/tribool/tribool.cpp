#include <bits/stdc++.h>
using namespace std;
int n, m;
int typ[100005], id[100005];
int fa[200005];
int find( int x ) {
    if ( fa[x] == x ) return x;
    return (fa[x]=find(fa[x]));
}
/*
T:200001
F:200002
U:200003
*/
void work() {
    scanf("%d%d", &n, &m);
    for ( int i = 1; i <= 200003; ++i ) {
        fa[i] = i;
    }
    for ( int i = 1; i <= n; ++i ) {
        typ[i] = id[i] = 0;
    }
    char op;
    int x, y;
    while ( m-- ) {
        scanf(" %c%d", &op, &x);
        if ( op == 'U' ) {
            typ[x] = 3;
        } else if ( op == 'F' ) {
            typ[x] = -2;
        } else if ( op == 'T' ) {
            typ[x] = 2;
        } else {
            scanf("%d", &y);
            if ( op == '+' ) {
                if ( typ[y] ) {
                    if ( typ[y] == 3 ) {
                        typ[x] = 3;
                    } else {
                        typ[x] = typ[y];
                        id[x] = id[y];
                    }
                } else {
                    typ[x] = 1;
                    id[x] = y;
                }
            } else {
                if ( typ[y] ) {
                    if ( typ[y] == 3 ) {
                        typ[x] = 3;
                    } else {
                        typ[x] = -typ[y];
                        id[x] = id[y];
                    }
                } else {
                    typ[x] = -1;
                    id[x] = y;
                }
            }
        }
    }
    for ( int i = 1; i <= n; ++i ) {
        if ( typ[i] == 2 ) {
            fa[find(i)] = find(200001);
            fa[find(i+100000)] = find(200002);
        } else if ( typ[i] == -2 ) {
            fa[find(i)] = find(200002);
            fa[find(i+100000)] = find(200001);
        } else if ( typ[i] == 3 ) {
            fa[find(i)] = find(200003);
            fa[find(i+100000)] = find(200003);
        } else if ( typ[i] == 1 ) {
            fa[find(i)] = find(id[i]);
            fa[find(i+100000)] = find(id[i]+100000);
        } else {
            fa[find(i)] = find(id[i]+100000);
            fa[find(i+100000)] = find(id[i]);
        }
    }
    int ans = 0;
    for ( int i = 1; i <= n; ++i ) {
        if ( find(i) == find(i+100000) ) {
            ++ans;
        } else if ( find(i) == find(200003) || find(i+100000) == find(200003) ) {
            ++ans;
        }
    }
    printf("%d\n",ans);
}
int main() {
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    int t;
    scanf("%*d%d", &t);
    while (t--) work();
}