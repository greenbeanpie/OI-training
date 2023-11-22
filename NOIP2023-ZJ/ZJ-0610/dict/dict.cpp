#include<bits/stdc++.h>
using namespace std;
int n,m;
string s[4000];
string c[4000];
int check[4000][29];
int ans[4000];
int nowp=0;
string now;
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	now=s[1];
	if(n==1) cout<<"1";
	else if(m==1) {
		for(int i=1;i<=n;i++){
			if(s[i]<=now) {
				nowp=i;
				now=s[i];
			}
		}
		for(int i=1;i<=n;i++){
			if(s[i]==now) {
				if(i!=nowp) break;
				else ans[i]=1;
			}
		}
		for(int i=1;i<=n;i++){
			cout<<ans[i];
		}
	}else{
		for(int i=1;i<=n;i++){
			
			if(s[i]<=now) {
				now=s[i];
				nowp=i;	
			}
		}
		for(int i=1;i<=n;i++){
			if(s[i]==now) {
				if(i!=nowp) break;
				else ans[i]=1;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=0;j<s[i].size();j++){
				check[i][s[i][j]-'a']++;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=0;j<=25;j++){
				while(check[i][j]--){
					c[i]+=(j+'a');
				}
			}	
		}
		for(int i=1;i<=n;i++){
			if(c[i]<now) ans[i]=1;
		}
		for(int i=1;i<=n;i++){
			cout<<ans[i];
		}
	}
}  