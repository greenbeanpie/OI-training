#include<bits/stdc++.h>
const int N = 5e5+7;
int c, n, m, q, a[N], b[N], ta[N], tb[N];
namespace slv1{
    int f[2][N];
    bool main(){
        memset(f, 0, sizeof(f));
        f[0][1] = true;
        for(int i=1; i<=m; i++){
            int k = i&1;
            for(int j=1; j<=n; j++){
                if(a[j] < b[i] && (f[!k][j] || f[k][j-1]))
                    f[k][j] = true;
                else
                    f[k][j] = false;
            }
        }
        return f[m&1][n];
    }
}
namespace slv2{
    int max[N], min[N], cnt;
    bool main(){
        for(int i=1; i<=n; i++)
            if(a[i] >= b[m])
                return 0;
        max[cnt=1] = b[1];
        min[cnt] = b[1];
        for(int i=2; i<=m; i++){
            if(b[i] > max[cnt]){
                max[++cnt] = b[i];
                min[cnt] = b[i];
            }
            else
                min[cnt] = std::min(min[cnt], b[i]);
        }
        int r = 1, low = a[1];
        for(int i=1; i<cnt; i++){
            while(r < n && max[i] > a[r+1]){
                r++; low = std::min(low, a[r]);
            }
            if(low >= min[i])
                return 0;
        }
        return 1;
    }
}
bool slv(){
    if(c <= 7) return slv1::main();
    if(c <= 14) return slv2::main();
    return 0;
}
int main(){
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);
    scanf("%d%d%d%d", &c, &n, &m, &q);
    for(int i=1; i<=n; i++)
        scanf("%d", a+i);
    for(int j=1; j<=m; j++)
        scanf("%d", b+j);
    memcpy(ta, a, sizeof(a));
    memcpy(tb, b, sizeof(b));
    do{
        if(a[1] > b[1]){
            for(int i=1; i<=n; i++)
                a[i] = -a[i];
            for(int j=1; j<=m; j++)
                b[j] = -b[j];
            printf("%d", slv());
        }else if(a[1] == b[1]){
            printf("0");
        }else{
            printf("%d", slv());
        }
        if(!q) break;
        memcpy(a, ta, sizeof(a));
        memcpy(b, tb, sizeof(b));
        int k1, k2; scanf("%d%d", &k1, &k2);
        for(int i=1; i<=k1; i++){
            int p, v; scanf("%d%d", &p, &v);
            a[p] = v;
        }
        for(int j=1; j<=k2; j++){
            int p, v; scanf("%d%d", &p, &v);
            b[p] = v;
        }
    }while(q--);
    printf("\n");
    return 0;
}
