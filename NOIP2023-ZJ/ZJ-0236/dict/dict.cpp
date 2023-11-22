#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 0x7fffffff
int n,m,h;
char a[3005][3005],b[3005][3005];
string s;
char mn[3005];
int t[30];
signed main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s;
		for(int j=0;j<m;j++){
			t[s[j]-97]++;
		}
		int p=0;
		for(int j=0;j<26;j++){
			for(int k=1;k<=t[j];k++){
				char c=j+97;
				a[i][++p]=c;
			}
		}
		p=0;
		for(int j=25;j>=0;j--){
			for(int k=1;k<=t[j];k++){
				char c=j+97;
				b[i][++p]=c;
			}
		}
		for(int j=0;j<26;j++) t[j]=0;
	}
	for(int i=1;i<=m;i++){
		mn[i]='z';
	}
	for(int i=1;i<=n;i++){
		int k=1;
		while(b[i][k]==mn[k]&&k<=m){
			k++;
		}
		if(b[i][k]<mn[k]){
			h=i;
			for(int j=k;j<=m;j++){
				mn[j]=b[i][j];
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(i==h){
			cout<<1;
			continue;
		}
		int k=1;
		while(a[i][k]==mn[k]&&k<=m){
			k++;
		}
		if(a[i][k]<mn[k]){
			cout<<1;
		}else{
			cout<<0;
		}
	}
	cout<<"\n";
    return 0;
}