#include<bits/stdc++.h>
using namespace std;
int n,m,a[26];
string str[3030],mx[3030],mn[3030],st[3030];
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>str[i];
	for(int i=1;i<=n;i++){
		st[i]="";
		mx[i]=str[i];
		mn[i]=str[i];
		for(int j=0;j<=25;j++) a[j]=0;
		for(int j=0;j<m;j++){
			a[str[i][j]-'a']++;
		}
		int cnt=0;
		for(int j=0;j<26;j++){
			for(int k=1;k<=a[j];k++) st[i]+=(j+'a');
		}
		
		for(int j=0;j<m;j++){
			if(mn[i][j]!=st[i][j]){
				char c=mn[i][j];
				for(int k=m-1;k>=0;k--){
					if(mn[i][k]==st[i][j]) {
						mn[i][j]=st[i][j];
						mn[i][k]=c;
						break;
					}
				}
				break;
			}
		}
		for(int j=0;j<m;j++){
			if(mx[i][j]!=st[i][m-j-1]){
				char c=mx[i][j];
				for(int k=m-1;k>=0;k--){
					if(mx[i][k]==st[i][m-j-1]) {
						mx[i][j]=st[i][m-j-1];
						mx[i][k]=c;
						break;
					}
				}
				break;
			}
		}	
	}
	//meow~
	for(int i=1;i<=n;i++){
		int ans=1;
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			if(mn[i]>=mx[j]){
				ans=0;
				break;
			}
		}
		cout<<ans;
	}
	return 0;
}