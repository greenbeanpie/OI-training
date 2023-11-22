#include<iostream>
#include<cstdio>
#include<algorithm>
#define maxn 1005
#define ll long long
#define int long long
using namespace std;
int id,T,n,m,k; ll d,f[maxn][2]; struct chal{int l,r; ll val;}a[maxn];
bool cmp1(chal xx,chal yy){return xx.r<yy.r;}
bool cmp2(chal xx,chal yy){return xx.l<yy.l;}
signed main(){
	freopen("run.in","r",stdin); freopen("run.out","w",stdout);
	scanf("%lld%lld",&id,&T);
	if(id<=4){
		while(T--){
			scanf("%d%d%d%lld",&n,&m,&k,&d); for(int i=0;i<=n;i++) f[i][0]=f[i][1]=0;
			for(int i=1;i<=m;i++) scanf("%lld%lld%lld",&a[i].r,&a[i].l,&a[i].val),a[i].l=a[i].r-a[i].l+1;
			for(int i=1;i<=n;i++){
				f[i][0]=max(f[i][0],max(f[i-1][0],f[i-1][1]));
				for(int j=i;j>=max(i-k+1,1LL);j--){
					ll res=f[j-1][0];
					for(int p=1;p<=m;p++) if(j<=a[p].l&&i>=a[p].r) res+=a[p].val;
					f[i][1]=max(f[i][1],res-1LL*d*(i-j+1));
				}
			} printf("%lld\n",max(f[n][0],f[n][1]));
		} return 0;
	}else{
		while(T--){
			scanf("%d%d%d%lld",&n,&m,&k,&d); for(int i=0;i<=n;i++) f[i][0]=f[i][1]=0;
			for(int i=1;i<=m;i++) scanf("%lld%lld%lld",&a[i].r,&a[i].l,&a[i].val),a[i].l=a[i].r-a[i].l+1;
			sort(a+1,a+1+m,cmp1); int pos=0;
			for(int i=1;i<=n;i++){
				f[i][0]=max(f[i][0],max(f[i-1][0],f[i-1][1]));
				while(pos<m&&a[pos+1].r<=i) pos++; sort(a+1,a+1+pos,cmp2);
				ll res=0; for(int j=pos;j>=1&&a[j].l>=i-k+1;j--){
					res+=a[j].val;
					f[i][1]=max(f[i][1],f[a[j].l-1][0]+res-d*(i-a[j].l+1));
				}
			} printf("%lld\n",max(f[n][0],f[n][1]));
		} return 0;
	}
	return 0;
}
