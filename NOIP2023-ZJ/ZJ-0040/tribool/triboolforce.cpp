#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=(l),i##_end=(r);i<i##_end;++i)
using namespace std;
constexpr int N=1e5+5;
int neg(int a){return a^(3*!!a);}
int tt,ans,n,m,pa[N][2],a[N],b[N];
char op[N];
bool check()
{
	F(i,0,n)b[i]=a[i];
	F(i,0,m)
	{
		if(op[i]=='+')b[pa[i][0]]=b[pa[i][1]];
		if(op[i]=='-')b[pa[i][0]]=neg(b[pa[i][1]]);
		if(op[i]=='U')b[pa[i][0]]=0;
		if(op[i]=='T')b[pa[i][0]]=1;
		if(op[i]=='F')b[pa[i][0]]=2;
	}
	F(i,0,n)if(b[i]!=a[i])return false;
	return true;
}
void dfs(int i,int cost)
{
	if(cost>=ans)return;
	if(i==n)
	{
		if(check())ans=cost;
		return;
	}
	a[i]=1;
	dfs(i+1,cost);
	a[i]=2;
	dfs(i+1,cost);
	a[i]=0;
	dfs(i+1,cost+1);
}
int main()
{
	scanf("%*d%d",&tt);
	while(tt--)
	{
		scanf("%d%d",&n,&m);
		F(i,0,m)
		{
			scanf(" %c",&op[i]);
			scanf("%d",&pa[i][0]),--pa[i][0];
			if(op[i]=='+'||op[i]=='-')scanf("%d",&pa[i][1]),--pa[i][1];
		}
		ans=n+1;
		dfs(0,0);
		if(ans==n+1)ans=-1;
		printf("%d\n",ans);
	}
	return 0;
}
