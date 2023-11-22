#include<bits/stdc++.h>
using namespace std;
char c[3010][3010],a1[3010][3010],s[3010];
int n,m;
int main() {
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>c[i]+1;
		for(int j=1; j<=m; j++)s[j]=c[i][j];
		sort(s+1,s+m+1);
		for(int j=1; j<=m; j++)a1[i][j]=s[j],c[i][m-j+1]=s[j];
	}
	for(int i=1; i<=n; i++) {
		int ff=0;
		for(int j=1; j<=n; j++) {
			if(i==j)continue;
			int fff=0;
			for(int k=1; k<=m; k++) {
				if(a1[i][k]>c[j][k]) {
					fff=1;
					break;
				}
				if(a1[i][k]<c[j][k]) {
					fff=0;
					break;
				}
				if(a1[i][k]==c[j][k]&&k==m) {
					fff=1;
					break;
				}
			}
			if(fff==1){
			ff=1;
			break;
			}
		}
		if(ff==0)cout<<1;
		else cout<<0;
	}
	return 0;
}
