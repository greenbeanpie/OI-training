#include<bits/stdc++.h>
#define int long long
#define x r
#define y l
const int M = 1e5+7;
int n, m, k, d;
struct bonus{
    int l, r, v;
    static bool cmp(bonus x, bonus y){
        return x.l < y.l;
    }
} b[M];
namespace slv1{
    const int N = 1e3+7;
    std::vector<bonus> bon[N];
    int getbonus(int r, int t){
        if(bon[r].empty() || bon[r].front().y > t) return 0;
        return (--std::upper_bound(bon[r].begin(), bon[r].end(), bonus{t}, bonus::cmp))->v;
        /* int res = 0;
        for(int i=1; i<=m; i++){
            if(b[i].x == r && b[i].y <= t)
                res += b[i].v;
        }
        return res; */
    }
    int f[N][N], g[N];
    void main(){
        scanf("%lld%lld%lld%lld", &n, &m, &k, &d);
        for(int i=1; i<=m; i++)
            scanf("%lld%lld%lld", &b[i].x, &b[i].y, &b[i].v);
        for(int i=1; i<=n; i++)
            bon[i].clear();
        for(int i=1; i<=m; i++)
            bon[b[i].x].push_back(b[i]);
        for(int i=1; i<=n; i++){
            std::sort(bon[i].begin(), bon[i].end(), bonus::cmp);
            for(int j=1; j<bon[i].size(); j++)
                bon[i][j].v += bon[i][j-1].v;
        }
        for(int i=1; i<=n; i++){
            g[i] = 0;
            for(int j=0; j<=std::min(k, i); j++){
                if(j == 0){
                    f[i][j] = g[i-1];
                }
                else{
                    f[i][j] = f[i-1][j-1] - d;
                    f[i][j] += getbonus(i, j);
                }
                g[i] = std::max(g[i], f[i][j]);
            }
        }
        printf("%lld\n", g[n]);
    }
}
namespace slv2{
    void main(){
        scanf("%lld%lld%lld%lld", &n, &m, &k, &d);
        int ans = 0;
        for(int i=1; i<=m; i++){
            int x, y, v; scanf("%lld%lld%lld", &x, &y, &v);
            if(y > k) continue;
            ans += std::max(0ll, v-d*y);
        }
        printf("%lld\n", ans);
    }
}
/* namespace slv3{
    namespace lsh{
        int d[M<<1], len;
        void clear(){
            len = 0;
        }
        void push(int x){
            d[++len] = x;
        }
        void init(){
            std::sort(d+1, d+len+1);
            len = std::unique(d+1, d+len+1) - d - 1;
        }
        int fd(int x){
            return std::lower_bound(d+1, d+len+1, x) - d;
        }
    }
    const int N = 1e3+7;
    std::vector<bonus> bon[M<<1];
    int getbonus(int r, int t){
        if(bon[r].empty() || bon[r].front().y > t) return 0;
        return (--std::upper_bound(bon[r].begin(), bon[r].end(), bonus{t}, bonus::cmp))->v;
        \/\* int res = 0;
        for(int i=1; i<=m; i++){
            if(b[i].x == r && b[i].y <= t)
                res += b[i].v;
        }
        return res; \*\/
    }
    int f[2][N], g[2];
    void main(){
        scanf("%lld%lld%lld%lld", &n, &m, &k, &d);
        lsh::clear();
        for(int i=1; i<=m; i++){
            scanf("%lld%lld%lld", &b[i].x, &b[i].y, &b[i].v);
            lsh::push(b[i].x); lsh::push(b[i].x-b[i].y+1);
        }
        lsh::init();
        for(int i=1; i<=lsh::len; i++)
            bon[i].clear();
        for(int i=1; i<=m; i++)
            bon[lsh::fd(b[i].x)].push_back(b[i]);
        for(int i=1; i<=lsh::len; i++){
            std::sort(bon[i].begin(), bon[i].end(), bonus::cmp);
            for(int j=1; j<bon[i].size(); j++)
                bon[i][j].v += bon[i][j-1].v;
        }
        memset(f, 0, sizeof(f));
        g[0] = g[1] = 0;
        for(int i=1; i<=lsh::len; i++){
            int k = i&1;
            g[k] = 0;
            for(int j=0; i-j>=0 && lsh::d[i]-lsh::d[i-j]<=::k; j++){
                if(j == 0){
                    f[k][j] = g[!k];
                }
                else{
                    f[k][j] = f[!k][j-1] - d*(lsh::d[i]-lsh::d[i-1]);
                    f[k][j] += getbonus(i, lsh::d[i]-lsh::d[i-j]);
                }
                g[k] = std::max(g[k], f[k][j]);
            }
        }
        printf("%lld\n", g[lsh::len&1]);
    }
} */
int c, t;
void slv(){
    if(c <= 9) slv1::main();
    else if(c >= 17 && c <= 18) slv2::main();
    // else slv3::main();
}
signed main(){
    freopen("run.in", "r", stdin);
    freopen("run.out", "w", stdout);
    scanf("%lld%lld", &c, &t);
    while(t--) slv();
    return 0;
}
