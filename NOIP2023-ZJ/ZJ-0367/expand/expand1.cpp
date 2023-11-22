#include <bits/stdc++.h>
using namespace std;
int c,n,m,q,i,j,x,y,k,bo;
int dp[2001][2001],a[500001],b[500001],a1[500001],b1[500001];
void work()
{
	if (a1[1]<b1[1]) bo=0;else if (a1[1]>b1[1]) bo=1;else {cout<<0;return;}
	for (i=1;i<=n;i++) for (j=1;j<=m;j++)
	{
		if ((a1[i]<b1[j] && !bo) || (a1[i]>b1[j] && bo))
		{
			for (k=1;k<i;k++) 
			{
				if (dp[i][j]) break;
				dp[i][j]=dp[k][j-1];
			}
			for (k=1;k<j;k++) 
			{
				if (dp[i][j]) break;
				dp[i][j]=dp[i-1][k];
			}
		}
	}
	i=n;
	while (i && !dp[i][m]) i--;
	for (j=i+1;j<=n;j++) if (!((a1[j]<b1[m] && !bo) || (a1[j]>b1[m] && bo))) break;
	if (j>n) {cout<<1;return;}
	i=m;
	while (i && !dp[n][i]) i--;
	for (j=i+1;j<=m;j++) if (!((a1[n]<b1[i] && !bo) || (a1[n]>b1[i] && bo))) break;
	if (j>m) {cout<<1;return;}
	cout<<0;
}
int main()
{
	freopen("expand.in","r",stdin);freopen("expand.out","w",stdout);
	cin>>c>>n>>m>>q;
	for (i=1;i<=n;i++) scanf("%d",&a[i]),a1[i]=a[i];
	for (i=1;i<=m;i++) scanf("%d",&b[i]),b1[i]=b[i];
	work();
	while (q--)
	{
		for (i=1;i<=n;i++) a1[i]=a[i];
		for (i=1;i<=m;i++) b1[i]=b[i];
		cin>>k;
		for (i=1;i<=k;i++) scanf("%d%d",&x,&y),a1[x]=y;
		cin>>k;
		for (i=1;i<=k;i++) scanf("%d%d",&x,&y),b1[x]=y;
		work();
	}
}