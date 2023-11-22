#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i=(j),i##_=(k);i<=i##_;i++)
#define per(i,j,k) for(int i=(j),i##_=(k);i>=i##_;i--)
#define ckmn(i,j) (i=min(i,j))
#define ckmx(i,j) (i=max(i,j))
#define fir first
#define sec second
#define mkp make_pair
#define eb emplace_back
#define pb push_back
typedef long long ll;
typedef long double db;
#define siz(i) ((int)(i).size())
#define all(i) (i).begin(),(i).end()
// #define int ll
typedef vector<int> vi;
typedef pair<int,int> pi;
const int N=500010,inf=1e9+7;
int n,m,a[N],b[N],c[N],ia[N],ib[N];
pi ra[N],rb[N];
inline void shz(){
    sort(ia+1,ia+1+n,[](int x,int y){return a[x]<a[y];});
    sort(ib+1,ib+1+m,[](int x,int y){return b[x]<b[y];});
    int l,r,p;
    l=m+1,r=0,p=1;
    rep(i,1,n){
        int x=ia[i];
        while(p<=m && b[ib[p]]<a[x]){
            ckmn(l,ib[p]);
            ckmx(r,ib[p]);
            p++;
        }
        ra[x]=mkp(l,r);
        if(ra[x].fir>ra[x].sec){cout.put(48);return;}
    }
    l=n+1,r=0,p=n;
    per(i,m,1){
        int x=ib[i];
        while(p>0 && a[ia[p]]>b[x]){
            ckmn(l,ia[p]);
            ckmx(r,ia[p]);
            p--;
        }
        rb[x]=mkp(l,r);
        if(rb[x].fir>rb[x].sec){cout.put(48);return;}
    }
    memset(c+1,0x3f,n<<2);
    rep(i,1,m) ckmn(c[rb[i].fir],i);
    per(i,n,2) ckmn(c[i-1],c[i]);
    rep(i,1,n) if(c[i]<ra[i].fir){cout.put(48);return;}
    memset(c+1,0,n<<2);
    rep(i,1,m) ckmx(c[rb[i].sec],i);
    rep(i,1,n-1) ckmx(c[i+1],c[i]);
    rep(i,1,n) if(c[i]>ra[i].sec){cout.put(48);return;}
    cout.put(49);
}
inline void shabi(){
    sort(ib+1,ib+1+m,[](int x,int y){return b[x]<b[y];});
    sort(ia+1,ia+1+n,[](int x,int y){return a[x]<a[y];});
    int l,r,p;
    l=n+1,r=0,p=1;
    rep(i,1,m){
        int x=ib[i];
        while(p<=n && a[ia[p]]<b[x]){
            ckmn(l,ia[p]);
            ckmx(r,ia[p]);
            p++;
        }
        ra[x]=mkp(l,r);
        if(ra[x].fir>ra[x].sec){cout.put(48);return;}
    }
    l=m+1,r=0,p=m;
    per(i,n,1){
        int x=ia[i];
        while(p>0 && b[ib[p]]>a[x]){
            ckmn(l,ib[p]);
            ckmx(r,ib[p]);
            p--;
        }
        rb[x]=mkp(l,r);
        if(rb[x].fir>rb[x].sec){cout.put(48);return;}
    }
    memset(c+1,0x3f,m<<2);
    rep(i,1,n) ckmn(c[rb[i].fir],i);
    per(i,m,2) ckmn(c[i-1],c[i]);
    rep(i,1,m) if(c[i]<ra[i].fir){cout.put(48);return;}
    memset(c+1,0,m<<2);
    rep(i,1,n) ckmx(c[rb[i].sec],i);
    rep(i,1,m-1) ckmx(c[i+1],c[i]);
    rep(i,1,m) if(c[i]>ra[i].sec){cout.put(48);return;}
    cout.put(49);
}
inline void slv(){
    if(a[1]<b[1]){
        shabi();
    }else{
        shz();
    }
}
signed main(){ios::sync_with_stdio(false),cin.tie(nullptr);
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    int orz,x,y,T;
    cin>>orz>>n>>m>>T;
    rep(i,1,n) cin>>a[i];
    rep(i,1,m) cin>>b[i];
    iota(ia+1,ia+1+n,1);
    iota(ib+1,ib+1+m,1);
    slv();
    while(T--){
        cin>>x>>y;
        vector<pi> va(x),vb(y);
        for(auto&i:va){
            cin>>i.fir>>i.sec;
            swap(a[i.fir],i.sec);
        }
        for(auto&i:vb){
            cin>>i.fir>>i.sec;
            swap(b[i.fir],i.sec);
        }
        slv();
        for(const auto&i:va) a[i.fir]=i.sec;
        for(const auto&i:vb) b[i.fir]=i.sec;
    }
    cout<<'\n';
return 0;}