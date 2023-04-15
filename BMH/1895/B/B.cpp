#include <bits/stdc++.h>
using namespace std;
struct node{
	int w1,w2;
	int v1,v2;
}a[201];
int dp[10001];
int ans;
int main()
{
	int v,n,k;
	cin>>v>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i].v1>>a[i].w1>>a[i].v2>>a[i].w2;
	}
	for(int i=1;i<=n;i++){
		for(int j=v;j>=1;j--)
		{
			if(a[i].w1<=j)
			{
				dp[j]=max(dp[j],dp[j-a[i].w1]+a[i].v1);
				
			}
			if(a[i].w2<=j){
				dp[j]=max(dp[j],dp[j-a[i].w2]+a[i].v2);
				
			}
		}
		
	}
	for(int i=1;i<=v;i++){
		ans=max(ans,dp[i]);
	}
	cout<<ans+k<<endl;
	return 0;
}

