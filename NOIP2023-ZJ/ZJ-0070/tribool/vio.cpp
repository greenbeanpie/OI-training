#include<bits/stdc++.h>
using namespace std;
int C,T,n,m,fa[400005],cur[100005];
char met[15],fin[15];
struct ops{char v[2];int p,q;}a[100005];
int dfs(int cur,int cu)
{
	if(cur>n)
	{
		for(int i=1;i<=n;i++)fin[i]=met[i];
		for(int i=1;i<=m;i++)
		{
			int p=a[i].p,q=a[i].q;
			if(a[i].v[0]=='+')
				fin[p]=fin[q];
			else if(a[i].v[0]=='-')
			{
				if(fin[q]=='T')fin[p]='F';
				else if(fin[q]=='F')fin[p]='T';
				else if(fin[q]=='U')fin[p]='U';
			}
			else
				fin[p]=a[i].v[0];
		}
		bool flag=true;
		for(int i=1;i<=n;i++)
			if(fin[i]!=met[i])flag=false;
		//printf("%s %s\n",fin+1,met+1);
		if(flag)return cu;
		else return 0x3f3f3f3f;
	}
	met[cur]='T';
	int ret=dfs(cur+1,cu);
	met[cur]='F';
	ret=min(ret,dfs(cur+1,cu));
	met[cur]='U';
	ret=min(ret,dfs(cur+1,cu+1));
	return ret;
}
int main()
{
	//freopen("tribool2.in","r",stdin);
	//freopen("tribool.out","w",stdout);
	for(scanf("%d%d",&C,&T);T;T--)
	{
		scanf("%d%d",&n,&m);
		for(int i=0;i<=2*(n+m)+1;i++)
			fa[i]=i;
		for(int i=1;i<=n;i++)
			cur[i]=i;
		for(int i=1;i<=m;i++)
		{
			char v[2];
			scanf("%s",a[i].v);
			if(a[i].v[0]=='+' or a[i].v[0]=='-')
			{
				scanf("%d%d",&a[i].p,&a[i].q);
			}
			else
			{
				scanf("%d",&a[i].p);
			}
		}
		printf("%d\n",dfs(1,0));
	}
}