#include<stdio.h>
#include<bits/stdc++.h>
#define fir first
#define sec second
#define all(x) begin(x),end(x)
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
namespace __Clonoth__
{
template<typename type>
inline void chmin(type &x,const type &y)
{
	if(y<x)
		x=y;
}
template<typename type>
inline void chmax(type &x,const type &y)
{
	if(x<y)
		x=y;
}
constexpr int Max=2010;
int A[Max],B[Max],a[Max],b[Max];
int n,m,q;
int solve(int *a,int *b,int n,int m)
{
	static bool f[Max][Max];
	memset(f,false,sizeof(f));
	f[1][1]=true;
	cout<<"\n";
	for(int i=1;i<=n;cout<<"\n",++i)
		for(int j=1;j<=m;++j)
			cout<<(a[i]<b[j]);
	cout<<"\n";
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
		{
			if(!f[i][j])
				continue;
			if(i<n&&a[i+1]<b[j])
				f[i+1][j]=true;
			if(j<m&&a[i]<b[j+1])
				f[i][j+1]=true;
			if(i<n&&j<m&&a[i+1]<b[j+1])
				f[i+1][j+1]=true;
		}
	return f[n][m];
}
int solve()
{
	if(a[1]==b[1])
		return 0;
	if(a[1]<b[1])
		return solve(a,b,n,m);
	else
		return solve(b,a,m,n);
}
signed main()
{
	int tc;
	cin>>tc>>n>>m>>q;
	for(int i=1;i<=n;++i)
		cin>>A[i];
	for(int i=1;i<=m;++i)
		cin>>B[i];
	for(int i=1;i<=n;++i)
		a[i]=A[i];
	for(int i=1;i<=m;++i)
		b[i]=B[i];
	cout<<solve();
	while(q--)
	{
		for(int i=1;i<=n;++i)
			a[i]=A[i];
		for(int i=1;i<=m;++i)
			b[i]=B[i];
		int k1,k2,x,y;
		cin>>k1>>k2;
		while(k1--)
			cin>>x>>y,a[x]=y;
		while(k2--)
			cin>>x>>y,b[x]=y;
		cout<<solve();
	}
	cout<<"\n";
	return 0;
}
}
signed main()
{
	freopen("expand.in","r",stdin),freopen("expand.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	__Clonoth__::main();
	return 0;
}