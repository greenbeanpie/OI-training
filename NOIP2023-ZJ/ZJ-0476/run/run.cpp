#include<bits/stdc++.h>
#define ll long long
#define N 100005
using namespace std;
int n,m,a[N];
int k,t,d;
int x[N],y[N],v[N];
int op;
ll Max;
bool check()
{
	int sumrun=0;
	for (int i=1;i<=n;i++)
	{
		if (a[i]) sumrun+=1;
		else{
			if (sumrun>k) return false;
			sumrun=0;
		}
		//cout<<sumrun;
	}
	//cout<<endl;
	if (sumrun>k) return false;
	return true;
}
long long calc()
{
	ll kkkkk=0;
	int sumrun=0;
	for (int i=1;i<=n;i++)
	{
		if (a[i]) kkkkk-=d,sumrun+=1;
		else sumrun=0;
		for (int j=1;j<=m;j++)
			if (x[j]==i&&y[j]<=sumrun) kkkkk+=v[j];
	}
	//cout<<kkkkk<<"RP++"<<endl;
	return kkkkk;
}
void dfs(int day)
{
	if (day==n)
	{
		if (!check()) return ;
		ll sum=calc();
		Max=max(sum,Max);
		return ;
	}
	a[day+1]=true;
	dfs(day+1);
	a[day+1]=false;
	dfs(day+1);
	return ;
}
int main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	scanf("%d%d",&op,&t);
	while (t>0)
	{
		Max=-52020231118122703;
		scanf("%d%d%d%d",&n,&m,&k,&d);
		for (int i=1;i<=m;i++)
		{
			scanf("%d%d%d",&x[i],&y[i],&v[i]);
		}
		dfs(0);
		cout<<Max<<endl;
		t--;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
