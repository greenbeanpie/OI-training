#include<bits/stdc++.h>
using namespace std;
string s[6010];
int px[6010];
vector<int>dp[140];
int cnt[140];
int vis[3010];
int ans[3010];
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>s[i];
//	cout<<1;
	for(int i=1;i<=n;i++){
		memset(cnt,0,sizeof(cnt));
		for(int j=0;j<m;j++)
			cnt[s[i][j]]++;
		int now=0;
		for(int j='z';j>='a';j--){
			while(cnt[j]){
				s[i][now++]=j;
				cnt[j]--;
			}
		}
		for(int j=0;j<m;j++)
			s[n+i].push_back(s[i][m-j-1]);
	}
//	for(int i=1;i<=2*n;i++)
//		cout<<s[i]<<endl;
	for(int i=1;i<=2*n;i++)
		px[i]=i;
	for(int i=m-1;i>=0;i--){
		for(int j=1;j<=2*n;j++)
			dp[s[px[j]][i]].push_back(px[j]);
		int cnt=2*n;
		for(int j='z';j>='a';j--){
			while(!dp[j].empty()){
				px[cnt--]=dp[j][dp[j].size()-1];
				dp[j].pop_back();
			}
		}
//		for(int i=1;i<=2*n;i++)
//			printf("%d ",px[i]);
//		printf("\n");
	}
	int flag=0;
	for(int i=2*n;i>=1;i--){
		if(px[i]<=n)
			vis[px[i]]=1,flag++;
		else{
			if(flag==n||(flag==n-1&&vis[px[i]-n]==0))
				ans[px[i]-n]=1;
		}
//		cout<<flag<<endl;
	}
	for(int i=1;i<=n;i++)
		printf("%d",ans[i]);
	return 0;
}