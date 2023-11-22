#include <bits/stdc++.h>
#define int long long
const int INF = 1e9+10;
const int N = 100010;
using namespace std;
int c,T;
int n,m;
int x[N];
int xa[N];
bool fff,ff;
struct node
{
	char opt,a,b;
}o[N];
void solve()
{
	fff=0,ff=0;
	int ans=0;
	cin>>n>>m;
	for(int i = 1;i<=n;i++) x[i]=1;
	for(int i = 1;i<=m;i++)
	{
		char opt;
		int a,b;
		cin>>opt;
		if(opt=='T') 
		{
			cin>>a;
			o[i].opt=opt,o[i].a=a;
			x[a]=1;
			ff=1;
		}
		else if(opt=='F')
		{
			cin>>a;
			o[i].opt=opt,o[i].a=a;
			x[a]=2;
			ff=1;
		}
		else if(opt=='U')
		{
			cin>>a;
			o[i].opt=opt,o[i].a=a;
			x[a]=-1;
		}
		else if(opt=='+')
		{
			fff=1;
			cin>>a>>b;
			o[i].opt=opt,o[i].a=a,o[i].b=b;
			if(x[b]!=0)	x[a]=x[b];
		}
		else if(opt=='-')
		{
			fff=1,ff=1;
			cin>>a>>b;
			o[i].opt=opt,o[i].a=a,o[i].b=b;
			if(x[b]>0)	x[a]=3-x[b];
			else if(x[b]==-1) x[a]=-1;
		}
	}
	if(!fff)
	{
		for(int i = 1;i<=n;i++) if(x[i]==-1) ans++;
		cout<<ans<<"\n";
		return;
	}
	memcpy(xa,x,sizeof xa);
	for(int i = 1;i<=m;i++)
	{
		char opt=o[i].opt;
		int a=o[i].a,b=o[i].b;
		if(opt=='T') 
		{
			o[i].opt=opt,o[i].a=a;
			x[a]=1;
		}
		else if(opt=='F')
		{
			o[i].opt=opt,o[i].a=a;
			x[a]=2;
		}
		else if(opt=='U')
		{
			o[i].opt=opt,o[i].a=a;
		}
		else if(opt=='+')
		{
			fff=1;
			if(x[b]!=0)	x[a]=x[b];
		}
		else if(opt=='-')
		{
			fff=1,ff=1;
			if(x[b]>0)	x[a]=3-x[b];
			else if(x[b]==-1) x[a]=-1;
		}
	}
	for(int i = 1;i<=n;i++) if(x[i]!=xa[i]||x[i]==-1) ans++;
	cout<<ans<<"\n";
}
signed main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	cin>>c>>T;
	while(T--)	solve();
	return 0;
}