#include<bits/stdc++.h>
using namespace std;
const int N=2e3+10;
int c,n,m,q;
int a[N],b[N];
bool f[N][N],g[N][N];
void init()
{
	memset(f,0,sizeof f);
	memset(g,0,sizeof g);
}
bool solve()
{
	init();
	f[1][1]=a[1]>b[1];
	g[1][1]=a[1]<b[1];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(f[1][1])
			{
				f[i][j]|=f[i-1][j] && a[i]>b[j];
				f[i][j]|=f[i][j-1] && a[i]>b[j];
			}
			if(g[1][1])
			{
				g[i][j]|=g[i-1][j] && a[i]<b[j];
				g[i][j]|=g[i][j-1] && a[i]<b[j];
			}
		}
	}
	return f[n][m] || g[n][m];
}
pair<int,int> mod[3][N];
signed main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>q;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++) cin>>b[i];
	
	
//	for(int i=1;i<=n;i++) cout<<a[i]<<' ';
//	cout<<endl;
//	for(int i=1;i<=m;i++) cout<<b[i]<<' ';
//	cout<<endl;
	cout<<solve() ? 1:0;
//	cout<<endl;
		
		
	while(q--)
	{
		int kx,ky;
		cin>>kx>>ky;
		for(int i=1;i<=kx;i++)
		{
			cin>>mod[0][i].first>>mod[0][i].second;
			swap(a[mod[0][i].first],mod[0][i].second);
		}	
		for(int i=1;i<=ky;i++)
		{
			cin>>mod[1][i].first>>mod[1][i].second;
			swap(b[mod[1][i].first],mod[1][i].second);
		}
		
		
//		for(int i=1;i<=n;i++) cout<<a[i]<<' ';
//		cout<<endl;
//		for(int i=1;i<=m;i++) cout<<b[i]<<' ';
//		cout<<endl;
		cout<<solve() ? 1:0;
//		cout<<endl;
		
		
		
		for(int i=1;i<=kx;i++)
			swap(a[mod[0][i].first],mod[0][i].second);
		for(int i=1;i<=ky;i++)
			swap(b[mod[1][i].first],mod[1][i].second);
	}
}