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

const int N=100010;
int a[N],n,m,f[N],g[N],val[N];
bool kil[N];
inline void gf(int x){
    if(x==f[x]) return ;
    gf(f[x]);
    g[x]^=g[f[x]];
    f[x]=f[f[x]];
}
void work(){
    cin>>n>>m;
    iota(a+1,a+1+n,1);
    rep(i,1,m){
        char opt;
        cin>>opt;
        if(opt=='+'){
            int x,y;
            cin>>x>>y;
            a[x]=a[y];
        }else if(opt=='-'){
            int x,y;
            cin>>x>>y;
            a[x]=-a[y];
        }else if(opt=='T'){
            int x;
            cin>>x;
            a[x]=n+1;
        }else if(opt=='F'){
            int x;
            cin>>x;
            a[x]=-(n+1);
        }else if(opt=='U'){
            int x;
            cin>>x;
            a[x]=n+2;
        }else{
            #ifdef super
                assert(false);
            #endif
        }
    }
    iota(f+1,f+1+n,1);
    fill(g+1,g+1+n,0);
    fill(val+1,val+1+n,2);
    fill(kil+1,kil+1+n,false);
    rep(i,1,n){
        if(abs(a[i])<=n){
            int x=i,y=abs(a[i]),z=(a[i]<0);
            gf(x),gf(y);
            if(f[x]==f[y]){
                if((g[x]^g[y]^z)!=0){
                    kil[x]=true;
                }
            }else{
                g[f[y]]=g[x]^g[y]^z;
                f[f[y]]=f[x];
            }
        }
    }
    rep(i,1,n){
        if(abs(a[i])>n){
            gf(i);
            if(abs(a[i])==n+2){
                kil[i]=true;
            }else{
                int x=(a[i]>0);
                if(val[f[i]]!=2 && val[f[i]]!=x){
                    kil[i]=true;
                }else{
                    val[f[i]]=x;
                }
            }
        }
    }
    rep(i,1,n){
        gf(i);
        kil[f[i]]|=kil[i];
    }
    int cnt=0;
    rep(i,1,n){
        cnt+=kil[f[i]];
    }
    cout<<cnt<<"\n";
}
signed main(){ios::sync_with_stdio(false),cin.tie(nullptr);
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    int orz,T;cin>>orz>>T;
    while(T--)work();
return 0;}