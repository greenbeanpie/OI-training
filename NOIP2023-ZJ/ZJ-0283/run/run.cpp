#include<bits/stdc++.h>
#define N 1005
#define ll long long
using namespace std;
int n,C,T,m,lim,d;
ll f[N][N],mx[N];
struct node{
	int l,r,s;
}a[N];
inline ll read(){
	ll res=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9')f=ch=='-'?-1:f,ch=getchar();
	while(ch>='0'&&ch<='9')res=res*10+ch-'0',ch=getchar();
	return res*f;
}
inline bool cmp(node x,node y){
	if(x.l!=y.l)return x.l<y.l;return x.r<y.r;
}
inline void pre(){
	for(int i=1;i<=n;++i){
		mx[i]=-1e18;
		for(int j=0;j<=i;++j)f[i][j]=-1e18;
	}
}
signed main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	C=read(),T=read();
	a[0].r=-1;
	while(T--){
		m=read(),n=read(),lim=read(),d=read();
		for(int i=1;i<=n;++i)a[i].r=read(),a[i].l=a[i].r-read()+1,a[i].s=read();
		sort(a+1,a+n+1,cmp);
		pre();
		for(int i=1;i<=n;++i){
			if(a[i].r-a[i].l+1>lim)continue;
			for(int j=0;j<i;++j){
				if(a[i].l>a[j].r+1)f[i][i]=max(f[i][i],mx[j]-1ll*d*(a[i].r-a[i].l+1)+a[i].s);
				else{
					int th=0;
					for(int k=j;k>=0;--k){
						th=max(th,a[k].r);
						if(max(th,a[i].r)-a[k].l+1>lim)break;
						f[i][k]=max(f[i][k],f[j][k]-1ll*d*max(0,a[i].r-th)+a[i].s);
					}
				}
			}
			for(int j=0;j<=i;++j)mx[i]=max(mx[i],f[i][j]);
		}
		ll ans=0;
//		for(int i=1;i<=n;++i)printf("%lld ",mx[i]);puts("");
		for(int i=1;i<=n;++i)ans=max(ans,mx[i]);
		printf("%lld\n",ans);
	}
	return 0;
}