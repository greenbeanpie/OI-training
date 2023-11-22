#include<bits/stdc++.h>
using namespace std;
char a[3001][3001],mi[3001],mx[3001];
int n,m;//a 0 
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin>>n>>m;
	memset(mi,'z',sizeof(mi));
	memset(mx,'a',sizeof(mx));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
			if (a[i][j]<mi[i]) mi[i]=a[i][j];
			if (a[i][j]>mx[i]) mx[i]=a[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		int flag=1;
		for(int j=1;j<=n;j++){
			if (i==j) continue;
			if (mx[j]>mi[i]) continue;
			else {
				flag=0;
				break;
			}
		}
		if (flag) cout<<'1';
		else cout<<'0';
	}
}