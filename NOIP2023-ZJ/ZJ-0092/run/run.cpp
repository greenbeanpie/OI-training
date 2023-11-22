#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fr(i,a,b) for(int i=a;i>=b;i--)
#define wr(x) write(x),putchar(' ')
#define mp(x,y) make_pair(x,y)
#define wt(x) write(x),puts("")
inline int read(){
    int x=0,k=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') k*=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+ch-48;
        ch=getchar();
    }
    return x*k;
}
void write(int x){
    if(x<0){
        x=-x;
        putchar('-');
    }
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
const int N=1e6+7,mod=998244353;
int n,m,tot,cnt,ans,d,k;
int f[2001][2001];
int g[2][N];
vector<pair<int,int> > q[10000];
struct query{
    int x,y,z;
}qq[N];
bool cmp(query a,query b){
    return a.x<b.x;
}
void solve(){
    tot=0;
    fo(i,1,m){
        int x=read(),y=read(),z=read();
        if(y>k) continue;
        qq[++tot]={x,y,z};
    }
    sort(qq+1,qq+tot+1,cmp);
    fo(i,0,1)
        fo(j,0,k) g[i][j]=-1e18;
    f[0][0]=0;
    int mx=0;
    int now=1,now1=1,tag=0;
    while(now<=n&&now1<=tot){
        if(now<qq[now1].x-qq[now1].y-k) now=qq[now1].x-qq[now1].y-k;
        while(now<qq[now1].x){
            tag^=1;
            fo(j,0,k) g[tag][j]=-1e18;
            fo(j,0,k){
                if(j==0) g[tag][j]=max(g[tag][j],mx);
                else g[tag][j]=max(g[tag][j],g[tag^1][j-1]-d);
            }
            mx=-1e18;
            fo(j,0,k) mx=max(mx,g[tag][j]);
            now++;
        }
        fo(p,qq[now1].y,k){
            g[tag][p]+=qq[now1].z;
        }
        now1++;
        mx=-1e18;
        fo(j,0,k) mx=max(mx,g[tag][j]);
    }
    ans=0;
    fo(i,0,k) ans=max(ans,g[tag][i]);
    wt(ans);
}
int st[N],top;
int h[N];
int sum[N];
void solve1(){
    tot=0;
    fo(i,1,m){
        int x=read(),y=read(),z=read();
        if(y>k) continue;
        qq[++tot]={x,y,z};
    }
    sort(qq+1,qq+tot+1,cmp);
    int hh=1,tt=0;
    ans=0;
    fo(i,1,tot) sum[i]=0,h[i]=0;
    fo(i,1,tot){
        if(qq[i].x-qq[i].y!=qq[i-1].x) hh=tt+1;
        sum[i]=sum[i-1]+qq[i].z-qq[i].y*d;
        if(hh>tt) h[i]=h[i-1]+qq[i].z-qq[i].y*d;
        else{
            while(hh<=tt&&qq[st[hh]].x<qq[i].x-k+1) hh++;
            h[i]=h[st[hh]]+sum[i]-sum[st[hh]+1];
            while(hh<=tt&&h[st[tt]]+sum[i]-sum[st[tt]+1]<=h[i]) tt--;
        }
        st[++tt]=i;
        ans=max(ans,h[i]);
    }
    wt(ans);
    return ;
}
signed main(){
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    int cc=read(),tt=read();
    while(tt--){
        n=read();m=read();k=read();d=read();
        if(cc>=15&&cc<=16){
            solve();
            continue;
        }
        if(cc>=17&&cc<=18){
            solve1();
            continue;
        }
        fo(i,1,n) q[i].clear();
        fo(i,1,m){
            int x=read(),y=read(),z=read();
            if(y>k) continue;
            q[x].push_back(mp(y,z));
        }
        fo(i,0,n)
            fo(j,0,k) f[i][j]=-1e18;
        f[0][0]=0;
        int mx=0;
        fo(i,1,n){
            fo(j,0,k){
                if(j==0) f[i][j]=max(f[i][j],mx);
                else f[i][j]=max(f[i][j],f[i-1][j-1]-d);
            }
            int o=q[i].size();
            fo(j,0,o-1){
                if(i<q[i][j].first) continue;
                fo(p,q[i][j].first,k){
                    f[i][p]+=q[i][j].second;
                }
            }
            mx=-1e18;
            fo(j,0,k) mx=max(mx,f[i][j]);
        }
        ans=0;
        fo(i,0,k) ans=max(ans,f[n][i]);
        wt(ans);
    }
    return 0;
}