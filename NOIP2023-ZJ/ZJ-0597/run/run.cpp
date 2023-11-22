#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	int C,t;
	scanf("%d%d",&C,&t);
	while(t--)
	{
		int m,n,k,d;
		scanf("%d%d%d%d",&m,&n,&k,&d);
		for(int i=1;i<=m;i++)
		{
			int tmp1,tmp2,tmp3;
			scanf("%d%d%d",&tmp1,&tmp2,&tmp3);
			sum+=tmp3;
		}
		printf("%d\n",(-1)*d*(n-n/k+1)+sum);
	}
	return 0;
}