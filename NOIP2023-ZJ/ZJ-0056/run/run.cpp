#include<bits/stdc++.h>
#define int long long
#define pii pair<long long,long long>
using namespace std;
long long C,T;
long long n,m,k,d,las;
int rt;
vector<pii> v[200001];

#define mid ((l+r)>>1)
long long s[10000001],lz[10000001],top;
int lc[10000001],rc[10000001];

inline int clone(){s[++top]=0; lz[top]=0; lc[top]=rc[top]=0; return top;}

inline void pd(int x){
if (!lz[x]) return;
if (!lc[x]) lc[x]=clone();
if (!rc[x]) rc[x]=clone();
s[lc[x]]+=lz[x],s[rc[x]]+=lz[x],
lz[lc[x]]+=lz[x],lz[rc[x]]+=lz[x];
lz[x]=0;
}

inline void build(int &x,int l,int r){
s[x]=lz[x]=0;
if (!x) x=++top; if (l==r) return;
build(lc[x],l,mid); build(rc[x],mid+1,r);
}

inline void upd(int &x,int l,int r,int ll,int rr,long long z){
if (l>rr || r<ll || ll>rr) return;
if (!x) x=clone();
if (l>=ll && r<=rr){s[x]+=z,lz[x]+=z; return;}
pd(x);
upd(lc[x],l,mid,ll,rr,z); upd(rc[x],mid+1,r,ll,rr,z);
s[x]=max(s[lc[x]],s[rc[x]]);
}

inline long long query(int &x,int l,int r,int ll,int rr){
if (!x) x=clone();
if (l==ll && r==rr) return s[x];
pd(x);
if (rr<=mid) return query(lc[x],l,mid,ll,rr);
if (ll>mid) return query(rc[x],mid+1,r,ll,rr);
return max(query(lc[x],l,mid,ll,mid),query(rc[x],mid+1,r,mid+1,rr));
}

struct st{
long long pos,l,val;
}e[1000001];
inline bool cmp(st aa,st bb){return aa.pos<bb.pos;}
long long dp[121];
set<long long> S;
signed main(){
freopen("run.in","r",stdin);
freopen("run.out","w",stdout);
ios::sync_with_stdio(false); cin.tie(0);
cin>>C>>T;
while (T--){
rt=0;
while (top) s[top]=0,lz[top]=0,lc[top]=rc[top]=0,--top;
cin>>n>>m>>k>>d; ++n;
if (n>100001){
S.clear();
for (int i=1;i<=m;++i){
long long x,y,z;
cin>>x>>y>>z;
e[i].pos=x; e[i].l=y; e[i].val=z;
}
sort(e+1,e+m+1,cmp);
memset(dp,-0x1f,sizeof(dp));
dp[110]=0;
for (int i=1;i<=m;++i) S.insert(e[i].pos+1);
S.insert(n);
int nnn=0,lt=0;
for (auto nowt:S){
int cha=nowt-lt; lt=nowt;
if (cha>=110){
int M=dp[110];
for (int i=0;i<=110;++i) dp[i]=M;
}
else{
for (int i=0;i+cha<=110;++i) dp[i]=dp[i+cha];
for (int i=110-cha+1;i<=110;++i) dp[i]=dp[i-1];
}
while (nnn<m && e[nnn+1].pos<nowt){
++nnn;
int L=109-e[nnn].l;
for (int i=0;i<=L;++i) dp[i]+=e[nnn].val;
}
for (int j=max(0ll,109-k);j<=108;++j) dp[110]=max(dp[110],dp[j]-(109-j)*d);
}
cout<<dp[110]<<'\n';
continue;
}
build(rt,0,n);
for (int i=1;i<=n;++i) v[i].clear();
for (int i=1;i<=m;++i){
long long x,y,z;
cin>>x>>y>>z;
v[x].push_back({x-y+1,z});
}
las=0;
for (int i=1;i<=n;++i){
for (auto now:v[i-1]) upd(rt,0,n,0,now.first-1,now.second);
long long p=0;
if (i>1) p=query(rt,0,n,max(0ll,i-k-1),i-2)-(i-1)*d;
p=max(p,las);
las=p; upd(rt,0,n,i,i,las+i*d);
}
cout<<las<<'\n';
}
return 0;
}
