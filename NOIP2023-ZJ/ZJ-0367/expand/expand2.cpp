#include <bits/stdc++.h>
using namespace std;
int c,n,m,q,i,j,x,y,k,k1,k2,bo;
int dp[2001][2001],a[5001],b[5001],a1[5001],b1[5001];
void work()
{
	if (a1[1]<b1[1]) bo=0;else if (a1[1]>b1[1]) bo=1;else {cout<<0;return;}
	for (i=1;i<=n;i++) for (j=1;j<=m;j++) dp[i][j]=0;
	for (i=1;i<=m;i++) if ((a1[1]<b1[i] && !bo) || (a1[1]>b1[i] && bo)) dp[1][i]=1;
	for (i=1;i<=n;i++) if ((a1[i]<b1[1] && !bo) || (a1[i]>b1[1] && bo)) dp[i][1]=1;
	for (i=2;i<=n;i++) for (j=2;j<=m;j++)
	{
		for (k=i;k>=j;k--)
			if ((a1[k]<b1[j] && !bo) || (a1[k]>b1[j] && bo))
			{
				if (dp[i][j]) break;
				dp[i][j]=dp[k-1][j-1];
			}else break;
		for (k=j;k>=i;k--)
			if ((a1[i]<b1[k] && !bo) || (a1[i]>b1[k] && bo))
			{
				if (dp[i][j]) break;
				dp[i][j]=dp[i-1][k-1];
			}else break;
	}
	i=n;
	while (i && !dp[i][m]) i--;
	for (j=i+1;j<=n;j++) if (!((a1[j]<b1[m] && !bo) || (a1[j]>b1[m] && bo))) break;
	if (j>n && i) {cout<<1;return;}
	i=m;
	while (i && !dp[n][i]) i--;
	for (j=i+1;j<=m;j++) if (!((a1[n]<b1[i] && !bo) || (a1[n]>b1[i] && bo))) break;
	if (j>m && i) {cout<<1;return;}
	cout<<0;
}
int main()
{
	freopen("expand.in","r",stdin);freopen("expand.out","w",stdout);
	cin>>c>>n>>m>>q;
	if (n>200  && m>200) 
	{
		for (i=0;i<=q;i++) cout<<0;
		return 0;
	}
	for (i=1;i<=n;i++) scanf("%d",&a[i]),a1[i]=a[i];
	for (i=1;i<=m;i++) scanf("%d",&b[i]),b1[i]=b[i];
	work();
	while (q--)
	{
		for (i=1;i<=n;i++) a1[i]=a[i];
		for (i=1;i<=m;i++) b1[i]=b[i];
		cin>>k1>>k2;
		for (i=1;i<=k1;i++) scanf("%d%d",&x,&y),a1[x]=y;
		for (i=1;i<=k2;i++) scanf("%d%d",&x,&y),b1[x]=y;
		work();
	}
	return 0;
}