#include<cstdio>
#include<algorithm>
int n,m,mx[3005],mn[3005];
char st[3005];
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) mx[i]=0,mn[i]=27;
	for (int i=1;i<=n;i++)
	{
		scanf("%s",st+1);
		for (int k=1;k<=m;k++)
		{
			int ch=st[k]-95;
			mx[i]=std::max(mx[i],ch);
			mn[i]=std::min(mn[i],ch);
		}
	}
	for (int i=1;i<=n;i++)
	{
		int flag=1;
		for (int j=1;j<=n;j++) if (i!=j&&mx[j]<=mn[i]) flag=0;
		putchar(flag+48);
	}
	puts("");
	return 0;
}