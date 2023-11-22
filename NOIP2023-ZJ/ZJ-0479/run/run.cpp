#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int c,t,n,m,k,d;
int a[N],b[N],v[N];
struct subtask1{
	int sum[25];
	bool check(){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(sum[i]==1) cnt++;
			else cnt=0;
			if(cnt>k) return false;
		}
		return true;
	}
	void work(){
		while(t--){
			scanf("%d%d%d%d",&n,&m,&k,&d);
			for(int i=1;i<=m;i++)
				scanf("%d%d%d",&a[i],&b[i],&v[i]);
			long long ans=0;
			for(int i=0;i<(1<<n);i++){
				long long res=0;
				memset(sum,0,sizeof(sum));
				for(int j=1;j<=n;j++) sum[n-j+1]=(bool)(i&(1<<(j-1)));
				if(!check()) continue;
				for(int j=1;j<=n;j++) sum[j]+=sum[j-1];
				for(int j=1;j<=m;j++){
					if(sum[a[j]]-sum[a[j]-b[j]]==b[j]) res+=(long long)v[j];
				}
				ans=max(ans,res-(long long)sum[n]*d);
			}
			printf("%lld\n",ans);
		}
	}
}S1;
struct subtask2{
	void work(){
		while(t--){
			scanf("%d%d%d%d",&n,&m,&k,&d);
			long long ans=0;
			for(int i=1;i<=m;i++) scanf("%d%d%d",&a[i],&b[i],&v[i]);
			for(int i=1;i<=m;i++) if(b[i]<=k) ans+=max((long long)(v[i]-(long long)b[i]*d),(long long)(0));
			printf("%lld\n",ans);
		}
	}
}S2;
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	scanf("%d%d",&c,&t);
	if(c==1||c==2) S1.work();
	if(c==17||c==18) S2.work();
	return 0;
}
