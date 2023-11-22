#include<bits/stdc++.h>
#define int long long
using namespace std;
int f[1005][10005],a[1005][10005],maxn[10005];
signed main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	int C,T;
	cin>>C>>T;
	while(T--){	
		memset(f,0,sizeof(f));
		memset(a,0,sizeof(a));
		memset(maxn,0,sizeof(maxn));
		int n,m,k,d;
		cin>>n>>m>>k>>d;
		while(m--){
			int x,y,v;
			cin>>x>>y>>v;
			for(int i=y;i<=k;i++){
				a[x][i]+=v;
			}
		}
		for(int i=1;i<=n;i++){
			f[i][0]=maxn[i-1];
			maxn[i]=f[i][0];
			for(int j=1;j<=min(i,k);j++){
				f[i][j]=f[i-1][j-1]+a[i][j]-d;
				maxn[i]=max(maxn[i],f[i][j]);
			}
		}
		cout<<maxn[n]<<endl;
	}
	return 0;
}