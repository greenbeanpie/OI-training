// Navia you take me away
//freopen
#include<bits/stdc++.h>
using namespace std;
int c,t,n,m;
int curval[200010],vis[200010],fa[200010],bad[200010];
vector<int> e[200010];
char opt[11];
int get(int x)
{
	return x==fa[x]?x:fa[x]=get(fa[x]);
}
void merge(int x,int y)
{
	x=get(x);y=get(y);
	if(x!=y)
		fa[x]=y;
}
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);	
		for(int i=1;i<=n;i++)
			curval[i]=i,e[i].clear(),vis[i]=0,fa[i]=i,fa[i+n]=i+n,bad[i]=bad[i+n]=0;
		for(int i=1;i<=m;i++)
		{
			int x,y;
			scanf("%s",opt);
			if(opt[0]=='+')
			{
				scanf("%d%d",&x,&y);
				curval[x]=curval[y];
			}
			else if(opt[0]=='-')
			{
				scanf("%d%d",&x,&y);
				curval[x]=-curval[y];
			}
			else if(opt[0]=='T')
			{
				scanf("%d",&x);
				curval[x]=n+1;
			}
			else if(opt[0]=='F')
			{
				scanf("%d",&x);
				curval[x]=-(n+1);
			}
			else 
			{
				scanf("%d",&x);
				curval[x]=0;
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(curval[i]>=1&&curval[i]<=n)
			{
				merge(i,curval[i]);
				merge(i+n,curval[i]+n);
			}
			else if(curval[i]>=-n&&curval[i]<=-1)
			{
				int t=-curval[i];
				merge(i,t+n);
				merge(t,i+n);
			}
		}
		for(int i=1;i<=n;i++)
			if(get(i)==get(i+n)||curval[i]==0)
				bad[get(i)]=bad[get(i+n)]=1;
		int ans=0;
		for(int i=1;i<=n;i++)
			if(bad[get(i)]||bad[get(i+n)])
				ans++;
		printf("%d\n",ans);
	}
}
