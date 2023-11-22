#include<bits/stdc++.h>
using namespace std;
int c,t,n,m;
int op[100010],x[100010],y[100010];
int Get()
{
	char ch=getchar();
	while(ch!='T'&&ch!='F'&&ch!='U'&&ch!='+'&&ch!='-')
		ch=getchar();
	switch(ch)
	{
		case 'T':return 0;
		case 'U':return 1;
		case 'F':return 2;
		case '+':return 3;
		case '-':return 4;
	}
}
namespace solve1
{
	int a[100010];
	int b[100010];
	void Main()
	{
		int ans=n+1;
		int tot=1;
		for(int i=1;i<=n;++i)
			tot*=3;
		for(int st=0;st<tot;++st)
		{
			for(int i=1,pw=1;i<=n;++i,pw*=3)
				a[i]=b[i]=st/pw%3;
			for(int i=1;i<=m;++i)
				switch(op[i])
				{
					case 0:case 1:case 2:a[x[i]]=op[i];break;
					case 3:a[x[i]]=a[y[i]];break;
					case 4:a[x[i]]=2-a[y[i]];break;
				}
			bool flag=1;
			for(int i=1;i<=n;++i)
				flag&=(a[i]==b[i]);
			if(!flag)
				continue;
			int res=0;
			for(int i=1;i<=n;++i)
				res+=(a[i]==1);
			ans=min(ans,res);
		}
		printf("%d\n",ans);
		return;
	}
}
namespace solve2
{
	int a[100010];
	void Main()
	{
		for(int i=1;i<=n;++i)
			a[i]=-1;
		for(int i=1;i<=m;++i)
			a[x[i]]=op[i];
		int res=0;
		for(int i=1;i<=n;++i)
			res+=(a[i]==1);
		printf("%d\n",res);
		return;
	}
}
namespace solve3
{
	int a[100010];
	bool vis[100010];
	vector<int>e[100010];
	void dfs(int x)
	{
		if(vis[x])
			return;
		vis[x]=1;
		for(int y:e[x])
			dfs(y);
		return;
	}
	void Main()
	{
		for(int i=0;i<=n;++i)
		{
			a[i]=i;
			vis[i]=0;
			e[i].clear();
		}
		for(int i=1;i<=m;++i)
			if(op[i]==1)
				a[x[i]]=0;
			else
				a[x[i]]=a[y[i]];
		for(int i=1;i<=n;++i)
		{
			e[i].push_back(a[i]);
			e[a[i]].push_back(i);
		}
		dfs(0);
		int res=0;
		for(int i=1;i<=n;++i)
			res+=vis[i];
		printf("%d\n",res);
		return;
	}
}
namespace solve4
{
	int tot,color,cnt;
	int a[200010];
	int sz[200010];
	int col[200010];
	int vis[200010];
	int book[200010];
	bool tag[200010];
	vector<int>e[200010];
	vector<int>mp[200010];
	void dfs(int x,int c)
	{
		if(col[x])
			return;
		++sz[c];
		col[x]=c;
		for(int y:e[x])
			dfs(y,c);
		return;
	}
	void Dfs(int x,int c)
	{
		if(vis[x])
			return;
		vis[x]=c;
		cnt+=sz[x];
		for(int y:mp[x])
			Dfs(y,c);
		return;
	}
	bool check(int x,int c)
	{
		if(tag[x])
			return false;
		if(!book[x])
			return (book[x]==c);
		book[x]=c;
		bool flag=1;
		for(int y:mp[x])
			flag&=check(y,3-c);
		return flag;
	}
	void Main()
	{
		tot=color=0;
		for(int i=1;i<=n*2;++i)
		{
			a[i]=i;
			sz[i]=0;
			col[i]=0;
			vis[i]=0;
			tag[i]=0;
			book[i]=0;
			e[i].clear();
			mp[i].clear();
		}
		for(int i=1;i<=m;++i)
			if(op[i]==3)
				a[x[i]]=a[y[i]];
			else
			{
				if(a[y[i]]>n)
					a[x[i]]=a[y[i]]-n;
				else
					a[x[i]]=a[y[i]]+n;
			}
		for(int i=1;i<=n*2;++i)
		{
			e[i].push_back(a[i]);
			e[a[i]].push_back(i);
		}
		for(int i=1;i<=n*2;++i)
			if(!col[i])
			{
				++tot;
				dfs(i,tot);
			}
		for(int i=1;i<=n;++i)
			if(col[i]!=col[n+i])
			{
				mp[col[i]].push_back(col[n+i]);
				mp[col[n+i]].push_back(col[i]);
			}
			else
				tag[col[i]]=1;
		int res=0;
		for(int i=1;i<=tot;++i)
			if(!vis[i])
			{
				cnt=0;
				++color;
				Dfs(i,color);
				res+=cnt*(!check(i,1));
			}
		printf("%d\n",res);
		return;
	}
}
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;++i)
		{
			op[i]=x[i]=y[i]=0;
			op[i]=Get();
			scanf("%d",x+i);
			if(op[i]>2)
				scanf("%d",y+i);
		}
		switch(c)
		{
			case 1:case 2:solve1::Main();break;
			case 3:case 4:solve2::Main();break;
			case 5:case 6:solve3::Main();break;
			case 7:case 8:solve4::Main();break;
			case 9:case 10:solve1::Main();break;
		}
	}
	return 0;
}
