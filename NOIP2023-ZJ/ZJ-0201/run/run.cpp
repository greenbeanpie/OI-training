#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1005,M=1e5+10;
int c,T,n,m,k,d,f[N][N];
struct nd{
	int x,y,v;
	bool operator<(const nd &a)const{
		if(x==a.x) return y<a.y;
		return x<a.x;
	}
}a[M];
signed main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>T;
	while(T--){
		memset(f,-63,sizeof(f));
		f[0][0]=0;
		cin>>n>>m>>k>>d;
		for(int i=1;i<=m;i++)
			cin>>a[i].x>>a[i].y>>a[i].v;
		sort(a+1,a+1+m);
		int pos=1;
		for(int i=1;i<=n;i++){
			f[i][0]=0;
			for(int j=0;j<=min(k,i-1);j++)
				f[i][0]=max(f[i][0],f[i-1][j]);
			int sm=0;
			while(i>a[pos].x&&pos<=m) pos++;
			for(int j=1;j<=min(k,i);j++){
				f[i][j]=f[i-1][j-1]-d;
				while(i==a[pos].x&&j>=a[pos].y&&pos<=m){
					sm+=a[pos].v;
					pos++;
				}
				f[i][j]+=sm;
			}
		}
		int ans=-1e18;
		for(int i=0;i<=min(k,n);i++)
			ans=max(ans,f[n][i]);
		cout<<ans<<"\n";
	}
	return 0;
}