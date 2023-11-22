#include <bits/stdc++.h>
#define int long long
const int INF = 1e9+10;
const int N = 500010;
using namespace std;
int c,n,m,q;
int xa[N],ya[N],x[N],y[N];
int minn=INF,maxx;
int kx,ky;
bool spc=1;
void solve()
{
	int f=0;
	if(x[1]==y[1]||(x[1]-y[1])*(x[n]-y[m])<0)
	{
		cout<<0;
		return;
	}
	if(n==1&&m==1)
	{
		if(x[1]>y[1]) cout<<1;
		else cout<<0;
		return;
	}
	if(n==2&&m==2)
	{
		if(x[1]>y[1]&&x[2]>y[2]) cout<<1;
		else if(x[1]<y[1]&&x[2]<y[2]) cout<<1;
		else cout<<0;
		return ;
	}
	if(x[1]<y[1]) f=-1;
	else f=1;
	for(int i = 1;i<=n;i++) 
	{
		if(x[i]==0&&f==1) 
		{
			cout<<0;
			return;
		}
		if(y[i]==0&&f==-1) 
		{
			cout<<0;
			return;
		}	
	}
	bool same=0;
	for(int i = 1;i<=n;i++)	if((x[i]-y[min(i,m)])*f<=0) same=1;
	if(!same)
	{
		cout<<1;
		return;
	}
	int l=1;
	for(int i = 1;i<=n;i++)
	{
		l=min(l,m);
		for(int j = l;j<=m;j++)
		{
			if((x[i]-y[j])*f<0)
			{
				int tot=i-1;
				while((x[tot]-y[j])*f<0&&tot) tot--;
				if(j==m&&(x[i]-y[j])*f<0) 
				{
					cout<<0;
					return ;
				}
				if(tot==0)
				{
					cout<<0;
					return;
				}
				i=tot+1;
				l=j+1;
				break;
			} 
		}
	}
	cout<<1;
} 
signed main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	cin>>c>>n>>m>>q;
	for(int i = 1;i<=n;i++) cin>>xa[i],x[i]=xa[i];
	for(int i = 1;i<=m;i++) cin>>ya[i],y[i]=ya[i];
	minn=x[n],maxx=y[m];
	for(int i = 1;i<n;i++)
	{
		if(x[i]<minn||x[i]==minn) 
		{
			spc=0;
			break;
		}
	}
	for(int i = 1;i<m;i++)
	{
		if(y[i]>maxx||y[i]==maxx) 
		{
			spc=0;
			break;
		}
	}
	if(spc)
	{
		if(x[n]>=y[m]) cout<<0;
		else 
		{
			//pan duan shi fou ke xing 
			cout<<1;
		}
		while(q--)
		{
			memcpy(x,xa,sizeof x);
			memcpy(y,ya,sizeof y);
			cin>>kx>>ky;
			for(int i = 1;i<=kx;i++) 
			{
				int a,b;
				cin>>a>>b;
				x[a]=b;
			}
			for(int i = 1;i<=ky;i++) 
			{
				int a,b;
				cin>>a>>b;
				y[a]=b;
			}
			if(x[n]>=y[m]) cout<<0;
			else cout<<1;
		}
		return 0;
	}
	solve();//chu shi xun wen
	while(q--) 
	{
		memcpy(x,xa,sizeof x);
		memcpy(y,ya,sizeof y);
		cin>>kx>>ky;
		for(int i = 1;i<=kx;i++) 
		{
			int a,b;
			cin>>a>>b;
			x[a]=b;
		}
		for(int i = 1;i<=ky;i++) 
		{
			int a,b;
			cin>>a>>b;
			y[a]=b;
		}
		solve();
	}
	return 0;
}