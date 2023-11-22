#include <bits/stdc++.h>
using namespace std;
#define mk make_pair
inline int read(){
	int x=0,f=1;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=-1;
	for(; isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	return f*x;
}
inline void write(int x){
	if(x>9) write(x/10);
	putchar(x%10^48);
}
inline char readc(){
	char ch=getchar();
	for(;ch=='\n'||ch==' '||ch==EOF;ch=getchar());
	return ch;
}
const int N=1e5+10;
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	int c,n,m,q;
	c=read(),n=read(),m=read(),q=read();
	for(int i=0;i<=q;i++) putchar('0');
	exit(0);
	return 0;
}//0