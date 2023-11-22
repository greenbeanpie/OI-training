#include <stdio.h>
#include <iostream>
using namespace std;
char d[4000],e[4000];
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	int a,b,n;string c;
	scanf("%d%d",&a,&b);
	for(int i=0;i<a;i++)
	{
		cin>>c;
		d[i]=e[i]=c[0];
		for(int j=1;j<b;j++)
		{
			d[i]=min(d[i],c[j]);
			e[i]=max(e[i],c[j]);
		}
	}
	for(int i=0;i<a;i++)
	{
		n=1;
		for(int j=0;j<a;j++)
		{
			if(j!=i)
			{
				if(d[i]>=e[j])
				{
					n=0;break;
				}
			}
		}
		printf("%d",n);
	}
	return 0;
}
