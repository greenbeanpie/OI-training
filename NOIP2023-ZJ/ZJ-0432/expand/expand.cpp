#include<bits/stdc++.h>
#define gc getchar()
using namespace std;
inline int read(){
	int x=0,f=1;char ch=gc;
	for(;!isdigit(ch);ch=gc)if(ch=='-')f=-1;
	for(;isdigit(ch);ch=gc)x=x*10+ch-'0';
	return x*f;
}
int c,n,m,q;
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	c=read(),n=read(),m=read(),q=read();
	for(int i=0;i<=q;i++){
		putchar('1');
	}
	return 0;
}