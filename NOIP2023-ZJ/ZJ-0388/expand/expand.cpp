#include<bits/stdc++.h>
using namespace std;
int C,n,m,q;
int read(){
	int w=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') w=(w<<1)+(w<<3)+(ch^48),ch=getchar();
	return w*f;
}
namespace T31{
	int f[2005][2005],g[2005][2005],x[2005],y[2005],a[2005],b[2005];
	bool solve1(int i,int j){
		if(i==0&&j==0) return 1;
		if(i==0||j==0) return 0;
		if(f[i][j]!=-1) return f[i][j];
		int res=0;
		if(x[i]>y[j]) res=(solve1(i-1,j-1)|solve1(i,j-1)|solve1(i-1,j));
		return f[i][j]=res;
	}
	bool solve2(int i,int j){
		if(i==0&&j==0) return 1;
		if(i==0||j==0) return 0;
		if(g[i][j]!=-1) return g[i][j];
		int res=0;
		if(x[i]<y[j]) res=(solve2(i-1,j-1)|solve2(i,j-1)|solve2(i-1,j));
		return g[i][j]=res;
	}
	void solve(){
		for(int i=1;i<=n;i++) a[i]=read();
		for(int i=1;i<=m;i++) b[i]=read();
		for(int i=0;i<=q;i++){
			for(int j=1;j<=n;j++) x[j]=a[j];
			for(int j=1;j<=m;j++) y[j]=b[j];
			for(int j=1;j<=n;j++)
				for(int k=1;k<=m;k++) f[j][k]=g[j][k]=-1;
			if(i==0){
				if(solve1(n,m)||solve2(n,m)) putchar('1');
				else putchar('0');
				continue;
			}
			int kx=read(),ky=read();
			for(int j=1,p,v;j<=kx;j++){
				p=read();v=read();
				x[p]=v;
			}
			for(int j=1,p,v;j<=ky;j++){
				p=read();v=read();
				y[p]=v;
			}
			if(solve1(n,m)||solve2(n,m)) putchar('1');
			else putchar('0');
		}
		printf("\n");
	}
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	C=read();n=read();m=read();q=read();
	if(C<=7){
		T31::solve();
		return 0;
	}
	return 0;
}