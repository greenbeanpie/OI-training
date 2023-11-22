#include<bits/stdc++.h>
using namespace std;
const int N=2005;
int n,m,c,q,x[N],y[N],tmp[N];
int a[N],b[N],s,t;
bool dp[N][N];
bool g(){
	for(int i=0;i<=s;i++){
		for(int j=0;j<=t;j++)	dp[i][j]=0;
	}
	dp[0][0]=1;
	for(int i=1;i<=s;i++){
		for(int j=1;j<=t;j++){
			int maxn=-1;
			for(int k=j-1;k>=0;k--){
				maxn=max(maxn,b[k+1]);
				if(maxn>=a[i])	break;
				if(dp[i-1][k]){
					dp[i][j]=1;
					break;
				}
			}
			if(dp[i][j])	continue;
			int minn=INT_MAX/2;
			for(int k=i-1;k>=0;k--){
				minn=min(minn,a[k+1]);
				if(minn<=b[j])	break;
				if(dp[k][j-1]){
					dp[i][j]=1;
					break;
				}
			}
		}
	}
	return dp[s][t];
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	cin>>c>>n>>m>>q;
	for(int i=1;i<=n;i++)	scanf("%d",&x[i]);
	for(int i=1;i<=m;i++)	scanf("%d",&y[i]);
	s=n,t=m;
	for(int i=1;i<=n;i++)	a[i]=x[i];
	for(int i=1;i<=m;i++)	b[i]=y[i];
	if(g()){
		cout<<1;
	}
	else{
		for(int i=1;i<=n;i++)	tmp[i]=a[i];
		for(int i=1;i<=m;i++)	a[i]=b[i];
		for(int i=1;i<=n;i++)	b[i]=tmp[i];
		s=m,t=n;
		cout<<g();
	}
	while(q--){
		int k1,k2;
		scanf("%d%d",&k1,&k2);
		for(int i=1;i<=n;i++)	a[i]=x[i];
		for(int i=1;i<=m;i++)	b[i]=y[i];
		for(int i=1;i<=k1;i++){
			int p,v;
			scanf("%d%d",&p,&v);
			a[p]=v;
		}
		for(int i=1;i<=k2;i++){
			int p,v;
			scanf("%d%d",&p,&v);
			b[p]=v;
		}
		s=n,t=m;
		if(g()){
			cout<<1;
			continue;
		}
		for(int i=1;i<=n;i++)	tmp[i]=a[i];
		for(int i=1;i<=m;i++)	a[i]=b[i];
		for(int i=1;i<=n;i++)	b[i]=tmp[i];
		s=m,t=n;
		cout<<g();
	} 
	return 0;
}/*
3 3 3 1
8 6 9
1 7 4
1 0
3 0
所以f-g要么全大于0要么全小于0 
*/
