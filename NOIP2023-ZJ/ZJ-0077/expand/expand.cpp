#include <bits/stdc++.h>
#define int long long 
#define pb push_back
using namespace std;
const int INF=1e6+5;
const int INFN=2e3+5;
int c,n,m,q,x[INF],y[INF],f[INF],fl,f1[INF],xx[INF],yy[INF];
int query() {
    if (x[1]==y[1]) return 0;
    int op=(x[1]<y[1]);
    f[1]=1;
    for (int j=2;j<=m;j++) {
        f[j]=0;
        if (op==1) {
            if (x[1]<y[j]) f[j]=f[j-1];
        } 
        else {
            if (x[1]>y[j]) f[j]=f[j-1];
        }
    }
    for (int i=2;i<=n;i++) {
        for (int j=1;j<=m;j++) f1[j]=f[j];
        for (int j=1;j<=m;j++) {
            f[j]=0;
            if (op==1) {
                if (x[i]<y[j]) f[j]=f[j-1]|f1[j];
            } 
            else {
                if (x[i]>y[j]) f[j]=f[j-1]|f1[j];
            }
        }
        int fl=0;
        for (int j=1;j<=m;j++) fl|=f[j];
        if (!fl) return 0;
        // for (int j=1;j<=m;j++) cerr<<f[j]<<" ";
        // cerr<<" endl\n";
    }
    return f[m];
}
signed main()
{
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>c>>n>>m>>q;
    for (int i=1;i<=n;i++) cin>>x[i];
    for (int i=1;i<=m;i++) cin>>y[i];
    cout<<query();
    for (int i=1;i<=q;i++) {
        int kx=0,ky=0;
        cin>>kx>>ky;
        vector <int> cntx,cnty;
        for (int i=1;i<=kx;i++) {
            int a=0,b=0;
            cin>>a>>b;
            xx[a]=x[a];x[a]=b;
            cntx.pb(a);
        }
        for (int i=1;i<=ky;i++) {
            int a=0,b=0;
            cin>>a>>b;
            yy[a]=y[a];y[a]=b;
            cnty.pb(a);
        }
        cout<<query();
        for (int i:cntx) x[i]=xx[i];
        for (int i:cnty) y[i]=yy[i];
    }
    cout<<"\n";
    return 0;
}