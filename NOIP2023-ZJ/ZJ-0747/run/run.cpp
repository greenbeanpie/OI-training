#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e5+5;
int dp[maxn],v[maxn],num[maxn],n,m,d,ans,sum,res,lst[maxn],k;
struct node{
	int l,r,val;
}g[maxn];
bool cmp(node a,node b){
	if(a.r==b.r) return a.l>b.l;
	return a.r<b.r;
}
bool check(int x){
	for(int i=1;i<=m;i++){
		dp[i]=-1e18,v[i]=1e18,num[i]=1e18,lst[i]=1e18;
	}
	dp[0]=v[0]=num[0]=0;
	for(int i=1;i<=m;i++){
		int val=0,cot=0;
		for(int j=0;j<i;j++){
			int tmp=g[i].r-g[i].l+1;
			if(g[i].l<=g[j].l) {
				val+=g[j].val;
				cot++;
				continue;
			}
			if(g[i].l>g[j].r){
				if(dp[i]<dp[j]-(g[i].r-g[i].l+1)*d-x+g[i].val){
					dp[i]=dp[j]-(g[i].r-g[i].l+1)*d-x+g[i].val;
					v[i]=max(v[j],tmp);
					lst[i]=tmp;
					num[i]=num[j]+1;
				}
				if(dp[i]==dp[j]-(g[i].r-g[i].l+1)*d-x+g[i].val){
					if(max(v[j],tmp)<v[i]){
						v[i]=max(v[j],tmp);
						lst[i]=tmp;
						num[i]=num[j]+1;
					}
					else if(max(v[j],tmp)==v[i]){
						if(num[i]<num[j]+1){
							num[i]=num[j]+1;
							lst[i]=tmp;
						}
						else if(num[i]==num[j]+1){
							lst[i]=min(lst[i],tmp);
						}
					}
				}
			}
			if(g[i].l<=g[j].r){
				val=0,cot=0;
				if(dp[i]<dp[j]-(g[i].r-g[j].r)*d-x+g[i].val){
					dp[i]=dp[j]-(g[i].r-g[j].r)*d-x+g[i].val;
					v[i]=max(lst[j]+(g[i].r-g[j].r),v[j]);
					lst[i]=lst[j]+(g[i].r-g[j].r);
					num[i]=num[j]+1;
				}
				if(dp[i]==dp[j]-(g[i].r-g[j].r)*d-x+g[i].val){
					if(v[i]>max(lst[j]+(g[i].r-g[j].r),v[j])){
						v[i]=max(lst[j]+(g[i].r-g[j].r),v[j]);
						lst[i]=lst[j]+(g[i].r-g[j].r);
						num[i]=num[j]+1;
					}
					else if(v[i]==v[j]+(g[i].r-g[j].r)){
						if(num[i]<num[j]+1){
							num[i]=num[j]+1,lst[i]=lst[j]+(g[i].r-g[j].r);
						}
						else if(num[i]==num[j]+1){
							lst[i]=min(lst[i],lst[j]+(g[i].r-g[j].r));
						}
					}
				}
			}
		}
		dp[i]+=val-x*cot,num[i]+=cot;
	}
	ans=-1e18,res=-1e18,sum=1e18;
	for(int i=1;i<=m;i++){
		if(dp[i]>ans){
			ans=dp[i];
			sum=v[i];
			res=num[i];
		}
		else if(dp[i]==ans){
			if(sum>v[i]){
				sum=v[i];
				res=num[i];
			}
			else if(sum==v[i]){
				res=max(res,num[i]);
			}
		}
	}
	return sum<=k;
}
void solve(){
	scanf("%lld%lld%lld%lld",&n,&m,&k,&d);
	for(int i=1,x,y	;i<=m;i++){
		scanf("%lld%lld%lld",&x,&y,&g[i].val);
		g[i].r=x,g[i].l=x-y+1;
	}
	sort(g+1,g+m+1,cmp);
	int l=0,r=6e9,Ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)){
			r=mid-1;
			Ans=mid;
		}
		else l=mid+1;
	}
	check(Ans);
	printf("%lld\n",max(ans+res*Ans,0ll));
}
int tid,T;
signed main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	scanf("%lld%lld",&tid,&T);
	while(T--){
		solve();
	}
	return 0;
}

