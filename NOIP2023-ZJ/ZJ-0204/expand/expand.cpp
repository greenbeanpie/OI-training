#include<cstdio>
#include<cstring>
using namespace std;
inline int read(){
	int x=0;char ch;
	do ch=getchar(); while(ch<'0'||ch>'9');
	do x=(x<<3)+(x<<1)+(ch^48),ch=getchar(); while(ch>='0'&&ch<='9');
	return x;
}
const int N=2005;
int c,q;
int ls,lt,s[N],t[N];
int a[N],b[N],f[N][N];
void solve(){
    int flg=a[1]>b[1];
    memset(f,0,sizeof(f));
    f[0][0]=1;
    for(int i=1;i<=ls;i++)
        for(int j=1;j<=lt;j++)
			(a[i]>b[j]==flg)?f[i][j]=f[i-1][j-1]|f[i-1][j]|f[i][j-1]:0;
    putchar(f[ls][lt]+'0');
}
int main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    c=read();ls=read();lt=read();q=read();
    for(int i=1;i<=ls;i++)s[i]=read();
    for(int i=1;i<=lt;i++)t[i]=read();
    memcpy(a,s,sizeof(s));
    memcpy(b,t,sizeof(t));
    solve();
	while(q--){
        int kx=read(),ky=read();
        memcpy(a,s,sizeof(s));
        memcpy(b,t,sizeof(t));
        while(kx--){
            int px=read(),vx=read();
            a[px]=vx;
        }
		while(ky--){
            int py=read(),vy=read();
            b[py]=vy;
        }
        solve();
    }
    return 0;
}
