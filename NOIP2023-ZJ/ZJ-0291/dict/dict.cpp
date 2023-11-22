#include <bits/stdc++.h>
using namespace std;
char s[3010][3010], cnt[3010][2];
int n, m;
void Fre()
{
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	return;
}
void Read()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> s[i];
	return;
}
void Init()
{
	for (int i = 1; i <= n; i++)
	{
		cnt[i][0] = s[i][0];
		cnt[i][1] = s[i][0];
		for (int j = 1; j < m; j++)
		{
			if (s[i][j] < cnt[i][0])
				cnt[i][0] = s[i][j];
			if (s[i][j] > cnt[i][1])
				cnt[i][1] = s[i][j];
		}		
	}
	return;
}
void Work()
{
	int flag;
	for (int i = 1; i <= n; i++)
	{
		flag = 1;
		for (int j = 1; j <= n; j++)
			if (i != j && cnt[i][0] >= cnt[j][1])
			{
				flag = 0;
				break;
			}
		putchar(flag + 48);
	}
	putchar(10);
	return;
}
signed main()
{
	Fre();
	Read();
	Init();
	Work();
	return 0;
}