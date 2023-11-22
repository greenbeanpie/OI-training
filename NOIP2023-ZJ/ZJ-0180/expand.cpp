#include<bits/stdc++.h>
#define F(i,l,r) for(int i=(l),i##end=(r);i<=i##end;++i)
using namespace std;
int _[10009],_1[10009];
int a[10009];
int b[10009];
int c,n,m,q;
bool f[2009][2009];
bool solve()
{
	F(i,1,n) f[i][0]=false;
	F(i,1,m) f[i][1]=false;
//	F(i,1,n)cout<<a[i]<<",\n"[i==n];
//	F(i,1,m)cout<<b[i]<<",\n"[i==m];
	f[0][0]=true;
	int k=a[1]>b[1];
	F(i,1,n)
	F(j,1,m)
	{
		if(a[i]==b[j])
		{
			f[i][j]=false;
			continue;
		}
		if((a[i]>b[j])==k)f[i][j]=(f[i][j-1]||f[i-1][j]||f[i-1][j-1]);
		else f[i][j]=false;
	}
	return f[n][m];
}
int p[10009],p1[10009];
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>c>>n>>m>>q;
	F(i,1,n) cin>>a[i],_[i]=a[i];
	F(i,1,m) cin>>b[i],_1[i]=b[i];
	cout<<solve();//cerr<<"````\n";
	F(CC,1,q)
	{
		int k,y,k1;
		cin>>k;cin>>k1;
		F(i,1,k) cin>>p[i]>>y,a[p[i]]=y;
		F(i,1,k1) cin>>p1[i]>>y,b[p1[i]]=y;
		cout<<solve();
		F(i,1,k) a[p[i]]=_[p[i]];
		F(i,1,k1) b[p1[i]]=_1[p1[i]];
	//	cerr<<"````\n";
	}
} 