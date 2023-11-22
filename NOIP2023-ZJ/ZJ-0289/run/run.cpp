#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define mst(a,b) memset(a,b,sizeof(a))
#define kp(a,b) make_pair(a,b)
#define fi first
#define se second
inline int read(){
	int x=0;bool f=true;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=false;
	for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+c-'0';
	return f?x:(~(x-1));
}
int c,T;
int n,m,k;
ll d;
namespace Sub1{
	const int N=1e3+100;
	ll a[N][N],sum[N][N],f[N][N];
	void work(){
		mst(a,0);mst(f,0);
		n=read();m=read();k=read();d=read();
		for(int i=1;i<=m;i++){
			int x=read(),y=read(),v=read();
			a[x][y]+=v;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k;j++){
				sum[i][j]=sum[i][j-1]+a[i][j];
			}
		}
		for(int i=0;i<=n;i++){
			for(int j=0;j<=k;j++){
				f[i][j]= -0x3f3f3f3f3f3f3f3f;
			}
		}
		f[0][0]=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j<=k;j++){
				f[i][0]=max(f[i][0],f[i-1][j]);
			}
			for(int j=1;j<=k;j++){
				f[i][j]=f[i-1][j-1]-d+sum[i][j];
			}
		}
		ll ans=0;
		for(int i=0;i<=n;i++){
			ans=max(ans,f[n][i]);
		}
		printf("%lld\n",ans);
	}
}
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	c=read();T=read();
	while(T--){
		Sub1::work();
	}
	return 0;
}