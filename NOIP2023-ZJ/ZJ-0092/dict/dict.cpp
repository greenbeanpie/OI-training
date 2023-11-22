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
const int N=3007,mod=998244353;
int n,m,k,tot,cnt;
int a[2][N][N],b[N];
char s[N];
bool cmp(int x,int y){
    return x>y;
}
bool check(int x,int y){
    fo(i,1,m){
        if(a[1][x][i]<a[1][y][i]) return true;
        else if(a[1][x][i]>a[1][y][i]) return false;
    }
    return false;
}
signed main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    n=read();m=read();
    fo(i,1,n){
        cin>>(s+1);
        fo(j,1,m){
            a[1][i][j]=a[0][i][j]=s[j]-'a';
        }
        b[i]=i;
    }
    fo(i,1,n){
        sort(a[0][i]+1,a[0][i]+m+1);
        sort(a[1][i]+1,a[1][i]+m+1,cmp);
    }
    fo(i,1,m) a[1][0][i]=27;
    int mx=0,mmx=0;
    fo(i,1,n){
        if(check(i,mmx)){
            if(check(i,mx)){
                mmx=mx;
                mx=i;
            }
            else mmx=i;
        }
    }
    fo(i,1,n){
        int x=mx;
        if(i==mx) x=mmx;
        int fl=0;
        fo(j,1,m){
            if(a[0][i][j]<a[1][x][j]){
                putchar('1');
                fl=1;
                break;
            }
            else if(a[0][i][j]>a[1][x][j]){
                putchar('0');
                fl=1;
                break;
            }
        }
        if(!fl) putchar('0');
    }
    return 0;
}
/*
1096
*/