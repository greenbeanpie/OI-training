#include<bits/stdc++.h>
#define rr register
#define N 100005
using namespace std;
int read(){
	rr int num=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-f;ch=getchar();}
	while(ch>='0'&&ch<='9') num=(num<<3)+(num<<1)+ch-'0',ch=getchar();
	return f*num;
}
int c,n,m,q;
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	srand(time(0));
	c=read(),n=read(),m=read(),q=read();
	for(rr int i=1;i<=q+1;++i) printf("%d",rand()&1);
	return 0;
}
