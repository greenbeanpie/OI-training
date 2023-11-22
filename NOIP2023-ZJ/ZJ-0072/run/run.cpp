#include<bits/stdc++.h>
using namespace std;
#define ll long long 
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
ll n,m,K,D;
struct node{ll l,r,v;}a[100010];
bool cmp(node a,node b){if(a.r!=b.r)return a.r<b.r;return a.l<b.l;}
void subB(){
    ll res=0;
    f(i,1,m)if(a[i].r-a[i].l+1<=K)
    res+=max(0ll,a[i].v-D*(a[i].r-a[i].l+1));
    cout<<res<<endl;
}
ll st[100010][20];
ll lg[100010];
void up(ll pos,ll k){
    st[pos][0]=k;
    f(i,1,19)if(pos-(1<<i-1)<=0)st[pos][i]=st[pos][i-1];
    else st[pos][i]=max(st[pos][i-1],st[pos-(1<<i-1)][i-1]);
}ll getm(ll l,ll r){
    ll g=lg[r-l+1];
    return max(st[r][g],st[l+(1<<g)-1][g]);
}
ll dp[100010],c[100010];
ll pre[100010],r[100010],l[100010];
ll mx[100010];
ll qqq[100010];
void subC(){ll res=0;
// cout<<"qwq\n";
    f(i,1,m)r[i]=a[i].r,c[i]=c[i-1]+a[i].v,l[i]=a[i].l,dp[i]=0,mx[i]=0;
    f(i,1,m){pre[i]=0;
        pre[i]=upper_bound(r+1,r+m+1,a[i].l-2)-r-1;
    }
    // f(i,1,m)cout<<a[i].l<<" "<<a[i].r<<endl;
    // f(i,1,m)cout<<pre[i]<<" ";cout<<endl;
    f(i,1,m){
        ll L=lower_bound(l+1,l+m+1,r[i]-K+1)-l,R=i-1;
        // cout<<i<<" "<<L<<" "<<R<<endl;
        // if(r[i]-l[L]+1>K)puts("QWq");
        if(L<=R)dp[i]=max(0ll,c[i]-D*(r[i]+1)+getm(L,R));
        if(a[i].r-a[i].l+1<=K)dp[i]=max(dp[i],mx[pre[i]]+a[i].v-D*(a[i].r-a[i].l+1));
        up(i,mx[pre[i]]-c[i-1]+D*l[i]);
        res=max(res,dp[i]);mx[i]=max(mx[i-1],dp[i]);
    }cout<<res<<endl;
}
ll stk[100010],tp;
ll val[100010];
ll t[100010];
ll A[100010],o;
ll ls[100010];
ll LIM;
#define lb(x) (x&(-x))
void add(ll x,ll k){
    while(x<=LIM)t[x]+=k,x+=lb(x);
}ll ask(ll x){
    ll res=0;while(x)res+=t[x],x-=lb(x);
    return res;
}
void bf(){
    ll res=0;LIM=m;
    f(i,1,m)A[i]=a[i].l,t[i]=0;sort(A+1,A+m+1);
    f(i,1,m)ls[i]=lower_bound(A+1,A+m+1,a[i].l)-A;
    f(i,1,m)r[i]=a[i].r,c[i]=c[i-1]+a[i].v,l[i]=a[i].l,dp[i]=0,mx[i]=0;
    f(i,1,m){pre[i]=0;
        pre[i]=upper_bound(r+1,r+m+1,a[i].l-2)-r-1;
    }
    
    stk[++tp]=1;val[1]=a[1].v;
    dp[1]=(r[1]-l[1]+1>K)?0ll:max(0ll,a[1].v-D*(a[1].r-a[1].l+1));res=dp[1];
    mx[1]=dp[1];add(ls[1],a[1].v);
    f(i,2,m){
        // ll x=a[i].v;
        // while(tp&&a[i].l<=a[stk[tp]].l)x+=val[tp--];
        // stk[++tp]=i,val[tp]=x;ll s=0;
        // for(int j=tp;j>=1;j--){
        //     s+=val[j];ll pos=stk[j];
        //     if(r[i]-l[pos]+1>K)break;
        //     dp[i]=max(dp[i],mx[pre[pos]]+s-D*(r[i]-l[pos]+1));
        // }
        ll M=l[i];add(ls[i],a[i].v);
        for(int j=i;j>=1;j--)if(r[i]-l[j]+1<=K){
            // M=min(M,l[j]);//if(M!=l[j])continue;
            ll x=ask(m)-ask(ls[j]-1);
            // f(k,1,i)if(l[k]>=l[j]&&r[k]<=r[i])x+=a[k].v;
            dp[i]=max(dp[i],mx[pre[j]]+x-D*(r[i]-l[j]+1));
        }
        
        res=max(res,dp[i]);mx[i]=max(mx[i-1],dp[i]);
    }cout<<res<<endl;
    // f(i,1,m)cout<<dp[i]<<" ";cout<<endl;
}
vector<ll>P[100010];
void bbf(){
    ll res=0;LIM=n;
    f(i,1,m)A[i]=a[i].l,t[i]=0;sort(A+1,A+m+1);
    // f(i,1,m)ls[i]=lower_bound(A+1,A+m+1,a[i].l)-A;
    f(i,1,m)r[i]=a[i].r,c[i]=c[i-1]+a[i].v,l[i]=a[i].l;
    f(i,1,n)dp[i]=0,mx[i]=0,t[i]=0;
    f(i,1,n){pre[i]=0;
        pre[i]=upper_bound(r+1,r+m+1,i-2)-r-1;
        pre[i]=r[pre[i]];
    }
    f(i,1,m)P[r[i]].push_back(i);
    f(i,1,n){
        for(int j=0;j<P[i].size();j++){
            ll ii=P[i][j];
            add(l[ii],a[ii].v);
        }for(int j=i;j>=1;j--)if(i-j+1<=K){
            // M=min(M,l[j]);//if(M!=l[j])continue;
            ll x=ask(n)-ask(j-1);
            // f(k,1,i)if(l[k]>=l[j]&&r[k]<=r[i])x+=a[k].v;
            dp[i]=max(dp[i],mx[pre[i]]+x-D*(i-j+1));
        }mx[i]=max(mx[i-1],dp[i]);res=max(res,dp[i]);
    }
    cout<<res<<endl;
}
int main(){
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    f(i,2,100000)lg[i]=lg[i>>1]+1;
    ll C=d,TT=d;while(TT--){
        n=d,m=d,K=d,D=d;
        f(i,1,m){
            ll x=d,y=d,v=d;
            a[i]={x-y+1,x,v};
        }
        sort(a+1,a+m+1,cmp);
        bool flB=1,flC=1;
        f(i,1,m-1){
            if(a[i].r>=a[i+1].l)flB=0;
            if(a[i].l>=a[i+1].l)flC=0;
        }
        if(flB){subB();continue;}
        if(flC){subC();continue;}
        bf();
    }
    return 0;
}