#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,q;
int x[N],y[N];

inline void solve(){
    if(x[1]==y[1])return cout<<0,void();
    if(n==1&&m==1)cout<<(x[1]==y[1]?0:1);
    else if(n<=2&&m<=2)
    {
        if(n==1&&m==2)
        {
            if(x[1]<y[1])
            {
                if(x[1]<y[2])cout<<1;
                else cout<<0;
            }
            else {
                if(x[1]>y[2])cout<<1;
                else cout<<0;
            }
        }
        else if(n==2&&m==1)
        {
            if(x[1]<y[1])
            {
                if(x[2]<y[1])cout<<1;
                else cout<<0;
            }
            else {
                if(x[2]>y[1])cout<<1;
                else cout<<0;
            }
        }
        else {
            if(x[1]<y[1])
            {
                if(x[2]<y[2])cout<<1;
                else cout<<0;
            }
            else {
                if(x[2]>y[2])cout<<1;
                else cout<<0;
            }
        }
    }
}

signed main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    int C;cin>>C>>n>>m>>q;
    for(int i=1;i<=n;i++)cin>>x[i];
    for(int i=1;i<=m;i++)cin>>y[i];
    solve();
    while(q--){
        int kx,ky;cin>>kx>>ky;
        for(int i=1;i<=kx;i++)
        {
            int px,v;cin>>px>>v;
            x[px]=v;
        }
        for(int i=1;i<=ky;i++)
        {
            int py,v;cin>>py>>v;
            y[py]=v;
        }
        solve();
    }
    return 0;
}