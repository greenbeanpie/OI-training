#include<bits/stdc++.h>
using namespace std;
int C,T,n,m,fa[400005],cur[100005];
int fath(int x)
{
	if(fa[x]!=x)fa[x]=fath(fa[x]);
	return fa[x];
}
int E(int x,char y)
{
	if(y=='F')return 2*x;
	else return 2*x+1;
}
void lnk(int x_1,char t_1,int x_2,char t_2)
{
	int p=fath(E(x_1,t_1)),q=fath(E(x_2,t_2));
	fa[p]=q;
}
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	for(scanf("%d%d",&C,&T);T;T--)
	{
		scanf("%d%d",&n,&m);
		for(int i=0;i<=2*(n+m)+1;i++)
			fa[i]=i;
		for(int i=1;i<=n;i++)
			cur[i]=i;
		for(int i=1;i<=m;i++)
		{
			char v[2];int p,q;
			scanf("%s",v);
			if(v[0]=='+')
			{
				scanf("%d%d",&p,&q);
				int lst=cur[q];
				cur[p]=n+i;
				lnk(cur[p],'T',lst,'T');
				lnk(cur[p],'F',lst,'F');
			}
			else if(v[0]=='-')
			{
				scanf("%d%d",&p,&q);
				int lst=cur[q];
				cur[p]=n+i;
				lnk(cur[p],'T',lst,'F');
				lnk(cur[p],'F',lst,'T');
			}
			else
			{
				scanf("%d",&p);
				cur[p]=n+i;
				if(v[0]=='U')
					lnk(cur[p],'T',cur[p],'F');
				else
					lnk(cur[p],v[0],0,v[0]);
			}
		}
		for(int i=1;i<=n;i++)
		{
			lnk(i,'T',cur[i],'T');
			lnk(i,'F',cur[i],'F');
		}
		int cu=0;
		for(int i=1;i<=n;i++)
		{
			if(fath(E(i,'T'))==fath(E(i,'F')))
				cu++;
		}
		printf("%d\n",cu);
	}
	return 0;
}