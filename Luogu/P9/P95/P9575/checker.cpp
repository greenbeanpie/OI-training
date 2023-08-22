#include "testlib.h"
#include <vector>
#include <cmath>
#include <algorithm>

int main(int argc, char *argv[])
{
	registerTestlibCmd(argc, argv);
	int n = inf.readInteger();
	std::vector<int> num;
	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		num.push_back(inf.readInteger());
		sum += *num.rbegin();
	}
	int x = ouf.readInteger();
	if (sum % 2 && x == -1)
		quitf(_ok, "The answer is correct.");
	else
		quitf(_wa, "The answer is wrong.");
	int sum1 = 0, sum2 = 0;
	for (int i = 0; i < n; i++)
	{
		if (ouf.readChar() == '0')
		{
			sum1 += std::__gcd(num[i], x);
		}
		else
		{
			sum2 += std::__gcd(num[i], x);
		}
	}
	if (sum1 == sum2)
		quitf(_ok, "The answer is correct.");
	else
		quitf(_wa, "The answer is wrong.sum1 = %d,sum2 = %d",sum1,sum2);
}