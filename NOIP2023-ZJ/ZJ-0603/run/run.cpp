#include<bits/stdc++.h>
using namespace std;
int n,m,k,d,Ans;
struct Node
{
	int x,v;
}b[2000];
void dfs(int t,int sum,int cnt)
{
	if(b[t-1].v!=0&&cnt>=b[t-1].x) 
	{
		sum+=b[t-1].v;
	}
	if(t>n+1)
	{
		Ans=max(Ans,sum);
		return;
	}
	if(cnt==k) dfs(t+1,sum,0);
	else
	{
		dfs(t+1,sum-d,cnt+1);
		dfs(t+1,sum,0);
	}
}
int main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	int c,q;
	cin>>c>>q;
	while(q--)
	{
		memset(b,0,sizeof(b));
		cin>>n>>m>>k>>d;
		Ans=-d*n;
		if(c==17||c==18) Ans=0;
		for(int i=1;i<=m;i++)
		{
			int xx,y,vv;
			cin>>xx>>y>>vv;
			if(c==17||c==18)
			{
				if(y<=k)
					Ans+=max(vv-y*d,0);
			}
			b[xx].x=y; b[xx].v=vv;
		}
		if(c==17||c==18) cout<<Ans<<'\n';
		else 
		{
			dfs(1,0,0);
			cout<<Ans<<'\n';
		}
	}
	fclose(stdin); fclose(stdout);
	return 0;
}