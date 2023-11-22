#include<bits/stdc++.h>
#define int long long
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
const int N=1e5+10;
int n,m,k,d;
int c,t;
namespace pts28{
	int dp[1010][1010];
	int sum[1010][1010];
	inline void _main(){
		for(;t--;){
			memset(sum,0,sizeof(sum));
			n=read(),m=read();k=read(),d=read();
			for(int i=1,x,y,z;i<=m;++i)
				x=read(),y=read(),z=read(),sum[x][y]+=z;
			for(int i=1;i<=n;++i)
				for(int j=1;j<=k;++j)
					sum[i][j]+=sum[i][j-1];
			memset(dp,-0x3f,sizeof(dp));
			dp[0][0]=0;
			for(int i=1;i<=n;++i){
				dp[i][0]=dp[i-1][0];
				for(int j=1;j<=k;++j)
					dp[i][0]=max(dp[i][0],dp[i-1][j]),
					dp[i][j]=max(dp[i][j],dp[i-1][j-1]-d+sum[i][j]);
				dp[i][0]+=sum[i][0];
			}
			int ans=0;
			for(int j=0;j<=k;++j) ans=max(ans,dp[n][j]);
			write(ans,true);
		}
	}
}

namespace ptsA{
	tuple<int,int,int>a[N+200];
	int dp[2][N];
	inline void _main(){
		for(;t--;){
			memset(a,0,sizeof(a));
			n=read(),m=read();k=read(),d=read();
			for(int i=1,x,y,v;i<=m;++i){
				x=read(),y=read(),v=read();
				if(y<=k&&y<=x) a[i]=make_tuple(x,y,v);
			}
			sort(a+1,a+m+1);
			a[++m]=make_tuple(n,0,0);
			bool f=0;
			memset(dp[f],-0x3f,sizeof dp[f]);
			dp[f][0]=0;
			for(int i=1,x,y,v;i<=m;++i){
				tie(x,y,v)=a[i];
				f^=1;
				memset(dp[f],-0x3f,sizeof(dp[f]));
				dp[f][0]=dp[f^1][0];
				int dis=x-get<0>(a[i-1]);
				for(int j=1;j<=k;++j)dp[f][0]=max(dp[f][0],dp[f^1][j]);
				for(int j=min(k,x);~j;--j){
					if(dis<=j)dp[f][j]=max(dp[f][j],dp[f^1][j-dis]-dis*d+v*(j>=y));
					else dp[f][j]=max(dp[f][j],dp[f][0]-j*d+v*(j>=y));
				}
			}
			int ans=0;
			for(int i=0;i<=k;++i) ans=max(ans,dp[f][i]);
			write(ans,true);
		}
	}
	
}


signed main(){
	freopen("run.in","r",stdin),freopen("run.out","w",stdout);
	c=read(),t=read();
	if(c<=7) pts28::_main(),exit(0);
	ptsA::_main(),exit(0);
	return (39-39);
}

