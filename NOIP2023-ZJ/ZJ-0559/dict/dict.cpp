#include<bits/stdc++.h>
using namespace std;
int n,m,a[3010][3010];
char s;
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin>>n>>m;
	if(n == 1)
	{
		printf("1");
		return 0;
	}
	if(m == 1)
	{
		int minn = 999;
	    for(int i=1;i<=n;i++)
	    {
		  cin>>s;
		  a[i][1] = s;
		  if(a[i][1] < minn)
		    minn = a[i][1];
	    }
		for(int i=1;i<=n;i++)
		  if(a[i][1] == minn)
		    printf("1");
		  else
		    printf("0");
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>s;
			a[i][j] = int(s) - int('a') + 1;
		}
		sort(a[i]+1,a[i]+1+m);
	}
	int maxp = 1;
	for(int i=2;i<=n;i++)
	{
		for(int j=m;j>=1;j++)
		{
			if(a[maxp][j] < a[i][j])
			  break;
			if(a[maxp][j] > a[i][j])
			{
				maxp = i;
				break;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(i == maxp)
		{
			printf("1");
			continue;
		}
		for(int j=1;j<=m;j++)
		{
			if(a[i][j] > a[maxp][m - j + 1])
			{
				printf("0");
				break;
			}
			if(a[i][j] < a[maxp][m - j + 1])
			{
				printf("1");
				break;
			}
		}
	}
	fclose(stdin);
	fclose(stdin);
	return 0;
}