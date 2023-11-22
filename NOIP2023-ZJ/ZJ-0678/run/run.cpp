#include<bits/stdc++.h>
using namespace std;
int c,t;
int a[5005][5005];
int f[500005];
int main() {
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	cin>>c>>t;
	while(t--) {
		int n=0,m=0,k=0,d=0;
		cin>>n>>m>>k>>d;
		int cnt=0;
		memset(a,0,sizeof(a));
		memset(f,0,sizeof(f));
		for(int i=1; i<=m; i++) {
			int x=0,y=0,v=0;
			cin>>x>>y>>v;
			if(x-y+1>k) continue;
			else {
				a[x-y+1][x]=v;
			}
		}
		for(int i=1; i<=n-k+1; i++) {
			for(int j=i; j<=i+k-1; j++) {
				a[i][i+k-1]+=a[i][j];
			}
			a[i][k]-=k*d;
			if(a[i][k]<0) a[i][k]=0;
		}
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j+=k+1) {
				f[i]+=a[j][j+k-1];
			}
		}
		int ans=-1;
		for(int i=1;i<=n;i++) ans=max(ans,f[i]);
		cout<<ans<<"\n";
	}

	return 0;
}
