#include<bits/stdc++.h>
#define re register
using namespace std;
const int N=1e5+10;
int c,t,n,m,sum,fa[N],a[N];
inline int find(int x)
{
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
inline void solve34()
{
	for(re int i=1;i<=t;i++)
	{
		sum=0;
		scanf("%d%d",&n,&m);
		for(re int j=1;j<=m;j++)
		{
			int x;
			char ch;
			cin>>ch;
			if(ch=='U')
			{
				scanf("%d",&x);
				sum++;
			}
			else scanf("%d",&x);
		}
		printf("%d\n",sum);
	}
}
inline void solve56()
{
	for(re int i=1;i<=t;i++)
	{
		scanf("%d%d",&n,&m);
		memset(a,0,sizeof a);
		sum=0;
		for(re int j=1;j<=n;j++)fa[j]=j;
		for(re int j=1;j<=m;j++)
		{
			int u,v;
			char ch;
			cin>>ch;
			if(ch=='U')
			{
				scanf("%d",&u);
				a[u]=1;
			}
			else
			{
				scanf("%d%d",&u,&v);
				fa[find(u)]=find(v);
			}
		}
		for(re int j=1;j<=n;j++)if(a[j]==1)a[fa[j]]=a[j];
		for(re int j=1;j<=n;j++)sum+=(a[fa[j]]==1);
		printf("%d\n",sum);
	}
}
int main()
{
    freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	scanf("%d%d",&c,&t);
	if(c==3||c==4)solve34();
	if(c==5||c==6)solve56();
	return 0;
}
