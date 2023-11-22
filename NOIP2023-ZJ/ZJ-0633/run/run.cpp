#include<bits/stdc++.h>
#define ll long long
#define MAXN 100005
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
int C,T,n,m;
ll k,d,maxn;
ll eng2[25];
ll x[MAXN],y[MAXN],v[MAXN];
ll read(){
	ll x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x;
}
void dfs2(int step){
	if(step==n+1){
		ll sum=0,cnt=0,cost=0;
		rep(i,1,n){
			if(!eng2[i])cnt=0;
			else cnt++,cost+=d;
			if(cnt>k)
				return;
		}
		rep(i,1,m){
			int flag=0;
			rep(j,x[i]-y[i]+1,x[i]){
				if(!eng2[j]){
					flag=1;
					break;
				}
			}
			if(!flag)sum+=v[i];
		}
		maxn=max(maxn,sum-cost);
		return;
	}
	eng2[step]=0;
	dfs2(step+1);
	eng2[step]=1;
	dfs2(step+1);
}
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	scanf("%d%d",&C,&T);
		if(C<=2){
			while(T--){
				scanf("%d%d%lld%lld",&n,&m,&k,&d);
				rep(i,1,m)
					scanf("%lld%lld%lld",&x[i],&y[i],&v[i]);
				maxn=-1;
				dfs2(1);
				printf("%lld\n",maxn);	
			}
		}
		else{
			while(T--){
				scanf("%d%d%lld%lld",&n,&m,&k,&d);
				ll ans=0;
				rep(i,1,m){
					ll xx,yy,vv;
					xx=read(),yy=read(),vv=read();
//					scanf("%lld%lld%lld",&xx,&yy,&vv);
					if(yy<=k&&vv>d*yy)
						ans+=vv-d*yy;
				}
				printf("%lld\n",ans);	
			}
		}	
	return 0;
}


