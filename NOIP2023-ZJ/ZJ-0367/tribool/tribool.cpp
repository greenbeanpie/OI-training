#include <bits/stdc++.h>
using namespace std;
const int t=1e9-1,f=1e9,u=1e9+1;
int c,T,n,x,y,m,i,a[100001],ans;
char ch;
bool b[100001],b1[100001],bo;
void huan(int x)
{
	if (b1[x]) return;
	b1[x]=1;
	if (a[x]<0) bo=1-bo,huan(-a[x]);else huan(a[x]);
}
void dfs(int x)
{
	if (a[x]>=t) return;
	if (b[x]) 
	{
		bo=1;
		huan(x);
		if (bo) a[x]=t;else a[x]=u;
		return;
	}
	b[x]=1;
	int xx=abs(a[x]),fuhao;
	if (xx==a[x]) fuhao=1;else fuhao=0;
	dfs(xx);
	if (a[xx]==t) if (fuhao) a[x]=t;else a[x]=f;else
	if (a[xx]==f) if (fuhao) a[x]=f;else a[x]=t;else
	if (a[xx]==u) a[x]=u;
}
int main()
{
	freopen("tribool.in","r",stdin);freopen("tribool.out","w",stdout);
	cin>>c>>T;
	while (T--)
	{
		cin>>n>>m;
		for (i=1;i<=n;i++) a[i]=i,b[i]=0,b1[i]=0;
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
				if (a[y]<t) a[x]=-a[y];else
				{
					if (a[y]==t) a[x]=f;
					if (a[y]==f) a[x]=t;
					if (a[y]==u) a[x]=u;
				}
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
			if (a[i]<t) dfs(i);
		ans=0;
		for (i=1;i<=n;i++) if (a[i]==u) ans++;
		cout<<ans<<endl;
	}
	return 0;
}