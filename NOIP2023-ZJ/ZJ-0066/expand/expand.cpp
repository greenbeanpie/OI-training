#include<bits/stdc++.h>
using namespace std;
constexpr int M=5e5+5;
int n,m,c,q,p,v,x[M],y[M],a[M],b[M];
bool dp[2][M];
int read(){
	int x=0;char ch=getchar();
	while (!isdigit(ch)) ch=getchar();
	while (isdigit(ch)) x=x*10+ch-48,ch=getchar();
	return x;
}
int calc(){
	if (x[1]==y[1]) return 0;
	bool f=x[1]<y[1];
	int xmin=1<<30,xmax=0,ymin=1<<30,ymax=0;
	for (int i=1;i<=n;i++) xmin=min(xmin,x[i]),xmax=max(xmax,x[i]);
	for (int i=1;i<=m;i++) ymin=min(ymin,y[i]),ymax=max(ymax,y[i]);
	if (f&&xmax>=ymax||!f&&xmin<=ymin) return 0;
	for (int i=0;i<=m;i++) dp[0][i]=dp[1][i]=0;
	int now=0,mx=1;dp[0][1]=1;
	for (int i=1;i<=n;now^=1,i++){
		for (int i=1;i<=mx;i++) dp[!now][i]=0;
		for (int j=1;j<=mx;j++){
			if (!dp[now][j]) continue;
			if (i<n&&(f?x[i+1]<y[j]:x[i+1]>y[j])) dp[!now][j]=1;
			if (j<m&&(f?x[i]<y[j+1]:x[i]>y[j+1])) dp[now][j+1]=1,mx=max(mx,j+1);
		}
	}
	return dp[!now][m];
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	c=read();n=read();m=read();q=read();
	for (int i=1;i<=n;i++) x[i]=a[i]=read();
	for (int i=1;i<=m;i++) y[i]=b[i]=read();
	putchar(calc()+'0');
	for (int i=1;i<=q;i++){
		for (int i=1;i<=n;i++) x[i]=a[i];
		for (int i=1;i<=m;i++) y[i]=b[i];
		int k1=read(),k2=read();
		while (k1--){p=read();v=read();x[p]=v;}
		while (k2--){p=read();v=read();y[p]=v;}
		putchar(calc()+'0');
	}
	return 0;
}
/*

#include<bits/stdc++.h>
using namespace std;
constexpr int M=5e5+5;
int n,m,c,q,p,v,x[M],y[M],a[M],b[M];
int read(){
	int x=0;char ch=getchar();
	while (!isdigit(ch)) ch=getchar();
	while (isdigit(ch)) x=x*10+ch-48,ch=getchar();
	return x;
}
int maxx(int l,int r){
	int pos=l;
	for (int i=l;i<=r;i++)
		if (x[i]>x[pos])
			pos=i;
	return pos;
}
int minx(int l,int r){
	int pos=l;
	for (int i=l;i<=r;i++)
		if (x[i]<x[pos])
			pos=i;
	return pos;
}
int maxy(int l,int r){
	int pos=l;
	for (int i=l;i<=r;i++)
		if (y[i]>y[pos])
			pos=i;
	return pos;
}
int miny(int l,int r){
	int pos=l;
	for (int i=l;i<=r;i++)
		if (y[i]<y[pos])
			pos=i;
	return pos;
} bool fl;
int chk(int xl,int xr,int yl,int yr){
	if (xl>xr||yl>yr) return 1;
	int posx=maxx(xl,xr),posy=maxy(yl,yr);
	if (x[posx]<=y[posy]) return 0;
	int p1=miny(yl,posy),p2=miny(posy,yr);
	int q1=minx(xl,posx),q2=minx(posx,xr);
	if (x[q1]<=y[p1]||x[q2]<=y[p2]) return 0;
	return chk(xl,posx-1,yl,p1)&&chk(q1,xr,p2,yr);
}
int calc(){
	if (x[1]==y[1]) return 0;
	if (x[1]<y[1]){
		for (int i=1;i<=n;i++) x[i]=-x[i];
		for (int i=1;i<=m;i++) y[i]=-y[i];
	}
	return chk(1,n,1,m);
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	c=read();n=read();m=read();q=read();
	for (int i=1;i<=n;i++) x[i]=a[i]=read();
	for (int i=1;i<=m;i++) y[i]=b[i]=read();
	putchar(calc()+'0');
	for (int i=1;i<=q;i++){
		for (int i=1;i<=n;i++) x[i]=a[i];
		for (int i=1;i<=m;i++) y[i]=b[i];
		int k1=read(),k2=read();
		while (k1--){p=read();v=read();x[p]=v;}
		while (k2--){p=read();v=read();y[p]=v;}
		putchar(calc()+'0');
	}
	return 0;
}
*/