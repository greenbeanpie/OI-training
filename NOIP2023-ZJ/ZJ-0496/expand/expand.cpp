#include<bits/stdc++.h>


using namespace std;
const int N=4e4+10;
int c,n,m,q;
int a[N],b[N];
int aa[N],bb[N];
int pa[N],pb[N];
int dp[2020][2020];
int fu;
int dfs(int x,int y)
{
//	printf("%d %d\n",x,y);
	if(dp[x][y]!=-1) return dp[x][y];
	if(x>n||y>m) return 0;
	if(x==n&y==m) return 1;
	int fl=0;
	if(a[x+1]*fu<b[y]*fu ) fl|=dfs(x+1,y);
	if(a[x]*fu<b[y+1]*fu ) fl|=dfs(x,y+1);
	if(a[x+1]*fu<b[y+1]*fu ) fl|=dfs(x+1,y+1);
	return dp[x][y]=fl;
}


int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%d%d%d%d",&c,&n,&m,&q);
	memset(dp,-1,sizeof(dp));
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d",b+i);
	}
	fu=(a[1]<b[1] ? 1:-1);
	
	
//	for(int i=1;i<=n;i++)
//	{
//		printf("%d ",a[i]);
//	}
//	puts("");
//	for(int i=1;i<=m;i++)
//	{
//		printf("%d ",b[i]);
//	}	
//	puts(" ");


	printf("%d",dfs(1,1));

	while(q--)
	{
		memset(dp,-1,sizeof(dp));
		int ka,kb;
		scanf("%d%d",&ka,&kb);
		for(int i=1;i<=ka;i++)
		{
			int p,v;
			scanf("%d%d",&p,&v);
			aa[i]=a[p];
			pa[i]=p;
			a[p]=v;
		}
		for(int i=1;i<=kb;i++)
		{
			int p,v;
			scanf("%d%d",&p,&v);
			bb[i]=b[p];
			pb[i]=p;
			b[p]=v;
		}
		
		
//		for(int i=1;i<=n;i++)
//		{
//			printf("%d ",a[i]);
//		}
//		puts("");
//		for(int i=1;i<=m;i++)
//		{
//			printf("%d ",b[i]);
//		}
//		puts(" ");


		fu=(a[1]<b[1] ? 1:-1);
		
		if(a[1]==b[1]) printf("0");
		else printf("%d",dfs(1,1));
		for(int i=1;i<=ka;i++)
		{
			a[pa[i]]=aa[i];
		}
		for(int i=1;i<=kb;i++)
		{
			b[pb[i]]=bb[i];
		}
	}
	
	
	return 0;
}



//zsy dalao orz
//sjh dalao orz
//lzy dalao orz
//大佬们保佑我
//骗分出省一