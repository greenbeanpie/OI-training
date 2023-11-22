#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define pii pair<int,int>
inline int read(void) {
    int sgn=1,x=0; char c=getchar();
    while(c< '0'||'9'< c) { c=='-' && (sgn=0); c=getchar(); }
    while('0'<=c&&c<='9') { x=x*10+c-'0'; c=getchar(); }
    return sgn ? x : -x;
}
void write(int x) {
    if(x<0) putchar('-'),x=-x;
    if(x>9) write(x/10);
    putchar('0'+x%10);
}
inline void clear(vector <int>&A) {
    vector <int> V;
    V.swap(A);
    return ;
}
int n,m,Ans;
int val[500005];  // 0 U  1-n val[i] n+1/-n-1 T/F
int nxt[500005];
vector <int> E[500111];
int vis[500111];  // 0 not vis  
inline void addE(int x,int y) {
    E[x].push_back(y);
    E[y].push_back(x);
}
void dfs(int x,int col) {
    vis[x]=col;
    for(int v : E[x]) if(!vis[v]) {
        dfs(v,col);
    }
}
inline void work() {
    n=read(); m=read(); Ans=0;
    for(int i=0; i<=n+1; ++i) val[i]=i,nxt[i]=i+n+1; nxt[0]=0; nxt[n+1]=2*n+2;
    for(int i=1; i<=m; ++i) {
        char c; int x,y;
        scanf("%c",&c);
        if(c=='+') { x=read(); y=read(); val[x]=val[y]; }
        if(c=='-') { x=read(); y=read(); val[x]=-val[y]; }
        if(c=='T') { x=read(); val[x]=n+1; }
        if(c=='F') { x=read(); val[x]=-n-1; }
        if(c=='U') { x=read(); val[x]=0; }
    }
    for(int i=1; i<=n; ++i) {
        if(val[i]<0) {
            addE(i,nxt[-val[i]]);
            addE(nxt[i],-val[i]);
        } else {
            addE(i,val[i]);
            addE(nxt[i],nxt[val[i]]);
        }
    }
    // for(int i=0; i<=n; ++i) cerr<<val[i]<<' ';
    // cerr<<endl;
    int cntcol=0;
    for(int i=0; i<=2*n+2; ++i) if(!vis[i]) dfs(i,++cntcol);
    // for(int i=0; i<=2*n+2; ++i) cerr<<vis[i]<<' ';
    // cerr<<endl;
    for(int i=1; i<=n; ++i) if(vis[i]==vis[nxt[i]]) {
        ++Ans;
    }
    write(Ans); puts("");
    for(int i=0; i<=2*n+2; ++i) clear(E[i]),vis[i]=0;
}
signed main() {
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    read(); int T=read();
    while(T--) work();
    return 0;
}