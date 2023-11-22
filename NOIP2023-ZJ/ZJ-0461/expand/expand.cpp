#include<bits/stdc++.h>
using namespace std;
int c,n,m,q,x,y;
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	
	cin>>c>>n>>m>>q;
	if(c==1)
	{
		cin>>x>>y;
		if(x!=y)cout<<1;
		for(int i=1;i<=q;i++)
		{
			if(x!=y)cout<<1;
			
		}
	}
	return 0;
}
