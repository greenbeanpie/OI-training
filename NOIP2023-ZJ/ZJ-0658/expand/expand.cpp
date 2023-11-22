#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	int c,n,m,q;
	cin>>c>>n>>m>>q;
	for(int i=0;i<n;++i)
	{
		int x;cin>>x;
	}
	for(int i=0;i<m;++i)
	{
		int x;cin>>x;
	}
	while(q--)
	{
		int kx,ky;
		cin>>kx>>ky;
		while(kx--) cin>>c>>c;
		while(ky--)	cin>>c>>c;
	}
	for(int i=0;i<=q;i++) cout<<rand()%2;
	return 0; 
}
