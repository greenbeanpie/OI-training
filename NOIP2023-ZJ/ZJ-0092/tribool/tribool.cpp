#include<bits/stdc++.h>
using namespace std;
// #define int long long
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fr(i,a,b) for(int i=a;i>=b;i--)
#define wr(x) write(x),putchar(' ')
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
const int N=2e5+7,mod=998244353;
int n,m,k,tot,cnt,ans;
int a[N],b[N];
char s[10];
struct query{
    int opt;
    int x,y;
}q[N];
void dfs(int num){
    if(num==n+1){
        fo(i,1,n) b[i]=a[i];
        fo(i,1,m){
            if(q[i].opt==1) b[q[i].x]=b[q[i].y];
            else if(q[i].opt==2) b[q[i].x]=-b[q[i].y];
            else if(q[i].opt==3) b[q[i].x]=1;
            else if(q[i].opt==4) b[q[i].x]=-1;
            else if(q[i].opt==5) b[q[i].x]=0;
        }
        int fl=0;
        int p=0;
        fo(i,1,n){
            if(a[i]!=b[i]) fl=1;
            if(b[i]==0) p++;
        }
        if(!fl){
            ans=min(ans,p);
        }
        return ;
    }
    a[num]=1;
    dfs(num+1);
    a[num]=-1;
    dfs(num+1);
    a[num]=0;
    dfs(num+1);
}
void solve1(){
    ans=1e9;
    dfs(1);
    wt(ans);
    return ;
}
void solve2(){
    fo(i,1,n) a[i]=1;
    fo(i,1,m){
        if(q[i].opt==3) a[q[i].x]=1;
        else if(q[i].opt==4) a[q[i].x]=-1;
        else if(q[i].opt==5) a[q[i].x]=0;
    }
    ans=0;
    fo(i,1,n){
        if(a[i]==0) ans++;
    }
    wt(ans);
    return ;
}
set<int> c1[N],c2[N];
int d[N];
queue<int> qq;
void dfs1(int id,int tim){
    auto x=c1[id].lower_bound(tim);
    auto y=c2[id].lower_bound(tim);
    while(x!=c1[id].end()&&(y==c2[id].end()||(y!=c2[id].end()&&(*x)<(*y)))){
        int xx=*x;
        c1[id].erase(xx);
        c2[q[xx].x].erase(xx);
        x=c1[id].lower_bound(xx);
        dfs1(q[xx].x,xx);
    }
    if(y==c2[id].end()){
        if(!d[id]){
            d[id]=1;
            ans++;
            qq.push(id);
        }
    }
}
void solve3(){
    fo(i,1,n) c1[i].clear(),c2[i].clear();
    fo(i,1,n) d[i]=0;
    ans=0;
    fo(i,1,m){
        if(q[i].opt==1){
            if(q[i].x==q[i].y) continue;
            c1[q[i].y].insert(i);
            c2[q[i].x].insert(i);
        }
    }
    fo(i,1,m){
        if(q[i].opt==5){
            dfs1(q[i].x,i);
        }
    }
    while(!qq.empty()){
        int x=qq.front();
        qq.pop();
        dfs1(x,1);
    }
    wt(ans);
}
signed main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    int cc=read(),tt=read();
    while(tt--){
        n=read();m=read();
        fo(i,1,m){
            cin>>(s+1);
            if(s[1]=='+') q[i]={1,read(),read()};
            else if(s[1]=='-') q[i]={2,read(),read()};
            else if(s[1]=='T') q[i]={3,read(),0};
            else if(s[1]=='F') q[i]={4,read(),0};
            else if(s[1]=='U') q[i]={5,read(),0};
        }
        if(cc>=1&&cc<=2) {
            solve1();
            continue;
        }
        else if(cc>=3&&cc<=4){
            solve2();
            continue;
        }
        else if(cc>=5&&cc<=6){
            solve3();
            continue;
        }
    }
    return 0;
}