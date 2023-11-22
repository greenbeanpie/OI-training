#include<bits/stdc++.h>
using namespace std;

typedef pair<long long,long long> pll;
typedef long long ll;
const ll N=1e5+86,INF=0x3f3f3f3f3f3f3f3f;

template<typename T>
inline void read(T &x)
{
    T k=1;char ch=getchar();x=0;
    while(ch<'0'||ch>'9'){if(ch=='-')k=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48),ch=getchar();}
    x*=k;
}

// ll n,m,K,d;
// vector<pll> vec[N];
// map<int,ll> f[N];
// void solve()
// {
//     read(n),read(m),read(K),read(d);
//     for(int i=0;i<=n;i++) f[i].clear();
//     for(int i=1,x,y,v;i<=m;i++)
//         read(x),read(y),read(v),vec[x].push_back({y,v});
//     f[0][0]=0;
//     ll ans=-INF;
//     for(int i=1;i<=n;i++)
//     {
//         if(!f[i].count(0)) f[i][0]=f[i-1][0];
//         else f[i][0]=max(f[i][0],f[i-1][0]);
//         if(i==n) ans=max(ans,f[i][0]);
//         sort(vec[i].begin(),vec[i].end());
//         ll pre=0;
//         if(vec[i].size()==0) continue;
//         for(auto j:vec[i])
//         {
//             ll v=j.second,y=j.first;
//             pre+=v;
//             if(i<y) break;
//             for(auto k:f[i-y])
//                 if(k.first+y<=K)
//                 {
//                     if(!f[i].count(k.first+y)) f[i][k.first+y]=k.second+pre-y*d;
//                     else f[i][k.first+y]=max(f[i][k.first+y],k.second+pre-y*d);
//                     if(!f[i+1].count(0)) f[i+1][0]=f[i][k.first+y];
//                     else f[i+1][0]=max(f[i+1][0],f[i][k.first+y]);
//                     if(i==n) ans=max(ans,f[i][k.first+y]);
//                 }
//         }
//         vec[i].clear();
//     }
//     printf("%lld\n",ans);
// }

ll n,m,K,d;
ll f[2][N];
vector<pll> vec[N];
void solve()
{
    read(n),read(m),read(K),read(d);
    for(int i=1,x,y,v;i<=m;i++)
        read(x),read(y),read(v),vec[x].push_back({y,v});
    f[0][0]=0;
    for(int i=1;i<=K;i++) f[0][i]=-INF;
    int pre=0,now=1;
    ll ans=-INF;
    for(int i=1;i<=n;i++)
    {
        if(vec[i].size())
        {
            sort(vec[i].begin(),vec[i].end());
            for(int j=1;j<(int)vec[i].size();j++)
                vec[i][j].second+=vec[i][j-1].second;
        }
        int p=vec[i].size()-1;
        ll mx=-INF;
        for(int j=K;j>=0;j--)
        {
            while(p>=0&&vec[i][p].first>j) p--;
            mx=max(mx,f[pre][j]);
            if(j==0) f[now][j]=mx+(p>=0?vec[i][p].second:0);
            else f[now][j]=f[pre][j-1]-d+(p>=0?vec[i][p].second:0);
            if(i==n) ans=max(ans,f[now][j]);
        }
        swap(now,pre);
        vec[i].clear();
    }
    printf("%lld\n",ans);
}

int main()
{
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    int C,T;
    read(C),read(T);
    while(T--) 
    {
       solve();
    }
    return 0;
}