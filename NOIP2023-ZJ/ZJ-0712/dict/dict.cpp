#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

const int N = 3005;

string s;
int mi1p, mi2p;
int mi1[N], mi2[N];
int a[N][N], aa[N][N];

inline bool cmp(const int &p, const int &q)
{
	return p > q;
}

int main()
{
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	for(int i = 1; i <= m; ++ i)
		mi1[i] = mi2[i] = 30;
	for(int i = 1; i <= n; ++ i)
	{
		cin >> s;
		for(int j = 0; j < m; ++ j)
			a[i][j + 1] = s[j] - 'a';
		sort(a[i] + 1, a[i] + m + 1, cmp);
		for(int j = 1; j <= m; ++ j)
			aa[i][j] = a[i][j];
		sort(a[i] + 1, a[i] + m + 1);
		bool f = 0;
		for(int j = 1; j <= m; ++ j)
		{
			if(aa[i][j] < mi1[j])
			{
				f = 1, mi1p = i;
				for(int k = 1; k <= m; ++ k)
					mi1[k] = aa[i][k];
				break;
			}
			if(aa[i][j] > mi1[j]) break;
		}
		if(f) continue;
		for(int j = 1; j <= m; ++ j)
		{
			if(aa[i][j] < mi2[j])
			{
				mi2p = i;
				for(int k = 1; k <= m; ++ k)
					mi2[k] = aa[i][k];
				break;
			}
			if(aa[i][j] > mi2[j]) break;
		}
	}
	for(int i = 1; i <= n; ++ i)
	{
		bool flag = 1;
		int t = mi1p;
		if(mi1p == i) t = mi2p;
		for(int j = 1; j <= m; ++ j)
		{
			if(a[i][j] < aa[t][j]) break;
			if(a[i][j] > aa[t][j])
			{
				flag = 0; break;
			}
		}
		if(flag) cout << 1;
		else cout << 0;
	}
}