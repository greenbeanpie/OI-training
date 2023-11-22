#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1005;
const int maxm=1e5+5;
bool f1;
int cs,ans,t,p[maxn][maxn],sum[maxn][maxn],f[maxn][maxn],n,m,k,d;
bool f2;
struct node{
	int x,r,v;
}a[maxm];
signed main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	scanf("%lld%lld",&cs,&t);
	while(t--){
		if(cs<=9){
			scanf("%lld%lld%lld%lld",&n,&m,&k,&d);
			for(int i=1;i<=m;i++)
				scanf("%lld%lld%lld",&a[i].r,&a[i].x,&a[i].v);
			for(int i=1;i<=m;i++){
				p[a[i].r][a[i].x]+=a[i].v;
				
			}
			for(int i=1;i<=n;i++){
				sum[i][0]=p[i][0];
				for(int j=1;j<=i;j++){
					sum[i][j]=sum[i][j-1]+p[i][j];
				}
			}
			for(int i=0;i<=n;i++)
				for(int j=0;j<=n;j++)
					f[i][j]=-1e18;
			f[0][0]=0;
			for(int i=1;i<=n;i++){
				int top=min(i,k);
				f[i][0]=f[i-1][0]+sum[i][0];
				for(int j=1;j<=top;j++){
					f[i][j]=f[i-1][j-1]-d+sum[i][j];
					f[i][0]=max(f[i][0],f[i-1][j]);
//					if(t==9)cout<<p[i][j]<<endl;
//					if(f[i][j]>0&&t==9)cout<<f[i][j]<<" "<<i<<" "<<j<<endl;
				}
				
			}
			for(int i=0;i<=n;i++)ans=max(ans,f[n][i]);
			printf("%lld\n",ans);
			ans=0;
			for(int i=1;i<=n;i++)
				for(int j=0;j<=n;j++)
					p[i][j]=sum[i][j]=0;
		}		
	}
	return 0;
}
