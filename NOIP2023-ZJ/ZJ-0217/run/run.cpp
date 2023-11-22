#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e3+25,M=1e5+110;
int read(){
	int x=0,f=1;char c=getchar();
	while(c>'9' || c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c>='0' && c<='9'){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
int c,T,n,m,K,d;
int sum[N];
int l[M],r[M],ad[M];
void solve(){
	memset(sum,0,sizeof(sum));
	n=read(),m=read(),K=read(),d=read();
	for(int i=1;i<=m;i++){
		r[i]=read(),l[i]=r[i]-read()+1,ad[i]=read();
	}
	for(int i=1;i<=n;i++){
		int maxn=0;
		for(int j=1;j<=min(K,i);j++){
			int tmp=((i-j-1>=0)?sum[i-j-1]:0)-d*j;
			for(int p=1;p<=m;p++)
				if(l[p]>=i-j+1 && r[p]<=i)tmp+=ad[p];
			maxn=max(maxn,tmp);
		}
		sum[i]=max(sum[i-1],maxn);
	}
	printf("%lld\n",sum[n]);
	return;
}
signed main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	c=read(),T=read();
	while(T--)solve();
	return 0;
}