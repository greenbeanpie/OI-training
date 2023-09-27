#include <bits/stdc++.h>
using namespace std;
int a, b;
int main()
{
	freopen("divide.in", "w", stdout);
	random_device rd;
	int a = rd() % 10000000 + 1, b = rd() % 10000000 + 1;
	if (a > b)
	{
		swap(a, b);
	}
	long double l = 1.0 * a / b;
	printf("%.19Lf\n", l);
	cerr << a << " " << b;
	return 0;
}
