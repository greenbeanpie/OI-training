#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,t,n,m,k,d,ans;
ll b[100010];
struct wht{
	ll l,r;
	ll val;
}a[100010];
bool cmp(wht x,wht y){
	if(x.l==y.l)
	return x.r<y.r;
	return x.l<y.l;
}
void dfs(ll x){
	if(x==n+1){
		ll sum=0;
		for(int i=1;i<=m;i++){
			ll t5=0;
			if(a[i].val>0){
				for(int j=a[i].l;j<=a[i].r;j++){
					if(b[j]==0){
						t5=1;
						break;
					}
				}
				if(t5==0)
				sum+=a[i].val;
			}
		}
		ans=max(ans,sum);
	}
	int cann=0;
	for(int i=x-k+1;i<x;i++){
		if(b[i]==0){
			cann=1;
			break;
		}
	}
	if(cann==1){
		b[x]=1;
		dfs(x+1);
		b[x]=0;
	}
	dfs(x+1);
	return ;
}
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	ll tot=0;
	while(t--){
		scanf("%lld%lld%lld%lld",&n,&m,&k,&d);
		for(int i=1;i<=tot;i++)
		a[i].l=0,a[i].r=0,a[i].val=0;
		tot=0;
		ans=0;
		for(int i=1;i<=m;i++){
			ll L,R,redu;
			cin>>L>>R>>redu;
			a[++tot].l=L;
			a[tot].r=L-R+1;
			a[tot].val=redu-(R*d);
		}
		sort(a+1,a+1+m,cmp);
		if(c==1||c==2){
			memset(b,0,sizeof(b));
			ans=0;
			dfs(1);
			cout<<ans<<endl;
		}
		if(c==17||c==18){
			ll t=0;
			a[0].r=-1;
			a[tot+1].l=10e9;
			for(int i=1;i<=tot;i++){
				t+=a[i].r-a[i].l+1;
				if(a[i].l>a[i-1].r-1&&a[i].r<a[i+1].l-1&&a[i].val>0)
				ans+=a[i].val;
				if(a[i].l==a[i-1].r+1&&a[i].val>0&&a[i-1].val>0){
					if(a[i].r-a[i].l+1+t<=k)
					ans+=a[i].val;
				}
				else
				t=0;
			}
			cout<<ans<<endl;
		}
		else{
			for(int i=1;i<=tot;i++){
				if(a[i].val>0)
				ans+=a[i].val;
			}
			cout<<ans<<endl;
		}
	}
}
