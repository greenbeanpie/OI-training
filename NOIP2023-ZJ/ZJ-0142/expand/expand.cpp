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
const int N=5e5+10;
ll tid, n, m, q, x[N], y[N], ox[N], oy[N];
namespace subtask1{
    /**
     * case n,m<=2000 tid<=7 
     * O(qnm) DP
    */
    int f[2020][2020];
    bool work(){
        memset(f, 0, sizeof(f));
        f[1][1]=1;
        REP(i, 1, n) REP(j, 1, m){
            if(i==1&&j==1) continue;
            if((x[i]-y[j])*(x[1]-y[1])>0){
                f[i][j]=f[i-1][j-1]||f[i][j-1]||f[i-1][j];
            }
        }
        return f[n][m];
    }
    void solve(){
        printf("%d", work());
        REP(i, 1, q){
            ll kx=rd(), ky=rd();
            REP(j, 1, kx){
                ll p=rd(), v=rd();
                x[p]=v;
            }
            REP(j, 1, ky){
                ll p=rd(), v=rd();
                y[p]=v;
            }
            printf("%d", work());
            REP(j, 1, n) x[j]=ox[j];
            REP(j, 1, m) y[j]=oy[j];
        }
    }
}
int main(){
    OPFI(expand);
    tid=rd(), n=rd(), m=rd(), q=rd();
    REP(i, 1, n) ox[i]=x[i]=rd();
    REP(i, 1, m) oy[i]=y[i]=rd();
    if(tid<=7){
        subtask1::solve();
    }
    return 0;
}