#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5;
int n,m,k,d;
struct clg{
    int l,r,v;
}a[N];

int ans_bf;
bool v[N];
inline void calc(){
    int res=0;
    int cnt=0;
    // for(int i=1;i<=n;i++)
    //     cerr<<v[i];
    // cerr<<'\n';
    for(int i=1;i<=n;i++)
        if(v[i])
        {
            cnt++;
            res-=d;
        }
        else{
            if(cnt>k)return;
            cnt=0;
        }
    if(cnt>k)return;
    for(int i=1;i<=m;i++)
    {
        bool flag=true;
        for(int j=a[i].l;j<=a[i].r;j++)
            if(!v[j]){flag=false;break;}
        if(flag)res+=a[i].v;
    }
    ans_bf=max(ans_bf,res);
}
inline void dfs(int dep){
    if(dep==n+1)return calc(),void();
    dfs(dep+1);
    v[dep]=1,dfs(dep+1);v[dep]=0;
}
inline void solve_bf(){
    cin>>n>>m>>k>>d;
    for(int i=1;i<=m;i++)
    {
        int x,y,v;cin>>x>>y>>v;
        a[i]={x-y+1,x,v};
    }
    ans_bf=LLONG_MIN;
    dfs(1);cout<<ans_bf<<'\n';
}
inline void solve_B(){
    cin>>n>>m>>k>>d;
    int res=0;
    for(int i=1;i<=m;i++)
    {
        int x,y,v;cin>>x>>y>>v;
        a[i]={x-y+1,x,v};
    }
    // for(int i=1;i<m;i++)
    //     if(a[i].r)
    cout<<res<<'\n';
}
signed main(){
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    int C,T;cin>>C>>T;
    if(C<=2)while(T--)solve_bf();
    // if(C==17||C==18)while(T--)solve_B();
    return 0;
}