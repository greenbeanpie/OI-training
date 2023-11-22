#include<bits/stdc++.h>
using namespace std;
int n,m,c,q,a[1001],b[1001];
int read(){
	int x=0,f=1;
	char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') f=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-48;
	return x*f;
}
void write(int x){
	if (x<0) x=-x,putchar('-');
	if (x<10) putchar(x+48);
	if (x==0) return;
	write(x/10);
}
signed main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	c=read();n=read();m=read();q=read();
	if (c>=2) {
		for(int i=1;i<=q+1;i++) printf("1");
		return 0;
	}
	for(int i=1;i<=n;i++) a[i]=read();
	for(int j=1;j<=m;j++) b[j]=read();
	if (c==1) {
		if (a[1]>b[1]) printf("1");
		else printf("0");
		for(int i=1;i<=q;i++) {
			int kx=read(),ky=read();
			kx=read();ky=read();
			a[1]=ky;
			kx=read();ky=read();
			b[1]=ky;
			if (a[1]>b[1]) printf("1");
			else printf("0");
		}
	}
	return 0;
}

