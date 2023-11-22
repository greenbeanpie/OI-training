#include <bits/stdc++.h>
using namespace std;
const int t=1e9-1,f=1e9,u=1e9+1;
int c,T,n,x,y,m,i,a[100001],fa[100001],ans;
char ch;
bool b[100001],b1[100001],bo;
int zbb(int x)
{
	int zz=fa[x],xx;
	while (fa[zz]!=zz) zz=fa[zz];
	while (fa[x]!=zz) xx=fa[x],fa[x]=zz,x=xx;
	return zz;
}
void huan(int x)
{
	if (b1[x]) return;
	b1[x]=1;
	if (a[x]<0) bo=1-bo,huan(-a[x]);else huan(a[x]);
}
int main()
{
	freopen("tribool0.in","r",stdin);freopen("tribooltest.out","w",stdout);
	cin>>c>>T;
	while (T--)
	{
		cin>>n>>m;
		for (i=1;i<=n;i++) a[i]=i,fa[i]=i,b[i]=0,b1[i]=0;
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
		{
			if (a[i]<t && !b[i])
			{
				x=i;
				while (!b[x] && a[x]<t)
				{
					if (b[x]) 
					{
						bo=1;
						huan(x);
						if (bo) a[x]=t;else a[x]=u;
						break;
					}
					b[x]=1;
					int xx=abs(a[x]),fuhao;
					if (xx==a[x]) fuhao=1;else fuhao=0;
					fa[x]=zbb(xx);
					x=xx;
				}
			}
		}
		for (i=1;i<=n;i++) if (a[i]<t) a[i]=a[zbb(i)];
		ans=0;
		for (i=1;i<=n;i++) if (a[i]==u) ans++;
		cout<<ans<<endl;
	}
	return 0;
}