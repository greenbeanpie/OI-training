#include <bits/stdc++.h>

const int N=1e5+55;

struct A
{
	int fa,k;
}a[N];

int vis[N],ans[N];

std::set<int> s;

void dfs(int i)
{
	if(a[i].fa<0)
	{
		vis[i]=1;
		return;
	}
	if(s.find(a[i].fa)!=s.end()||a[i].fa==i)
	{
		int k=1;
		for(auto j=s.find(a[i].fa);j!=s.end();++j)k*=a[*j].k;
		a[i].fa=i;
		a[i].k*=k;
		vis[i]=1;
		return;
	}
	s.insert(i);
	if(!vis[a[i].fa])dfs(a[i].fa);
	dfs(a[i].fa);
	s.erase(i);
	if(a[a[i].fa].fa!=i)
	{
		a[i].k*=a[a[i].fa].k;
		a[i].fa=a[a[i].fa].fa;
	}
	vis[i]=1;
}

void cal(int i)
{
	if(a[i].fa<0)
	{
		if(a[i].fa==-1)ans[i]=1;
		if(a[i].fa==-2)ans[i]=-1;
		if(a[i].fa==-3)ans[i]=0;
		vis[i]=1;
		return;
	}
	if(a[i].fa==i)
	{
		ans[i]=(a[i].k==1);
		vis[i]=1;
		return;
	}
	if(!vis[a[i].fa])cal(a[i].fa);
	ans[i]=ans[a[i].fa]*a[i].k;
	vis[i]=1;
}

int main()
{
//	freopen("tribool.in","r",stdin);
//	freopen("tribool.out","w",stdout);
	
	int c,T;scanf("%d%d",&c,&T);
	while(T--)
	{
		int n,m;scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i)a[i].fa=i,a[i].k=1;
		for(int i=1;i<=m;++i)
		{
			char op[3];scanf("%s",op);
			if(op[0]=='+')
			{
				int x,y;scanf("%d%d",&x,&y);
//				a[x].fa=a[y].fa;
//				a[x].k=a[y].k;
				a[x].fa=y;
				a[x].k=1;
			}
			if(op[0]=='-')
			{
				int x,y;scanf("%d%d",&x,&y);
//				a[x].fa=a[y].fa;
//				a[x].k=-a[y].k;
				a[x].fa=y;
				a[x].k=-1;
			}
			if(op[0]=='T')
			{
				int x;scanf("%d",&x);a[x].fa=-1;
			}
			if(op[0]=='F')
			{
				int x;scanf("%d",&x);a[x].fa=-2;
			}
			if(op[0]=='U')
			{
				int x;scanf("%d",&x);a[x].fa=-3;
			}
		}
		for(int i=1;i<=n;++i)vis[i]=0;
		for(int i=1;i<=n;++i)
			if(!vis[i])
				dfs(i);
		for(int i=1;i<=n;++i)vis[i]=0;
		for(int i=1;i<=n;++i)ans[i]=9;
		for(int i=1;i<=n;++i)
			if(!vis[i])
				cal(i);
		int ret=0;
		for(int i=1;i<=n;++i)ret+=(!ans[i]);
//		for(int i=1;i<=n;++i)printf("%d%c",ans[i]," \n"[i==n]);
//		for(int i=1;i<=n;++i)printf("%d %d\n",a[i].fa,a[i].k);
		printf("%d\n",ret);
	}
	
	return 0;
}