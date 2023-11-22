#include<bits/stdc++.h>
using namespace std;
struct node
{
	char tmp[3005];
}a[6005];
int n,m;
bool cmp(node x,node y)
{
	for(int i=1;i<=m;i++)
	{
		if(x.tmp[i]!=y.tmp[i])
		{
			return x.tmp[i]<y.tmp[i];
		}
	}
	return true;
}
int main ()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("\n");
		for(int j=1;j<=m;j++)
		{
			a[i].tmp[j]=getchar();
		}
		sort(a[i].tmp+1,a[i].tmp+m+1);
		for(int j=1;j<=m;j++)
		{
			a[i+n].tmp[j]=a[i].tmp[m-j+1];
		}
	}
	node mn=a[n+1];
	for(int i=n+2;i<=2*n;i++)
	{
		if(cmp(a[i],mn))
		{
			mn=a[i];
		}
	}
	for(int i=1;i<=n;i++)
	{
		printf("%d",cmp(a[i],mn));
	}
}