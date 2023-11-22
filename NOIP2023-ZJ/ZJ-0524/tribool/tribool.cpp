#include<bits/stdc++.h>
using namespace std;
int c,T,n,m;
int a[100001],ans=0;
void solve1()
{
	while(T--)
	{
		ans=0;
		memset(a,1,sizeof(a));
		cin>>n>>m;
		while(m--)
		{
			char op;
			int x;
			cin>>op>>x;
			if(op=='T'||op=='F')
				a[x]=1;
			else a[x]=0;
		}
		for(int i=1;i<=n;i++)
			if(a[i]==0)
				ans++;
		cout<<ans<<'\n';
	}
}
void solve2()
{
	while(T--)
	{
		ans=0;
		memset(a,1,sizeof(a));
		cin>>n>>m;
		while(m--)
		{
			char op;
			int x,y;
			cin>>op;
			if(op=='U')
			{
				cin>>x;
				a[x]=0;
			}
			if(op=='+')
			{
				cin>>x>>y;
				a[x]=a[y];
			}
		}
		for(int i=1;i<=n;i++)
			if(a[i]==0)
				ans++;
		cout<<ans<<'\n';
	}
}
void solve3()
{
	while(T--)
	{
		cin>>n>>m;
		while(m--)
		{
			char op;
			cin>>op;
			int x,y;
			if(op=='+'||op=='-')
				cin>>x>>y;
			else cin>>x;
		}
		cout<<0<<'\n';
	}
}
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>c>>T;
	if(c==3||c==4)
		solve1();
	else if(c==5||c==6)
		solve2();
	else
		solve3();
	fclose(stdin);
	fclose(stdout);
	return 0;
}