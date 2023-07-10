#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
int N, M, K;
long long ans, A[20], B[400][400], a, b, c;
int count(int x)
{
	int c = 0;
	while (x)
		c++, x &= (x - 1);
	return c;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("P4941.in", "r", stdin);
	freopen("P4941_TJ.out", "w", stdout);
#endif
	scanf("%d%d%d", &N, &M, &K);
	long long f[1 << (N+1)][20];
	memset(f,0,sizeof(f));
	for (int i = 1; i <= N; i++)
		scanf("%lld", &A[i]);
	for (int i = 1; i <= K; i++)
	{
		scanf("%lld%lld%lld", &a, &b, &c);
		if (a == b)
			A[a] += c;
		B[a][b] += c;
	}
	for (int i = 1; i <= N; i++)
		f[1 << (i - 1)][i] = A[i];
	for (int i = 1; i <= (1 << N) - 1; i++)
	{
		for (int j = 1; j <= N; j++)
			if (i & (1 << (j - 1)))
			{
				for (int k = 1; k <= N; k++)
				{
					if (i & (1 << (k - 1)) && j != k)
					{
						f[i][j] = max(f[i][j], f[i - (1 << (j - 1))][k] + B[k][j] + A[j]);
					}
				}
				if (count(i) == M)
				{
					for (int j = 1; j <= N; j++)
					{
						if (i & (1 << (j - 1)))
						{
							ans = max(ans, f[i][j]);
						}
					}
				}
			}
	}
	cout << ans;
	return 0;
}
