#include<bits/stdc++.h>
using namespace std;
#define N 3005
int n,m;
char c[N];
int cnt[N][30],sum[N][30],ans[N];
bool check(int x){
	for(int i=1;i<=n;i++){
		if(i==x) continue;
		for(int j=0;j<26;j++){
			if(sum[x][j]){
				if(sum[i][j]>=m) return false; 
				break;
			}
		}
	}
	return true;
}
//freopen("dict1.in","r",stdout)
//freopen("dict4.out","r",stdin)
//freopen("dict2.out","w",stdin)
//freopen("dict3.in","w",stdout)
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>c+1;
		for(int j=1;j<=m;j++) cnt[i][c[j]-'a']++;
		sum[i][0]=cnt[i][0];
		for(int j=1;j<26;j++) sum[i][j]=sum[i][j-1]+cnt[i][j];
	}
	for(int i=1;i<=n;i++){
		ans[i]=check(i);
	}
	for(int i=1;i<=n;i++) cout<<ans[i];
	cout<<"\n";
	return 0;
}
/*
8:51 Huge example:ex4 AC -finish
8:52 freopen dict4.in  ji~~~~~~~
*/
