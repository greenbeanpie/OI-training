#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=3e3+5,A=26,H=2;
const LL base[H]={233,521},mod[H]={998244353,1000000007};
int n,m,cnt[A];
string s[N],t[N];
LL prehs[H][N][N],preht[H][N][N];

inline LL Mod(const int &h,const LL &x){return x>=mod[h]?x-mod[h]:x;}
signed main()
{
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;++i)
    {
        cin>>s[i];
        for(auto c:s[i])
            cnt[c-'a']++;
        s[i].clear();
        for(int j=0;j<A;++j)
        {
            for(int k=1;k<=cnt[j];++k)
                s[i].push_back(j+'a');
            cnt[j]=0;
        }
        t[i]=s[i];
        reverse(t[i].begin(),t[i].end());
        s[i]=" "+s[i],t[i]=" "+t[i];
    }
    cerr<<"Time1: "<<clock()<<" ms.\n";
    for(int h=0;h<H;++h)
    {
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=m;++j)
            {
                prehs[h][i][j]=Mod(h,prehs[h][i][j-1]*base[h]%mod[h]+s[i][j]);
                preht[h][i][j]=Mod(h,preht[h][i][j-1]*base[h]%mod[h]+t[i][j]);
            }
        }
    }
    for(int i=1;i<=n;++i)
    {
        bool ans=true;
        for(int j=1;j<=n;++j)
        {
            if(i==j) continue;
            int l=0,r=m-1;
            while(l<r)
            {
                int mid=l+r+1>>1;
                if(prehs[0][i][mid]==preht[0][j][mid]&&prehs[1][i][mid]==preht[1][j][mid]) l=mid;
                else r=mid-1;
            }
            if(s[i][l+1]>=t[j][l+1])
            {
                ans=false;
                break;
            }
        }
        cout<<(ans?1:0);
    }
    cerr<<"Time: "<<clock()<<" ms.\n";
    return 0;
}
// 9:32 done.