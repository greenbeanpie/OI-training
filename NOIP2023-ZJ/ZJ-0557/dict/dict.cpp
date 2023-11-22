#include<bits/stdc++.h>
using namespace std;
int n, m;
int bucket[3010][27];

int main()
{
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
	{
		string s;
		cin >> s;
		for(int j = 0; j < s.size(); j++)
		{
			bucket[i][s[j] - 96]++;
		}
	}
	for(int i = 1; i <= n; i++)
	{
		bool flag = true;
		for(int j = 1; j <= n; j++)
		{
			if(j == i) continue;
			int k = 1, l = 26;
			for(; k <= 26; k++)
			{
				if(!bucket[i][k]) continue;
				for(; l >= 1; l--)
				{
					if(!bucket[j][l]) continue;
					if(k >= l) {flag = false; break;}
					else {l = 0, k = 27; break;}
				}
				if(flag == false) break;
			}
			if(flag == false) break;
		}
		if(flag == true) printf("1");
		else printf("0");
	}
	return 0;
}
