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
struct shoudao{
    int a[N],n,lim,s[N],cnt[N];
    void init(int nn){
        n=nn;
        rep(i,1,n) cin>>a[i];
        copy(a+1,a+1+n,s+1);
        sort(s+1,s+1+n);
        lim=unique(s+1,s+1+n)-s-1;
        rep(i,1,n) a[i]=lower_bound(s+1,s+1+lim,a[i])-s;
        fill(cnt+1,cnt+1+lim,0);
        rep(i,1,n) cnt[a[i]]++;
    }
    void md(int&vl,int&vr,int&mn,vector<pi>&v){
        mn=inf;
        vl=s[a[1]],vr=s[a[n]];
        for(auto&i:v){
            ckmn(mn,i.sec);
            cnt[a[i.fir]]--;
            swap(a[i.fir],i.sec);
        }
        rep(i,1,lim){
            if(s[i]>mn) break;
            if(cnt[i]){
                mn=s[i];
                break;
            }
        }
        for(auto&i:v){
            cnt[i.sec]++;
            if(i.fir==1) vl=a[i.fir];
            if(i.fir==n) vr=a[i.fir];
            a[i.fir]=i.sec;
        }
    }
}A,B;
int ax,ay,az;
int bx,by,bz;
bool pan(){
    return (ax<bx && ay<by && az<bz) || (ax>bx && ay>by && az>bz);
}
signed main(){ios::sync_with_stdio(false),cin.tie(nullptr);
    // freopen("expand.in","r",stdin);
    // freopen("expand.out","w",stdout);
    int orz,x,y,T;
    cin>>orz>>x>>y>>T;
    A.init(x);
    B.init(y);
    vector<pi> emp;
    A.md(ax,ay,az,emp);
    B.md(bx,by,bz,emp);
    cout<<pan();
    while(T--){
        cin>>x>>y;
        vector<pi> va(x),vb(y);
        for(auto&i:va) cin>>i.fir>>i.sec;
        for(auto&i:vb) cin>>i.fir>>i.sec;
        A.md(ax,ay,az,va);
        B.md(bx,by,bz,vb);
        cout<<pan();
    }
    cout<<'\n';
return 0;}