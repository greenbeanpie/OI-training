#include<bits/stdc++.h>
using namespace std;
const int N=2e3+10;
bool f[N][N],g[N][N];
int C,n,m,q,X[N],Y[N],XX[N],YY[N];
int kn,km;
inline bool work(){
	memset(f,0,sizeof f);
	memset(g,0,sizeof g);
	for(int i=1;i<=n;i++){
		f[0][0]=1,g[0][0]=1;
		for(int j=1;j<=m;j++){
			if(X[i]>Y[j]){
				f[i][j]|=(f[i-1][j-1]|f[i-1][j]|f[i][j-1]);
			}
		}
		for(int j=1;j<=m;j++){
			if(X[i]<Y[j]){
				g[i][j]|=(g[i-1][j-1]|g[i-1][j]|g[i][j-1]);
			}
		}
	}
	return (f[n][m]|g[n][m]);
}
inline int read(){
	char ch=getchar();
	int ret=0;
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')ret=ret*10+ch-'0',ch=getchar();
	return ret;
}
signed main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	C=read(),n=read(),m=read(),q=read();
	for(int i=1;i<=n;i++)XX[i]=read(),X[i]=XX[i];
	for(int i=1;i<=m;i++)YY[i]=read(),Y[i]=YY[i];
	if(work())putchar('1');
	else putchar('0');
	while(q--){
		for(int i=1;i<=n;i++)X[i]=XX[i];
		for(int i=1;i<=m;i++)Y[i]=YY[i];
		kn=read(),km=read();
		for(int i=1,x,y;i<=kn;i++)x=read(),y=read(),X[x]=y;
		for(int i=1,x,y;i<=km;i++)x=read(),y=read(),Y[x]=y;
		if(work())putchar('1');
		else putchar('0');
	}
	putchar('\n');
	return 0;
}
/*
12:10 finish 
expext 35pts
*/