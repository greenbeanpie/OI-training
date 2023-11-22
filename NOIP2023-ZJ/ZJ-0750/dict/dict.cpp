#include<bits/stdc++.h>
using namespace std;

int n, m;
int s1[3005][26], s2[3005][26];

int main()
{
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			char x = getchar();
			while (x < 'a' || x > 'z') x = getchar();
			s1[i][x - 'a']++;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		bool flag = true;
		for (int j = 1; j <= n; j++)
		{
			if (i == j) continue;
			int k1 = 0, k2 = 25;
			while (s1[i][k1] == 0) k1++;
			while (s1[j][k2] == 0) k2--;
			if (k1 > k2)
			{
				cout << "0";
				flag = false;
				break;
			}
			if (k1 < k2)
			{
				continue;
			}
			if (s1[i][k1] < s1[j][k2]) continue;
			if (s1[i][k1] > s1[j][k2])
			{
				cout << "0";
				flag = false;
				break;
			}
		}
		if (flag) cout << "1";
	}
	return 0;
}
