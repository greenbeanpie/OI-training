#include<bits/stdc++.h>
using namespace std;
char c[3051][3051];
string big[3051],small[3051];
int b[3051][27];
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>c[i][j];
			b[i][c[i][j]-'a'+1]++;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=26;j++)
		for(int k=1;k<=b[i][j];k++) small[i]+=char('a'+j-1);
		for(int j=26;j>=1;j--)
		for(int k=1;k<=b[i][j];k++) big[i]+=char('a'+j-1);	
	}
	for(int i=1;i<=n;i++){
		int flag=1;
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			if(big[j]<=small[i]){
				flag=0;
				break;
			}
		}
		cout<<flag;
	}
	return 0;
}
