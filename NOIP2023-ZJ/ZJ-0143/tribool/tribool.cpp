#include<bits/stdc++.h>
#define maxn 500005
using namespace std;
int zyp[maxn],ans,n,m,lst[maxn],tot,fa[maxn];
int ac[maxn];
int find(int x)
{
	if(x==fa[x]) return x;
	int r=find(fa[x]);
	ac[x]^=ac[fa[x]];
	fa[x]=r;
	return r;
}
void merge(int x,int y,int op)
{
	int r1=find(x);
	int r2=find(y);
	ac[r1]=op^ac[x]^ac[y];
	if(zyp[r1]==1 || zyp[r1]==0) zyp[r2]=zyp[r1]^ac[r1];
	else if(zyp[r1]==2) zyp[r2]=2;
	fa[r1]=r2;
}
void clear()
{
	ans=0;
	for(int i=1;i<=tot;i++) ac[i]=0,fa[i]=i,zyp[i]=-1;
	tot=0;
}
void solve()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)lst[i]=i,fa[i]=i;
	tot=n;
	while(m--){
		char op;
		int u,v;
		cin>>op;
		if(op=='+' || op=='-')
		{
			scanf("%d%d",&u,&v);
			if(u==v)
			{
				++tot;
				fa[tot]=tot;
				merge(lst[u],tot,(op=='-'));
				lst[u]=tot;
				continue;
			}
			lst[u]=++tot;
			fa[tot]=tot;
			merge(lst[u],lst[v],(op=='-'));
		}
		else
		{
			scanf("%d",&u);
			lst[u]=++tot;
			fa[tot]=tot;
			if(op=='T') zyp[tot]=0;
			if(op=='F') zyp[tot]=1;
			if(op=='U') zyp[tot]=2;
		}
	}
	for(int i=1;i<=n;i++)
	{
		int r1=find(lst[i]),r2=find(i);
		if(r1!=r2) merge(i,lst[i],0);
	}
	for(int i=1;i<=n;i++)
	{
		int r1=find(lst[i]),r2=find(i);
		if(r1==r2 && ac[lst[i]]!=ac[i]) zyp[r1]=2;
	}
	for(int i=1;i<=n;i++)
	{
		int r=find(lst[i]);
		if(zyp[r]==2) ans++;
	}
	printf("%d\n",ans);
}
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	memset(zyp,-1,sizeof(zyp));
	int T,_;
	scanf("%d%d",&_,&T);
	while(T--)
	{
		clear();
		solve();
	}
}
