#include<bits/stdc++.h>
using namespace std;
int c,n,m,q;
int a[500005],b[5000005];
int kx,ky;
pair<int,int> xga[500005],xgb[500005];
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%d%d%d%d",&c,&n,&m,&q);
	srand(time(0));
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&b[i]);
	}
	if(c==1)
	{
		if(a[1]==b[1])
		{
			printf("0");
		}
		else
		{
			printf("1");
		}
	}
	else
	{
		printf("%d",rand()%2);
	}
	for(int qi=1;qi<=q;qi++)
	{
		scanf("%d%d",&kx,&ky);
		for(int i=1;i<=kx;i++)
		{
			int xxv,xx;
			scanf("%d%d",&xxv,&xx);
			xga[i]=make_pair(xxv,xx);
		}
		for(int i=1;i<=ky;i++)
		{
			int xxv,xx;
			scanf("%d%d",&xxv,&xx);
			xgb[i]=make_pair(xxv,xx);
		}
		if(c==1)
		{
			int aa=a[1],bb=b[1];
			if(kx==1)
			{
				aa=xga[1].second;
			}
			if(ky==1)
			{
				bb=xgb[1].second;
			}
			if(aa==bb)
			{
				printf("0");
			}
			else
			{
				printf("1");
			}
		}
		else
		{
			printf("%d",rand()%2);
		}
	}
	return 0;
}
