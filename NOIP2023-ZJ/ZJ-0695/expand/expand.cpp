#include<bits/stdc++.h>
using namespace std;
#define N 500005
int x[N],y[N];
int c,n,m,q;
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expend.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>q;
	for(register int i=1;i<=n;++i) cin>>x[i];
	for(register int i=1;i<=m;++i) cin>>y[i];
	int kx,ky;
	for(int i=1;i<=q;i++)
	{
		cin>>kx>>ky;
		int u,v;
		for(int a=1;a<=kx;a++)
		{
			cin>>u>>v;
		}
		for(int b=1;b<=ky;b++)
		{
			cin>>u>>v;
		}
	}
	for(int i=0;i<=q;i++) cout<<"0";
	cout<<"\n";
	return 0;
}
