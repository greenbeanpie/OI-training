#include<bits/stdc++.h>
#define For(i,l,r) for(int i=(l);i<=(r);++i)
const int N=500010;
using namespace std;
int c,n,m,q;
int X[N],Y[N],pre_X[N],pre_Y[N];
void solve()
{
    if((n==1) && (m==1)){if(X[1]!=Y[1])cout<<"1";else cout<<"0";return;}
    if((n==1) && (m==2))
    {
        if((X[1]<Y[1]) && (X[1]<Y[2])){cout<<"1";return;}
        if((X[1]>Y[1]) && (X[1]>Y[2])){cout<<"1";return;}
        cout<<"0";return;
    }
    if((n==2) && (m==1))
    {
        if((X[1]<Y[1]) && (X[2]<Y[1])){cout<<"1";return;}
        if((X[1]>Y[1]) && (X[2]>Y[1])){cout<<"1";return;}
        cout<<"0";return;
    }
    if((n==2) && (m==2))
    {
        if((X[1]<Y[1]) && (X[2]<Y[2])){cout<<"1";return;}
        if((X[1]>Y[1]) && (X[2]>Y[2])){cout<<"1";return;}
        cout<<"0";return;
    }
}
int main()
{
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>q;
    For(i,1,n)cin>>X[i];For(i,1,m)cin>>Y[m];
    solve();
    while(q--)
    {
        int kx,ky;cin>>kx>>ky;
        For(i,1,n){pre_X[i]=X[i];}For(i,1,m){pre_Y[i]=Y[i];}
        For(i,1,kx){int p,v;cin>>p>>v;X[p]=v;}
        For(i,1,ky){int p,v;cin>>p>>v;Y[p]=v;}
        solve();
        For(i,1,n){X[i]=pre_X[i];}For(i,1,m)Y[i]=pre_Y[i];
    }
    return 0;
}