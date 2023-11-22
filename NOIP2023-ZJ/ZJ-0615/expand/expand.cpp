#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define maxn(x,num) tree[num][x].maxn
#define l(x,num) tree[num][x].l
#define r(x,num) tree[num][x].r
using namespace std;
const int MAXN=5e5+3;
struct Node{
    ll l,r,maxn;
};
Node tree[2][4*MAXN];
ll a[2][MAXN],n,m,c,q;
void pushup(int num,int N){
    maxn(num,N)=max(maxn(num*2,N),maxn(num*2+1,N));
}
void build(int N,int num,int L,int R){
    l(num,N)=L,r(num,N)=R;
    if(L==R){
        maxn(num,N)=a[N][L];
        return;
    }
    int mid=(L+R)/2;
    build(N,num*2,L,mid);
    build(N,num*2+1,mid+1,R);
    pushup(num,N);
}
void upd(int N,int num,int pos,ll val){
    if(l(num,N)==r(num,N)){
        maxn(num,N)=val;
        return;
    }
    int mid=(l(num,N)+r(num,N))/2;
    if(pos<=mid) upd(N,num*2,pos,val);
    else upd(N,num*2+1,pos,val);
    pushup(num,N);
}
ll find(int N,int num,int L,int R){
    if(L<=l(num,N)&&r(num,N)<=R){
        return maxn(num,N);
    }
    int mid=(l(num,N)+r(num,N))/2;
    ll ans=0;
    if(L<=mid) ans=max(ans,find(N,num*2,L,R));
    if(R>mid) ans=max(ans,find(N,num*2+1,L,R));
    return ans;
}
bool check(){

}
int main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>q;
    for(int i=1;i<=n;i++){
        cin>>a[0][i];
    }
    for(int i=1;i<=m;i++){
        cin>>a[1][i];
    }
    build(0,1,1,n);
    build(1,1,1,m);
    if(n<=1&&m<=1){
        cout<<(a[0][1]!=a[1][1]);
    }
    // else{
    //     cout<<check();
    // }
    for(int i=1;i<=q;i++){
        if(n<=1&&m<=1){
            int px,py;
            ll u=a[0][1],v=a[1][1];
            cin>>px>>py;
            for(int j=1;j<=px;j++){
                int kx,vx;
                cin>>kx>>vx;
                a[0][kx]=vx;
            }
            for(int j=1;j<=py;j++){
                int kx,vx;
                cin>>kx>>vx;
                a[1][kx]=vx;
            }
            cout<<(a[0][1]!=a[1][1]);
            a[0][1]=u;
            a[1][1]=v;
        }
    }
    return 0;
}