#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n, m, maxn[3010][3010], minn[3010][3010];
string a;
bool cmp(ll x, ll y)
{
	return x > y;
}
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin >> n >> m; 
//	scanf("%ll%ll", &n, &m);
//	printf("%ll", n);
	for (int i = 1; i <= n; i++)
	{
//		scanf("%s", &a);
		cin >> a;
		ll t[3010];
		for (int j = 0; j < m; j++) t[j] = a[j] - 'a';
		sort(t, t + m);
		for (int j = 0; j < m; j++) minn[i][j] = t[j];
		sort(t, t + m, cmp);
		for (int j = 0; j < m; j++) maxn[i][j] = t[j];
	}
	for (ll i = 1; i <= n; i++)
	{
		bool flag = 1;
		for(ll j = 1; j <= n; j++)
		{
			if(i == j) continue;
			int num = 0;
			while(minn[i][num] == maxn[j][num] && num < m) num++;
			if(num == m) 
			{
				printf("%d", 0);
				flag = 0;
				break;
			}
			if(minn[i][num] > maxn[j][num])
			{
				printf("%d", 0);
				flag = 0;
				break;
			}
		}
		if(flag) printf("%d", 1);
	}
	return 0;
}
