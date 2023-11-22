#include <bits/stdc++.h>
using namespace std;
int c,t;
int n,m;
int ans;
struct num{
	int zhengfu;
	int ans;
	char con;
}shu[114514];int a,b;
bool vis[114514];
void dfs(int point,int zhengfu)
{
	if(vis[point])
	{
		if(zhengfu==1) shu[point].con='T';
		else shu[point].con='U';
		return;
	}
	int to=shu[point].ans;
	if(to==point)
	{
		if(zhengfu==1) shu[point].con='T';
		else shu[point].con='U';
		return;
	}
	else
	{
		if(shu[to].con!='X')
		{
			if(shu[to].con=='U') shu[point].con='U';
			else shu[point].con='T';
		}
		else
		{
			vis[point]=true;
			dfs(to,shu[to].zhengfu);
			vis[point]=false;
			if(shu[to].con=='U') shu[point].con='U';
			else shu[point].con='T';
		}
		return;
	}
}
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int c,t;
	cin>>c>>t;
	char x;
	while(t--)
	{
		cin>>n>>m;
		ans=0;
		for(int i=1;i<=n;i++)
		{
			shu[i].zhengfu=1;
			shu[i].ans=i;
			shu[i].con='X';
		}
		for(int i=1;i<=m;i++)
		{
			cin>>x;
			if(x=='T'||x=='U'||x=='F')
			{
				cin>>a;
				shu[a].con=x;
			}
			else
			{
				if(x=='+')
				{
					cin>>a>>b;
					if(shu[b].con!='X') shu[a].con=shu[b].con;
					else
					{
						shu[a].con='X';
						shu[a].zhengfu=shu[b].zhengfu;
						shu[a].ans=shu[b].ans;
					}
				}
				else
				{
					cin>>a>>b;
					if(shu[b].con!='X')
					{
						if(shu[b].con=='T') shu[a].con='F';
						else if(shu[b].con=='F') shu[a].con='T';
						else shu[a].con='U';
					}
					else
					{
						shu[a].con='X';
						shu[a].zhengfu=-shu[b].zhengfu;
						shu[a].ans=shu[b].ans;
					}
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(shu[i].con!='X')
			{
				if(shu[i].con=='U')
				{
					ans++;
				}
			}
			else
			{
				dfs(i,shu[i].zhengfu);
				if(shu[i].con=='U')
				{
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
