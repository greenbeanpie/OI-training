#include<bits/stdc++.h>
using namespace std;
int n,m,x,a[3005];
string s[3050],mi[3050];
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		for(int j=0;j<m;j++){
			a[j]=s[i][j]-'a';
		}
		sort(a,a+m);
		for(int j=0;j<m;j++){
			mi[i]+=a[j]+'a';
		}
	}	
	x=1;
	for(int i=2;i<=n;i++){
		if(s[i]<s[x]){
			x=i;
		}
	}
	for(int i=1;i<=n;i++){
		if(mi[i]<=s[x]){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
}