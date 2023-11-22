#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
const int N=2e5+10;
const int inf=1e9;
inline void fre()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
}
int c,t;
int n,m,ans;
//--------------------------------------
char ch;
int a[N],b[N];
struct node
{
	int opt,x,y;
}q[N];
inline bool check()
{
	for(int i=1;i<=n;i++) b[i]=a[i];
	for(int i=1;i<=m;i++)
	{
		if(q[i].opt==1) b[q[i].x]=q[i].y;
		else if(q[i].opt==2) b[q[i].x]=b[q[i].y];
		else b[q[i].x]=4-b[q[i].y];
	}
	for(int i=1;i<=n;i++)
	{
		if(b[i]!=a[i]) return 0;
	}
	return 1;
}
inline void dfs(int x,int sum)
{
	if(sum>ans) return;
	if(x>n)
	{
		if(check()) ans=sum;
		return;
	}
	a[x]=1,dfs(x+1,sum);
	a[x]=3,dfs(x+1,sum);
	a[x]=2,dfs(x+1,sum+1);
}
inline void solve1()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>ch;
		if(ch=='T'||ch=='F'||ch=='U')
		{
			q[i].opt=1;
			cin>>q[i].x;
			if(ch=='T') q[i].y=1;
			else if(ch=='F') q[i].y=3;
			else q[i].y=2;
		}
		else if(ch=='+')
		{
			q[i].opt=2;
			cin>>q[i].x>>q[i].y;
		}
		else
		{
			q[i].opt=3;
			cin>>q[i].x>>q[i].y;
		}
	}
	ans=inf;
	dfs(1,0);
	cout<<ans<<'\n';
}

//---------------------------------------------------
int val,pos;
inline void solve2()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) a[i]=0;
	for(int i=1;i<=m;i++)
	{
		cin>>ch;
		if(ch=='T') val=1;
		else if(ch=='F') val=3;
		else val=2;
		cin>>pos;
		a[pos]=val;
	}
	ans=0;
	for(int i=1;i<=n;i++) if(a[i]==2) ans++;
	cout<<ans<<'\n';
}
//---------------------------------------------------
struct Node
{
	int id,fl;
}f[N];
int X,Y;
inline Node getfather(int x)
{
//	cout<<x<<'\n';
	if(f[x].id==x) return f[x];
	Node a=getfather(f[x].id);
	f[x].id=a.id;
	f[x].fl=(!(f[x].fl^a.fl));
	return f[x];
}
inline void solve3()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) f[i]=(Node){n+i,1},f[n+i]=(Node){n+i,1};
	f[2*n+1]=(Node){2*n+1,1};
	f[2*n+2]=(Node){2*n+2,1};
	f[2*n+3]=(Node){2*n+3,1};
	for(int i=1;i<=m;i++)
	{
		cin>>ch;
		if(ch=='T'||ch=='F'||ch=='U')
		{
			cin>>X;
			if(ch=='T') f[X]=(Node){2*n+1,1};
			else if(ch=='F') f[X]=(Node){2*n+3,1};
			else f[X]=(Node){2*n+2,1};
		}
		else if(ch=='+')
		{
			cin>>X>>Y;
			f[X]=(Node){Y,1};
			getfather(X);
		}
		else
		{
			cin>>X>>Y;
			f[X]=(Node){Y,0};
			getfather(X);
		}
	}
//	for(int i=1;i<=n;i++) cout<<f[i].id<<' '<<f[i].fl<<'\n';
	for(int i=1;i<=n;i++) a[i]=0;
	bool flag=1;
	while(flag)
	{
		flag=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]) continue;
			getfather(i);
			if(f[i].id>2*n)
			{
				flag=1;
				int Val=f[i].id-2*n;
				if(f[i].fl) a[i]=Val;
				else a[i]=4-Val;
				f[n+i]=(Node){f[i].id,1};
			}
			else 
			{
				Node fa=getfather(n+i);
				if(f[i].id==fa.id&&f[i].fl!=fa.fl)
				{
					flag=1;
					a[i]=2;
					f[f[i].id]=(Node){2*n+2,1};
				}
			}
		}
		for(int i=1;i<=2*n;i++) getfather(i);
//		for(int i=1;i<=2*n+3;i++) cout<<i<<' '<<f[i].id<<' '<<f[i].fl<<'\n';
	}
//	for(int i=1;i<=2*n+3;i++) cout<<i<<' '<<f[i].id<<' '<<f[i].fl<<'\n';
	ans=0;
	for(int i=1;i<=n;i++) if(a[i]==2) ans++;
	cout<<ans<<'\n';
}
//---------------------------------------------------
signed main()
{
	fre();
	IOS;
	cin>>c>>t;
	while(t--)
	{
		if(c<=2) solve1();
		else if(c<=4) solve2();
		else solve3();
	}
	return 0;
}
