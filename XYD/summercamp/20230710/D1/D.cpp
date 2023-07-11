#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXN 50010
using namespace std;
void swap(int &x, int &y)
{
	int tmp;
	tmp = x;
	x = y;
	y = tmp;
}

int n, k;
int r[MAXN], a[MAXN], ans[MAXN];
int dict[MAXN];
int main()
{

	cin >> n >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> r[i];
	}
	for (int i = 0; i < n; i++)
	{
		dict[i] = i;
	}
	int left = 0, right = n - 1;
	int mini = 0;
	memset(ans, 0, sizeof(ans));
	for (int i = 0; i < n; i++)
	{
		int p = (r[i % k] % (right - left + 1));
		p += left;
		if (dict[p] == mini)
		{
			ans[dict[p]] = left + 1;
			swap(dict[p], dict[left]);
			++left;
			while (ans[mini] != 0)
				mini++;
		}
		else
		{
			ans[dict[p]] = right + 1;
			swap(dict[p], dict[left]);
			swap(dict[left], dict[right]);
			--right;
		}
	}
	for (int i = 0; i < n; i++)
	{
		printf("%d\n", ans[i]);
	}
	return 0;
}