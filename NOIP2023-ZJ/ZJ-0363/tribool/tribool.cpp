#include<bits/stdc++.h>
#define DEBUG puts("en en shui ye mei kan de qi ni");
using namespace std;
inline int read()
{
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		s=(s<<3)+(s<<1)+(ch^48);
		ch=getchar();
	}
	return s*w;
}
inline void print(int x)
{
	if(x<0)x=-x,putchar('-');
	if(x>=10)print(x/10);
	putchar(x%10+'0');
}
const int inf=1e9;
int id,T,n,m;
struct Genshin//do you know mi huo xing wei da shang?
{
	char op;
	int x,y;
}c[1000010];
int col[15],lst[15],ans;
inline bool chk()
{
	memcpy(lst,col,sizeof(lst));
	for(int i=1;i<=m;i++)
	{
		char op=c[i].op;
		if(op=='+'||op=='-')
		{
			int x=c[i].x,y=c[i].y;
			if(op=='+')
			{
				lst[x]=lst[y];
			}
			else
			{
				if(lst[y]=='U')lst[x]='U';
				else
				{
					if(lst[y]=='T')lst[x]='F';
					else lst[x]='T';
				}
			}
		}
		else
		{
			int x=c[i].x;
			lst[x]=op;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(lst[i]!=col[i])
		{
			return 0;
		}
	}
	return 1;
}
inline void dfs(int dep,int s)
{
	if(dep==n+1)
	{
		if(chk())
		{
			ans=min(ans,s);
		}
		return;
	}
	col[dep]='T';
	dfs(dep+1,s);
	col[dep]='F';
	dfs(dep+1,s);
	col[dep]='U';
	dfs(dep+1,s+1);
}
inline void solve1()
{
	n=read();
	m=read();
	ans=inf;
	for(int i=1;i<=m;i++)
	{
		cin>>c[i].op;
		if(c[i].op=='+'||c[i].op=='-')
		{
			c[i].x=read();
			c[i].y=read();
			continue;
		}
		c[i].x=read();
	}
	dfs(1,0);
}
vector<pair<int,int> > ve[100010];
int t,f,U,pre[1000010];
int fa[1000010];
inline int get(int x)
{
	return x==fa[x]?x:fa[x]=get(fa[x]);
}
map<pair<int,int>,int> mp;
inline int get(int u,int tim)
{
	if(mp[{u,tim}])return mp[{u,tim}];
	int l=0,r=(int)ve[u].size()-1,res=-1;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(ve[u][mid].first<tim)
		{
			res=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	if(res==-1)
	{
		return mp[{u,tim}]=u;
	}
	int x=ve[u][res].second,pretim=ve[u][res].first;
	return mp[{u,tim}]=get(x,pretim);
}
/*
3
2
5 5
+ 2 1
+ 3 2
U 2
+ 4 2
+ 5 4
5 5
+ 2 1
+ 3 2
U 2
+ 4 2
+ 5 4
*/
inline void solve()
{
	n=read();
	m=read();
	for(int i=1;i<=n+3;i++)ve[i].clear(),fa[i]=i;
	mp.clear();
	ans=0;
	for(int i=1;i<=m;i++)
	{
		cin>>c[i].op;
		if(c[i].op=='+'||c[i].op=='-')
		{
			c[i].x=read();
			c[i].y=read();
			continue;
		}
		c[i].x=read();
	}
	t=n+1;
	f=n+2;
	U=n+3;
	for(int i=1;i<=m;i++)
	{
		char op=c[i].op;
		if(op=='+')
		{
			int x=c[i].x,y=c[i].y;
			//x fan xiang bian dao y
			ve[x].push_back({i,y});
			continue;
		}
		int x=c[i].x;
		if(op=='T')
		{
			ve[x].push_back({i,t});
		}
		if(op=='F')
		{
			ve[x].push_back({i,f});
		}
		if(op=='U')
		{
			ve[x].push_back({i,U});
		}
	}
//	for(int i=1;i<=n;i++)sort(ve[i].begin(),ve[i].end());
	for(int i=1;i<=n;i++)
	{
		pre[i]=get(i,inf);
		fa[get(i)]=get(pre[i]);
	}
	for(int i=1;i<=n;i++)
	{
//		cout<<pre[i]<<' '<<U<<'\n';
		if(get(i)==get(U))ans++;
	}
}
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	id=read();
	T=read();
	if(id<=2)
	{
		while(T--)
		{
			solve1();
			print(ans);
			puts("");
		}
		return 0;
	}
	if(id>=3&&id<=6)
	{
		while(T--)
		{
			solve();
			print(ans);
			puts("");
		}
		return 0;
	}
	return 0;
}