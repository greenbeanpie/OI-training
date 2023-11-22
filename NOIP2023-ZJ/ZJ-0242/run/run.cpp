#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5,inf=0x3f3f3f3f3f3f3f3f;
int cas,T,n,m,k,d;
namespace K1{
	int f[1005][1005];
	struct kk{
		int y,v;
		bool operator<(const kk &x)const{
			return y<x.y;
		}
	};
	vector<kk> a[1005];
	void main(){
		while(T--){
			int ans=-inf;
			scanf("%lld%lld%lld%lld",&n,&m,&k,&d);
			for(int i=1;i<=n;i++){
				a[i].clear();
			}
			for(int i=1;i<=m;i++){
				int x,y,v;
				scanf("%lld%lld%lld",&x,&y,&v);
				a[x].push_back({y,v});
			}
			memset(f,-0x3f,sizeof f);
			f[0][0]=0;
			for(int i=1;i<=n;i++){
				for(int j=0;j<=k;j++){
					f[i][0]=max(f[i][0],f[i-1][j]);
					if(j>0)f[i][j]=max(f[i][j],f[i-1][j-1]-d);
				}
				sort(a[i].begin(),a[i].end());
				int sum=0;
				for(int j=0;j<a[i].size();j++){
					int y=a[i][j].y,v=a[i][j].v;
					sum+=v;
					for(int q=y;q<=k;q++){
						f[i][q]=max(f[i][q],f[i-1][q-1]-d+sum);
					}
				}
			}
			for(int i=0;i<=k;i++){
				ans=max(ans,f[n][i]);
			}
			printf("%lld\n",ans);
		}
		exit(0);
	}
}
namespace K2{
	int ans;
	void main(){
		while(T--){
			scanf("%lld%lld%lld%lld",&n,&m,&k,&d);
			ans=0;
			for(int i=1;i<=m;i++){
				int x,y,v;
				scanf("%lld%lld%lld",&x,&y,&v);
				ans+=max(0ll,v-y*d);
			}
			printf("%lld\n",ans);
		}
		exit(0);
	}
}
signed main(){
//	system("fc run3.ans run.out");
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	scanf("%lld%lld",&cas,&T);
	if(cas<=9)K1::main();
	if(17<=cas&&cas<=18)K2::main();
	
	return 0;
}