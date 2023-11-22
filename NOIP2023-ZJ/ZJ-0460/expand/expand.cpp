#include<bits/stdc++.h>
using namespace std;
int c,n,m,q;
int x[10],y[10];
string ans="";
char pd(void)
{
	if(n==1&&m==1)
	{
		if(x[1]!=y[1]) return '1';
		else return '0';
	}
	else if(n==2&&m==2)
	{
		if((x[1]-y[1])*(x[2]-y[2])>0) return '1';
		else return '0';
	}
	else if(n==1&&m==2)
	{
		if((x[1]-y[1])*(x[1]-y[2])>0) return '1';
		else return '0';
	}
	else if(n==2&&m==1)
	{
		if((x[1]-y[1])*(x[2]-y[1])>0) return '1';
		else return '0';
	}
	return char(rand()%2+'0');
}
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%d%d%d%d",&c,&n,&m,&q);
	for(int i=1;i<=n;i++) scanf("%d",&x[i]);
	for(int i=1;i<=m;i++) scanf("%d",&y[i]);
	ans+=pd();
	while(q--)
	{
		int k1,k2,p,v;
		scanf("%d%d",&k1,&k2);
		while(k1--)
		{
			scanf("%d%d",&p,&v);
			x[p]=v;
		}
		while(k2--)
		{
			scanf("%d%d",&p,&v);
			y[p]=v;
		}
		ans+=pd();
	}
	cout<<ans<<'\n';
	return 0;
}
