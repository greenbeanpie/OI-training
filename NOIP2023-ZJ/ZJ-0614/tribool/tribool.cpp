#include <bits/stdc++.h>
using namespace std;

int c,t,n,m;
int ans=0x3f3f3f3f;
int i[11],j[11];
char g[100010],h[11],v[11];

void che12();
char oppo(char x)
{
	if(x=='T') return 'F';
	if(x=='F') return 'T';
	return 'U';
}

void dfs(int dep)
{
	if(dep>n)
	{
		che12();
		return;
	}
	g[dep]=h[dep]='T';
	dfs(dep+1);
	g[dep]=h[dep]='F';
	dfs(dep+1);
	g[dep]=h[dep]='U';
	dfs(dep+1);
}

void che12()
{
	for(int k=1;k<=m;k++)
	{
		if(v[k]=='+')
			g[i[k]]=g[j[k]];
		else if(v[k]=='-')
			g[i[k]]=oppo(g[j[k]]);
		else
			g[i[k]]=v[k];
	}
	int cnt=0;
	bool pd=0;
	for(int k=1;k<=n;k++)
	{
		if(g[k]!=h[k])
		{
			pd=1;
			g[k]=h[k];
		}
		else if(g[k]=='U') cnt++;
	}
	if(!pd) ans=min(ans,cnt);
}

int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	cin>>c>>t;
	if(c==1 || c==2)
	{
		for(int k=1;k<=t;k++)
		{
			cin>>n>>m;
			for(int l=1;l<=m;l++)
			{
				cin>>v[l];
				if(v[l]=='+' || v[l]=='-') cin>>i[l]>>j[l];
				else cin>>i[l];
			}
			ans=0x3f3f3f3f;
			dfs(1);
			cout<<ans<<endl;
		}
	}
	else if(c==3 || c==4)
	{
		for(int k=1;k<=t;k++)
		{
			cin>>n>>m;
			for(int l=1;l<=m;l++)
			{
				char a;
				int b;
				cin>>a>>b;
				g[b]=a;
			}
			ans=0;
			for(int l=1;l<=n;l++)
				if(g[l]=='U')
					ans++;
			cout<<ans<<endl;
		}
	}
	return 0;
}