#include<bits/stdc++.h>
using namespace std;
const int N=3005;
int n,m;
char w[N][N],ans[N];
int cnt[N][35];
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	if(n==1){
		cout<<1;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>w[i]+1;
		for(int j=1;j<=m;j++)
			cnt[i][w[i][j]-'a'+1]++;
		int pos=1;
		for(int j=1;j<=26;j++)
			while(cnt[i][j]>0){
				w[i][pos]=j+'a'-1;
				cnt[i][j]--;
				pos++;
			}
		for(int j=1;j<=m;j++)
			cnt[i][w[i][j]-'a'+1]++;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			int pos=0;
			for(int k=26;k>=1;k--){
				if(pos==n) break;
				if(!cnt[j][k]) continue;
				if(w[i][pos+1]<k+'a'-1)
					break;
				pos+=cnt[j][k];
				if(w[i][pos]>k+'a'-1){
					ans[i]='0';
					break;
				}
			}
			bool flag=1;
			for(int k=1;k<=26;k++)
				if(cnt[i][k]^cnt[j][k]){
					flag=0;
					break;
				}
			flag=(flag&&(w[i][1]==w[i][m]));
			if(flag||ans[i]=='0'){
				ans[i]='0';
				break;
			}
		}
		if(ans[i]!='0') ans[i]='1';
	}
	cout<<ans+1;
	return 0;
}