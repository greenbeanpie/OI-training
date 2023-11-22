#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e5+10;
int c,T,n,m,ans;
int v[M],nw[M];
struct Node
{
	char op[2];
	int x,y;
}q[M];
void solve1()
{
	for(int i=1;i<=n;++i)nw[i]=v[i];
	for(int i=1;i<=m;++i)
	{
		if(q[i].op[0]=='+')nw[q[i].x]=nw[q[i].y];
		else if(q[i].op[0]=='-')
		{
			if(nw[q[i].y]==2)nw[q[i].x]=2;
			else nw[q[i].x]=nw[q[i].y]^1;
		}
		else
		{
			if(q[i].op[0]=='U')nw[q[i].x]=2;
			if(q[i].op[0]=='T')nw[q[i].x]=1;
			if(q[i].op[0]=='F')nw[q[i].x]=0;
		}
	}
	int cnt=0;
	for(int i=1;i<=n;++i)if(v[i]!=nw[i])return;
	for(int i=1;i<=n;++i)if(v[i]==2)++cnt;
	ans=min(ans,cnt);
}
void dfs(int x)//0->F 1->T 2->U 
{
	if(x>n){solve1();return;}
	for(int i=0;i<=2;++i)
	{
		v[x]=i;
		dfs(x+1);
	}
}
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	scanf("%d%d",&c,&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;++i)
		{	
			scanf("%s",q[i].op);
			if(q[i].op[0]=='+'||q[i].op[0]=='-')
				scanf("%d%d",&q[i].x,&q[i].y);
			else scanf("%d",&q[i].x);
		}
		ans=0x3f3f3f3f;
		if((c==1||c==2)&&n<=10&&m<=10)
		{
			dfs(1);
			printf("%d\n",ans);
			continue;
		}
		if(c==3||c==4)
		{
			for(int i=1;i<=n;++i)v[i]=-1;
			for(int i=1;i<=m;++i)
			{
				if(q[i].op[0]=='U')v[q[i].x]=2;
				if(q[i].op[0]=='T')v[q[i].x]=1;
				if(q[i].op[0]=='F')v[q[i].x]=0;
			}
			ans=0;
			for(int i=1;i<=n;++i)if(v[i]==2)++ans;
			printf("%d\n",ans);continue;
		}
		printf("0\n");
	}
	return 0;
}
