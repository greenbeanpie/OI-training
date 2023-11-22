#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define il inline
#define re register
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
//#define int ll
#define pii pair<int,int>
#define mp make_pair
#define F(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define DF(i,a,b) for(int (i)=(a);(i)>=(b);(i)--)
#define G(i,u) for(int (i)=head[(u)];(i);(i)=nxt[(i)])
il ll read(){ll x=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-48;ch=getchar();}return x*f;}
const int N=100010,M=400010;
int n,m,ans;
int can[N];
int val[N],b[N];
struct MS
{
	char opt;
	int u,v;
}q[N];
il void check()
{
	F(i,1,n) b[i]=val[i];
	F(i,1,m)
	{
		if(q[i].opt=='+')
		{
			val[q[i].u]=val[q[i].v];
		}
		else if(q[i].opt=='-')
		{
			if(val[q[i].v]==1) val[q[i].u]=2;
			else if(val[q[i].v]==2) val[q[i].u]=1;
			else if(val[q[i].v]==3) val[q[i].u]=3;
		}
		else
		{
			if(q[i].opt=='T') val[q[i].u]=1;
			else if(q[i].opt=='F') val[q[i].u]=2;
			else if(q[i].opt=='U') val[q[i].u]=3;
		}
	}
	F(i,1,n)
	{
		if(b[i]!=val[i]) return ;
	}
	int cnt=0;
	F(i,1,n) if(b[i]==3) cnt++;
	ans=min(ans,cnt);
}
il void dfs(int step)
{
	if(step==n+1)
	{
		check();
		F(i,1,n) val[i]=b[i];
		return ;
	}
	F(i,1,3)
	{
		val[step]=i;
		dfs(step+1);
	}
}
int main()//¶à²âÇå¿Õ£¡ 
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	int C=read(),T=read();
	if(C==1||C==2)
	{
		while(T--)
		{
			ans=INF;
			memset(val,0,sizeof(val));
			memset(b,0,sizeof(b));
			n=read(),m=read();
			F(i,1,m)
			{
				cin>>q[i].opt;
				if(q[i].opt=='+'||q[i].opt=='-')
					q[i].u=read(),q[i].v=read();
				else
					q[i].u=read();
			}
			dfs(1);
			printf("%d\n",ans);
		}
	}
	else if(C==3||C==4)
	{
		while(T--)
		{
			ans=0;
			memset(val,0,sizeof(val));
			n=read(),m=read();
			char ch;
			F(i,1,m)
			{
				cin>>ch;
				int x=read();
				if(ch=='U') val[x]=1;
				else val[x]=0;
			}
			F(i,1,n) if(val[i]) ans++;
			printf("%d\n",ans);
		}
	}
	else if(C==5||C==6)
	{
		while(T--)
		{
			ans=0;
			n=read(),m=read();
			F(i,1,n) val[i]=i;
			char ch;
			F(i,1,m)
			{
				cin>>ch;
				if(ch=='U')
				{
					int x=read();
					val[x]=n+1;
				}
				else if(ch=='+')
				{
					int u=read(),v=read();
					val[u]=val[v];
				}
			}
			F(i,1,n) if(val[i]==n+1||val[val[i]]==n+1)
				ans++;
			printf("%d\n",ans);
		}
	}
	else
	{
		while(T--)
		{
			n=read(),m=read();
			char ch;
			F(i,1,m)
			{
				cin>>ch;
				if(ch=='+'||ch=='-')
				{
					int u=read(),v=read();
				}
				else
				{
					int u=read();
				}
			}
			printf("0\n");
		}
	}
	return 0;
}
