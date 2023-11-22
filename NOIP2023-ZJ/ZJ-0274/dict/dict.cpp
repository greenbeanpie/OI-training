#include<bits/stdc++.h>
using namespace std;
const int o=3e3+5;
char c[o][o],a[o][o],b[o][o],d[o][o];
int n,m,t[o];
bool qaq(char x[o],char y[o]){
	for (int i=1;i<=m;i++)
		if (x[i]>y[i]) return 0;
		else if (x[i]<y[i]) return 1;
	return 0;	
}
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	  cin>>(c[i]+1);
	for (int i=1;i<=m;i++)
	  b[0][i]='z'+1,d[n+1][i]='z'+1;
	for (int i=1;i<=n;i++){
	  sort(c[i]+1,c[i]+m+1);
	  for (int j=1;j<=m;j++)
	    a[i][j]=c[i][m-j+1],b[i][j]=b[i-1][j];
		if (qaq(a[i],b[i])){
			for (int j=1;j<=m;j++)
				b[i][j]=a[i][j];
		}
	}
	for (int i=n;i>=1;i--){
		for (int j=1;j<=m;j++)
			d[i][j]=d[i+1][j];
		if (qaq(a[i],d[i])){
			for (int j=1;j<=m;j++)
				d[i][j]=a[i][j];
		}
	}
	for (int i=1;i<=n;i++)
		if (qaq(c[i],b[i-1])&&qaq(c[i],d[i+1])) cout<<1;
														          else cout<<0;
	return 0;
}