#include <cstdio>
#define mo 1000003
using namespace std;

long long n, d, z, ans, a[55], b[55], v, p;
int i, t;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("P1762.in", "r", stdin);
	freopen("P1762_TJ.out", "w", stdout);
#endif
	scanf("%lld", &v);
	n = v;
	z = 1;
	d = z << 50; // 因为2^50恰好大于10^15
	t = 50;
	while (n != 0)
	{
		if (n >= d)
		{
			n = n - d;
			a[++a[0]] = t; // 将2^t 的t存入数组中
		}
		d /= 2;
		t--;
	}

	b[0] = 1;
	for (i = 1; i <= a[1]; ++i)
		b[i] = (b[i - 1] * 3) % mo; // 进行预处理，准备好3^t 的数字在数组b中

	for (i = 1; i <= a[0]; ++i)
		ans += b[a[i]] * (long long)(z << i - 1); // 求所有奇数个数的和

	p = (((z + v % mo) * (v % mo)) / 2); // 求和公式
	p %= mo;
	ans %= mo;
	if (p < ans)
		p += mo;
	p = (p - ans) % mo; // 总个数减去所有奇数个数就是偶数个数了
	printf("%lld\n", p);
	return 0;
}
