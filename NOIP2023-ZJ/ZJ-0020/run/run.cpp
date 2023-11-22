#include<bits/stdc++.h>
#define V vector
#define Vi vector<int>
#define all(a) a.begin(),a.end()
#define For(i,l,r) for(int i=l;i<=r;i++)
#define Int pair<int,int>
#define Inf ((int)1e18)
#define fi first
#define se second
#define pb push_back
#define sz(a) ((int)a.size())
using namespace std;
#define int long long
struct hzy{int l,r,z;};
#define seg int p,int l,int r
#define lid p<<1,l,mid
#define rid p<<1|1,mid+1,r
#define mid ((l+r)/2)
struct Ace_taffy{
  Ace_taffy(int n):s(4*n+5,-Inf),lam(4*n+5,-Inf),las(4*n+5){};
  void work1(int p,int z){s[p]+=z;las[p]+=z;}
  void work2(int p,int z){
    // cout<<p<<' '<<z<<endl;
    s[p]=max(s[p],z),lam[p]=max(lam[p],z-las[p]);
  }
  void pd(int p){
    // cout<<p<<' '<<lam[p]<<endl;
    if(lam[p]!=-Inf)work2(p<<1,lam[p]),work2(p<<1|1,lam[p]),lam[p]=-Inf;
    if(las[p])work1(p<<1,las[p]),work1(p<<1|1,las[p]),las[p]=0;
  }
  void add(seg,int L,int R,int z){
    if(L>R)return;
    if(l>=L&&r<=R)return work1(p,z);
    if(lam[p]!=-Inf||las[p])pd(p);
    if(L<=mid)add(lid,L,R,z);
    if(R>mid)add(rid,L,R,z);
  }
  void mdf(seg,int L,int R,int z){
    // cout<<L<<' '<<R<<' '<<z<<endl;
    if(L>R)return;
    if(l>=L&&r<=R)return work2(p,z);
    if(lam[p]!=-Inf||las[p])pd(p);
    if(L<=mid)mdf(lid,L,R,z);
    if(R>mid)mdf(rid,L,R,z);
  }
  int ask(seg,int x){
    if(l==r)return s[p];
    if(lam[p]!=-Inf||las[p])pd(p);
    return x<=mid?ask(lid,x):ask(rid,x);
  }
  void write(seg){
    if(l==r){
      // cout<<s[p]<<' ';
      return;
    }
    pd(p);
    write(lid),write(rid);
  }
  Vi s,lam,las;
};
void Yui_Yagi(){
  int n,m,K,d;
  cin>>n>>m>>K>>d;
  V<hzy> vec(m+5);
  Vi v;
  for(int i=1,l,r,x;i<=m;i++){
    cin>>r>>l>>x;
    vec[i]=(hzy){r-l+1,r,x};
    // cout<<r-l+1<<' '<<r<<' '<<x<<endl;
    v.pb(r-l+1),v.pb(r);
  }
  sort(all(v));
  v.erase(unique(all(v)),v.end());
  n=sz(v);
  V<V<Int>> q(n+5);
  For(i,1,m){
    vec[i].l=lower_bound(all(v),vec[i].l)-v.begin()+1;
    vec[i].r=lower_bound(all(v),vec[i].r)-v.begin()+1;
    q[vec[i].l].pb({vec[i].r,vec[i].z});
  }
  Ace_taffy tr(n);
  int res=0;
  v.pb(2e9);
  // for(int x:v)cout<<x<<' '
  For(i,1,n){
    int t=lower_bound(all(v),v[i-1]+K)-v.begin();
    // cout<<t<<endl;
    tr.mdf(1,1,n,i,t,res);
    for(auto j:q[i]){tr.add(1,1,n,j.fi,n,j.se);
    }
    tr.add(1,1,n,i,i,-d);
    if(i<n)tr.add(1,1,n,i+1,n,-d*(v[i]-v[i-1]));
    if(i>1)res=max(res,tr.ask(1,1,n,i-1));
    if(v[i]>v[i-1]+1)res=max(res,tr.ask(1,1,n,i));
    // cout<<res<<' '<<v[i-1]<<' '<<i<<endl;
    // tr.write(1,1,n);
    // cout<<endl;
    // cout<<tr.ask(1,1,n,5)<<endl;
  }
  cout<<max(res,tr.ask(1,1,n,n))<<'\n';
}
signed main(){
  freopen("run.in","r",stdin);
  freopen("run.out","w",stdout);
  ios::sync_with_stdio(0);  
  int c,_;
  for(cin>>c>>_;_--;)Yui_Yagi();
}