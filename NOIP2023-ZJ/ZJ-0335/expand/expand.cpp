#include <bits/stdc++.h>

const int maxn = 2005;
int arr[2][maxn], arr1[2][maxn], dp[maxn][maxn], n[2];

bool check()
{
	if(arr[0][1] == arr[1][1] || arr[0][n[0]] == arr[1][n[1]]) return false;
	if(arr[0][1] > arr[1][1] && arr[0][n[0]] < arr[1][n[1]]) return false;
	if(arr[0][1] < arr[1][1] && arr[0][n[0]] > arr[1][n[1]]) return false;
	int x = 0;
	if(arr[0][1] < arr[1][1]) x = 1;
	
	if(arr[x][1] > arr[1 - x][1])dp[1][1] = 1;
	for(int i = 1; i <= n[x]; i++)
	{
		for(int j = 1; j <= n[1 - x]; j++)
		{
			if(i != 1 || j != 1)dp[i][j] = 0;
			if(arr[x][i] > arr[1 - x][j])
			{
				dp[i][j] |= dp[i - 1][j - 1];
				dp[i][j] |= dp[i][j - 1];
				dp[i][j] |= dp[i - 1][j];
			}
//			std::cerr << i << " " << j << " " << dp[i][j] << std::endl;
		}
	}
	return dp[n[x]][n[1 - x]];
}

int main()
{
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	int c, q;
	scanf("%d%d%d%d", &c, &n[0], &n[1], &q);
	for(int i = 1; i <= n[0]; i++) {scanf("%d", &arr[0][i]); arr1[0][i] = arr[0][i];}
	for(int i = 1; i <= n[1]; i++) {scanf("%d", &arr[1][i]); arr1[1][i] = arr[1][i];}
	if(check()) printf("1");
	else printf("0");
	for(int i = 0; i < q; i++)
	{
		for(int j = 1; j <= n[0]; j++) arr[0][j] = arr1[0][j];
		for(int j = 1; j <= n[1]; j++) arr[1][j] = arr1[1][j];
		int k1, k2;
		scanf("%d%d", &k1, &k2);
		int a, b;
		for(int j = 0; j < k1; j++)
		{
			scanf("%d%d", &a, &b);
			arr[0][a] = b;
		}
		for(int j = 0; j < k2; j++)
		{
			scanf("%d%d", &a, &b);
			arr[1][a] = b;
		}
//		if(i == 1)
//		{
//			for(int j = 1; j <= 6; j++) std::cerr << arr[0][j] << " " << arr[1][j] << std::endl;
//		}
		if(check()) printf("1");
		else printf("0");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}