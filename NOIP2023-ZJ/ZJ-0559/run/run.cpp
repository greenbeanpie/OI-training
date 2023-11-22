#include<bits/stdc++.h>
using namespace std;
int c,t;
int a[101],f[101];
int n,m,d,k;
int x[1001],y[101],z[101];
int main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	scanf("%d%d",&c,&t);
	if(c <= 2)
	{
		while(t--)
		{
			int maxn = 0;
			scanf("%d%d%d%d",&n,&m,&k,&d);
			k++;
			for(int i=1;i<=m;i++)
			{
				scanf("%d%d%d",&x[i],&y[i],&z[i]);
			}
			int len = 1;
			for(int i=1;i<=n;i++)
			  len *= 2;
			for(int i=1;i<len;i++)
			{
				int ans = 0,cnt = 0;
				int temp;
				for(int j=0;j<=n;j++)
				{
					a[j] = 0;
					f[j] = 0;
				}
				temp = i;
				while(temp)
				{
					cnt++;
					a[cnt] = temp % 2;
					temp /= 2;
				}
				for(int j=1;j<=n;j++)
				{
					f[j] = f[j - 1] + a[j];
				}
				bool flag = 0;
				for(int j=1;j<=n-k+1;j++)
				{
					if(f[j + k - 1] - f[j - 1] >= k)
					{
						flag = 1;
						break;
					}
				}
				if(flag)
				  continue;
				for(int j=1;j<=m;j++)
				{
					if(f[x[j]] - f[x[j] - y[j]] == y[j])
					  ans += z[j];
				}
				ans -= d * f[n];
				if(ans > maxn)
				  maxn = ans;
			}
			printf("%d\n",maxn);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}