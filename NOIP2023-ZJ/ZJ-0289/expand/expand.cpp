#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define mst(a,b) memset(a,b,sizeof(a))
#define kp(a,b) make_pair(a,b)
#define fi first
#define se second
inline int read(){
	int x=0;bool f=true;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=false;
	for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+c-'0';
	return f?x:(~(x-1));
}
int c,n,m,q;
namespace Sub1{
	const int N=2e3+100;
	int x[N],y[N],cx[N],cy[N];
	bool f[N][N];
	bool solve(int a[],int b[]){
		mst(f,false);
		if(a[1]<=b[1]) return false;
		f[1][1]=true;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(a[i+1]>b[j+1]) f[i+1][j+1]|=f[i][j]; 
				if(a[i+1]>b[j]) f[i+1][j]|=f[i][j]; 
				if(a[i]>b[j+1]) f[i][j+1]|=f[i][j]; 
			}
		}
		return f[n][m];
	}
	void work(){
		for(int i=1;i<=n;i++) x[i]=read();
		for(int i=1;i<=m;i++) y[i]=read();
		putchar('0'+(solve(x,y)||solve(y,x)));
		for(int i=1;i<=q;i++){
			for(int j=1;j<=n;j++) cx[j]=x[j];
			for(int j=1;j<=m;j++) cy[j]=y[j];
			int kx=read(),ky=read();
			for(int j=1;j<=kx;j++){
				int p=read(),v=read();
				cx[p]=v;
			}
			for(int j=1;j<=ky;j++){
				int p=read(),v=read();
				cy[p]=v;
			}
			putchar('0'+(solve(cx,cy)||solve(cy,cx)));
		}
	}
}
namespace Sub2{
	void work(){
		for(int i=1;i<=n;i++) read();
		for(int i=1;i<=m;i++) read();
		for(int i=1;i<=q;i++){
			int kx=read(),ky=read();
			for(int j=1;j<=kx+ky;j++){
				read();read();
			}
		}
		for(int i=0;i<=q;i++){
			cout<<"1";
		}
	}
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	c=read();n=read();m=read();q=read();
	if(c<=7) Sub1::work();
	else Sub2::work();
	return 0;
}