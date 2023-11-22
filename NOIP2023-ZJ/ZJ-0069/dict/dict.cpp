#include<bits/stdc++.h>
using namespace std;
long long n,m,i,j,a;
char c[3003][3003],d[3003];
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i=i+1)
	{
		scanf("%s",c[i]);
		sort(c[i],c[i]+m);a=0;
		if(i==1)a=1;
		else
		{
			for(j=0;j<m;j=j+1)
			{
				if(c[i][m-j-1]<d[j]){a=1;break;}
				else if(c[i][m-j-1]>d[j])break;
			}
		}
		if(a==1)
		{
			for(j=0;j<m;j=j+1)d[j]=c[i][m-j-1];
		}
	}
	for(i=1;i<=n;i=i+1)
	{
		a=1;
		for(j=0;j<m;j=j+1)
		{
			if(c[i][j]<d[j])break;
			else if(c[i][j]>d[j]){a=0;break;}
		}
		printf("%lld",a);
	}
	return 0;
}
