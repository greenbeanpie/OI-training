#include <bits/stdc++.h>
const int MaxN = 100123;

int n, a[MaxN], b[MaxN], c[MaxN], f[MaxN];
std::vector<int> V;

void Modify(int x, int v)
{
	V.push_back(x);
	for(; x <= n; x += (x & (-x))) c[x] = std::max(c[x], v);
}

int Query(int x)
{
	int res = 0;
	for(; x; x -= (x & (-x))) res = std::max(res, c[x]);
	return res;
}

void clear()
{
	for(int x : V)
	for(; x <= n; x += (x & -x)) c[x] = 0;
	V.clear();
}

int main()
{
    freopen("factor.in", "r", stdin);
    freopen("factor.out", "w", stdout);	
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", a + i);
	for(int i = 1; i <= n; ++i) scanf("%d", b + i);
	
	std::function<void(int, int)> solve = [&](int L, int R)
	{
		if(L == R) return f[L] = std::max(f[L], 1), void();
		int Mid = (L + R) / 2;
		
		solve(L, Mid);
		
		std::vector<int> V;
		for(int i = L; i <= R; ++i) V.push_back(i);
		std::sort(V.begin(), V.end(),
			[&](int i, int j) {return std::tie(a[i], b[i]) < std::tie(a[j], b[j]);});
		
		for(int i : V)
		if(i <= Mid) Modify(b[i], f[i]);
		else f[i] = std::max(f[i], Query(b[i]) + 1);
		
		clear();
		
		solve(Mid + 1, R);
	};
	
	solve(1, n);
	printf("%d\n", *std::max_element(f + 1, f + n + 1));
	return 0;
}
