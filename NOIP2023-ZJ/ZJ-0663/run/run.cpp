#include<bits/stdc++.h>
#define int long long
#define forr(i,l,r) for(int i=l;i<=r;i++)
#define ffor(i,l,r) for(int i=l;i>=r;i--)
using namespace std;
const int N=1e5+10;
int a[N],b[N],c[N],n,m,k,d,ans=-1e18;
int r[N];
void calc(int l)
{
	int ccc=0;
	forr(i,1,n)
	{
		if(r[i])
		{
			ccc++;
			if(ccc>k)
			{
				return ;
			}
		}
		else
		{
			ccc=0;
		}
	}
//	cout<<l<<endl;
	int cnt=-l*d;
//	cout<<"qwq"<<r[n]<<"qa";
	forr(i,1,m)
	{
		forr(j,a[i]-b[i]+1,a[i])
		{
			if(r[j]==0)
			{
				break;
			}
			if(j==a[i])
			{
				cnt+=c[i];
			}
		}
//		if(r[a[i]]-r[a[i]-b[i]+1]==b[i]-1)
//		{
//			cnt+=c[i];
//		}
	}
	ans=ans>cnt?ans:cnt;
//	cout<<ans<<endl;
}
void dfs(int x,int l)
{
	if(x==n+1)
	{
		calc(l);
		return ;
	}
	r[x]=0;
	dfs(x+1,l);
	r[x]=1;
	dfs(x+1,l+1);
//	r[x]=0;
}
signed main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int cc,t;
	cin>>cc>>t;
	if(cc<=4)
	{
		while(t--)
		{
			cin>>n>>m>>k>>d;
			forr(i,1,m)
			{
				cin>>a[i]>>b[i]>>c[i];
			}
			ans=-1e18;
			dfs(1,0);
			cout<<ans<<'\n';
		}
		return 0;
	}
	
}
