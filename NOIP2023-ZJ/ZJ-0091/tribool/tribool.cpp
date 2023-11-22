#include<bits/stdc++.h>
using namespace std;
#define clo 1000.*clock()/CLOCKS_PER_SEC
#ifndef xxzx
#define endl '\n'
#endif
using ll=long long;
using PII=pair<int,int>;
const int N=2e5+10;
bool mem1;
int Case,T,n,m,x[N];
int f(int x) {
    if(x<n+2) return x+n+2;
    if(x==n+2) return x;
    return x-(n+2);
}
int fa[N],sp[N];
int find(int x) { 
    if(x==fa[x]) return x;
    return fa[x]=find(fa[x]);
}
void Merge(int x,int y) {
    x=find(x), y=find(y);
    fa[x]=y;
}
void solve() {
    cin>>n>>m;
    for(int i=1;i<=n;i++) x[i]=i;
    for(int i=1,a,b;i<=m;i++) {
        char op; cin>>op;
        if(op=='+') {
            cin>>a>>b;
            x[a]=x[b];
        }
        else if(op=='-') {
            cin>>a>>b;
            x[a]=f(x[b]);
        }
        else {
            cin>>a;
            if(op=='T') x[a]=n+1;
            if(op=='F') x[a]=f(n+1);
            if(op=='U') x[a]=n+2;
        }
    }
    for(int i=1;i<=2*n+4;i++) fa[i]=i, sp[i]=0;
    for(int i=1;i<=n;i++) Merge(i,x[i]), Merge(f(i),f(x[i]));
    // for(int i=1;i<=n;i++) cerr<<find(x[i])<<" "; cerr<<endl;
    sp[n+2]=1;
    for(int i=1;i<=n;i++) if(find(i)==find(f(i)))
        sp[i]=sp[f(i)]=1;
    int ans=0;
    for(int i=1;i<=n;i++) ans+=sp[find(i)];
    cout<<ans<<endl;
}
bool mem2;
int main() {
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    ios::sync_with_stdio(false), cin.tie(nullptr);

    cin>>Case>>T;
    while(T--) solve();

    #ifdef xxzx
    cerr<<"Time "<<clo<<"MS"<<endl;
    cerr<<"Memory "<<abs(&mem1-&mem2)/1024./1024.<<"MB"<<endl;
    #endif
    return 0;
}