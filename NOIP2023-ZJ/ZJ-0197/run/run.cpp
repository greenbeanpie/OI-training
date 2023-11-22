#include<bits/stdc++.h>
#define maxn 100005
#define int long long
using namespace std;
int c,ans,T,n,m,k,d,f[1005][1005];
int v[1005][1005];
inline int read(){
	int ret=0;char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch)) ret=ret*10+ch-'0',ch=getchar();
	return ret;
}
void work1(){
	while(T--){
		n=read(),m=read(),k=read(),d=read();
		memset(v,0,sizeof v);memset(f,0,sizeof f);
		for(int i=1;i<=m;i++){
			int x=read(),y=read();v[x][y]+=read();
		}
		for(int i=1;i<=n;i++)
		for(int j=1;j<=k;j++) v[i][j]+=v[i][j-1];
		f[1][1]=v[1][1]-d;
		int Max=max(f[1][0],f[1][1]),ans=-1ll<<60;
		for(int i=2;i<=n;i++){
			f[i][0]=max(Max,f[i-1][0]);
			int maxx=f[i][0];
			for(int j=1;j<=min(i,k);j++){
				f[i][j]=f[i-1][j-1]-d+v[i][j];
				maxx=max(maxx,f[i][j]);
			}Max=maxx;ans=max(ans,maxx);
		}
//		for(int i=0;i<=k;i++) ans=max(ans,f[n][i]);
		printf("%lld\n",ans);
	}
}
signed main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	c=read(),T=read();
	if(c<=9) work1();
//	else work2();
	return 0;
}