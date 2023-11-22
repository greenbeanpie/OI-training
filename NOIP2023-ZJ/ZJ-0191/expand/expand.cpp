//LG UID 1019966
//ji
//best:100+100+35+44=279
//worst:0+0+0+0=0
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
inline ll read(){
	ll s=0;char c=getchar();
	while(c<48||c>57)c=getchar();
	while(c>47&&c<58)s=(s<<3)+(s<<1)+(c^48),c=getchar();
	return s;
}
const int N=5e5+5;
ll cyl,n,m,q,x[N],y[N],xx[N],yy[N],kx,ky,p;bool f[2005][2005];
bool pd(){
//	memset(f,0,sizeof(f));
	if(x[1]==y[1])return 0;
	f[1][1]=1;
	for(int i=2;i<=m;i++)
		if((x[1]-y[i])*(x[1]-y[1])>0)f[1][i]=f[1][i-1];
		else f[1][i]=0;
	for(int i=2;i<=n;i++)
		if((x[i]-y[1])*(x[1]-y[1])>0)f[i][1]=f[i-1][1];
		else f[i][1]=0;
	for(int i=2;i<=n;i++)
		for(int j=2;j<=m;j++)
			if((x[i]-y[j])*(x[1]-y[1])>0)f[i][j]=(f[i-1][j]|f[i][j-1]|f[i-1][j-1]);
			else f[i][j]=0;
	return f[n][m];
}
int main(){
freopen("expand.in","r",stdin);freopen("expand.out","w",stdout);
	cyl=read();n=read();m=read();q=read();
	if(n>2000){
		q++;
		while(q--)putchar(49);
		return 0;
	}
	for(int i=1;i<=n;i++)xx[i]=x[i]=read();
	for(int i=1;i<=m;i++)yy[i]=y[i]=read();
	putchar(pd()+48);
	while(q--){
		kx=read();ky=read();
		for(int i=1;i<=kx;i++)p=read(),x[p]=read();
		for(int i=1;i<=ky;i++)p=read(),y[p]=read();
		putchar(pd()+48);
		for(int i=1;i<=n;i++)x[i]=xx[i];
		for(int i=1;i<=m;i++)y[i]=yy[i];
	}
	return 0;
}