#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
const int N=1e5+5;
int T,c,M[205],Q[205];
int n,m,a[N],b[N];
int ans;
bool flag,flag1;
struct node
{
	int v;
	int to;
	int from;
}opt[N];
inline void calc(int ot,int x,int y)
{
	if(ot<3) a[x]=ot;
	else if(ot==3) a[x]=a[y];
	else a[x]=Q[a[y]];
	return;
}
namespace sub1
{
	inline bool check()
	{
		bool flag=true;
		for(int i=1;i<=n;i++) b[i]=a[i];
		for(int i=1;i<=m;i++) calc(opt[i].v,opt[i].to,opt[i].from);
		for(int i=1;i<=n;i++) if(a[i]!=b[i]) flag=false;
		for(int i=1;i<=n;i++) a[i]=b[i];
		if(flag) return true;
		return false;
	}
	inline void dfs(int x,int num)
	{
		if(x==n+1)
		{
			if(check()) ans=min(ans,num);
			return;
		}
		if(num>=ans) return;
		for(int i=0;i<3;i++)
		{
			a[x]=i;
			if(i==2) dfs(x+1,num+1);
			else dfs(x+1,num);
			a[x]=-1;
		}
	}
	inline void S1()
	{
		ans=n;
		dfs(1,0);
		printf("%d\n",ans);
	}
}
namespace sub2
{
	inline void S2()
	{
		for(int i=1;i<=m;i++) calc(opt[i].v,opt[i].to,opt[i].from);
		ans=0;
		for(int i=1;i<=n;i++) if(a[i]==2) ans++;
		printf("%d\n",ans);
	}
}
namespace sub3
{
	inline void S3()
	{
		printf("0");
		puts("");
	}
}
inline void mem()
{
	flag=true;
	flag1=true;
	for(int i=1;i<=n;i++) a[i]=-1,b[i]=-1;
	for(int i=1;i<=m;i++) opt[i]=node{-1,0,0};
}
inline void init()
{
	mem();
	n=read(),m=read();
	for(int i=1;i<=m;i++)
	{
		char c;
		int x=0,y=0;
		cin>>c;
		if(c=='+'||c=='-')
		{
			x=read(),y=read();
			opt[i]=node{M[int(c)],x,y};
			flag=false;
		}
		else
		{
			x=read();
			opt[i]=node{M[int(c)],x,0};
			if(c=='T'||c=='F') flag1=false;
		}
	}
}
inline void work()
{
	if(n<=10) sub1::S1();
	else if(flag||flag1) sub2::S2();
	else sub3::S3();
}
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	M[int('T')]=1,M[int('F')]=0,M[int('U')]=2,M[int('+')]=3,M[int('-')]=4;
	Q[1]=0,Q[0]=1,Q[2]=2;
	c=read(),T=read();
	while(T--)
	{
		init();
		work();
	}
	return 0;
}
