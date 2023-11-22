#include<bits/stdc++.h>
using namespace std;
void read()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
}
int c,n,m,k,d,t;
int main()
{
    read();
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>m>>k>>d;
		int ans=0;
		for(int i=1;i<=m;i++)
		{
			int x,y,v;
			cin>>x>>y>>v;
			if(y<=k&&x-y+1>0)
			{
				ans+=max(0,v-y*d);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

