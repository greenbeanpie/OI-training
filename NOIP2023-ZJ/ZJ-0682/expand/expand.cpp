#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define N 500010

int c, n, m, q, Q;
int a[N], b[N];
int k_x, k_y, p, v;
int k, ans[N], res;

int main()
{
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	scanf("%d%d%d%d", &c, &n, &m, &q);
	for(int i = 1; i <= n; i ++)
		scanf("%d", &a[i]);
	for(int i = 1; i <= m; i ++)
		scanf("%d", &b[i]);
	Q = q + 1;
	while(Q > 0)
	{
		if(Q <= q)
		{
			scanf("%d%d", &k_x, &k_y);
			for(int i = 1; i <= k_x; i ++)
			{
				scanf("%d%d", &p, &v);
				a[p] = v;
			}
			for(int i = 1; i <= k_y; i ++)
			{
				scanf("%d%d", &p, &v);
				b[p] = v;
			}
		}

		
		if(a[1] > b[1] && a[n] > b[m])
			k = 1;
		else if(a[1] < b[1] && a[n] < b[m])
			k = -1;
		else{
			ans[q + 2 - Q] = 0;
			Q -= 1;
			continue;	
		}
		if(c == 2 || c == 1)
		{
			ans[q + 2 - Q] = 1;
			Q -= 1;
			continue;
		}
		Q -= 1;
	}
	for(int i = 1; i <= q + 1; i ++)
		cout << ans[i];
	
		
	
	
	return 0;
}
