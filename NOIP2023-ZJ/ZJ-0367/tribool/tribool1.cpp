#include <bits/stdc++.h>
using namespace std;
const int t=1e9-1,f=1e9,u=1e9+1;
int c,T,n,x,y,m,i,a[100001],ans;
char ch;
bool b[100001];
void dfs(int x,int fuhao)
{
	if (a[x]>=t) return;
	if (b[x]) 
	{
		if (!fuhao) a[x]=u;else a[x]=t;
		return;
	}
	b[x]=1;
	if (a[x]<0) a[x]=-a[x],fuhao=1-fuhao;
	dfs(a[x],fuhao);
	if (a[x]>=t) return;
	if (a[a[x]]==t) if (fuhao) a[x]=t;else a[x]=f;else
	if (a[a[x]]==f) if (fuhao) a[x]=f;else a[x]=t;else
	if (a[a[x]]==u) a[x]=u;
}
int main()
{
	freopen("tribool.in","r",stdin);freopen("tribool.out","w",stdout);
	cin>>c>>T;
	while (T--)
	{
		cin>>n>>m;
		for (i=1;i<=n;i++) a[i]=i,b[i]=0;
		for (i=1;i<=m;i++)
		{
			cin>>ch;
			if (ch=='+')
			{
				scanf("%d%d",&x,&y);
				a[x]=a[y];
			}
			if (ch=='-')
			{
				scanf("%d%d",&x,&y);
				a[x]=-a[y];
			}
			if (ch=='T')
			{
				scanf("%d",&x);
				a[x]=t;
			}
			if (ch=='F')
			{
				scanf("%d",&x);
				a[x]=f;
			}
			if (ch=='U')
			{
				scanf("%d",&x);
				a[x]=u;
			}
		}
		for (i=1;i<=n;i++) 
			if (a[i]<t) dfs(i,1);
		ans=0;
		for (i=1;i<=n;i++) if (a[i]==u) ans++;
		cout<<ans<<endl;
	}
	return 0;
}