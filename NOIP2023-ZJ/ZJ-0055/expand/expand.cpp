#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
char buf[N<<2],*p1,*p2;
#define getchar() ((p1==p2&&(p2=(p1=buf)+fread(buf,1,N<<2,stdin),p1==p2))?0:*p1++)
inline int read(){
	char ch=getchar();int x=0;
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9')
		x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x;
}
int c,n,m,q,x[N],y[N];
int a[N],b[N];bool f[N][2];
void dp(){
	memset(f,0,sizeof(f));f[0][0]=1;
	if(x[1]<y[1]){
		for(int i=1;i<=n;i++){
			int p=i&1,np=!p;
			int now=f[0][np];f[0][p]=0;
			for(int j=1;j<=m;j++)
				if(x[i]>=y[j]) now=f[j][np],f[j][p]=0;
				else f[j][p]=(now|=f[j][np]);
		}
	}else if(x[1]>y[1]){
		for(int i=1;i<=n;i++){
			int p=i&1,np=!p;
			int now=f[0][np];f[0][p]=0;
			for(int j=1;j<=m;j++)
				if(x[i]<=y[j]) now=f[j][np],f[j][p]=0;
				else f[j][p]=(now|=f[j][np]);
		}
	}else f[m][n&1]=0;
	putchar(f[m][n&1]^48);
}
signed main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	c=read();n=read();m=read();q=read();
	for(int i=1;i<=n;i++) x[i]=read();
	for(int i=1;i<=m;i++) y[i]=read();dp();
	for(int i=1;i<=q;i++){
		int kx=read(),ky=read();
		memcpy(a,x,(n+1)<<2);memcpy(b,y,(m+1)<<2);
		for(int j=1;j<=kx;j++){
			int pos=read(),v=read();
			x[pos]=v;
		}
		for(int j=1;j<=ky;j++){
			int pos=read(),v=read();
			y[pos]=v;
		}dp();
		memcpy(x,a,(n+1)<<2);memcpy(y,b,(m+1)<<2);
	}
	return 0;
}//35pts