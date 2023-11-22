#include<bits/stdc++.h>
using namespace std;
#define ll int
#define f(i,a,b) for(int i=(a);i<=(b);i++)
ll rd(){
    ll x=0,f=1;
    char c=getchar();
    while(!isdigit(c)){
        if(c=='-')f=-1;
        c=getchar();
    }while(isdigit(c)){
        x=x*10+c-'0';
        c=getchar();
    }return x*f;
}
#define d rd()
ll n,m,Q;
ll a[500010],b[500010];
vector<pair<ll,ll> >A,B;
ll dp[2010][2010];
ll pos[2020][2020];
ll s[2020][2020];
bool ch(){
    f(i,1,n)f(j,1,m)dp[i][j]=0,s[i][j]=0;;
    if(a[1]<=b[1])return 0;
    f(i,1,m)if(a[1]>b[i])dp[1][i]=1;else break;
    f(j,1,m)s[1][j]=s[1][j-1]+dp[1][j];
    f(i,2,n){
        ll l=-1,r=-1;
        f(j,1,m){
            if(a[i]<=b[j]){l=r=-1;continue;}
            if(l==-1)l=j;r=j;
            if(s[i-1][r]-s[i-1][l-1]>0)dp[i][j]=1;
        }f(j,1,m)s[i][j]=s[i][j-1]+dp[i][j];
    }
    // f(i,1,n){f(j,1,m)cout<<dp[i][j];cout<<endl;}
    return dp[n][m];
}bool get(){
    if(ch())return 1;
    swap(n,m);f(i,1,max(n,m))swap(a[i],b[i]);
    bool fl=ch();
    swap(n,m);f(i,1,max(n,m))swap(a[i],b[i]);
    return fl;
}
int main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    ll C=d;n=d,m=d,Q=d;
    // n=d,m=d;
    f(i,1,n)a[i]=d;f(i,1,m)b[i]=d;
    // ch();
    if(get())putchar('1');else putchar('0');
    // puts("qwq");
    while(Q--){
        ll x=d,y=d;
        A.clear(),B.clear();
        f(i,1,x){
            ll pos=d,v=d;
            A.push_back({pos,a[pos]});
            a[pos]=v;
        }f(i,1,y){
            ll pos=d,v=d;
            B.push_back({pos,b[pos]});
            b[pos]=v;
        }
        // f(i,1,n)cout<<a[i]<<" ";cout<<endl;
        // f(i,1,m)cout<<b[i]<<" ";cout<<endl;
        if(get())putchar('1');else putchar('0');
        f(i,0,x-1)a[A[i].first]=A[i].second;
        f(i,0,y-1)b[B[i].first]=B[i].second;
        // f(i,1,n)cout<<a[i]<<" ";cout<<endl;
        // f(i,1,m)cout<<b[i]<<" ";cout<<endl;
        // puts("");
    }
    return 0;
}