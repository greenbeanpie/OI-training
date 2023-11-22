#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int team[N][5],q[15],qq[15],vis[N];
int n,m,ans=1e6;
void dfs20(int now)
{
	if (now==n)
	{
		for (int i = 1; i <= n; i++)
		  qq[i]=q[i];
		for (int i = 1; i <= m; i++)
		{
			if (team[i][0]==1)
				qq[team[i][1]]=qq[team[i][2]];
			if (team[i][0]==-1)
			{
				if (qq[team[i][2]]==0)
				  qq[team[i][1]]=0;
				else qq[team[i][1]]=5-qq[team[i][2]];
			}
			if (team[i][0]==0)
			  qq[team[i][1]]=0;
			if (team[i][0]==2)
			  qq[team[i][1]]=2;
			if (team[i][0]==3)
			  qq[team[i][1]]=3;
		}
		bool b=true;
		int cnt=0;
		for (int i = 1; i <= n; i++)
		{
			if (qq[i]!=q[i])
			{
				b=false;
				break;
			}
			if (qq[i]==0)
			  cnt++;
		}
		if (b && cnt<ans)
			ans=cnt;
		return;
	}
	q[now+1]=0;
	dfs20(now+1);
	q[now+1]=2;
	dfs20(now+1);
	q[now+1]=3;
	dfs20(now+1);
}
void pf20()
{
	scanf("%d%d",&n,&m);
	for (int i = 1; i <= m; i++)
	{
		char c = getchar();
		c=getchar();
		int x,y;
		if (c=='+' || c=='-')
		{
			team[i][0]=1;
			if (c=='-') team[i][0]=-1;
			scanf("%d%d",&x,&y);
			team[i][1]=x;
			team[i][2]=y;
		}
		if (c=='T')
		{
			scanf("%d",&x);
			team[i][0]=2;
			team[i][1]=x;
		}
		if (c=='F')
		{
			scanf("%d",&x);
			team[i][0]=3;
			team[i][1]=x;
		}
		if (c=='U')
		{
			scanf("%d",&x);
			team[i][0]=0;
			team[i][1]=x;
		}
	}
	dfs20(0);
}
void pf40()
{
	memset(vis,0,sizeof(vis));
	scanf("%d%d",&n,&m);
	for (int i = 1; i <= m; i++)
	{
		char c = getchar();
		c=getchar();
		int x,y;
		if (c=='T')  
		{
			scanf("%d",&x);
			vis[x]=0;
	    }
		if (c=='F')  
		{
			scanf("%d",&x);
			vis[x]=0;
		}
		if (c=='U')
		{
			scanf("%d",&x);
			vis[x]=1;
		}
	}
	int cnt=0;
	for (int i = 1; i <= n; i++)
	  cnt+=vis[i];
	printf("%d\n",cnt);
}
void pf60()
{
	memset(vis,0,sizeof(vis));
	scanf("%d%d",&n,&m);
	for (int i = 1; i <= m; i++)
	{
		char c = getchar();
		c=getchar();
		int x,y;
		if (c=='+') 
		{
			scanf("%d%d",&x,&y);
			team[i][0]=0;
			team[i][1]=x;
			team[i][2]=y;
			vis[x]=vis[y];
		}
		if (c=='U')
		{
			scanf("%d",&x);
			vis[x]=1;
			team[i][0]=1;
			team[i][1]=x;
		}
	}
	for (int i = 1; i <= m; i++)
	{
		if (team[i][0]==0)
		  vis[team[i][1]]=vis[team[i][2]];
		else
		  vis[team[i][1]]=1;
	}
	int cnt=0;
	for (int i = 1; i <= n; i++)
	  cnt+=vis[i];
	printf("%d\n",cnt);
}
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	int zl,T;
	cin>>zl>>T;
	if (zl<=2)
	{
		while (T--)
		{
		    ans=1e6;
			pf20();
			printf("%d\n",ans);
		}
		return 0;
	}
	if (zl<=4)
	{
		while (T--)
			pf40();
		return 0;
	}
	if (zl<=6)
	{
		while (T--)
		  pf60();
		return 0;
	}
	return 0;
}

