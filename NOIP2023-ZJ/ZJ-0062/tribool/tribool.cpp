#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int a[N],n,m,w[N],ty[N];
bool g[N],ins[N];
char ch[10];
void dfs(int u)
{
	int v,l;ins[u] = g[u] = 1;
	if(a[u] > 0) v = a[u],l = 0;
	else v = -a[u],l = 1;
	//cout<<u<<" "<<v<<" "<<l<<"\n";
	if(g[v])
	{
		if(ins[v])
		{
			ty[u] = w[u]^w[v]^l;
		}
		else
		{
			ty[u] = ty[v];
		}
	}
	else
	{
		w[v] = w[u]^l;
		dfs(v);
		ty[u] = ty[v];
	}
	ins[u] = 0;
}
void solve()
{
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n+2;i++) a[i] = i,g[i] = ty[i] = ins[i] = 0;
	a[n+2] = -n-2;
	for(int i = 1;i <= m;i++)
	{
		scanf("%s",ch+1);
		int x,y;
		if(ch[1] == '+')
		{
			scanf("%d%d",&x,&y);
			a[x] = a[y];
		}
		else if(ch[1] == '-')
		{
			scanf("%d%d",&x,&y);
			a[x] = -a[y];
		}
		else
		{
			scanf("%d",&x);
			if(ch[1] == 'U') a[x] = n+2;
			if(ch[1] == 'T') a[x] = n+1;
			if(ch[1] == 'F') a[x] = -n-1;
		}
	}
	for(int i = 1;i <= n+2;i++)
		if(!g[i]) dfs(i);
	int ans = 0;
	for(int i = 1;i <= n;i++) ans += ty[i];
	printf("%d\n",ans);
}
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	int C,T;scanf("%d%d",&C,&T);
	while(T--) solve();
	return 0;
}