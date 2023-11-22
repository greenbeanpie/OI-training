#include<bits/stdc++.h>
using namespace std;
int c;
struct node{
	int op,x,y;
};
namespace subtask1
{
	const int N=15;
	int t,now[N],pre[N],n,m;
	node g[N];
	int fan(int x)
	{
		if(x==1) return 0;
		if(x==0) return 1;
		else return 2;
	}
	bool check()
	{
		for(int i=1;i<=n;i++) pre[i]=now[i];
		for(int i=1;i<=m;i++)
		{
			if(g[i].op==1) now[g[i].x]=g[i].y;
			else if(g[i].op==2) now[g[i].x]=now[g[i].y];
			else now[g[i].x]=fan(now[g[i].y]);
		}
		int flag=1;
		for(int i=1;i<=n;i++)
		{
			if(now[i]!=pre[i])
			{
				flag=0;
				break;
			}
		}
		return flag;
	}
	void solve()
	{
		scanf("%d",&t);
		while(t--)
		{
			int ans;
			scanf("%d%d",&n,&m);
			ans=n;
			for(int i=1;i<=m;i++)
			{
				char s[5];
				scanf("%s",s);
				if(s[0]=='F'||s[0]=='T'||s[0]=='U')
				{
					int x,y;
					if(s[0]=='F') y=0;
					else if(s[0]=='T') y=1;
					else y=2;
					scanf("%d",&x);
					g[i]=(node){1,x,y};
				}
				else if(s[0]=='+')
				{
					int x,y;
					scanf("%d%d",&x,&y);
					g[i]=(node){2,x,y};
				}
				else
				{
					int x,y;
					scanf("%d%d",&x,&y);
					g[i]=(node){3,x,y};
				}
			}
			for(int i=0;i<(int)pow(3,n);i++)
			{
				int nowi=i,cnt=0;
				while(nowi)
				{
					now[++cnt]=nowi%3;
					nowi/=3;
				}
				if(check())
				{
					int res=0;
					for(int i=1;i<=n;i++)
					{
						res+=(now[i]==2);
					}
					ans=min(ans,res);
				}
			}
			printf("%d\n",ans);
		}
	}
}
namespace subtask2
{
	const int N=1e5+5;
	int t,m,n,last[N],vis[N];
	node g[N];
	void solve()
	{
		scanf("%d",&t);
		while(t--)
		{
			int ans=0;
			scanf("%d%d",&n,&m);
			memset(vis,0,sizeof(vis));
			memset(last,0,sizeof(last));
			for(int i=1,x;i<=m;i++)
			{
				char s[5];
				scanf("%s",s);
				scanf("%d",&x);
				if(s[0]=='T') g[i].op=1,g[i].x=x,g[i].y=1;
				else if(s[0]=='F') g[i].op=0,g[i].x=x,g[i].y=0;
				else g[i].op=2,g[i].x=x,g[i].y=2;
			}
			for(int i=m;i>=1;i--)
			{
				if(!vis[g[i].x]) last[g[i].x]=g[i].y,vis[g[i].x]=1;
			}
			for(int i=1;i<=n;i++) ans+=(last[i]==2);
			//for(int i=1;i<=n;i++) if(last[i]==2) printf("%d ",i);
			printf("%d\n",ans);
		}
	}
}
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	scanf("%d",&c);
	if(c==3||c==4) subtask2::solve();
	else subtask1::solve();
}
