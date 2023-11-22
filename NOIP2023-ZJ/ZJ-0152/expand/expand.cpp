#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010],b[500010],c[500010],d[500010];
bool f[2010][2010];
bool sol()
{
	int i,j;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)f[i][j]=0;
	
	if(c[1]<d[1]){
		f[1][1]=1;
		for(i=1;i<=n;i++)
			for(j=1;j<=m;j++)
				if(c[i]<d[j]&&(i!=1||j!=1))f[i][j]=f[i-1][j]|f[i][j-1]|f[i-1][j-1];
	}
	else if(c[1]>d[1]){
		f[1][1]=1;
		for(i=1;i<=n;i++)
			for(j=1;j<=m;j++)
				if(c[i]>d[j]&&(i!=1||j!=1))f[i][j]=f[i-1][j]|f[i][j-1]|f[i-1][j-1];
	}
	return f[n][m];
}
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	int hornex,t,i;
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);   
	cin>>hornex>>n>>m>>t;
	for(i=1;i<=n;i++)cin>>a[i],c[i]=a[i];
	for(i=1;i<=m;i++)cin>>b[i],d[i]=b[i];
	cout<<sol(); 
	while(t--){
		int x,y;
		cin>>x>>y;
		for(i=1;i<=n;i++)c[i]=a[i];
		for(i=1;i<=m;i++)d[i]=b[i];
		while(x--){
			int p,w;
			cin>>p>>w;
			c[p]=w;
		}
		while(y--){
			int p,w;
			cin>>p>>w;
			d[p]=w;
		}
		cout<<sol();
	}
}
/*
I want Mythic
I killed 107M11U,then only get 4M
*/