#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int c,n,m,q,_x[N],_y[N],x[N],y[N];
namespace K1{
	bool f[2005][2005],ans;
	void main(){
		ans=0;
		if(x[1]>y[1]){
			memset(f,0,sizeof f);
			f[1][1]=1;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=m;j++){
					if(j>1&&x[i]>y[j])f[i][j]|=f[i][j-1];
					if(i>1&&x[i]>y[j])f[i][j]|=f[i-1][j];
				}
			}
			ans|=f[n][m];
		}
		if(x[1]<y[1]){
			memset(f,0,sizeof f);
			f[1][1]=1;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=m;j++){
					if(j>1&&x[i]<y[j])f[i][j]|=f[i][j-1];
					if(i>1&&x[i]<y[j])f[i][j]|=f[i-1][j];
				}
			}
			ans|=f[n][m];
		}
		printf("%d",ans);
		return;
	}
}
namespace K2{
	unordered_map<int,int> mp;
	bool dfs(int i,int j,bool op){
		if(i==n&&j==m)return true;
		if(mp[(i-1)*m+j])return false;
		if(i<n&&((x[i+1]>y[j])==op)&&dfs(i+1,j,op))return true;
		if(j<m&&((x[i]>y[j+1])==op)&&dfs(i,j+1,op))return true;
		mp[(i-1)*m+j]=1;
		return false;
	}
	void main(){
		mp.clear();
		printf("%d",dfs(1,1,x[1]>y[1]));
		return;
	}
}
void solve(){
	if(n<=2000&&m<=2000)K1::main();
	else K2::main();
	return;
}
int main(){
//	system("fc expand4.ans expand.out");
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%d%d%d%d",&c,&n,&m,&q);
	for(int i=1;i<=n;i++){
		scanf("%d",&_x[i]);
		x[i]=_x[i];
	}
	for(int i=1;i<=m;i++){
		scanf("%d",&_y[i]);
		y[i]=_y[i];
	}
	solve();
	while(q--){
		int kx,ky;
		scanf("%d%d",&kx,&ky);
		for(int i=1;i<=n;i++){
			x[i]=_x[i];
		}
		for(int i=1;i<=m;i++){
			y[i]=_y[i];
		}
		for(int i=1;i<=kx;i++){
			int p,v;
			scanf("%d%d",&p,&v);
			x[p]=v;
		}
		for(int i=1;i<=ky;i++){
			int p,v;
			scanf("%d%d",&p,&v);
			y[p]=v;
		}
		solve();
	}
	return 0;
}