#include<bits/stdc++.h>
#define int long long
#define forr(i,l,r) for(int i=l;i<=r;i++)
#define ffor(i,l,r) for(int i=l;i>=r;i--)
using namespace std;
const int N=1e5+10;
char a[N],c[N],nb[4],d[N];
int b[N],bb[N];
bool f[N];
int n,m,ans;
char dd(char x)
{
	if(x=='U')
	{
		return 'U';
	}
	else
	{
		return (x=='T'?'F':'T');
	}
}
int pd()
{
	int l=0;
	forr(i,1,n)
	{
		d[i]=c[i];
		if(d[i]=='U')
		{
			l++;
		}
	}
	forr(i,1,m)
	{
		if(a[i]=='T'||a[i]=='F'||a[i]=='U')
		{
			c[b[i]]=a[i];
		}
		if(a[i]=='+')
		{
			c[b[i]]=c[bb[i]];
		}
		if(a[i]=='-')
		{
			c[b[i]]=dd(c[bb[i]]);
//			cout<<"qwq";
		}
	}
	forr(i,1,n)
	{
		if(c[i]!=d[i])
		{
			return 1e18;
		}
	}
	return l;
}
void dfs(int x)
{
	if(x==n+1)
	{
		int cc=pd();
		ans=ans>cc?cc:ans;
		return ;
	}
	forr(i,1,3)
	{
		c[x]=nb[i];
		dfs(x+1);
	}
}
signed main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	nb[1]='T';
	nb[2]='F';
	nb[3]='U';
	int c,t;
	cin>>c>>t;
	if(c==3||c==4)
	{
		while(t--)
		{
			memset(f,0,sizeof(f));
			ans=0;
			cin>>n>>m;
			forr(i,1,m)
			{
				cin>>a[i]>>b[i];
			}
			ffor(i,m,1)
			{
				if(!f[b[i]])
				{
					f[b[i]]=1;
					if(a[i]=='U')
					{
						ans++;
					}
				}
			}
			cout<<ans<<'\n';
		}
		return 0;
	}
	if(c==1||c==2)
	{
		while(t--)
		{
			memset(f,0,sizeof(f));
			ans=1e18;
			cin>>n>>m;
			forr(i,1,m)
			{
				cin>>a[i];
				if(a[i]=='T'||a[i]=='F'||a[i]=='U')
				{
					cin>>b[i];
				}
				else
				{
					cin>>b[i]>>bb[i];
				}
			}
			dfs(1);
			cout<<ans<<'\n';
		}
	}
}
