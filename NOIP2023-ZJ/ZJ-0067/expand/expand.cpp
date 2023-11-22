#include<bits/stdc++.h>
using namespace std;
const int N=500005,INF=0x3f3f3f3f;
int n,m,q,a[N],b[N],A[N],B[N];
struct node {
    int x,y;
    bool operator <(const node &o) const {return x!=o.x?x<o.x:y<o.y;}
};
void chkmax(node &x,node y) {if(x<y) x=y;}
void chkmin(node &x,node y) {if(y<x) x=y;}
struct bit {
    int n;
    node a[N],b[N];
    void init(int _n,int *_a) {
        n=_n;
        for(int i=1;i<=n;i++) a[i]=b[i]=(node){_a[i],i};
        for(int i=2;i<=n;i++) {
            chkmax(a[i],a[i-1]);
            chkmin(b[i],b[i-1]);
        }
    }
    int askmx(int x) {
        return a[x].y;
    }
    int askmn(int x) {
        return b[x].y;
    }
} ta,tb;
int fun(int n,int m) {
    if(n==1||m==1) return 1;
    int pa=ta.askmx(n-1),pb=tb.askmn(m-1);
    int ka=(A[pa]>B[tb.askmx(m-1)]);
    int kb=(A[ta.askmn(n-1)]>B[pb]);
    if(!ka&&!kb) return 0;
    if(ka&&kb) return fun(pa,pb);
    if(ka) return fun(pa,m);
    if(kb) return fun(n,pb);
    return -1;
}
int calc() {
    if(A[1]==B[1]) return 0;
    int flag=0;
    if(A[1]<B[1]) {
        flag=1;
        swap(n,m);
        swap(A,B);
    }
    if(A[n]<=B[m]) {
        if(flag) {
            swap(n,m);
            swap(A,B);
        }
        return 0;
    }
    ta.init(n,A);
    tb.init(m,B);
    int pa=ta.askmx(n),pb=tb.askmn(m),ans=1;
    if(A[pa]<=B[tb.askmx(m)]) ans=0;
    if(A[ta.askmn(n)]<=B[pb]) ans=0;
    if(ans) ans=fun(pa,pb);
    if(!ans) {
        if(flag) {
            swap(n,m);
            swap(A,B);
        }
        return 0;
    }
    reverse(A+1,A+n+1);
    reverse(B+1,B+m+1);
    ta.init(n,A); tb.init(m,B);

    pa=n-pa+1; pb=m-pb+1;
    if(ans) ans=fun(pa,pb);

    reverse(A+1,A+n+1);
    reverse(B+1,B+m+1);
    if(flag) {
        swap(n,m);
        swap(A,B);
    }
    return ans;
}
int main() {
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int c;
    cin>>c>>n>>m>>q;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++) cin>>b[i];
    for(int i=1;i<=n;i++) A[i]=a[i];
    for(int i=1;i<=m;i++) B[i]=b[i];
    cout<<calc();
    while(q--) {
        int kx,ky;
        cin>>kx>>ky;
        for(int i=1;i<=n;i++) A[i]=a[i];
        for(int i=1;i<=m;i++) B[i]=b[i];
        for(int i=1;i<=kx;i++) {
            int px,vx;
            cin>>px>>vx;
            A[px]=vx;
        }
        for(int i=1;i<=ky;i++) {
            int py,vy;
            cin>>py>>vy;
            B[py]=vy;
        }
        cout<<calc();
    }
    return 0;
}