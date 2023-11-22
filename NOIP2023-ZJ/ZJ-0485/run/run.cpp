#include <stdio.h>
#include <algorithm>
using namespace std;
struct xyz{int a,b,c;}h[200000];
bool mcp(xyz n,xyz m)
{
	return n.a<m.a;
}
long long a[1000][1000],l;
int main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	int b,c,d,e,f,g;
	scanf("%d%d",&b,&c);
	while(c--)
	{
		scanf("%d%d%d%d",&d,&e,&f,&g);
		for(int i=0;i<e;i++){scanf("%d%d%d",&h[i].a,&h[i].b,&h[i].c);
		}
		sort(h,h+e,mcp);
		l=0;
		for(int i=1;i<=d;i++)
		{
			for(int j=0;j<=f && j<i;j++)a[i][0]=max(a[i-1][j],a[i][0]);
			for(int j=1;j<=f && j<=i;j++)
			{
				a[i][j]=a[i-1][j-1]-g;
			}
			while(l<e && h[l].a==i)
			{
				for(int j=h[l].b;j<=f;j++)a[i][j]+=h[l].c;
				l++;
			}
		}
		l=a[d][0];
		for(int j=1;j<=f;j++)l=max(l,a[d][j]);
		printf("%lld\n",l);
		if(c)
		for(int i=0;i<=d;i++)
		{
			for(int j=0;j<=f;j++)a[i][j]=0;
		}
	}
	return 0;
}
