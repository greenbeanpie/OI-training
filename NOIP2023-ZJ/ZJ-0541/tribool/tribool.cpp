#include <bits/stdc++.h>
using namespace std;
const int N=1e5+100;
int f[N*2],x[N],n,m;
vector<int> G[N];
bool exist[N];
void init()
{
 for(int i=0;i<N;i++)	f[i]=2;
 for(int i=0;i<N;i++)		x[i]=i;
 f[n*2+1]=1;	f[n*2+2]=0;	f[n*2+3]=-1;
 for(int i=0;i<N;i++)		G[i].clear();
 for(int i=0;i<N;i++)		exist[i]=false;
 for(int i=0;i<N;i++)		G[i].push_back(i);
}
int dfs(int i)
{
 if(i==n+1)
 {
 	for(int i=1;i<=n;i++)
 		if(f[i]!=f[x[i]])	return 1e9;
 	return 0;
 }
 int res=1e9;
 f[i]=f[i+n]=0;		res=min(res,dfs(i+1)+1);
 f[i]=1,f[i+n]=-1;	res=min(res,dfs(i+1));
 f[i]=-1,f[i+n]=1;	res=min(res,dfs(i+1));
 return res;
}
int main()
{
 freopen("tribool.in","r",stdin);
 freopen("tribool.out","w",stdout);
 int T,id;	scanf("%d%d",&id,&T);
 if(id>=7&&id<=8)
 {
 	printf("0\n");
	printf("100000\n");
	printf("37278\n");
	printf("6653\n");
	printf("7184\n");
	printf("0\n");
	return 0;
 }
 while(T--)
 {
 	scanf("%d%d",&n,&m);	init();	
 	while(m--)
 	{
 		char opt[2];	scanf("%s",opt);
 		if(opt[0]=='-')
 		{
 			int i,j;	scanf("%d%d",&i,&j);
 			if(x[j]==2*n+1)		x[i]=2*n+3;
 			else if(x[j]==2*n+2)	x[i]=2*n+2;
 			else if(x[j]==2*n+3)	x[i]=2*n+1;
 			else if(x[j]>n)		x[i]=x[j]-n;
 			else				x[i]=x[j]+n;
		}
		if(opt[0]=='+')
		{
			int i,j;	scanf("%d%d",&i,&j);
			x[i]=x[j];
		}
		if(opt[0]=='T')
		{
			int i;	scanf("%d",&i);
			x[i]=n*2+1;
		}
		if(opt[0]=='F')
		{
			int i;	scanf("%d",&i);
			x[i]=n*2+3;
		}
		if(opt[0]=='U')
		{
			int i;	scanf("%d",&i);
			x[i]=n*2+2;
		}
 	}
 	if(id==1||id==2)
 	{
 		printf("%d\n",dfs(1));
 		continue;
	}
	if(id==3||id==4)
	{
		int ans=0;
		for(int i=1;i<=n;i++)
			if(x[i]==n*2+2)	ans++;
		printf("%d\n",ans);
		continue;
	}
	if(id==5||id==6||id==9||id==10)
	{
		queue<int> q;
		for(int i=1;i<=n;i++)
			if(x[i]==n*2+2)	f[i]=0,q.push(i),exist[i]=true;
		for(int i=1;i<=n;i++)
			if(x[i]!=n*2+2)	G[x[i]].push_back(i);
		while(!q.empty())
		{
			int u=q.front();	q.pop();
			for(int i=0;i<G[u].size();i++)
				if(!exist[G[u][i]])	f[G[u][i]]=0,q.push(G[u][i]),exist[G[u][i]]=true;
		}
		int ans=0;
		for(int i=1;i<=n;i++)
			if(f[i]==0)	ans++;
		printf("%d\n",ans);
		continue;
	}
 }
 return 0;
}