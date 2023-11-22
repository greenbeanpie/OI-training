#include <bits/stdc++.h>
using namespace std;
int n,m,t,a[500005],b[500005],c[500005],d[500005];
bool opt[2005][2005];
int read(){
	int ret=0;bool f=true;char ch=getchar();
	while (!isdigit(ch)){if (ch=='-') f=false;ch=getchar();}
	while (isdigit(ch)) ret=(ret<<1)+(ret<<3)+(ch&15),ch=getchar();
	return f?ret:-ret;
}
bool work(int k){
	if (n>2000){return 1;}
	for (int i=1;i<=n;i++) a[i]=c[i];
	for (int i=1;i<=m;i++) b[i]=d[i];
	if (k){
		int x=read(),y=read();
		for (int i=1;i<=x;i++){
			int pos=read();
			a[pos]=read();
		}for (int i=1;i<=y;i++){
			int pos=read();
			b[pos]=read();
		}
	}opt[0][0]=1;
	if (a[1]<b[1]){
		for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++) if (a[i]<b[j]&&(opt[i-1][j]||opt[i-1][j-1]||opt[i][j-1]))
			opt[i][j]=1;else opt[i][j]=0;
		return opt[n][m];
	}else if (a[1]>b[1]){
		opt[1][1]=1;
		for (int i=1;i<=m;i++)
		for (int j=1;j<=n;j++) if (b[i]<a[j]&&(opt[i-1][j]||opt[i-1][j-1]||opt[i][j-1]))
			opt[i][j]=1;else opt[i][j]=0;
		return opt[m][n];
	}return 0;
}
int main(){
	freopen ("expand.in","r",stdin);
	freopen ("expand.out","w",stdout);
	read(),n=read(),m=read(),t=read();
	for (int i=1;i<=n;i++) c[i]=read();
	for (int j=1;j<=m;j++) d[j]=read();
	for (int k=0;k<=t;k++) printf ("%d",work(k));
	return 0;
}