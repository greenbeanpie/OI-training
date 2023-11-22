#include<bits/stdc++.h>
using namespace std;
int c,t;
int a[5005][5005];
int ma[5005];
bool s[5005];
char fan(char ch){
	if(ch=='T') return 1;
	else if(ch=='F') return 2;
	return 3;
}
int solve(int u){
	if(u==1) return 2;
	else if(u==2) return 1;
	return 3; 
}
int main() {
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,m;
		char c;
		cin>>n>>m;
		memset(s,0,sizeof(s));
		memset(ma,0,sizeof(ma));
		for(int i=1;i<=m;i++){
			cin>>c;
			int ii=0,jj=0;
			if(c=='T'||c=='U'||c=='F'){
				int x;
				cin>>x;
				ma[x]=fan(c);
				s[x]=1;
			}
			else if(c=='+'){
				cin>>ii>>jj;
				a[ii][jj]=a[jj][ii]=2; //---
				s[ii]=s[jj]=1;
			}
			else {
				a[ii][jj]=a[jj][ii]=1;//-->
				s[ii]=s[jj]=1;
			}
		}
		if(ma[1]==0) ma[1]=1;
		int kkk=ma[1];
		for(int i=1;i<=n;i++){
			if(ma[i]!=0) {
				for(int j=1;j<=n;j++){
					if(a[i][j]==2) ma[j]=ma[i];
					else if(a[i][j]==1) ma[j]=solve(ma[i]);
					else continue;
				}
			}
			
		}
		if(kkk!=ma[1]) {
			cout<<n<<"\n";
			continue;
		}
	}
	return 0;
}
