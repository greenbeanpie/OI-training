#include<bits/stdc++.h>
using namespace std;
int n,dp[1010],pre[1010],a[1010],cmp1[1010],cmp2[1010];
void readout(int x){
	if(x==-1) return;
	readout(pre[x]);
	printf("%d ",a[x]);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	memset(dp,0,sizeof(dp));
	memset(pre,-1,sizeof(pre));
	dp[1]=1;
	for(int i=2;i<=n;i++){
		for(int j=i-1;j>=1;j--)
			if(a[i]>a[j]){
				if(dp[j]+1>dp[i]) dp[i]=dp[j]+1,pre[i]=j;
			}
			if(dp[i]==0) dp[i]=1;
		}
	int maxx=1;
	for(int i=2;i<=n;i++){
		if(dp[i]>dp[maxx]) maxx=i;
		else if(dp[i]==dp[maxx]){
			memset(cmp1,0,sizeof(cmp1));
			memset(cmp2,0,sizeof(cmp2));
			int cnt=0,r=i;
			do{
				cmp1[++cnt]=r;
				r=pre[r];
			}while(r!=-1);
			r=maxx,cnt=0;
			do{
				cmp2[++cnt]=r;
				r=pre[r];
			}while(r!=-1);
			for(int j=cnt;j>=1;j--)
				if(a[cmp1[j]]<a[cmp2[j]]) maxx=i;
		}
    }
    readout(maxx);
}