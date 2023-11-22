#include<bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=5e5+5;
int task,n,m,q,a[N],b[N],c[N],d[N];
int kx,ky;
int dp[2][N];
inline void init(){
	for(int i=1;i<=n;i++)c[i]=a[i];
	for(int i=1;i<=m;i++)d[i]=b[i];
}
inline int solve(){
	if(c[1]==d[1])return 0;
	vector<int>C,D;
	C.pb(c[1]),D.pb(d[1]);
	bool f=(c[2]>=c[1]);
	for(int i=2;i<=n;i++){
		if(c[i]>=c[i-1]){
			if(f==0)C.pb(c[i-1]),f=1;
		}else{
			if(f==1)C.pb(c[i-1]),f=0;
		}
	}
	C.pb(c[n]);
	f=(d[2]>=d[1]);
	for(int i=2;i<=m;i++){
		if(d[i]>=d[i-1]){
			if(f==0)D.pb(d[i-1]),f=1;
		}else{
			if(f==1)D.pb(d[i-1]),f=0;
		}
	}
	D.pb(d[m]);
	for(int i=0;i<=(int)D.size();i++)dp[0][i]=dp[1][i]=0;
	if(c[1]>d[1]){
		for(int i=1;i<=(int)C.size();i++){
			for(int j=1;j<=(int)D.size();j++){
				if(C[i-1]>D[j-1]){
					dp[i%2][j]=dp[(i+1)%2][j-1]|dp[i%2][j-1]|dp[(i+1)%2][j];
					if(i==1&&j==1){
						dp[i%2][j]=1;
					}
				}else{
					dp[i%2][j]=0;
				}
			}
		}
	}else{
		for(int i=1;i<=(int)C.size();i++){
			for(int j=1;j<=(int)D.size();j++){
				if(C[i-1]<D[j-1]){
					dp[i%2][j]=dp[(i+1)%2][j-1]|dp[i%2][j-1]|dp[(i+1)%2][j];
					if(i==1&&j==1){
						dp[i%2][j]=1;
					}
				}else{
					dp[i%2][j]=0;
				}
			}
		}
	}
	return dp[(int)C.size()%2][(int)D.size()];
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%d%d%d%d",&task,&n,&m,&q);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=m;i++){
		scanf("%d",&b[i]);
	}
	init();
	printf("%d",solve());
	while(q--){
		scanf("%d%d",&kx,&ky);
		init();
		for(int i=1,p,v;i<=kx;i++){
			scanf("%d%d",&p,&v);
			c[p]=v;
		}
		for(int i=1,p,v;i<=ky;i++){
			scanf("%d%d",&p,&v);
			d[p]=v;
		}
		printf("%d",solve());
	}
	puts("");
	return 0;
}