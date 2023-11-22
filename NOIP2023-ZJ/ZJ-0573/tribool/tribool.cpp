#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;

int c,t;
int n,m;

int b[N];
int sum;
int ans;

struct node
{
	int step;
	int x,y;
}a[N];

int change(int x,int type)
{
	if(x==3)
		return 3;
	if(type==4)
		return x;
	else
		return 3-x;
}

bool judge()
{
	int c[N];
	for(int i=1;i<=n;i++)
		c[i]=b[i];
	for(int i=1;i<=m;i++)
	{
		if(a[i].step==1)
			c[a[i].x]=1;
		else if(a[i].step==2)
			c[a[i].x]=2;
		else if(a[i].step==3)
			c[a[i].x]=3;
		else if(a[i].step==4)
			c[a[i].x]=change(c[a[i].y],4);
		else if(a[i].step==5)
			c[a[i].x]=change(c[a[i].y],5);
	}
	for(int i=1;i<=n;i++)
		if(c[i]!=b[i])
			return false;
	return true;
}

void dfs(int now)
{
	if(now==n+1)
	{
		if(judge())
		{
			ans=min(ans,sum);
		}
		return;
	}
	for(int i=1;i<=3;i++)
	{
		b[now]=i;
		if(i==3)
			sum++;
		if(sum<ans)
			dfs(now+1);
		if(i==3)
			sum--;
	}
	return;
}

int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		ans=0x7fffffff;
		sum=0;
		cin>>n>>m;
		for(int i=1;i<=m;i++)
		{
			char x;
			cin>>x;
			if(x=='+')
			{
				int y,z;
				cin>>y>>z;
				a[i].step=4;
				a[i].x=y,a[i].y=z;
			}
			else if(x=='-')
			{
				int y,z;
				cin>>y>>z;
				a[i].step=5;
				a[i].x=y,a[i].y=z;
			}
			else if(x=='T')
			{
				int y;
				cin>>y;
				a[i].step=1;
				a[i].x=y;
			}
			else if(x=='F')
			{
				int y;
				cin>>y;
				a[i].step=2;
				a[i].x=y;
			}
			else if(x=='U')
			{
				int y;
				cin>>y;
				a[i].step=3;
				a[i].x=y;
			}
		}
		dfs(1);
		cout<<ans<<endl;
	}	
	return 0;
}
