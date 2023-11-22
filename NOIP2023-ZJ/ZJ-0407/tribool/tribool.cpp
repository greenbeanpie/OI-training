#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=100010;
char op;
int f,t,n,m,ans,a[N],b[N][5],c[20],d[20];
void dfs(int x)//T1 F2 U3
{
	if(x==n+1)
	{
		int cnt1=0,cnt2=0;
		for(int i=1;i<=n;i++) d[i]=c[i];
		for(int i=1;i<=m;i++)
		{
			if(b[i][1]<=3) d[b[i][2]]=b[i][1];
			else
			{
				if(b[i][1]==4) d[b[i][2]]=d[b[i][3]];
				else
				{
					if(d[b[i][3]]<3) d[b[i][2]]=3-d[b[i][3]];
					else d[b[i][2]]=3;
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(c[i]==d[i])
			{
				cnt1++;
				if(c[i]==3) cnt2++;
			}
			else break ;
		}
		if(cnt1==n) ans=min(ans,cnt2);
		return ;
	}
	for(int i=1;i<=3;i++)
	{
		c[x]=i;
		dfs(x+1);
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	int g,h;
	cin>>f>>t;
	if(f==1||f==2)//dfs
	{
		for(int k=1;k<=t;k++)
		{
			cin>>n>>m;
			ans=n;
			for(int i=1;i<=n;i++) for(int j=1;j<=3;j++) b[i][j]=0;
			for(int i=1;i<=m;i++)
			{
				cin>>op;
				if(op=='U'||op=='T'||op=='F')
				{
					cin>>g; b[i][2]=g;
					if(op=='U') b[i][1]=3;
					if(op=='T') b[i][1]=1;
					if(op=='F') b[i][1]=2;
				}
				else
				{
					cin>>g>>h;
					b[i][2]=g; b[i][3]=h;
					if(op=='+') b[i][1]=4;
					else b[i][1]=5;//-
				}
			}
			for(int i=1;i<=n;i++) c[i]=0;
			dfs(1);
			cout<<ans<<'\n';
		}
	}
	if(f==3||f==4)
	{
		for(int k=1;k<=t;k++)
		{
			cin>>n>>m;
			ans=0;
			for(int i=1;i<=n;i++) a[i]=0;
			for(int i=1;i<=m;i++)
			{
				cin>>op>>g;
				if(op=='U') a[g]=3;
				if(op=='T') a[g]=2;
				if(op=='F') a[g]=1;
			}
			for(int i=1;i<=n;i++) if(a[i]==3) ans++;
			cout<<ans<<'\n';
		}
	}
	if(f==5||f==6)//jiale
	{
		for(int k=1;k<=t;k++)
		{
			int cnt=0;
			cin>>n>>m;
			ans=0;
			for(int i=1;i<=n;i++) a[i]=0;
			for(int i=1;i<=m;i++)
			{
				cin>>op;
				if(op=='U')
				{
					cin>>g;
					a[g]=3;
				}
				else
				{
					cin>>g>>h;
					if(a[h]==3) a[g]=3;
					else
					{
						cnt++;
						b[cnt][2]=g;
						b[cnt][3]=h;
					}
				}
			}
			for(int i=cnt;i>=1;i--) a[b[i][2]]=a[b[i][3]];
			for(int i=1;i<=n;i++) if(a[i]==3) ans++;
			cout<<ans<<'\n';
		}
	}
	return 0;
}
