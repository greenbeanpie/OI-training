#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define OPFI(x) freopen(#x".in", "r", stdin);\
                freopen(#x".out", "w", stdout)
#define REP(i, a, b) for(int i=(a); i<=(b); ++i)
#define REPd(i, a, b) for(int i=(a); i>=(b); --i)
inline ll rd(){
    ll r=0, k=1; char c=0; while(!isdigit(c=getchar())) if(c=='-') k=-k;
    while(isdigit(c)) r=r*10+c-'0', c=getchar(); return r*k;
}
ll tid, T, n, m, k, d;
namespace subtask1{
    /**
     * DP case n<=1000
     * O(Tnk)
    */
    ll f[1010][1010], w[1010][1010], g[1010][1010];
    void solve(){
        while(T--){
            memset(f, 0xcf, sizeof(f)); 
            memset(g, 0xcf, sizeof(g)); 
            memset(w, 0, sizeof(w));
            n=rd(), m=rd(), k=rd(), d=rd();
            REP(i, 1, m){
                ll x=rd(), y=rd(), v=rd();
                w[x][y]+=v;
            }
            REP(i, 1, n) REP(j, 1, n) w[i][j]+=w[i][j-1];
            f[0][0]=0;
            REP(i, 0, k) g[0][i]=0;
            REP(i, 1, n){
                g[i][0]=f[i][0]=g[i-1][k];
                REP(j, 1, k){
                    f[i][j]=f[i-1][j-1]-d+w[i][j];
                }
                REP(j, 1, k) g[i][j]=max(g[i][j-1], f[i][j]);
            }
//            REP(i, 1, n) REP(j, 0, k){
//                fprintf(stderr, "%lld%c", f[i][j], " \n"[j==k]);
//            }
            printf("%lld\n", g[n][k]);
        }
    }
}
int main(){
    OPFI(run);
    tid=rd(), T=rd();
    if(tid<=9){
        subtask1::solve();
    }
    return 0;
}