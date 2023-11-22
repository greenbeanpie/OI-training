#include<bits/stdc++.h>
using namespace std;
#define clo 1000.*clock()/CLOCKS_PER_SEC
#ifndef xxzx
#define endl '\n'
#endif
using ll=long long;
using PII=pair<int,int>;
const int N=2e3+10;
bool mem1;
int Case,n,m,q,a[N],b[N],c[N],d[N];
int dp[2][N][N];
bool calc() {
    memset(dp,0,sizeof(dp));
    for(int op=0;op<=1;op++) {
        dp[op][0][0]=1;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++) {
                if(!op) {
                    if(a[i]<b[j]) 
                        dp[op][i][j]=dp[op][i-1][j]|dp[op][i][j-1]|dp[op][i-1][j-1];
                }
                else {
                    if(a[i]>b[j]) 
                        dp[op][i][j]=dp[op][i-1][j]|dp[op][i][j-1]|dp[op][i-1][j-1];
                }
            }
        // if(!op) {
            // for(int i=1;i<=n;i++) {
            //     for(int j=1;j<=m;j++) cerr<<dp[0][i][j];
            //     cerr<<endl;
            // }
        //     for(int j=1;j<=m;j++) {
        //         for(int i=1;i<=n;i++) cerr<<dp[0][i][j];
        //         cerr<<endl;
        //     }
        // }
        if(dp[op][n][m]) return true;
    }
    return false;
}
bool mem2;
int main() {
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    ios::sync_with_stdio(false), cin.tie(nullptr);

    cin>>Case>>n>>m>>q;
    for(int i=1;i<=n;i++) cin>>a[i], c[i]=a[i];
    for(int i=1;i<=m;i++) cin>>b[i], d[i]=b[i];
    cout<<calc();
    while(q--) {
        int kx,ky; cin>>kx>>ky;
        for(int i=1,p,x;i<=kx;i++) cin>>p>>x, a[p]=x;
        for(int i=1,p,x;i<=ky;i++) cin>>p>>x, b[p]=x;
        // for(int i=1;i<=n;i++) cerr<<a[i]<<" "; cerr<<endl;
        // for(int i=1;i<=m;i++) cerr<<b[i]<<" "; cerr<<endl;
        cout<<calc();
        for(int i=1;i<=n;i++) a[i]=c[i];
        for(int i=1;i<=m;i++) b[i]=d[i];
    }
    cout<<endl;

    #ifdef xxzx
    cerr<<"Time "<<clo<<"MS"<<endl;
    cerr<<"Memory "<<abs(&mem1-&mem2)/1024./1024.<<"MB"<<endl;
    #endif
    return 0;
}