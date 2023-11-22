#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ms(x,y) memset(x,y,sizeof(x))
const int M=314514;
char op[M][4],x[M],y[M];
int res[M],p[M];
int ans=0x3f3f3f3f;
int n,m;
void calc()
{
	for(int i=1;i<=n;i++) res[i]=p[i];
	for(int i=1;i<=m;i++)
	{
		if(op[i][0]=='U') res[x[i]]=2;
		else if(op[i][0]=='T') res[x[i]]=1;
		else if(op[i][0]=='F') res[x[i]]=0;
		else if(op[i][0]=='+') res[x[i]]=res[y[i]];
		else res[x[i]]=(res[y[i]]==2)?(2):(res[y[i]]^1);
	}
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		cnt+=(res[i]==2);
		if(res[i]!=p[i]) return;
	}
	ans=min(ans,cnt);
}
void dfs(int i)
{
	if(i>n) {calc();return;}
	p[i]=0,dfs(i+1);
	p[i]=1,dfs(i+1);
	p[i]=2,dfs(i+1);
}
int f[M];
int Find(int x) {return (f[x]==x)?(f[x]):(f[x]=Find(f[x]));}
void Union(int x,int y) {f[Find(x)]=Find(y);}
bool vis[M];
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	int C,T;
	scanf("%d%d",&C,&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		ans=0x3f3f3f3f;
//		cout<<T<<" "<<C<<"\n";
		for(int i=1;i<=m;i++)
		{
			scanf("%s",op[i]);
			if(op[i][0]=='-'||op[i][0]=='+') scanf("%d%d",&x[i],&y[i]);
			else scanf("%d",&x[i]),y[i]=x[i];
		}
		if(C<=2)
		{
			dfs(1);
			cout<<ans<<"\n";
		}
		else if(C<=4)
		{
			ms(res,-1);
			int ans=0;
			for(int i=m;i>=1;i--)
			{
				if(res[x[i]]!=-1) continue;
				if(op[i][0]=='U') ans++;
				res[x[i]]=1;
			}
			cout<<ans<<"\n";
		}
		else cout<<"0\n";
	}
	return 0;
}
