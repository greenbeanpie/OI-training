#include<bits/stdc++.h>
using namespace std;
const int N=5005;
int Min[N],Max[N];
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for (int i = 1; i <= n; i++)
	{
		char c=getchar();
		Min[i]=1e6, Max[i]=-1;
		for (int j = 1; j <= m; j++)
		{
			c=getchar();
			int x = c-'a';
			if (x<Min[i])
			  Min[i]=x;
			if (x>Max[i])
			  Max[i]=x;
		}
	}
	if (n==1)
	{
		cout<<1;
		return 0;
	}
	for (int i = 1; i <= n; i++)
	{
		bool b=true;
		for (int j = 1; j <= n; j++)
		{
			if (i==j)
			  continue;
			if (Min[i]>=Max[j])
			{
				b=false;
				break;
			}
		}
		if (b)
		  printf("1");
		else
		  printf("0");
	}
	return 0;
}
