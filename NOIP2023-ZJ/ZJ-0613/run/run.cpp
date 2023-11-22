#include <bits/stdc++.h>
using namespace std;
int c,t,len,k,d,m,n;
struct node{int l,r,val,ls;}cha[100005];
typedef long long ll;
ll maxn;
bool cmp(node x,node y)
{
	if(x.r==y.r) return x.val>y.val;
	else return x.r<y.r;
}
int read()
{
	char s=getchar();
	int ans=0;
	while('0'<=s && '9'>=s)
	{
		ans=ans*10+(s-'0');
		s=getchar();
	}
	return ans;
}
void dfs(int ti,int si,ll ans)
{
	if(ti>n)
	{
		maxn=max(maxn,ans);
		return;
	}
	for(int i=1;i<=m;i++)
	{
		if(cha[i].r==ti && si<=k &&si>=cha[i].ls)
			ans+=cha[i].val;
	}	
	if(si+1<=k)
	{
		dfs(ti+1,si+1,ans-d);
		dfs(ti+1,0,ans);
	}
	else
	{
		dfs(ti+1,0,ans);
	}
	
}
int main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	c=read();t=read();
	for(;t>=1;t--)
	{
		memset(cha,0,sizeof(cha));
		ll x,y,z,sum1=0,sum2=0;
		len=1,k=0;
		n=read();m=read();k=read();d=read();
		for(int i=1;i<=m;i++)
		{
			x=read();y=read();z=read();
			cha[i].l=x-y+1;
			cha[i].r=x;
			cha[i].val=z;
			cha[i].ls=y;
		}
		len-=1;
		if(c==17 || c==18)
		{
			ll ans=0;
			for(int i=1;i<=m;i++)
			{
				ll cost=cha[i].ls*d;
				if(cha[i].ls>k){continue;}
				if(cost>cha[i].val){continue;}
				ans+=cha[i].val-cost;
			}
			cout<<ans<<endl;
		}
		else
		{
			sort(cha+1,cha+m+1,cmp);
			dfs(1,1,0-d);
			dfs(1,0,0);
			cout<<maxn<<endl;
		}
	}
	return 0;
}