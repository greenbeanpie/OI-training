#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,T;
namespace Sub1{
	int n,m,k,d;
	int f[2][100010];
	struct tiaozhan{
		int x,y,v;
		friend inline bool operator <(tiaozhan _x,tiaozhan _y){
			return _x.x<_y.x;
		}
	}t[100010];
	signed work(){
		while(T--){
			scanf("%lld %lld %lld %lld ",&n,&m,&k,&d);
			for(int i=1;i<=m;++i)scanf("%lld %lld %lld ",&t[i].x,&t[i].y,&t[i].v);
			sort(t+1,t+m+1);
			for(int i=1,cnt=1;i<=n;++i){
				int I=i&1,L=I^1;
				for(int j=0;j<=k;++j)f[I][j]=LLONG_MIN;
				f[I][0]=f[L][0];
				for(int j=1;j<=k;++j){
					if(cnt<=m&&t[cnt].x==i&&t[cnt].y<=j)
					f[I][j]=max(f[I][j],f[L][j-1]-d+t[cnt].v);
					else f[I][j]=max(f[I][j],f[L][j-1]-d);
					f[I][0]=max(f[I][0],f[L][j]);
				}
				if(cnt<=m&&t[cnt].x==i)++cnt;
			}
			int ans=LLONG_MIN;
			for(int i=0;i<=k;++i)ans=max(ans,f[n&1][i]);
			printf("%lld\n",ans);
		}
		return 0;
	}
}
/*

*/
signed main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	scanf("%d %d ",&c,&T);
	if(c<=9)Sub1::work();
}