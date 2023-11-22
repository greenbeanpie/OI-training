#include<bits/stdc++.h>
using namespace std;
int c,t,m,n;
char x[100005];
int p[100005];
int ans;
int find(int n)
{
	if(p[n]==n)
	{
		return n;
	}
	else
	{
		return find(p[n]);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	cin>>c>>t;
	while(t)
	{
		t--;
		cin>>n>>m;
		for(int i=1;i<=m;i++)
		{
			char v;
			int a,b;
			cin>>v;
			if(v!='-' and v!='+')
			{
				cin>>a;
				x[a]=v;
				x[find(a)]=v;
			}
			if(v=='+')
			{
				cin>>a>>b;
				if(p[b]!=0)
				p[a]=b;
				else if(p[a]!=0)
				p[b]=a;
				else
				{
					p[a]=b;
					p[b]=b;
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(x[i]=='U')
			ans++;
			else
			{
				if(x[find(i)]=='U')
				ans++;
			}
			x[i]='0';
		}
		cout<<ans<<endl;
		ans=0;
	}	return 0;
}
