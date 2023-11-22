#include <iostream>
#include <string.h>
using namespace std;
const int N = 500005, MAX = 1e9+7;
int n, m, q, x[N], y[N], cx[N], cy[N];
int read(){
    int x = 0;
    char a = getchar();
    while(a < '0' || '9' < a) a = getchar();
    while('0' <= a && a <= '9') x = (x << 1) + (x << 3) + (a ^ 48), a = getchar();
    return x;
}
void write(int x){
    if(x > 9) write(x / 10);
    putchar(x | 48);
}
bool lt(int x[], int y[]){
    int maxx = x[1], minx = x[1], maxy = y[1], miny = y[1];
    if(x[1] - y[1] <= 0 || x[n] - y[m] <= 0) return 0;
    for(int i = 1; i <= n; ++ i){
        if(x[i] > maxx) maxx = x[i];
        if(x[i] < minx) minx = x[i];
    }
    for(int i = 1; i <= m; ++ i){
        if(y[i] > maxy) maxy = y[i];
        if(y[i] < miny) miny = y[i];
    }
    if(maxx - maxy <= 0 || minx - miny <= 0) return 0;
    int lx = 1, rx, ly = 1, ry;
    while(lx <= n){
        if(x[lx] <= y[ly]) return 0;
        minx = lx;
        rx = lx;
        while(rx < n && x[rx + 1] <= x[rx]) if(x[++ rx] < x[minx]) minx = rx;
        while(ly <= m){
            ry = ly;
            miny = MAX;
            while(ry < m && y[ry + 1] < x[lx]) if(y[++ ry] < miny) miny = y[ry];
            if(miny >= minx){
                if(y[ly] >= minx) return 0;
                break;
            }
            ly = ry + 1;
            if(ly > m){
                ly = m;
                break;
            }
        }
        lx = rx + 1;
    }
    return 1;
}
int main(){
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);
    read(), n = read(), m = read(), q = read();
    for(int i = 1; i <= n; ++ i) cx[i] = x[i] = read();
    for(int i = 1; i <= m; ++ i) cy[i] = y[i] = read();
    putchar(lt(cx, cy) || lt(cy, cx)? '1': '0');
    for(int i = 1; i <= q; ++ i){
        int kx = read(), ky = read();
        memset(cx, -1, sizeof cx), memset(cy, -1, sizeof cy);
        for(int j = 1, p; j <= kx; ++ j) p = read(), cx[p] = read();
        for(int j = 1, p; j <= ky; ++ j) p = read(), cy[p] = read();
        for(int j = 1; j <= n; ++ j) if(cx[j] == -1) cx[j] = x[j];
        for(int j = 1; j <= m; ++ j) if(cy[j] == -1) cy[j] = y[j];
        putchar(lt(cx, cy) || lt(cy, cx)? '1': '0');
    }
    return 0;
}
