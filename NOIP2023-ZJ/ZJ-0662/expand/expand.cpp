#include <bits/stdc++.h>
const int N=3e5+5;
using namespace std;
int id,n,m,Q;
int a[N],b[N],c[N],d[N],f[2005][2005];
int kx,ky,x,y;
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>id>>n>>m>>Q;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=m;i++)cin>>b[i];
	f[1][1]=1;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	if((a[1]>b[1]&&a[i]>b[j])||(a[1]<b[1]&&a[i]<b[j]))
	{
		f[i][j]|=f[i-1][j-1];
		f[i][j]|=f[i-1][j];
		f[i][j]|=f[i][j-1];
	}
	cout<<f[n][m];
	while(Q--)
	{
		cin>>kx>>ky;
		for(int i=1;i<=n;i++)c[i]=a[i];
		for(int i=1;i<=m;i++)d[i]=b[i];
		for(int i=1;i<=kx;i++)cin>>x>>y,c[x]=y;
		for(int i=1;i<=ky;i++)cin>>x>>y,d[x]=y;
		memset(f,0,sizeof(f));
		f[1][1]=1;
		for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		if((c[1]>d[1]&&c[i]>d[j])||(c[1]<d[1]&&c[i]<d[j]))
		{
			f[i][j]|=f[i-1][j-1];
			f[i][j]|=f[i-1][j];
			f[i][j]|=f[i][j-1];
		}
		cout<<f[n][m];
	}
}
