#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxn=500005;
ll c,n,m,q,a[maxn],b[maxn],f[maxn],fbmin[maxn][22],fbmax[maxn][22],lg2[maxn],tempa[maxn],tempb[maxn];
void init(ll m,ll *b){
	for(int i=1;i<=m;i++) fbmin[i][0]=fbmax[i][0]=b[i];
	for(int j=1;j<=20;j++)
		for(int i=1;i+(1<<j)-1<=m;i++)
			fbmin[i][j]=min(fbmin[i][j-1],fbmin[i+(1<<j-1)][j-1]),
			fbmax[i][j]=max(fbmax[i][j-1],fbmax[i+(1<<j-1)][j-1]);
}
ll querymin(ll x,ll y){
	ll len=lg2[y-x+1];
	return min(fbmin[x][len],fbmin[y-(1<<len)+1][len]);
}
ll querymax(ll x,ll y){
	ll len=lg2[y-x+1];
	return max(fbmax[x][len],fbmax[y-(1<<len)+1][len]);
}
bool solve1(ll n,ll m,ll *a,ll *b){
	if(a[1]==b[1]) return 0;
	if(a[1]<b[1]) return solve1(m,n,b,a);
	f[0]=1;
	for(int i=1;i<=n;i++){
		f[i]=f[i-1];
		while(f[i]<m&&a[i]>b[f[i]]) f[i]++;
		while(f[i]&&a[i]<=b[f[i]]) f[i]--;
		if(f[i]==0) return 0;
	}
	if(f[n]<m) return 0;
	return 1;
}
bool solve2(ll n,ll m,ll *a,ll *b){
	if(a[1]==b[1]) return 0;
	if(a[1]>b[1]){
		f[0]=1;
		for(int i=1;i<=n;i++){
			if(a[i]<=b[f[i-1]]){
				ll l=0,r=f[i-1];
				while(l<=r){
					ll mid=l+r>>1;
					if(querymin(mid,f[i-1])>=a[i]) f[i]=mid,r=mid-1;
					else l=mid+1;
				}
				f[i]--;
			}
			else{
				ll l=f[i-1],r=m;
				while(l<=r){
					ll mid=l+r>>1;
					if(querymax(l,mid)<a[i]) f[i]=mid,l=mid+1;
					else r=mid-1;
				}
			}
			if(f[i]==0) return 0;
		}
		if(f[n]<m) return 0;
		return 1;
	}
	else{
		f[0]=1;
		for(int i=1;i<=n;i++){
			if(a[i]>=b[f[i-1]]){
				ll l=1,r=f[i-1];
				while(l<=r){
					ll mid=l+r>>1;
					if(querymax(mid,f[i-1])<=a[i]) f[i]=mid,r=mid-1;
					else l=mid+1;
				}
				f[i]--;
			}
			else{
				ll l=f[i-1],r=m;
				while(l<=r){
					ll mid=l+r>>1;
					if(querymin(l,mid)>a[i]) f[i]=mid,l=mid+1;
					else r=mid-1;
				}
			}
			if(f[i]<=0) return 0;
		}
		if(f[n]<m) return 0;
		return 1;
	}

}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	srand(time(NULL));
	scanf("%lld%lld%lld%lld",&c,&n,&m,&q);
	lg2[0]=-1;
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=1;i<=m;i++) scanf("%lld",&b[i]),lg2[i]=lg2[i>>1]+1;
	if(c<=9||rand()%2==1) printf("%lld",solve1(n,m,a,b));
	else init(m,b),printf("%lld",solve2(n,m,a,b));
	for(ll T=0;T<q;T++){
		ll k1,k2;
		scanf("%lld%lld",&k1,&k2);
		for(int i=1;i<=n;i++) tempa[i]=a[i];
		for(int i=1;i<=m;i++) tempb[i]=b[i];
		for(int i=1;i<=k1;i++){
			ll x,val;
			scanf("%lld%lld",&x,&val);tempa[x]=val;
		}
		for(int i=1;i<=k2;i++){
			ll x,val;
			scanf("%lld%lld",&x,&val);tempb[x]=val;
		}
		if(c<=9||rand()%2==1) printf("%lld",solve1(n,m,tempa,tempb));
		else init(m,tempb),printf("%lld",solve2(n,m,tempa,tempb));
	}
	return 0;
}
