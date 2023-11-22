#include<bits/stdc++.h>
using namespace std;
int n,m;
char tmp;
char c[3030][30];
int reg[3030],rev[3030];
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin>>n>>m;
	if(n==1) cout<<1;
	else{
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>tmp;
				c[i][tmp-'a'+1]++;
			}
			for(int k=1;k<=26;k++)
				if(c[i][k]){
					reg[i]=k;
					break;
				}
			for(int k=26;k>=1;k--)
				if(c[i][k]){
					rev[i]=k;
					break;
				}
		}
		int flag;
		for(int i=1;i<=n;i++){
			flag=1;
			for(int j=1;j<=n;j++){
				if(j==i) continue;
				if(reg[i]>=rev[j]){
					flag=0;break;
				}
			}
			cout<<flag;
		}
	}
	return 0;
}
