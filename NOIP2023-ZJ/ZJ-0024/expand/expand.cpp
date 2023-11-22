#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define ssz(x) (int((x).size()))

auto chmin = [](auto& x, auto y) { if (x > y) x = y; };
auto chmax = [](auto& x, auto y) { if (x < y) x = y; };

using ll = long long;
const int max_n = 5e5, INF = 1145141919;

int aa[max_n], bb[max_n], a[max_n], b[max_n];

vector<pair<int, int>> sh, sl;
bool semsolve(int n, int m)
{
	sh.clear(), sl.clear();
	int cx = INF;
	for (int i = 0; i < n; i++)
	{
		if (sh.empty() || a[i] > a[sh.back().first])
			sh.emplace_back(i, cx), cx = INF;
		else
			chmin(cx, a[i]);
	}
	cx = 0;
	for (int i = 0; i < m; i++)
	{
		if (sl.empty() || b[i] < b[sl.back().first])
			sl.emplace_back(i, cx), cx = 0;
		else
			chmax(cx, b[i]);
	}
	
	int i = 1, j = 1;
	while (i < ssz(sh) || j < ssz(sl))
	{
		if (i < ssz(sh) && sh[i].second > b[sl[j - 1].first])
			i++;
		else if (j < ssz(sl) && sl[j].second < a[sh[i - 1].first])
			j++;
		else
			return 0;
	}
	return 1;
}

bool solve(int n, int m)
{
	if (a[0] == b[0] || a[n - 1] == b[m - 1])
		return 0;
	if ((a[0] < b[0]) != (a[n - 1] < b[m - 1]))
		return 0;
	if (a[0] < b[0])
		swap(a, b), swap(n, m);
	
	if (!semsolve(n, m))
		return 0;
	// cerr << sh.size() << " " << sl.size() << endl;
	int ar = n - sh.back().first - 1, br = m - sl.back().first - 1;
	reverse(a, a + n), reverse(b, b + m);
	if (!semsolve(n, m))
		return 0;
	// cerr << sh.size() << " " << sl.size() << endl;
	int al = sh.back().first, bl = sl.back().first;
	
	// cerr << al << " " << ar << " " << bl << " " << br << endl;
	
	if (b[bl] >= *min_element(a + al, a + ar + 1))
		return 0;
	if (a[al] <= *max_element(b + bl, b + br + 1))
		return 0;
	return 1;
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);  
	
	int cid, n, m, q;
	
	cin >> cid >> n >> m >> q;
	for (int i = 0; i < n; i++)
		cin >> aa[i];
	for (int i = 0; i < m; i++)
		cin >> bb[i];
	
	copy(aa, aa + n, a);
	copy(bb, bb + m, b);
	
	cout << solve(n, m);
	while (q--)
	{
		int kx, ky;
		cin >> kx >> ky;
		
		copy(aa, aa + n, a);
		copy(bb, bb + m, b);
		
		for (int i = 0, p, v; i < kx; i++)
			cin >> p >> v, a[p - 1] = v;
		for (int i = 0, p, v; i < ky; i++)
			cin >> p >> v, b[p - 1] = v;
		cout << solve(n, m);
	}
	
	return 0;
}
/*
0 5 2 0
4 19 10 18 6
14 14
*/