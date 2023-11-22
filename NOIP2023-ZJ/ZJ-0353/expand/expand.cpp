#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int c,n,m,q;
long long f[N],g[N];
long long f1[N],g1[N];
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%d%d%d%d",&c,&n,&m,&q);
	for(int i=1;i<=n;i++)
		scanf("%lld",&f[i]);
	for(int i=1;i<=m;i++)
		scanf("%lld",&g[i]);
	if(c<=2)
	{
		cout<<((f[1]-g[1])*(f[n]-g[m])>0);
		for(int i=1;i<=q;i++)
		{
			for(int j=1;j<=n;j++)
				f1[j]=f[j];
			for(int j=1;j<=m;j++)
				g1[j]=g[j];
			int a,b;
			scanf("%d%d",&a,&b);
			for(int j=1;j<=a;j++)
			{
				long long x,y;
				scanf("%lld%lld",&x,&y);
				f1[x]=y;
			}
			for(int j=1;j<=b;j++)
			{
				long long x,y;
				scanf("%lld%lld",&x,&y);
				g1[x]=y;
			}
			printf("%d",((f1[1]-g1[1])*(f1[n]-g1[m])>0));
		}
		puts("");
	}
}
