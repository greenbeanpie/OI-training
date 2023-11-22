#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int mn[3005], mx[3005], mx1[3005];
char str[3005];
int main()
{
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
	{
		scanf("%s", str + 1);
		mn[i] = 1000, mx[i] = 0;
		for(int j = 1; j <= m; j++)
			mn[i] = min(mn[i], (int)str[j]), mx[i] = max(mx[i], (int)str[j]);
		mx1[i] = mx[i];
	}
	sort(mx1 + 1, mx1 + n + 1), mx1[n + 1] = 1e9;
	for(int i = 1; i <= n; i++)
	{
		if(mn[i] < mx1[1] || (mx[i] == mx1[1] && mn[i] < mx1[2])) printf("1");
		else printf("0");
	}
	return 0;
}