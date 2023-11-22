#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN=1e3+5,MAXM=1e5+5;
vector<pair<int,int> > G[MAXM];
ll f[MAXN][MAXN];
//f[i][j]->max(day i,lianxu j)
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	int c,T;
	scanf("%d %d",&c,&T);
	if (c<=9){
		while (T--){
			memset(f,-0x3f,sizeof(f));
			int n,m,k,d;
			scanf("%d %d %d %d",&n,&m,&k,&d);
			for(int i=1;i<=m;++i) G[i].clear();
			for(int i=1,x,y,v;i<=m;++i){
				scanf("%d %d %d",&x,&y,&v);
				G[x].push_back({y,v});
			}
			f[0][0]=0ll;
			for(int i=0;i<=n;++i){
				for(int j=0;j<=min(i,k);++j){
					f[i+1][0]=max(f[i+1][0],f[i][j]);
					if (j+1<=k){
						f[i+1][j+1]=f[i][j]-d;
						if (G[i+1].size()!=0){
							for(int l=0;l<G[i+1].size();++l){
								if (j+1>=G[i+1][l].first){
									f[i+1][j+1]+=G[i+1][l].second;
								}
							}
						}
					}
				}
			}
			ll ans=0;
			for(int i=0;i<=k;++i){
				ans=max(ans,f[n][i]);
			}
			printf("%lld\n",ans);
		}
	}
	else{
		while (T--){
			printf("0\n");
		}
	}
	return 0;
}