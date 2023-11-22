//有点神秘 或许可以建图？或者是冰茶几？
#include<bits/stdc++.h>
#define N 100200
using namespace std;
int c,T;
int n,m,ans;
//T:1 F:0 U:-1
namespace sub1
{
	struct qwq{char op;int x,y;}a[N];
	int b[N],t[N];
	void dfs(int now,int sum)
	{
		if(now==n+1)
		{
			for(int i=1;i<=n;i++)t[i]=b[i];
			for(int i=1;i<=m;i++)
			{
				int op=a[i].op,x=a[i].x,y=a[i].y;
				if(op=='T')t[x]=1;
				else if(op=='F')t[x]=0;
				else if(op=='U')t[x]=-1;
				else if(op=='+')t[x]=t[y];
				else
				{
					if(t[y]==-1)t[x]=-1;
					else t[x]=t[y]^1;
				}
			}
			for(int i=1;i<=n;i++)if(t[i]!=b[i])return;
			ans=min(ans,sum);
//			if(sum==2)for(int i=1;i<=n;i++)cout<<t[i]<<" ";
//			cout<<endl;
			return;
		}
		b[now]=0;dfs(now+1,sum);
		b[now]=1;dfs(now+1,sum);
		b[now]=-1;dfs(now+1,sum+1);
	}
	void main()
	{
		while(T--)
		{
			cin>>n>>m;
			for(int i=1;i<=m;i++)
			{
				cin>>a[i].op>>a[i].x;
				if(a[i].op=='-'||a[i].op=='+')cin>>a[i].y;
			}
			ans=0x3f3f3f3f;dfs(1,0);
			cout<<ans<<'\n';
		}
	} 
}
namespace sub2
{
	int lst[N];
	void main()
	{
		while(T--)
		{
			cin>>n>>m;
			char op;int x;
			memset(lst,0,sizeof(lst));
			for(int i=1;i<=m;i++)
			{
				cin>>op>>x;
				if(op=='T')lst[x]=1;
				else if(op=='F')lst[x]=0;
				else lst[x]=-1;
			}
			ans=0;
			for(int i=1;i<=n;i++)ans+=(lst[i]==-1);
			cout<<ans<<'\n';
		}
	} 
}
namespace sub3
{
	struct qwq{char op;int x,y;}q[N];
	int a[N],t[N];
	void main()
	{
		while(T--)
		{
			cin>>n>>m;
			memset(a,0,sizeof(a));
			for(int i=1;i<=m;i++)
			{
				cin>>q[i].op>>q[i].x;
				if(q[i].op=='U')a[q[i].x]=1;
				else if(q[i].op=='+')
				{
					cin>>q[i].y;
					a[q[i].x]=a[q[i].y];
				}
			}
			ans=0;
			for(int i=1;i<=n;i++)ans+=a[i];
			cout<<ans<<'\n';
			/*
			for(int i=1;i<=m;i++)
			{
				if(q[i].op=='U')t[q[i].x]=1;
				else if(q[i].op=='+')t[q[i].x]=t[q[i].y];
			}
			for(int i=1;i<=n;i++)if(t[i]!=a[i])
			{
				cout<<"ERROR!\n";
				break;
			}
			*/
		}
	} 
}
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>c>>T;
	if(c<=2)sub1::main();//20pts
	else if(c<=4)sub2::main();//20pts
	else if(c<=6)sub3::main();//0pts
 } 
