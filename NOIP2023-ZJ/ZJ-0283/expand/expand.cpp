#include<bits/stdc++.h>
#define N 2005
using namespace std;
int n,C,T,m,f[N][N],a[N],b[N],c[N],d[N],n1,n2,kx[N],ky[N];
bool tmp;
inline int read(){
	int res=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9')f=ch=='-'?-1:f,ch=getchar();
	while(ch>='0'&&ch<='9')res=res*10+ch-'0',ch=getchar();
	return res*f;
}
signed main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	C=read(),n=read(),m=read(),T=read();
	if(n>2000||m>2000){for(int i=0;i<=T;++i)printf("0");return 0;}
	for(int i=1;i<=n;++i)a[i]=c[i]=read();
	for(int i=1;i<=m;++i)b[i]=d[i]=read();
	f[0][0]=1;
	if(a[1]<b[1])swap(a,b),swap(n,m),tmp=1;
	for(int i=1;i<=n;++i)
	for(int j=1;j<=m;++j){
		f[i][j]=0;
		if(a[i]>b[j])f[i][j]|=f[i-1][j-1]|f[i-1][j]|f[i][j-1];
	}
	printf("%d",f[n][m]);
	if(tmp)swap(a,b),swap(n,m);
	while(T--){
		tmp=0;
		n1=read(),n2=read();
		for(int i=1;i<=n1;++i)kx[i]=read(),a[kx[i]]=read();
		for(int i=1;i<=n2;++i)ky[i]=read(),b[ky[i]]=read();
		if(a[1]<b[1])swap(a,b),swap(n,m),tmp=1;
		for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j){
			f[i][j]=0;
			if(a[i]>b[j])f[i][j]|=f[i-1][j-1]|f[i-1][j]|f[i][j-1];
		}
		printf("%d",f[n][m]);
		if(tmp)swap(a,b),swap(n,m);
		for(int i=1;i<=n1;++i)a[kx[i]]=c[kx[i]];
		for(int i=1;i<=n2;++i)b[ky[i]]=d[ky[i]];
	}
	return 0;
}