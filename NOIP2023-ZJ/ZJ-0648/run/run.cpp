#include<bits/stdc++.h>
#define int long long
const int maxm = 1e4+5;
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-f;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return x*f;
}
int c,t;
int n,m,k,d;
int x[maxm],y[maxm],v[maxm];
int f[maxm][maxm];
signed main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	c=read();
	t=read();
	while(t--){
		n=read();
		m=read();
		k=read();
		d=read();
		for(int i=1;i<=m;i++){
			x[i]=read();
			y[i]=read();
			v[i]=read();
		}
		if(c==17||c==18){
			int ans=0;
			for(int i=1;i<=m;i++)
				ans=max(ans,ans+v[i]-d*y[i]);
			cout<<ans<<endl;
			continue;
		}
		for(int i=1;i<=m;i++){
			for(int j=0;j<=i;j++){
				f[i][j]=max(f[i][j],f[i-1][j]);
				if(x[j]-y[j]+1>x[j-1]-1&&y[j-1]<=k) f[i][j]=max(f[i][j],f[i-1][j-1]+v[j]-y[j]*d);
				else if(x[j]-x[j-1]+y[j-1]<=k)f[i][j]=max(f[i][j],f[i-1][j-1]+v[j]-(x[j]-x[j-1])*d);
			}
		}
		int ans=0;
		for(int i=0;i<=m;i++) ans=max(ans,f[m][i]);
		cout<<ans<<endl;
		for(int i=0;i<=m;i++)
		for(int j=0;j<=m;j++)
			f[i][j]=0;
	}
	return 0;
}
