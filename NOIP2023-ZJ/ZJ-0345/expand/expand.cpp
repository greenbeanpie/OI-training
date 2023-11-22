#include<bits/stdc++.h>
using namespace std;
int c,q,n,m,ans,a[500005],b[500005],A[500005],B[500005];
int read(){
	int ret=0,f=1;char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) if(ch=='-') f=-f;
	while(isdigit(ch)) ret=(ret<<3)+(ret<<1)+(ch&15),ch=getchar();
	return ret*f;
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	c=read(),n=read(),m=read(),q=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int j=1;j<=m;j++) b[j]=read();
	int I=1,J=1;
	if(a[I]==b[J]){putchar('0');goto loop;}
	if(a[I]>b[J]) while(I<n&&J<m){
		;
	}else while(I<n&&J<m){
		;
	}
	loop:while(q--){
		int ka=read(),kb=read(),x,y;
		memcpy(A,a,sizeof a);memcpy(B,b,sizeof b);
		for(int i=1;i<=ka;i++) x=read(),y=read(),A[x]=y;
		for(int i=1;i<=kb;i++) x=read(),y=read(),B[x]=y;
		;
		;
	}
//	printf("\n%lf\n",(double)clock()/CLOCKS_PER_SEC);
	return 0;
}
