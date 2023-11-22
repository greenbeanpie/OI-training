#include<bits/stdc++.h>
using namespace std;

const int N=2e5+5;
const int inf=1e9;

int n,m,c,t,a[N],b[N],ans,pos;
char opt;

struct node{
	int opt,x,y;
	inline node(int opt=0,int x=0,int y=0):
		opt(opt),x(x),y(y){}
}q[N];

inline bool check(void)
{
	for(int i=1;i<=n;i++) b[i]=a[i];
	for(int i=1;i<=m;i++)
	{
		if(q[i].opt<=3) b[q[i].x]=q[i].opt;
		if(q[i].opt==4) b[q[i].x]=b[q[i].y];
		if(q[i].opt==5)
		{
			if(b[q[i].y]==3) b[q[i].x]=3;
			else if(b[q[i].y]==2) b[q[i].x]=1;
			else if(b[q[i].y]==1) b[q[i].x]=2;
		}
	}
	for(int i=1;i<=n;i++)
		if(a[i]!=b[i]) return false;
	return true;
}

void dfs(int dep)
{
	if(dep==0)
	{
		if(check())
		{
			int cnt=0;
			for(int i=1;i<=n;i++)
				cnt+=(a[i]==3);
			ans=min(ans,cnt);
		}
		return;
	}
	for(int i=1;i<=3;i++)
	{a[dep]=i;dfs(dep-1);}
	return;
}

inline void sub1(void)//20
{
	while(t--)
	{
		cin>>n>>m;
		ans=inf;
		for(int i=1;i<=m;i++)
		{
			cin>>opt;
			if(opt=='T') q[i].opt=1,cin>>q[i].x;
			if(opt=='F') q[i].opt=2,cin>>q[i].x;
			if(opt=='U') q[i].opt=3,cin>>q[i].x;
			if(opt=='+'){q[i].opt=4;cin>>q[i].x>>q[i].y;}
			if(opt=='-'){q[i].opt=5;cin>>q[i].x>>q[i].y;}
		}
		dfs(n);
		cout<<ans<<endl;
	}
	return;
}

inline void sub2(void)//20
{
	while(t--)
	{
		cin>>n>>m;
		ans=0;
		memset(a,0,sizeof(a));
		for(int i=1;i<=m;i++)
		{
			cin>>opt>>pos;
			if(opt=='T') a[pos]=1;
			if(opt=='F') a[pos]=2;
			if(opt=='U') a[pos]=3;
		}
		for(int i=1;i<=n;i++)
			ans+=(a[i]==3);
		cout<<ans<<endl;
	}
	return;
}

inline void sub3(void)//10
{
	while(t--)
	{
		cin>>n>>m;
		ans=0;
		int cnt=0,lst=0;
		memset(a,0,sizeof(a));
		for(int i=1;i<=m;i++)
		{
			cin>>opt;
			if(opt=='U') q[i].opt=3,cin>>q[i].x;
			if(opt=='+'){q[i].opt=4;cin>>q[i].x>>q[i].y;}
		}
		for(int h=1;h<=n;h++)
		{
			for(int i=1;i<=m;i++)
			{
				if(q[i].opt==3) a[q[i].x]=3;
				if(q[i].opt==4) a[q[i].x]=a[q[i].y];
			}
			cnt=0;
			for(int i=1;i<=n;i++)
				cnt+=(a[i]==3);
			if(cnt==lst) break;
			else lst=cnt;
		}
		for(int i=1;i<=n;i++)
			ans+=(a[i]==3);
		cout<<ans<<endl;
	}
	return;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	
	cin>>c>>t;
	if(c>=1 && c<=2) sub1();
	else if(c>=3 && c<=4) sub2();
	else sub3();
    return 0;
}