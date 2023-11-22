#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{int l,r,w;}a[100005];
int n,m,k,d,C,T,f[105][105];
bool cmp(node x,node y){return x.r<y.r;}
namespace T41{
	void solve(){
		scanf("%lld%lld%lld%lld",&n,&m,&k,&d);
		for(int i=1,x,y;i<=m;i++){
			scanf("%lld%lld%lld",&x,&y,&a[i].w);
			a[i].l=x-y+1;a[i].r=x;
			a[i].w-=d*y;
		}
		int ans=0;
		for(int i=1;i<=m;i++){
			if(a[i].r-a[i].l+1>k) continue;
			if(a[i].w<=0) continue;
			ans+=a[i].w;
		}
		printf("%lld\n",ans);
	}
}
signed main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	scanf("%lld%lld",&C,&T);
	if(C<=4){
		while(T--){
			scanf("%lld%lld%lld%lld",&n,&m,&k,&d);
			for(int i=1,x,y;i<=m;i++){
				scanf("%lld%lld%lld",&x,&y,&a[i].w);
				a[i].l=x-y+1;a[i].r=x;
			}
			// sort(a+1,a+m+1,cmp);
			int ans=-1e18;
			for(int i=1;i<=n;i++){
				for(int j=max(1ll,i-k+1);j<=i;j++){
					int cnt=-d*(i-j+1);
					for(int t=1;t<=m;t++)
						if(j<=a[t].l&&a[t].r<=i) cnt+=a[t].w;
					f[j][i]=max(f[j][i],cnt);
				}
			}
			for(int len=k+1;len<=n;len++){
				for(int l=1;l+len-1<=n;l++){
					int r=l+len-1;
					for(int i=l-1;i<=r;i++)
						for(int j=i+2;j<=r+1;j++)
							f[l][r]=max(f[l][i]+f[j][r],f[l][r]);
				}
			}
			printf("%lld\n",f[1][n]);
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++) f[i][j]=0;
		}
		return 0;
	}
	if(C==17||C==18){
		while(T--)T41::solve();
		return 0;
	}
	return 0;
}