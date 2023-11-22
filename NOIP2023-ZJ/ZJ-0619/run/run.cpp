#include <bits/stdc++.h>
#define N 114514
#define int long long
using namespace std;
int n,le,ln,ans,mx,d,zy[N],k2[N],cnt,k1[N];
// dandiaoduilie youhuazhuanyi
inline int read(){
	int x=0,f=1;
	char g=getchar();
	while(!isdigit(g)){
		if(g=='-')f=-f;
		g=getchar();
	}
	while(isdigit(g)){
		x=(x<<3)+(x<<1)+(g^48);
		g=getchar();
	}
	return x*f;
}
struct xd{
	int ll,rr,va;
	int id;
}e[N];
long long dp[N][2],ks;
bool cmp(xd a,xd b){
	return a.rr<b.rr;
}
int fdr(int x){
	int l=0,r=n,mid,sum=0;
	while(l<r){
		mid=(l+r)>>1;
		if(e[mid].rr<x){
			sum=max(sum,mid);
			l=mid+1;
		}
		else r=mid-1;
	}
	return sum;
}
int fdl(int x,int ii){
	int l=0,r=n,mid,sum=ii;
	while(l<r){
		mid=(l+r)>>1;
		if(x-e[mid].ll<mx){
			sum=min(sum,mid);
			r=mid-1;
		}
		else l=mid+1;
	}
	return sum;
}
signed main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	int c,t;
	c=read(),t=read();
	e[0].rr=-1;
	while(t--){
		le=read(),n=read(),mx=read(),d=read();
		int xx,yy,vv;
		ln=0,ks=0;
		for(int i=1;i<=n;++i){
			xx=read(),yy=read(),vv=read();
			if(yy>mx)continue;
			e[++ln].rr=xx,e[ln].ll=xx-yy+1,e[ln].va=vv-yy*d;
		}
	//	printf("%d\n",ln);
		sort(e+1,e+ln+1,cmp);
		cnt=0;
		int zd,c2=0;
		for(int i=2;i<=ln;++i){k1[i]=fdr(e[i].ll);}
		for(int i=2;i<=ln;++i)k2[i]=fdl(e[i].rr,i);
		dp[1][1]=e[1].va,dp[1][0]=0;
		for(int i=2;i<=ln;++i){
			dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
			dp[i][1]=e[i].va;
			for(int j=1;j<k1[i];++j){
				dp[i][1]=max(dp[i][1],dp[j][0]+e[i].va);
				if(e[i].rr-e[j].ll>=mx&&e[j].rr>=e[i].ll)continue;
				dp[i][1]=max(dp[j][1]+e[i].va+max(0ll,e[j].rr+1-e[i].ll)*d,dp[i][1]);
			}
			for(int j=k2[i];j<i;++j){
				dp[i][1]=max(dp[i][1],dp[j][0]+e[i].va);
				if(e[i].rr-e[j].ll>=mx&&e[j].rr>=e[i].ll)continue;
				dp[i][1]=max(dp[j][1]+e[i].va+max(0ll,e[j].rr+1-e[i].ll)*d,dp[i][1]);
			}
			ks=max(ks,dp[i][0]);
			ks=max(ks,dp[i][1]);
		}
		printf("%lld\n",ks);
	}
	return 0;
}