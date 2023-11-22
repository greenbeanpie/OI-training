#include<bits/stdc++.h>
using namespace std;
#define INF 2147483647
const int N=1e5+10;
struct Node{
	int id;
	char val;
	bool flag;
}a[N],b[N];
int c,T;
int n,m,ans;
int fan[30];
char opt[N];
int x[N],y[N];
void init()
{
	for(int i=1;i<=n;i++)
	{
		a[i].id=-1;
		a[i].flag=false;
		a[i].val=' ';
	}
	ans=INF;
}
void solve()
{
	for(int i=1;i<=m;i++)
	{
		char opt;
		cin>>opt;
		if(opt=='T'||opt=='U'||opt=='F')
		{
			int x;
			scanf("%d",&x);
			a[x].id=-1;
			a[x].flag=false;
			a[x].val=opt;
		}else if(opt=='+')
		{
			int x,y;
			scanf("%d%d",&x,&y);
			if(a[y].val!=' ')
			{
				a[x].id=-1;
				a[x].flag=false;
				a[x].val=a[y].val;
			}else{
				if(a[y].id==-1)
				{
					a[x].id=y;
					a[x].flag=false;
					a[x].val=' ';
				}else{
					a[x].id=a[y].id;
					a[x].flag=a[y].flag;
					a[x].val=' ';
				}
			}
		}else if(opt=='-')
		{
			int x,y;
			scanf("%d%d",&x,&y);
			if(a[y].val!=' ')
			{
				a[x].id=-1;
				a[x].flag=false;
				a[x].val=fan[a[y].val-'A']+'A';
			}else{
				if(a[y].id==-1)
				{
					a[x].id=y;
					a[x].flag=true;
					a[x].val=' ';
				}else{
					a[x].id=a[y].id;
					a[x].flag=!a[y].id;
					a[x].val=' ';
				}
			}
		}
	}
}
void dfs(int p)
{
	if(p==n+1)
	{
		int res=0;
		for(int i=1;i<=n;i++)
			b[i].val=a[i].val;
		for(int i=1;i<=m;i++)
		{
			if(opt[i]=='T'||opt[i]=='F'||opt[i]=='U')
			{
				b[x[i]].val=opt[i];
			}else if(opt[i]=='+')
			{
				b[x[i]].val=b[y[i]].val;
			}else if(opt[i]=='-')
			{
				b[x[i]].val=fan[b[y[i]].val-'A']+'A';
			}
		}
		for(int i=1;i<=n;i++)
			if(a[i].val!=b[i].val) return ;
		for(int i=1;i<=n;i++)
			if(a[i].val=='U') res++;
		ans=min(ans,res);
		return ;
	}
	a[p].val='T';
	dfs(p+1);
	a[p].val='F';
	dfs(p+1);
	a[p].val='U';
	dfs(p+1);
}
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	fan['T'-'A']='F'-'A'; fan['F'-'A']='T'-'A'; fan['U'-'A']='U'-'A';
	scanf("%d%d",&c,&T);
	if(c==1||c==2)
	{
		while(T--)
		{
			scanf("%d%d",&n,&m);
			init();
			for(int i=1;i<=m;i++)
			{
				cin>>opt[i];
				if(opt[i]=='T'||opt[i]=='F'||opt[i]=='U')
				{
					scanf("%d",&x[i]);
				}else{
					scanf("%d%d",&x[i],&y[i]);
				}
			}
			dfs(1);
			printf("%d\n",ans);
		}
		return 0;
	}
	if(c==3||c==4)
	{
		while(T--)
		{
			scanf("%d%d",&n,&m);
			init();
			for(int i=1;i<=m;i++)
			{
				cin>>opt[i];
				scanf("%d",&x[i]);
			}
			for(int i=1;i<=m;i++)
			{
				a[x[i]].val=opt[i];
			}
			int res=0;
			for(int i=1;i<=n;i++)
				if(a[i].val=='U') res++;
			ans=min(ans,res);
			printf("%d\n",ans);
		}
		return 0;
	}
		while(T--)
		{
			scanf("%d%d",&n,&m);
			init();
			for(int i=1;i<=m;i++)
			{
				cin>>opt[i];
				if(opt[i]=='T'||opt[i]=='F'||opt[i]=='U')
				{
					scanf("%d",&x[i]);
				}else{
					scanf("%d%d",&x[i],&y[i]);
				}
			}
			dfs(1);
			printf("%d\n",ans);
		}
	return 0;
}
