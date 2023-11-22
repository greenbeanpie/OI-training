#include<bits/stdc++.h>
using namespace std;

const int N=2e3+5;

int c,n,m,t,a[N],b[N],p[N],q[N];
bool f[N][N];

inline bool check(void)
{
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)f[i][j]=0;
	if(p[1]>q[1]) 
	{
		f[1][1]=1;
		for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			if(p[i]>q[j]&&(f[i-1][j]||f[i][j-1]||f[i-1][j-1]))
				f[i][j]=1;
		}
	}
	if(p[1]<q[1]) 
	{
		f[1][1]=1;	
		for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			if(p[i]<q[j]&&(f[i-1][j]||f[i][j-1]||f[i-1][j-1]))
				f[i][j]=1;
		}
	}
	if(f[n][m]) return true;
	return false;
}

signed main()//35
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	cin>>c>>n>>m>>t;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=m;i++)cin>>b[i];
	
	for(int i=1;i<=n;i++)p[i]=a[i];
	for(int i=1;i<=m;i++)q[i]=b[i];
	cout<<check();
	
	while(t--)
	{
		int A,B,pos,val;cin>>A>>B;
		for(int i=1;i<=n;i++)p[i]=a[i];
		for(int i=1;i<=m;i++)q[i]=b[i];
		
		for(int i=1;i<=A;i++)
		{
			cin>>pos>>val;
			p[pos]=val;
		}
		for(int i=1;i<=B;i++)
		{
			cin>>pos>>val;
			q[pos]=val;
		}
		cout<<check();
	}
    return 0;
}
/*

*/
