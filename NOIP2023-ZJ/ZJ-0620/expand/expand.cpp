#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int f=1,x=0;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch<='9'&&ch>='0'){ x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int c,n,m,q;
int a[500005],b[500005];
int main(){
	c=read(),n=read(),m=read(),q=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	for(int j=1;j<=m;j++){
		b[j]=read();
	}
	while(q--){
		int x,y,a,b;
		x=read(),y=read();
		for(int i=1;i<=x;i++){
			a=read(),b=read();
		}
		for(int j=1;j<=y;j++){
			a=read(),b=read();
		}
		cout<<0;
	}
	return 0;
}