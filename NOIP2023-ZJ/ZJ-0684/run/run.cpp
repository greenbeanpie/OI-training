#include<bits/stdc++.h>
using namespace std;
int n,k,m,d;
struct poin{
	int y,v;
}a[100010];
bool b[100010];
long long ans;
void dfs(int nw,long long en,int co)
{
	if(co>k) return;
	else if(nw>n)
	{
		ans=max(ans,en);
		return ;
	}
	if(b[nw])
	{
		if(co+1>=a[nw].y)  dfs(nw+1,en+a[nw].v-d,co+1); 
	}	
	else dfs(nw+1,en-d,co+1);
	dfs(nw+1,en,co);
	return ;
}
int main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	int T,c;
	cin>>c>>T;
	while(T--)
	{
		cin>>n>>m>>k>>d;
		ans=n*d*(-1);
		for(int i=1;i<=m;i++)
		{
			int t;
			cin>>t;
			cin>>a[t].y>>a[t].v;
			b[t]=1;
		}
		dfs(0,0,0);
		cout<<ans<<endl;
	}
	return 0;
}
