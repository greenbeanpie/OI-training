#include<bits/stdc++.h>
using namespace std;
const long long MAXN=1e3+10,INF=1e18;
long long C,t,n,m,k,d,tmpx,tmpy,tmpv,ans;
long long f[MAXN][MAXN],now,w;
struct dat{
	long long x,v;
}tmp;
vector<dat> e[MAXN];
long long read()
{
	long long x=0;
	char ch=getchar();
	while(!('0'<=ch&&ch<='9')) ch=getchar();
	while('0'<=ch&&ch<='9')
		x=x*10+ch-'0',ch=getchar();
	return x;
}
bool cmp(dat x,dat y)
{
	return x.x<y.x;
}
void subtask()
{
	while(t--)
	{
		n=read();m=read();k=read();d=read();
		ans=0;
		for(int i=1;i<=m;i++)
		{
			tmpx=read();tmpy=read();tmpv=read();
			ans+=max(0ll,tmpv-tmpy*d);
		}
		printf("%lld\n",ans);
	}
}
int main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	C=read();t=read();
	if(C==17||C==18)
	{
		subtask();
		return 0;
	}
	while(t--)
	{
		n=read();m=read();k=read();d=read();
		for(int i=1;i<=n;i++) e[i].clear();
		for(int i=1;i<=m;i++)
			tmpx=read(),tmpy=read(),tmpv=read(),
			tmp.x=tmpy,tmp.v=tmpv,
			e[tmpx].push_back(tmp);
		for(int i=1;i<=n;i++)
			sort(e[i].begin(),e[i].end(),cmp);
		memset(f,0xc0,sizeof(f));
		f[0][0]=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=k;j++)
				f[i][j]=f[i-1][j-1]-d;
			for(int j=0;j<=k;j++) f[i][0]=max(f[i][0],f[i-1][j]);
			w=0;now=0;
			for(int j=1;j<=k;j++)
			{
				while(w<e[i].size()&&e[i][w].x==j)
					now+=e[i][w].v,w++;
				f[i][j]+=now;
			}
		}
		ans=-INF;
		for(int i=0;i<=k;i++) ans=max(ans,f[n][i]);
		printf("%lld\n",ans);
	}
	return 0;
}