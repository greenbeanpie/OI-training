#include <bits/stdc++.h>
using namespace std;


namespace Main{
	#define int long long
	const int mod=998244353,N=1e5+5;
	unsigned dp[N<<2];
	int main(){
		int n,x,y;
		cin >> n >> x >> y;
		dp[1]=1;
		signed sum=0;
		fill(dp,dp+2*N,1);
		dp[y]=0;
		for(int i=2;i<x;i++){
			for(int j=1;j<=i/2;j++){
				if(j==y || i-j==y || j>n || i-j>n){
					continue;
				}
				dp[i]+=dp[j];
				dp[i]%=mod;
			}
		}
		for(int i=(x+1)/2;i<=min(x,n);i++){
			sum+=dp[x-i];
			sum%=mod;
		}
		cout << sum << endl;
		return 0;
	} 
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("activity.in","r",stdin);
	freopen("activity.out","w",stdout);
	Main::main();
	return 0;
}

