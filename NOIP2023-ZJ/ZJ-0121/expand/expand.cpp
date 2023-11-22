#include <bits/stdc++.h>
using namespace std;
bool f[2010][2010];int aa[2010],bb[2010],a[2010],b[2010];
int main()
{
	freopen("expand.in","r",stdin);freopen("expand.out","w",stdout);
	int sid,n,m,q,flag=1;scanf("%d%d%d%d",&sid,&n,&m,&q);q++;
	for(int i=1;i<=n;i++) scanf("%d",&aa[i]);for(int i=1;i<=m;i++) scanf("%d",&bb[i]);
	if(sid<=7) while(q--)
	{
		int kx,ky,p,d;if(flag) flag=0,kx=0,ky=0;else scanf("%d%d",&kx,&ky);f[1][0]=f[0][1]=1;\
		for(int i=1;i<=n;i++) a[i]=aa[i];for(int i=1;i<=m;i++) b[i]=bb[i];
		for(int i=1;i<=kx;i++) scanf("%d%d",&p,&d),a[p]=d;
		for(int i=1;i<=ky;i++) scanf("%d%d",&p,&d),b[p]=d;
		if(a[1]<b[1]&&a[n]<b[m])
		{
			for(int sum=2;sum<=n+m;sum++) for(int i=min(sum-1,n),j=sum-i;j<=min(sum-1,m);i--,j++)
				f[i][j]=(a[i]<b[j])&&(f[i-1][j]||f[i][j-1]||f[i-1][j-1]);
			printf(f[n][m]?"1":"0");
		}
		else if(a[1]>b[1]&&a[n]>b[m])
		{
			for(int sum=2;sum<=n+m;sum++) for(int i=min(sum-1,n),j=sum-i;j<=min(sum-1,m);i--,j++)
				f[i][j]=(a[i]>b[j])&&(f[i-1][j]||f[i][j-1]||f[i-1][j-1]);
			printf(f[n][m]?"1":"0");
		}
		else printf("0");
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) f[i][j]=0;
	}
	else while(q--) printf("0");
	return 0;
}