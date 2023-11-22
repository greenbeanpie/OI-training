#include <bits/stdc++.h>
#define OK
using namespace std;
namespace Dict
{
	int n,m,b1=0,b2=0;
	char s[3005][3005],f[3005][3005],b[3005][3005];
	bool cmp (char* x,char* y)
	{
		for (int i=1;i<=m;i++)
		{
			if (x[i]<y[i]) return 1;
			if (x[i]>y[i]) return 0;
		}
		return 0;
	}
	int main ()
	{
#ifdef OK
		freopen ("dict.in","r",stdin);
		freopen ("dict.out","w",stdout);
#endif
		scanf ("%d%d",&n,&m);
		for (int i=1;i<=n;i++)
		{
			scanf ("%s",s[i]+1);
			for (int j=1;j<=m;j++)
				f[i][j]=b[i][j]=s[i][j];
			sort (f[i]+1,f[i]+m+1);
			sort (b[i]+1,b[i]+m+1,greater<char>());
//			printf ("%s, %s\n",f[i]+1,b[i]+1);
			if (!b1 || cmp(b[i],b[b1])) b2=b1,b1=i;
			else if (!b2 || cmp(b[i],b[b2])) b2=i;
		}
//		printf ("%d %d\n",b1,b2);
		for (int i=1;i<=n;i++)
			printf ("%d",i==b1 && cmp(f[i],b[b2]) ||
				i!=b1 && cmp(f[i],b[b1]));
#ifndef OK
		printf ("\n%d\n",clock());
#endif
		exit(0);
	}
}
int main ()
{
	Dict::main(); // 最坏 O(n^2) 
	return 0;
}
// 20min 样例4用了421ms 
