#include<bits/stdc++.h>
using namespace std;
int n,m,c,t,a,b,ans;
char op;
void read()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
}
int main()
{
    read();
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>m;
		for(int i=1;i<=m;i++)
		{
			cin>>op;
			if(op>'Z'||op<'A')
			{
				cin>>a>>b;
			}
			else
			{
				cin>>a;
			}
			if(op=='U')
			{
				ans++;
			}
		}
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
}

