#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define For(i,x,y) for(int i=x;i<=y;i++)
#define FOR(i,x,y) for(int i=x;i>=y;i--)
#define elif else if

int c,t;
namespace Subtask1
{
	const int INF=1e9;
	char ch[6]={' ','T','F','U','+','-'};
	char v[14],s[14],e[14];
	int n,m,ans,x1[14],x2[14];
	inline char fan(char x)
	{
		if(x=='T')return 'F';
			elif(x=='F')return 'T';
				else return 'U';
	}
	inline bool check()
	{
		For(i,1,n)e[i]=s[i];
		For(i,1,m)
		{
			if(v[i]=='+')e[x1[i]]=e[x2[i]];
				elif(v[i]=='-')e[x1[i]]=fan(e[x2[i]]);
					elif(v[i]=='U')e[x1[i]]='U';
						elif(v[i]=='F')e[x1[i]]='F';
							else e[x1[i]]='T';
		}
		For(i,1,n)if(e[i]!=s[i])return 0;
		return 1;
	}
	inline void dfs(int x,int U)
	{
		if(x==n+1)
		{
			if(check())ans=min(ans,U);
			return ;
		}
		if(U>=ans)return ;
		For(i,1,5)
		{
			s[x]=ch[i];
			if(i==3)dfs(x+1,U+1);
				else dfs(x+1,U);
		}
	}
	inline void solve()
	{
		while(t--)
		{
			cin>>n>>m;
			For(i,1,m)
			{
				cin>>v[i];
				if(v[i]=='+' || v[i]=='-')cin>>x1[i]>>x2[i];
					else cin>>x1[i];
			}
			ans=INF;
			dfs(1,0);
			cout<<ans<<"\n";
		}
	}
}
namespace Subtask2
{
	const int N=1e5+4;
	int n,m,x,ans;
	char v,a[N];
	void solve()
	{
		while(t--)
		{
			cin>>n>>m;
			For(i,1,n)a[i]=' ';
			while(m--)
			{
				cin>>v>>x;
				a[x]=v;
			}
			ans=0;
			For(i,1,n)if(a[i]=='U')ans++;
			cout<<ans<<"\n";
		}
	}
}
namespace Subtask3
{
	const int N=1e5+4;
	int n,m,ans,x1[N],x2[N];
	char s[N],v[N];
	inline void solve()
	{
		while(t--)
		{
			cin>>n>>m;
			For(i,1,n)s[i]=' ';
			For(i,1,m)
			{
				cin>>v[i]>>x1[i];
				if(v[i]=='U')s[x1[i]]='U';
					else cin>>x2[i],s[x1[i]]=s[x2[i]];
			}
			For(l,1,100)For(i,1,m)if(v[i]=='U')s[x1[i]]='U';else s[x1[i]]=s[x2[i]];
			ans=0;
			For(i,1,n)if(s[i]=='U')ans++;
			cout<<ans<<"\n";
		}
	}
}
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	IOS;
	cin>>c>>t;
	if(c<=2)return Subtask1::solve(),0;
	if(c>=3 && c<=4)return Subtask2::solve(),0;
	if(c>=5 && c<=6)return Subtask3::solve(),0;

	return 0;
}
