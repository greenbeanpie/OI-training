#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[3005][3005];
bool f[3005];
bool pd(int x,int y){
	for(int i=1;i<=m;i++){
		if(a[x][i]>a[y][m-i+1]) return 0;
		if(a[x][i]<a[y][m-i+1]) return 1;
	}
	return 0;
}
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	if(n==1){cout<<1;return 0;}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
	    	char ch;cin>>ch;
			a[i][j]=ch-'a';	
		}
	}
	for(int i=1;i<=n;i++) sort(a[i]+1,a[i]+1+m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			if(!pd(i,j)){f[i]=1;break;}
		}
	}
	for(int i=1;i<=n;i++){
		if(f[i]) cout<<0;
		else cout<<1;
	}
	return 0;
}