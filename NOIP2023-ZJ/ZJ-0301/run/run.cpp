#include<bits/stdc++.h>
#define int long long
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define Rep(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
inline int read() {
    int x=0;char c=getchar();bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x; return x;
}
const int maxn=100050;
int C,T,n,m,k,d;
struct Node{
    int x,len,c;
}s[maxn];
namespace s1{
    int f[1024][1024],ad[1024][1024];
    vector<int> aw[1024],sum[1024],ll[1024];
    int solve()
    {
        For(i,1,n) aw[i].clear(),sum[i].clear(),ll[i].clear();
        For(i,0,n) For(j,0,n) f[i][j]=ad[i][j]=0;
        For(i,1,m) aw[s[i].x].push_back(i);
        For(i,1,n) sort(aw[i].begin(),aw[i].end(),[&](int x,int y){
            return s[x].len<s[y].len;
        });
        For(i,1,n)
        {
            int cc=0;
            for(int j:aw[i])
            {
                cc+=s[j].c;
                sum[i].push_back(cc);
                ll[i].push_back(s[j].len);
            }
        }
        For(l,1,n)
            For(r,l,n)
            {
                if(r-l+1>k) break;
                ad[l][r]=ad[l][r-1];
                if(aw[r].empty()) continue;
                int pos=upper_bound(ll[r].begin(),ll[r].end(),r-l+1)-ll[r].begin()-1;
                if(pos==-1) continue;
                ad[l][r]+=sum[r][pos];
                // for(int i:aw[r])
                //     if(s[i].x-s[i].len+1>=l)
                //         ad[l][r]+=s[i].c;
                // cout<<l<<' '<<r<<' '<<ad[l][r]<<endl;
            }
        For(i,1,n)
        {
            Rep(j,i,1)
            {
                if(i-j+1>k) break;
                f[i][j]=f[j-1][0]-(i-j+1)*d+ad[j][i];
            }
            f[i][0]=f[i-1][0];
            Rep(j,i-1,1)
            {
                if(i-1-j+1>k) break;
                f[i][0]=max(f[i][0],f[i-1][j]);
            }
        }
        // For(i,1,n)
        // {
        //     For(j,0,i) cout<<f[i][j]<<' ';
        //     cout<<endl;
        // }
        int ans=0;
        For(j,0,n) ans=max(ans,f[n][j]);
        return ans;
    }
}
// namespace s10{
//     int f[1024][2];
//     vector<int> aw[1024];
//     int solve()
//     {
//         For(i,1,n) aw[i].clear();
//         For(i,0,n) For(j,0,1) f[i][j]=0;
//         sort(s+1,s+m+1,[&](Node x,Node y){
//             if(x.x!=y.x) return x.x<y.x;
//             return x.len<y.len;
//         });
//         For(i,1,m)
//         {
//             if(s[i].x==s[i-1].x) f[i][1]=f[i-1][1];
//         }
//         int ans=0;
//         return ans;
//     }
// }
namespace s17{
    int solve()
    {
        int ans=0;
        For(i,1,m)
            if(s[i].len<=k&&s[i].c>s[i].len*d)
                ans+=s[i].c-s[i].len*d;
        return ans;
    }
}
signed main()
{
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    C=read(); T=read();
    while(T--)
    {
        n=read(); m=read(); k=read(); d=read();
        For(i,1,m) s[i].x=read(),s[i].len=read(),s[i].c=read();
        if(C<=9) cout<<s1::solve()<<endl;
        else cout<<s17::solve()<<endl;
    }
    return 0;
}
/*
g++ run/run.cpp -O2 -Wall -o run.exe
./run.exe
*/