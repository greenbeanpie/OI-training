#pragma once

const int N = 1e6 + 5;
struct treearray
{
	int tre[N << 1], n;
	int lwbt(int x) { return x & (-x); }
	int ask(int i)
	{
		int ans = 0;
		for (; i; i -= lwbt(i))
			ans += tre[i];
		return ans;
	}
	void add(int i, int k)
	{
		for (; i <= n; i += lwbt(i))
			tre[i] += k;
	}
} t;
