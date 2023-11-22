#include<bits/stdc++.h>
using namespace std;
int x[100000],y[100000],z[100000],maxn=2;
int c,t,n,m,k,d;
void dfs(int s,int day,int all)
{
	if(s>maxn)
		maxn=s;
	for(int i=1;i<=m;i++)
	{
		if(x[i]>day&&x[i]-day+all+1<k)
		{
			dfs(s-d*(x[i]-day)+z[i],x[i],x[i]-day+all);
		}
	}
}
int main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n>>m>>k>>d;
		for(int j=1;j<=m;j++)
		{
			cin>>x[j]>>y[j]>>z[j];
		}
		dfs(0,0,0);
		cout<<maxn;
	}
	return 0;
}

