#include <bits/stdc++.h>
#define ll long long
using namespace std;
int T, ans;
long long a, tb, b, c;
__int128 mul;
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%lld%lld%lld", &a, &b, &c);
		if (a == 1 && b == 1 && c == 1)
		{
			puts("-1");
			continue;
		}
		if (a == 1 && b > 1 && c >= b)
		{
			tb = c;
			while (tb % b == 0)
				tb /= b;
			ans = (tb == 1);
		}
		else
			ans = (b == c);
		if (b == 1)
		{
			printf("%d\n", c == 1);
			continue;
		}
		mul = 1;
		tb = b;
		while (c && tb > 0)
		{
			if (mul > tb)
				break;
			tb -= mul * (c % b);
			mul *= a, c /= b;
		}
		printf("%d\n", ans + (!tb));
	}
	return 0;
}