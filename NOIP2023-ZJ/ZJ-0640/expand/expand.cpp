#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 1;

int c, n, m, q, a[N], b[N], x[N], y[N];

void sub1(){
}

int main(){
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);
    scanf("%d%d%d%d", &c, &n, &m, &q);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= m; i++)
        scanf("%d", &b[i]);
    memcpy(x + 1, a + 1, sizeof(int) * n);
    memcpy(y + 1, b + 1, sizeof(int) * m);
    if (c == 1){
            if (x[1] != y[1]) printf("1");
            else printf("0");
        }
    else if (c == 2){
        if (x[1] > y[1] && x[2] > y[2] || x[1] < y[1] && x[2] < y[2]) printf("1");
        else printf("0");
    }
    else{
        int minx = 2e9, maxx = -1, miny = 2e9, maxy = -1;
        for (int i = 1; i <= n; i++){
                minx = min(minx, x[i]);
                maxx = max(maxx, x[i]);
            }
        for (int i = 1; i <= m; i++){
            miny = min(miny, y[i]);
            maxy = max(maxy, y[i]);
        }
        if (x[1] < y[1] && x[n] < y[m] && minx < miny && maxx < maxy || x[1] > y[1] && x[n] > y[m] && minx > miny && maxx > maxy) printf("1");
        else printf("0");
    }
    while (q--){
        int kx, ky;
        scanf("%d%d", &kx, &ky);
        memcpy(x + 1, a + 1, sizeof(int) * n);
        memcpy(y + 1, b + 1, sizeof(int) * m);
        while (kx--){
            int p, v;
            scanf("%d%d", &p, &v);
            x[p] = v;
        }
        while (ky--){
            int p, v;
            scanf("%d%d", &p, &v);
            y[p] = v;
        }
        if (c == 1){
            if (x[1] != y[1]) printf("1");
            else printf("0");
        }
        else if (c == 2){
            if (x[1] > y[1] && x[2] > y[2] || x[1] < y[1] && x[2] < y[2]) printf("1");
            else printf("0");
        }
        else{
            int minx = 2e9, maxx = -1, miny = 2e9, maxy = -1;
            for (int i = 1; i <= n; i++){
                minx = min(minx, x[i]);
                maxx = max(maxx, x[i]);
            }
            for (int i = 1; i <= m; i++){
                miny = min(miny, y[i]);
                maxy = max(maxy, y[i]);
            }
            if (x[1] < y[1] && x[n] < y[m] && minx < miny && maxx < maxy || x[1] > y[1] && x[n] > y[m] && minx > miny && maxx > maxy) printf("1");
            else printf("0");
        }
    }
    return 0;
}