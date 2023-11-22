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
set<pi> sa,sb;
set<pi>::iterator aa[N],bb[N];
void swa(){
    rep(i,1,max(n,m)) swap(a[i],b[i]);
    swap(n,m);
    swap(sa,sb);
}
void slv(){
    bool flag=false;
    if(a[1]<b[1]){
        flag=true;
        swa();
    }
    int l,r;
    {
        l=m+1,r=0;
        auto p=sb.begin();
        for(auto it=sa.begin();it!=sa.end();it++){
            int x=it->sec;
            while(p!=sb.end() && b[p->sec]<a[x]){
                ckmn(l,p->sec);
                ckmx(r,p->sec);
                p++;
            }
            ra[x]=mkp(l,r);
        }
    }
    {
        l=n+1,r=0;
        auto p=sa.rbegin();
        for(auto it=sb.rbegin();it!=sb.rend();it++){
            int x=it->sec;
            while(p!=sa.rend() && a[p->sec]>b[x]){
                ckmn(l,p->sec);
                ckmx(r,p->sec);
                p++;
            }
            rb[x]=mkp(l,r);
        }
    }
    rep(i,1,n) if(ra[i].fir>ra[i].sec){cout<<'0';if(flag)swa();return;}
    rep(i,1,m) if(rb[i].fir>rb[i].sec){cout<<'0';if(flag)swa();return;}
    fill(c+1,c+1+n,m+1);
    rep(i,1,m) ckmn(c[rb[i].fir],i);
    per(i,n,2) ckmn(c[i-1],c[i]);
    rep(i,1,n) if(c[i]<ra[i].fir){cout<<'0';if(flag)swa();return;}
    fill(c+1,c+1+n,0);
    rep(i,1,m) ckmx(c[rb[i].sec],i);
    rep(i,1,n-1) ckmx(c[i+1],c[i]);
    rep(i,1,n) if(c[i]>ra[i].sec){cout<<'0';if(flag)swa();return;}
    cout<<'1';if(flag)swa();
}
signed main(){ios::sync_with_stdio(false),cin.tie(nullptr);
    // freopen("expand.in","r",stdin);
    // freopen("expand.out","w",stdout);
    int orz,x,y,T;
    cin>>orz>>n>>m>>T;
    rep(i,1,n) cin>>a[i];
    rep(i,1,m) cin>>b[i];
    rep(i,1,n) aa[i]=sa.insert(mkp(a[i],i)).fir;
    rep(i,1,m) bb[i]=sb.insert(mkp(b[i],i)).fir;
    slv();
    while(T--){
        cin>>x>>y;
        vector<pi> va(x),vb(y);
        for(auto&i:va){
            cin>>i.fir>>i.sec;
            sa.erase(aa[i.fir]);
            swap(a[i.fir],i.sec);
            aa[i.fir]=sa.insert(mkp(a[i.fir],i.fir)).fir;
        }
        for(auto&i:vb){
            cin>>i.fir>>i.sec;
            sb.erase(bb[i.fir]);
            swap(b[i.fir],i.sec);
            bb[i.fir]=sb.insert(mkp(b[i.fir],i.fir)).fir;
        }
        slv();
        for(const auto&i:va){
            sa.erase(aa[i.fir]);
            a[i.fir]=i.sec;
            aa[i.fir]=sa.insert(mkp(a[i.fir],i.fir)).fir;
        }
        for(const auto&i:vb){
            sb.erase(bb[i.fir]);
            b[i.fir]=i.sec;
            bb[i.fir]=sb.insert(mkp(b[i.fir],i.fir)).fir;
        }
    }
    cout<<'\n';
return 0;}