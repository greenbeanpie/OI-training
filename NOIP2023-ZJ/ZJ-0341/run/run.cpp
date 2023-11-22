#include<bits/stdc++.h>
using namespace std;
#define int long long

int read(){
	int x=0,f=1;char c;c=getchar();
	while(c<'0'||c>'9'){ if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ x=x*10+(c-48);c=getchar();}
	return x*f;
}

const int maxn=1e5+10,INF=-1e18;

int dp[maxn][2],n,m,k,d,num,t,b[maxn];
struct node{
	int st,ed,w;
}a[maxn];

void init(){
	for(int i=1;i<=n;i++) dp[i][0]=dp[i][1]=INF,b[i]=0;
}

signed main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	num=read(),t=read();
	while(t--){
		n=read(),m=read(),k=read(),d=read();
		init();
		for(int i=1;i<=m;i++){
			a[i].ed=read();
			int x=read();
			a[i].st=a[i].ed-x+1;
			a[i].w=read();
		}
		dp[0][0]=dp[0][1]=0;
		for(int i=1;i<=n;i++){
			int tmp=max(i-k+1,(long long)1),val=0;
			for(int j=tmp;j<=n;j++) b[j]=0;
			for(int j=1;j<=m;j++){
				if(a[j].st>=tmp&&a[j].ed<=i){
					b[a[j].st]+=a[j].w;
					val+=a[j].w;
				}
			}
			for(int j=tmp;j<=i;j++){
				dp[i][1]=max(dp[i][1],dp[j-1][0]+val-(i-j+1)*d);
				val-=b[j];
			}
			dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
		}
		printf("%lld\n",max(dp[n][0],dp[n][1]));
	}
	return 0;
}