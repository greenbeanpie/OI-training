#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int sub,T;
int n,m,ans;
char a[N],b[N];
char re(char ch)
{
	if(ch=='T') return 'F';
	if(ch=='F') return 'T';
	return 'U';
}
struct op
{
	char v;
	int x,y;
}q[N];
void init()
{
	ans=N;
}
namespace sub1
{
	bool check()
	{
		for(int i=1;i<=n;i++) b[i]=a[i];
		for(int i=1;i<=m;i++)
		{
			if(q[i].v=='T') b[q[i].x]='T';
			else if(q[i].v=='F') b[q[i].x]='F';
			else if(q[i].v=='U') b[q[i].x]='U';
			else if(q[i].v=='+') b[q[i].x]=b[q[i].y];
			else b[q[i].x]=re(b[q[i].y]);
		}
		for(int i=1;i<=n;i++)
			if(a[i]!=b[i]) return 0;
		return 1;
	}
	void dfs(int x,int cnt)
	{
		if(x>n)
		{
			if(check()) ans=min(ans,cnt);
			return ;
		}
		a[x]='T';dfs(x+1,cnt);
		a[x]='F';dfs(x+1,cnt);
		a[x]='U';dfs(x+1,cnt+1);
	}
	void solve()
	{
		cin>>n>>m;
		for(int i=1;i<=m;i++)
		{
			cin>>q[i].v;
			if(q[i].v=='+' || q[i].v=='-') cin>>q[i].x>>q[i].y;
			else cin>>q[i].x;
		}
		dfs(1,0);
	}
}

namespace sub2
{
/*
4 2

4 3
T 1
U 2
F 4

2 2
T 2
U 2
==========
1
1
*/
	void solve()
	{
		cin>>n>>m;
		for(int i=1;i<=n;i++) b[i]='*';
		for(int i=1;i<=m;i++)
		{
			cin>>q[i].v>>q[i].x;
			if(q[i].v=='T') b[q[i].x]='T';
			else if(q[i].v=='F') b[q[i].x]='F';
			else b[q[i].x]='U';
		}
		
		ans=0;
		for(int i=1;i<=n;i++) 
			if(b[i]=='U') ans++;
	}
}

signed main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>sub>>T;
	while(T--) 
	{
		init();
		if(sub<=2) sub1::solve();
		else if(sub<=4) sub2::solve();
		cout<<ans<<endl;
	}
}