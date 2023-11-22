#include<bits/stdc++.h>
using namespace std;
const int maxn=2e3+10;
typedef long long ll;
bool begin;
int cs,q,n,m;
int a[maxn],b[maxn],c[maxn],d[maxn];
bool dp[maxn][maxn];
int op,fl;
bool com(int x,int y)
{
	if(op==1)
		return x>y;
	else
		return x<y;
}
void calc()
{
	op=2;fl=1;
	memset(dp,0,sizeof(dp));
	if(a[1]>b[1]&&a[n]>b[m])//1 x>y  2 x<y
		op=1;
	else if(a[1]<b[1]&&a[n]<b[m])
		op=2;
	else
		fl=0;
	if(fl==0)
	{
		printf("0\n");
		return;
	}
	dp[1][1]=1;
	for(int i=2;i<=n;i++)
		dp[i][1]=dp[i-1][1]&(com(a[i],b[1]));
	for(int i=2;i<=m;i++)
		dp[1][i]=dp[1][i-1]&(com(a[1],b[i]));
	for(int i=2;i<=n;i++)
	{
		for(int j=2;j<=m;j++)
		{
			if(com(a[i],b[j]))
			{
				dp[i][j]=dp[i-1][j-1]|dp[i-1][j]|dp[i][j-1];
			}
		}
	}
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=m;j++)
//			cout<<dp[i][j]<<" ";
//		cout<<endl;
//	}
	printf("%d\n",dp[n][m]);
	return;
}
bool end;
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%d %d %d %d",&cs,&n,&m,&q);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)
		scanf("%d",&b[i]);
	calc();
	for(int tt=1;tt<=q;tt++)
	{
		for(int i=1;i<=n;i++)
			c[i]=a[i];
		for(int i=1;i<=m;i++)
			d[i]=b[i];
		int kx,ky;
		scanf("%d %d",&kx,&ky);
		for(int i=1;i<=kx;i++)
		{
			int pq,pt;
			scanf("%d %d",&pq,&pt);
			a[pq]=pt;
		}
		for(int i=1;i<=ky;i++)
		{
			int pq,pt;
			scanf("%d %d",&pq,&pt);
			b[pq]=pt;
		}
		calc();
		for(int i=1;i<=n;i++)
			a[i]=c[i];
		for(int i=1;i<=m;i++)
			b[i]=d[i];
	}
//	cerr<<(&end-&begin)/1024/1024<<"MB\n";
	return 0;
}

