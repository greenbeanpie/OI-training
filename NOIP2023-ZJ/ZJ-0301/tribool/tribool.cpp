#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define Rep(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int maxn=100050;
int C,T,n,m;
struct Options{
    int op,a,b;
}s[maxn];
inline int qf(int x) {
    if(x<=1) return x^1;
    return x;
}
namespace s12{
    int ans,a[13],b[13];
    bool check()
    {
        For(i,1,n) b[i]=a[i];
        For(i,1,m)
        {
            if(s[i].op<=2) b[s[i].a]=s[i].op;
            else if(s[i].op==3) b[s[i].a]=b[s[i].b];
            else if(s[i].op==4) b[s[i].a]=qf(b[s[i].b]);
        }
        For(i,1,n) if(b[i]!=a[i]) return false;
        return true;
    }
    void dfs(int pos,int cnt)
    {
        if(pos==n+1)
        {
            if(check()) ans=min(ans,cnt);
            return;
        }
        a[pos]=1;
        dfs(pos+1,cnt);
        a[pos]=0;
        dfs(pos+1,cnt);
        a[pos]=2;
        dfs(pos+1,cnt+1);
        a[pos]=0;
    }
    int solve()
    {
        ans=n;
        dfs(1,0);
        return ans;
    }
}
namespace s34{
    int a[maxn];
    int solve()
    {
        For(i,1,n) a[i]=-1;
        Rep(i,m,1) if(a[s[i].a]==-1) a[s[i].a]=s[i].op;
        int ans=0;
        For(i,1,n) if(a[i]==2) ans++;
        return ans;
    }
}
namespace s56{
    int f[2][maxn];
    int solve(int cs)
    {
        For(i,1,n) f[0][i]=f[1][i]=1;
        int cur=0,pre=1,ans=0;
        For(R,1,cs)
        {
            cur^=1,pre^=1;
            For(i,1,n) f[cur][i]=f[pre][i];
            For(i,1,m)
            {
                if(s[i].op<=2) f[cur][s[i].a]=s[i].op;
                if(s[i].op==3) f[cur][s[i].a]=f[cur][s[i].b];
                if(s[i].op==4) f[cur][s[i].a]=qf(f[cur][s[i].b]);
            }
            For(i,1,n) if(f[cur][i]!=f[pre][i]) goto loop;
            break;
            loop:;//cout<<R<<endl;
        }
        For(i,1,n) if(f[cur][i]!=f[pre][i]) f[cur][i]=2;
        For(i,1,n) if(f[cur][i]==2) ans++;
        return ans;
    }
}
namespace s5678{
    int f[5][maxn],e=5;
    int solve(int cs)
    {
        For(i,1,n) f[0][i]=f[1][i]=1;
        int ans=0,ed;
        For(R,1,cs)
        {
            For(i,1,n) f[R%e][i]=f[(R-1)%e][i];
            For(i,1,m)
            {
                if(s[i].op<=2) f[R%e][s[i].a]=s[i].op;
                if(s[i].op==3) f[R%e][s[i].a]=f[R%e][s[i].b];
                if(s[i].op==4) f[R%e][s[i].a]=qf(f[R%e][s[i].b]);
            }
            For(i,1,n)
                For(j,0,e-1)
                {
                    if(j==R%e) continue;
                    if(f[R%e][i]!=f[j][i]) goto loop;
                }
            ed=R;
            break;
            loop:ed=R;//cout<<R<<endl;
        }
        For(i,1,n)
        {
            For(j,0,e-1)
            {
                if(j==ed%e) continue;
                if(f[ed%e][i]!=f[j][i]) f[ed%e][i]=2;
            }
        }
        For(i,1,n) if(f[ed%e][i]==2) ans++;
        return ans;
    }
}
namespace s78{
    int f[3][maxn],e=3;
    int solve(int cs)
    {
        For(i,1,n) f[0][i]=f[1][i]=1;
        int ans=0,ed;
        For(R,1,cs)
        {
            For(i,1,n) f[R%e][i]=f[(R-1)%e][i];
            For(i,1,m)
            {
                if(s[i].op<=2) f[R%e][s[i].a]=s[i].op;
                if(s[i].op==3) f[R%e][s[i].a]=f[R%e][s[i].b];
                if(s[i].op==4) f[R%e][s[i].a]=qf(f[R%e][s[i].b]);
            }
            For(i,1,n)
                For(j,0,e-1)
                {
                    if(j==R%e) continue;
                    if(f[R%e][i]!=f[j][i]) goto loop;
                }
            ed=R;
            break;
            loop:ed=R;//cout<<R<<endl;
        }
        For(i,1,n)
        {
            For(j,0,e-1)
            {
                if(j==ed%e) continue;
                if(f[ed%e][i]!=f[j][i]) f[ed%e][i]=2;
            }
        }
        For(i,1,n) if(f[ed%e][i]==2) ans++;
        return ans;
    }
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    cin>>C>>T;
    while(T--)
    {
        cin>>n>>m;
        For(i,1,m)
        {
            string c; cin>>c;
            if(c[0]=='T') s[i].op=1,cin>>s[i].a;
            if(c[0]=='F') s[i].op=0,cin>>s[i].a;
            if(c[0]=='U') s[i].op=2,cin>>s[i].a;
            if(c[0]=='+') s[i].op=3,cin>>s[i].a>>s[i].b;
            if(c[0]=='-') s[i].op=4,cin>>s[i].a>>s[i].b;
        }
        if(C<=2)
        {
            cout<<s12::solve()<<endl;
            continue;
        }
        if(C<=4)
        {
            cout<<s34::solve()<<endl;
            continue;
        }
        else
        {
            if(n<=1000) cout<<s5678::solve(8000)<<endl;
            else cout<<s78::solve(250)<<endl;
            continue;
        }
    }
    return 0;
}
/*
g++ tribool/tribool.cpp -O2 -Wall -o tribool.exe
./tribool.exe
*/