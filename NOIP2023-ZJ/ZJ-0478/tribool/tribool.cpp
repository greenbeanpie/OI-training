#include<bits/stdc++.h>
#define ll long long 
#define UF(i,x,y) for(int i=x;i<=y;i++)
#define DF(i,x,y) for(int i=x;i>=y;i--)
#define ce continue
#define inf 0x7fffffff
#define N 100005
using namespace std;
struct rec{int x,z;char y;}a[N];
int n,m,ans,u,v,c,Q,f;
char op;
bool vis[N];
inline int read(){int x=0,f=1;char ch=getchar();while(ch<'0'||ch>'9') f=-f,ch=getchar();while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();return x*f;}
inline void dfs(int i,int stp)
{
	if(f==0) return;
	
	if(stp>n) 
	{
		int flag=1;
		if(a[i].y=='-') flag=-flag;
		
		int now=a[i].z;
		while(now!=i)
		{
			if(a[now].y=='-') flag=-flag;
			now=a[now].z;
		}
		
		if(flag==-1) a[i].x=1,a[i].y='U';else a[i].x=0;
		
		f=0;
		return;
	}
	
	if(a[i].x==1&&a[i].y=='U') ans++;
	
	if(a[i].x==2)
	{
		int to=a[i].z;
		if(!vis[to]) dfs(to,stp+1);
		if(f==0) return;
		if(a[to].x==0) a[i].x=0;
		if(a[to].x==1&&a[to].y=='U') ans++,a[i].x=1,a[i].y='U';
	}
	
	vis[i]=1;
}
inline void work()
{
	scanf("%d%d",&n,&m);
	UF(i,1,m)
	{
		cin>>op;
		if(op=='T'||op=='F'||op=='U') {scanf("%d",&u); a[u].x=1; a[u].y=op;}
		if(op=='-'||op=='+')
		{
			scanf("%d%d",&u,&v);
			if(a[v].x==0) a[u].x=2,a[u].y=op,a[u].z=v;else
			if(a[v].x==1) a[u].x=1,a[u].y=a[v].y;else
			if(a[v].x==2)
			{
				a[u].x=2;
				a[u].y=(op=='+') ? a[v].y : ( (a[v].y=='-') ? '+' : '-' );
				a[u].z=a[v].z;
			}
		}
	}
	
	UF(i,1,n) if(a[i].x==2&&a[i].z==i) if(a[i].y=='-') a[i].x=1,a[i].y='U';else a[i].x=0;
	
	f=1;
	UF(i,1,n) if(!vis[i]) 
	{
		dfs(i,0);
		if(!f) f=1,dfs(i,0);
	}
	printf("%d\n",ans);
	
	UF(i,1,n) vis[i]=a[i].x=a[i].z=0,a[i].y=' ';
	ans=0;
}
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	c=read(); Q=read();
	while(Q--) work();
	fclose(stdin);fclose(stdout);
	return 0;
}
