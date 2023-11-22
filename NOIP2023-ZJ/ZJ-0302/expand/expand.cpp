#include<bits/stdc++.h>
#define N 500005
using namespace std;
int fain[N],faax[N],fbin[N],fbax[N];
int a[N],b[N],_a[N],_b[N],f[N];
int n,m;
int read(){
	int cnt=0;
	char ch=getchar();
	while (ch<'0'||ch>'9') ch=getchar();
	while ('0'<=ch&&ch<='9') cnt=cnt*10+ch-'0',ch=getchar();
	return cnt;
}
void init(){
	a[0]=b[0]=1e9;
	faax[n]=n+1;
	fbax[n]=m+1;
	for (int i=n-1;i>=1;i--){
		if (a[fain[i+1]]<a[i+1]) fain[i]=fain[i+1]; else fain[i]=i+1;
		if (a[faax[i+1]]>a[i+1]) faax[i]=faax[i+1]; else faax[i]=i+1;
	}
	for (int i=m-1;i>=1;i--){
		if (b[fbin[i+1]]<b[i+1]) fbin[i]=fbin[i+1]; else fbin[i]=i+1;
		if (b[fbax[i+1]]>b[i+1]) fbax[i]=fbax[i+1]; else fbax[i]=i+1;
	}
}
bool judge(){
	memset(f,0,sizeof(f));
	memset(fain,0,sizeof(fain));
	memset(faax,0,sizeof(faax));
	memset(fbin,0,sizeof(fbin));
	memset(fbax,0,sizeof(fbax));
	if (a[1]==b[1]||a[n]==b[m]||(a[1]<b[1]&&a[n]>b[m])||(a[1]>b[1]&&a[n]<b[m])) return 0;
	init();
	f[0]=1;
	if (a[1]<b[1]){
		if (a[fain[1]]>=b[fbin[1]]||a[faax[1]]>=b[fbax[1]]) return 0;
		for (int i=1;i<=m;i++){
			for (int j=f[i-1];j<=n;j++)
				if (a[j]<b[i]) {f[i]=j;break;}
			while (a[faax[f[i]]]>=b[fbax[i]]&&f[i]!=n+1) if (a[faax[f[i]]]<b[i]) f[i]=faax[f[i]]; else return 0;
		}
		return 1;
	} else {
		if (a[fain[1]]<=b[fbin[1]]||a[faax[1]]<=b[fbax[1]]) return 0;
		for (int i=1;i<=m;i++){
			for (int j=f[i-1];j<=n;j++)
				if (a[j]>b[i]) {f[i]=j;break;}
			while (a[fain[f[i]]]<=b[fbin[i]]&&f[i]) if (a[fain[f[i]]]>b[i]) f[i]=fain[f[i]]; else return 0;
		}
		return 1;
	}
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	int opt=read();
	n=read(),m=read();
	int q=read();
	for (int i=1;i<=n;i++) a[i]=_a[i]=read();
	for (int i=1;i<=m;i++) b[i]=_b[i]=read();
	printf("%d",judge());
	while (q--){
		int kx=read(),ky=read(),x,y;
		for (int i=1;i<=kx;i++) x=read(),y=read(),a[x]=y;
		for (int i=1;i<=ky;i++) x=read(),y=read(),b[x]=y;
		printf("%d",judge());
		for (int i=1;i<=n;i++) a[i]=_a[i];
		for (int i=1;i<=m;i++) b[i]=_b[i];
	}
	return 0;
}
