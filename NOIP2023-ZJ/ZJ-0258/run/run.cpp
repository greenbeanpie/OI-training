#include<cstdio>
#include<iostream>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

#define ll long long
#define M 100005
int c,T,n,m,k,l[M],r[M];
ll d,sum[M],v[M];
void work1(){
	ll S=1<<n;
	ll cnt=0,ans=0,Ans=-1ll*n*d;
	for (ll U=0 ; U<S ; U++){
		bool flag=1;
		cnt=0,ans=0;
		for (int i=1 ; i<=n+2 ; i++) sum[i]=0;
		
		for (int i=1 ; i<=n ; i++){
			if (U&(1ll<<(i-1))){
			    sum[i]=sum[i-1]+1;
			    cnt++;
			}
		}
		int len=k;
		for (int i=1 ; i<=n-len ; i++)
		    if (sum[i+len]-sum[i-1]>len){
		    	flag=0;
		    	break;
			}
		if (!flag) continue;
		ans-=cnt*d;
		for (int i=1 ; i<=m ; i++){
			if (sum[r[i]]-sum[l[i]-1]==r[i]-l[i]+1) ans+=v[i];
		}
		Ans=max(Ans,ans);
	}
	printf("%lld\n",Ans);
}
void work2(){
	ll Ans=0;
	for (int i=1 ; i<=m ; i++){
		if (r[i]-l[i]+1>k) continue;
		ll tmp=v[i]-1ll*(r[i]-l[i]+1)*d;
		if (tmp>0) Ans+=tmp;
	}
	printf("%lld\n",Ans);
}
int main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	
	scanf("%d%d",&c,&T);
	while (T--){
		scanf("%d%d%d%lld",&n,&m,&k,&d);
		for (int i=1 ; i<=m ; i++){
			int x,y;
			scanf("%d%d%lld",&x,&y,&v[i]);
			l[i]=x-y+1,r[i]=x;
		}
		if (c==1 || c==2 || c==3 || c==4) work1();
		else if (c==17 || c==18) work2();
	}
	return 0;
}