//LG UID 1019966
//ji
//11:38 44pts
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
inline ll read(){
	ll s=0;char c=getchar();
	while(c<48||c>57)c=getchar();
	while(c>47&&c<58)s=(s<<3)+(s<<1)+(c^48),c=getchar();
	return s;
}
const int M=1e5+5;
ll cyl,_,n,m,k,d,x[M],y[M],v[M],f[1005][1005],ans;
int main(){
freopen("run.in","r",stdin);freopen("run.out","w",stdout);
	cyl=read();_=read();
	while(_--){
		n=read();m=read();k=read();d=read();
		for(int i=1;i<=m;i++)x[i]=read(),y[i]=read(),v[i]=read();
		if(cyl<10){
			memset(f,0,sizeof(f));
			for(int j=1;j<=k;j++)f[0][j]=-0x3f3f3f3f;
			ans=0;
			for(int i=1;i<=m;i++)
				if(y[i]<=k)
					for(int j=y[i];j<=k;j++)f[x[i]][j]+=v[i];
			for(int i=1;i<=n;i++){
				for(int j=0;j<=k;j++)f[i][0]=max(f[i-1][j],f[i][0]);
				for(int j=1;j<=k;j++)f[i][j]+=f[i-1][j-1]-d;
			}
			for(int j=0;j<=k;j++)ans=max(f[n][j],ans);
			printf("%lld\n",ans);
		}else{
			ans=0;
			for(int i=1;i<=m;i++)
				if(y[i]*d<v[i])ans+=v[i]-y[i]*d;
			printf("%lld\n",ans);
		}
	}
	return 0;
}