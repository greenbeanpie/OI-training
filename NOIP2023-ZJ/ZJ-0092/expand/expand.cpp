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
const int N=1e6+7,mod=998244353;
int n,m,tot,ans,cnt,q;
int a[N],b[N];
pair<int,int> d[N],e[N];
int c[N];
// void solve(){

// }
int f[3011][3011];
signed main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    int cc=read();
    n=read();m=read();q=read();
    fo(i,1,n) a[i]=read();
    fo(i,1,m) b[i]=read();
    // if(cc>=8&&cc<=14){
    //     solve();
    //     return 0;
    // }
    f[1][1]=1;
    if(a[1]<b[1]){
        fo(i,1,n){
            fo(j,1,m){
                if(!f[i][j]) continue;
                if(i<n&&a[i+1]<b[j]) f[i+1][j]=1;
                if(j<m&&a[i]<b[j+1]) f[i][j+1]=1;
            }
        }
        if(f[n][m]) c[0]=1;
        else c[0]=0;
    }
    else if(a[1]>b[1]){
        fo(i,1,n){
            fo(j,1,m){
                if(!f[i][j]) continue;
                if(i<n&&a[i+1]>b[j]) f[i+1][j]=1;
                if(j<m&&a[i]>b[j+1]) f[i][j+1]=1;
            }
        }
        if(f[n][m]) c[0]=1;
        else c[0]=0;
    }
    else c[0]=0;
    fo(k,1,q){
        int x=read(),y=read();
        fo(i,1,x){
            int p=read(),pp=read();
            d[i]=make_pair(p,a[p]);
            a[p]=pp;
        }
        fo(i,1,y){
            int p=read(),pp=read();
            e[i]=make_pair(p,b[p]);
            b[p]=pp;
        }
        fo(i,1,n)
            fo(j,1,m) f[i][j]=0;
        f[1][1]=1;
        if(a[1]<b[1]){
            fo(i,1,n){
                fo(j,1,m){
                    if(!f[i][j]) continue;
                    if(i<n&&a[i+1]<b[j]) f[i+1][j]=1;
                    if(j<m&&a[i]<b[j+1]) f[i][j+1]=1;
                }
            }
            if(f[n][m]) c[k]=1;
            else c[k]=0;
        }
        else if(a[1]>b[1]){
            fo(i,1,n){
                fo(j,1,m){
                    if(!f[i][j]) continue;
                    if(i<n&&a[i+1]>b[j]) f[i+1][j]=1;
                    if(j<m&&a[i]>b[j+1]) f[i][j+1]=1;
                }
            }
            if(f[n][m]) c[k]=1;
            else c[k]=0;
        }
        else c[k]=0;
        fo(i,1,x) a[d[i].first]=d[i].second;
        fo(i,1,y) b[e[i].first]=e[i].second;
    }
    fo(i,0,q) putchar(c[i]+'0');
    return 0;
}
/*
Y@T2L32#
*/