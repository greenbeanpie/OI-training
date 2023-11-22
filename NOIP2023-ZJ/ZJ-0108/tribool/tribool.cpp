#include<cstdio>
#include<vector>
#include<assert.h>
#include<algorithm>
int subt,t;
std::vector<int> vec;
int n,m,ans=0,pp[100005],g[100005],val[100005],c[100005],vis[100005];
/*
void del(int x)//del x
{
	g[x]=-1;
	val[x]=-2;
	c[x]=-1;
}
*/
void add(int x,int y,int opt)//add x to y(code:y<-x,upd y),opt=1:same,opt=-1:diff
{
//	printf("Add %d %d %d\n",x,y,opt);
	if (g[x]==-1)
	{
		if (val[x]!=-2) val[y]=(val[x]==-1?-1:(opt==1?val[x]:!val[x])),g[y]=-1,c[y]=-1;
		else g[y]=x,c[y]=(opt==1?1:0),val[y]=-2;
	}
	else g[y]=g[x],(opt==1?c[y]=c[x]:c[y]=!c[x]),val[y]=-2;//c=1:same,c=0:diff
}
char getopt()
{
	char ch=0;
	while (ch!='+'&&ch!='-'&&ch!='T'&&ch!='F'&&ch!='U') ch=getchar();
	return ch;
}
int dfs(int v,int now)
{
//	printf("dfs %d %d\n",v,now);
	if (pp[v])
	{
		if (!vis[v]||(g[v]==v&&(c[v]!=0||now==-1))) return (val[v]=now),1;
		else if (g[v]!=v&&val[v]==now) return 1;
		return 0;
	}
	vec.push_back(v);
	val[v]=now,pp[v]=1;
	return dfs(g[v],now!=-1?now^!c[v]:-1);
}
void clr(std::vector<int> vec)
{
	for (int i=0;i<(int)vec.size();i++) pp[vec[i]]=0,val[vec[i]]=-2;
}
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	scanf("%d%d",&subt,&t);
//	int cc=0;
	while (t--)
	{
//		printf("Testcase %d:\n",++cc);
		scanf("%d%d",&n,&m);
		for (int i=1;i<=n;i++) val[i]=-2,g[i]=-1,c[i]=-1;
		for (int i=1;i<=m;i++)
		{
			char opt=getopt();
//			printf("Type = %c\n",opt);
			//a_x<-a_y
			if (opt=='-')
			{
				int x,y;
				scanf("%d%d",&x,&y);
//				del(x);
				add(y,x,-1);
//				assert(x!=y);
				vis[x]=1;
			}
			else if (opt=='+')
			{
				int x,y;
				scanf("%d%d",&x,&y);
//				del(x);
				add(y,x,1);
//				assert(x!=y);
				vis[x]=1;
			}
			else if (opt=='T'||opt=='F'||opt=='U')
			{
				int x;
				scanf("%d",&x);
//				del(x);
				vis[x]=1;
				val[x]=(opt=='U'?-1:(opt=='T'));
				g[x]=-1,c[x]=-1;
			}
		}
		for (int i=1;i<=n;i++) if (g[i]==-1||g[i]==i) pp[i]=1;
		for (int i=1;i<=n;i++) assert(g[i]==-1||val[i]==-2);
//		for (int i=1;i<=n;i++) printf("%d:%d %d %d %d\n",i,vis[i],g[i],c[i],val[i]);
		for (int i=1;i<=n;i++)
		{
			if (pp[i]) continue;
			vec.clear();
			if (dfs(i,1)) continue;
			clr(vec);
			vec.clear();
			if (dfs(i,0)) continue;
			clr(vec);
			vec.clear();
			dfs(i,-1);
		}
		for (int i=1;i<=n;i++) assert(g[i]==-1||c[i]!=-1);
//		for (int i=1;i<=n;i++) assert(vis[i]==1||g[i]==-1);
		for (int i=1;i<=n;i++) if (!vis[i]&&val[i]==-2) val[i]=1;
		for (int i=1;i<=n;i++) if (g[i]==i&&val[i]==-2) c[i]==1?val[i]=1:val[i]=-1;
		for (int i=1;i<=n;i++) assert(val[i]!=-2);
		ans=0;
		for (int i=1;i<=n;i++) if (val[i]==-1) ++ans;
//		printf("Values:");for (int i=1;i<=n;i++) printf("%d ",val[i]);puts("");
		printf("%d\n",ans);
		for (int i=1;i<=n;i++) pp[i]=val[i]=g[i]=c[i]=vis[i]=0;
	}
	return 0;
}