#include <bits/stdc++.h>
using namespace std;

int n,m,k,front,FRONT,back,BACK,ans;
int a[1001][1001],q[1001],Q[1001];
int x[1001][1001],X[1001][1001];
int y[1001][1001],Y[1001][1001];

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("P2216.in", "r", stdin);
	freopen("P2216_TJ.out", "w", stdout);
#endif
	scanf("%d%d%d",&n,&m,&k);
	for (int I=1;I<=n;I++)
		for (int i=1;i<=m;i++)
			scanf("%d",&a[I][i]);
	for (int I=1;I<=n;I++)
		{
			FRONT=BACK=front=back=Q[1]=q[1]=1;
			for (int i=2;i<=m;i++)
				{
					while (a[I][i]>=a[I][Q[BACK]]&&FRONT<=BACK) BACK--;
					while (a[I][i]<=a[I][q[back]]&&front<=back) back--;
					BACK++;back++;Q[BACK]=i;q[back]=i;
					while (i-Q[FRONT]>=k) FRONT++;
					while (i-q[front]>=k) front++;
					if (i>=k) X[I][i-k+1]=a[I][Q[FRONT]],x[I][i-k+1]=a[I][q[front]];
				}
		}
	for (int I=1;I<=m-k+1;I++)
		{
			FRONT=BACK=front=back=Q[1]=q[1]=1;
			for (int i=2;i<=n;i++)
				{
					while (X[i][I]>=X[Q[BACK]][I]&&FRONT<=BACK) BACK--;
					while (x[i][I]<=x[q[back]][I]&&front<=back) back--;
					BACK++;back++;Q[BACK]=i;q[back]=i;
					while (i-Q[FRONT]>=k) FRONT++;
					while (i-q[front]>=k) front++;
					if (i>=k) Y[i-k+1][I]=X[Q[FRONT]][I],y[i-k+1][I]=x[q[front]][I];
				}
		}
    ans=0x3f3f3f3f;
	for (int I=1;I<=n-k+1;I++)
		for (int i=1;i<=m-k+1;i++)
			ans=min(ans,Y[I][i]-y[I][i]);
	printf("%d\n",ans);
	return 0;
}
