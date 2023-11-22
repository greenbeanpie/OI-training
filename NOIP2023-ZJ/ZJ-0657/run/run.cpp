#include<bits/stdc++.h>
using namespace std;
int c,t,ans,a[21];
int n,m,k,d;
struct cha
{
	int x;
	int y;
	int z;
}qwq[210];
int Q()
{
	int sum=0,l,r;
	for(int i=1;i<=m;i++)
	{
		int fl=qwq[i].z;
		l=qwq[i].x-qwq[i].y+1,r=qwq[i].x;
		for(int j=l;j<=r;j++)
			if(!a[j])
			{
				fl=0;
				break;
			}
		sum+=fl;
	}
	return sum;
}
void dfs(int x,int sum,int len)
{
	if(x==n)
	{
		ans=max(ans,Q()-sum);
		//for(int i=1;i<=n;i++) cout<<a[i]<<" ";
		//cout<<endl<<ans<<" "<<Q()<<" "<<sum<<endl;
		return;
	}
	if(len<k) 
	{
		a[x+1]=1;
		dfs(x+1,sum+d,len+1);
	}
	a[x+1]=0;
	dfs(x+1,sum,0);
	
}
bool cmp(cha p,cha q)
{
	return p.x<q.x;
}
void solve()
{
	ans=-1e9;
	scanf("%d%d%d%d",&n,&m,&k,&d);
	for(int i=1;i<=m;i++)
	scanf("%d%d%d",&qwq[i].x,&qwq[i].y,&qwq[i].z);
	sort(qwq+1,qwq+1+m,cmp);
	dfs(0,0,0);
	printf("%d\n",ans);
}
int main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--)
	{
		solve();
	}
	return 0;
}
