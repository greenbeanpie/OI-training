#include<bits/stdc++.h>
#define maxn 3005
#define maxl 500005
using namespace std;
int c,n,m,q,a[maxl],b[maxl],x[maxl],y[maxl];
bool f[maxn][maxn];
inline int read(){
	int ret=0;char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch)) ret=ret*10+ch-'0',ch=getchar();
	return ret;
}
void work1(){
	memset(f,0,sizeof f);f[1][1]=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(a[i]>b[j]) f[i][j]|=f[i-1][j-1]|f[i][j-1]|f[i-1][j];
	if(f[n][m]) printf("1");
	else printf("0");
}
void work2(){
	memset(f,0,sizeof f);f[1][1]=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(a[i]<b[j]) f[i][j]|=f[i-1][j-1]|f[i][j-1]|f[i-1][j];
//	for(int i=1;i<=n;i++)
//	for(int j=1;j<=m;j++) printf("%d%c",f[i][j],j==m?'\n':' ');	
	if(f[n][m]) printf("1");
	else printf("0");
}
void work3(){
	int lst=0;bool p;
	if(a[1]>b[1]) p=1;else p=0;
	for(int i=1;i<=n;i++){
		if(p==1) while(lst<m&&b[lst+1]<a[i]) lst++;
		else while(lst<m&&b[lst+1]>a[i]) lst++;
	}
	if(lst==m) printf("1");
	else printf("0");
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	c=read(),n=read(),m=read(),q=read();
	if(c<=7||(n<=3000&&m<=3000)){
		for(int i=1;i<=n;i++) x[i]=a[i]=read();
		for(int i=1;i<=m;i++) y[i]=b[i]=read();
		if(a[1]==b[1]||a[n]==b[m]) printf("0");
		else if(a[1]>b[1]) work1();
		else work2();
		while(q--){
			int k1=read(),k2=read();
			for(int i=1;i<=n;i++) a[i]=x[i];
			for(int i=1;i<=m;i++) b[i]=y[i];
			for(int i=1;i<=k1;i++){
				int x=read(),v=read();
				a[x]=v;
			}
			for(int i=1;i<=k2;i++){
				int x=read(),v=read();
				b[x]=v;
			}
			if(a[1]==b[1]||a[n]==b[m]) printf("0");
			else if(a[1]>b[1]) work1();
			else work2();
		}
	}else{
		for(int i=1;i<=n;i++) x[i]=a[i]=read();
		for(int i=1;i<=m;i++) y[i]=b[i]=read();
		if(a[1]==b[1]||a[n]==b[m]) printf("0");
		else if(a[1]>b[1]&&a[n]<b[m]) printf("0");
		else if(a[1]>b[1]&&a[n]<b[m]) printf("0");
		else work3();
		while(q--){
			int k1=read(),k2=read();
			for(int i=1;i<=n;i++) a[i]=x[i];
			for(int i=1;i<=m;i++) b[i]=y[i];
			for(int i=1;i<=k1;i++){
				int x=read(),v=read();
				a[x]=v;
			}
			for(int i=1;i<=k2;i++){
				int x=read(),v=read();
				b[x]=v;
			}
			if(a[1]==b[1]||a[n]==b[m]) printf("0");
			else if(a[1]>b[1]&&a[n]<b[m]) printf("0");
			else if(a[1]>b[1]&&a[n]<b[m]) printf("0");
			else work3();
		}
	}
	return 0;
}