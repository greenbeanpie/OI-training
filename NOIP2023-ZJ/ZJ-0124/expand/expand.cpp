#include<bits/stdc++.h>
using namespace std;
constexpr int N=2020;
int c,n,m,q,kx,ky,pos,val,x[N],y[N],a[N],b[N];
bool lt[N][N],gt[N][N];
inline bool calc()
{
	for(int i=0; i<=n; ++i)
		for(int j=0; j<=m; ++j)
			lt[i][j]=0,gt[i][j]=0;
	lt[1][1]=(a[1]<b[1]),gt[1][1]=(a[1]>b[1]);
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j)
		{
			if(i+j<3)
				continue;
			lt[i][j]=(lt[i-1][j-1]||lt[i-1][j]||lt[i][j-1])&&(a[i]<b[j]);
			gt[i][j]=(gt[i-1][j-1]||gt[i-1][j]||gt[i][j-1])&&(a[i]>b[j]);
		}
	return lt[n][m]||gt[n][m];
}
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>q;
	for(int i=1; i<=n; ++i)
		cin>>x[i],a[i]=x[i];
	for(int i=1; i<=m; ++i)
		cin>>y[i],b[i]=y[i];
	if(c<=7)
		cout<<calc();
	else
		if(c<=14)
			cout<<1;
		else
			cout<<0;
	while(q--)
	{
		for(int i=1; i<=n; ++i)
			a[i]=x[i];
		for(int i=1; i<=m; ++i)
			b[i]=y[i];
		cin>>kx>>ky;
		for(int i=1; i<=kx; ++i)
			cin>>pos>>val,a[pos]=val;
		for(int i=1; i<=ky; ++i)
			cin>>pos>>val,b[pos]=val;
		if(c<=7)
			cout<<calc();
		else
			if(c<=14)
				cout<<1;
			else
				cout<<0;
	}
	cout<<'\n';
	return 0;
}
