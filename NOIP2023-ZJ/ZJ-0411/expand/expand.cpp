#include<bits/stdc++.h>
using namespace std;
inline bool _u(char x){return x>='0'&&x<='9';}
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	for(;!_u(ch);ch=='-'&&(f=-1),ch=getchar());
	for(;_u(ch);x=x*10+(ch^48),ch=getchar());
	return x*f;
}
inline void write(int num,bool flag=0){
	static int st[39],tp=0;
	num<0&&(putchar('-'),num=-num);
	do st[++tp]=num%10;while(num/=10);
	while(tp)putchar(st[tp--]|48);
	putchar(flag?'\n':' ');
	return;
}
template<typename...Args>
inline void write(int t,Args...args){
	return write(t),write(args...);
}
const int N=5e5+10;
int a[N],b[N];
int c,n,m,q;

namespace ptsfyn{
	int a1[N],b1[N];
	bool dp[2][N];
	bool check(){
		bool f=0;
		memset(dp[f],0,sizeof(dp[f]));
		dp[f][0]=1;
		b[m+1]=b[m];
		for(int i=1;i<=n;++i){
			f^=1;
			memset(dp[f],0,sizeof(dp[f]));
			for(int j=1;j<=m+1;++j)
				if(a[i]!=b[j]&&(a[i]<b[j])==(a[1]<b[1])) dp[f][j]|=dp[f^1][j]|dp[f^1][j-1];
			for(int j=1;j<=m+1;++j)
				if(a[i]!=b[j]&&(a[i]<b[j])==(a[1]<b[1])) dp[f][j]|=dp[f][j-1];
			bool flag=0;
			dp[f][m]|=dp[f][m+1];
			for(int j=1;j<=m+1;++j)
				flag|=dp[f][j];
			if(!flag)return false;
		}
		if(!dp[f][m])return false;
		return true;
	}
	
	inline void _main(){
		memcpy(a1+1,a+1,n*sizeof(int));
		memcpy(b1+1,b+1,m*sizeof(int));
		putchar(check()|48);
		for(int kx,ky;q--;){
			kx=read(),ky=read();
			memcpy(a+1,a1+1,n*sizeof(int));
			memcpy(b+1,b1+1,m*sizeof(int));
			for(int i=1,x,y;i<=kx;++i)
				x=read(),y=read(),a[x]=y;
			for(int i=1,x,y;i<=ky;++i)
				x=read(),y=read(),b[x]=y;
			if(a[1]==b[1]||a[n]==b[m]){
				putchar('0');
				continue;
			}
			putchar(check()|48);
		}
		return;
	}
	
}

signed main(){
	freopen("expand.in","r",stdin),freopen("expand.out","w",stdout);
	c=read(),n=read(),m=read(),q=read();
	for(int i=1;i<=n;++i)a[i]=read();
	for(int i=1;i<=m;++i)b[i]=read();
	ptsfyn::_main();
	return (39-39);
}
/*
4 6 6 60
195982977 303897138 437154869 81559605 365511323 302808478
342942401 297976421 445071632 83871721 304067809 427239638
6 6
6 909678381
4 966742067
1 950087990
2 922968889
5 834991722
3 880355772
6 845896874
3 791681101
4 956185939
1 918655047
5 941339699
2 930778126
*/


