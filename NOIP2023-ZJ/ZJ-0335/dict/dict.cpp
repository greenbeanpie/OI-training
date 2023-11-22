#include <bits/stdc++.h>

const int maxn = 3005;
int shun[maxn][maxn], ni[maxn][maxn];
int n, m;

bool cmp(int i, int j)
{
	int flag = 1;
	for(int k = 0; k < m; k++)
	{
		if(ni[i][k] > ni[j][k]) {flag = 0; break;}
		if(ni[i][k] < ni[j][k]) {flag = 2; break;}
	}
	return flag;
}

int main()
{
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	std::cin >> n >> m;
	std::string s;
	for(int i = 0; i < n; i++)
	{
		std::cin >> s;
		for(int j = 0; j < m; j++)
		{
			shun[i][j] = s[j] - 'a';
			ni[i][j] = s[j] - 'a';
		}
		std::sort(shun[i], shun[i] + m, std::less<int>() );
		std::sort(ni[i], ni[i] + m, std::greater<int>() );
	}
	int maxni = 0;
	for(int i = 1; i < n; i++)
	{
		int x = cmp(maxni, i);//win:flag = 0
		if(x == 0) maxni = i;
	}
	int secmaxni = 0;
	for(int i = 0; i < n; i++)
	{
		if(i == maxni) continue;
		int x = cmp(secmaxni, i);//win:flag = 0
		if(x == 0) secmaxni = i;
	}
	
	for(int i = 0; i < n; i++)
	{
		int j;
		if(i == maxni) j = secmaxni;
		else j = maxni;
		bool ok = true;

		int flag = 1;
		for(int k = 0; k < m; k++)
		{
			if(shun[i][k] > ni[j][k]) {flag = 0; break;}
			if(shun[i][k] < ni[j][k]) {flag = 2; break;}
		}

		if(flag > 1) printf("1");
		else printf("0");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}