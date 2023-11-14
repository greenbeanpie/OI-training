#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cassert>
using namespace std;
template <class T>
void ChkMax(T &a, T b)
{
	if (a < b)
		a = b;
}
const int N = 1010;
int dp[6010][N];
struct TreeNode
{
	int cost, val, lson, rson;
} T[N * 10];
int tot, tot1 = 1;
void init(int x)
{
	scanf("%d%d", &T[x].cost, &T[x].val);
	T[x].cost *= 2;
	if (!T[x].val)
	{
		init(T[x].lson = ++tot1);
		init(T[x].rson = ++tot1);
	}
}
int dfs(int x, int tot)
{
	assert(x <= 6000 && tot <= 1000);
	if (dp[x][tot] > 0 || !tot)
		return dp[x][tot];
	if (T[x].val)
		return dp[x][tot] = min(T[x].val, (tot - T[x].cost) / 5);
	for (int k = 0; k <= tot - T[x].cost; k++)
		ChkMax(dp[x][tot], dfs(T[x].lson, k) + dfs(T[x].rson, tot - T[x].cost - k));
	return dp[x][tot];
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("P1270.in", "r", stdin);
	freopen("P1270_TJ.out", "w", stdout);
#endif
	scanf("%d", &tot);
	tot--;
	init(1);
	printf("%d", dfs(1, tot));
	return 0;
}