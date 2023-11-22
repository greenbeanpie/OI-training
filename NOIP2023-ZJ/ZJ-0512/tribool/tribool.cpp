#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	int c,t;
	cin>>c>>t;
	
	
	//------------TFU,3-4-------------

		for(int k=1;k<=t;k++)
		{
			int ans=0,m,n;//n geshu  m yujutiaoshu
			cin>>n>>m;
			char final[100005];
			for(int i=1;i<=n;i++)
			{
				final[i]='0';
			}
			for(int i=1;i<=m;i++)
			{
				char typ;
				int pos;
				cin>>typ>>pos;
				final[pos]=typ;
			} 
			for(int i=1;i<=n;i++)
			{
				if(final[i]=='U')
				{
					ans++;
				}
			}
			cout<<ans<<endl;
		}	

	return 0;
}