#include <bits/stdc++.h>
using namespace std;

const int N = 3005;

int n , m , jMax_pos;
string s[N];
int a[N][N] , U_P[N][N] , L_OW[N][N];

bool cmp_up(int x , int y)
{
	return x > y;
}

bool cmp_low(int x , int y)
{
	return x < y;
}

bool check(int a[] , int b[])
{
	for (int i = 1 ; i <= m ; i++)
	{
		if (a[i] > b[i])
			return false;
	}
	return true;
}

int main()
{
	freopen("dict.in" , "r" , stdin);
	freopen("dict.out" , "w" , stdout);
	
	scanf("%d%d" , &n , &m);
	
	if (n == 1)
	{
		printf("1");
		return 0;
	}
	
	else if (m == 1)
	{	
		for (int i = 1 ; i <= n ; i++)
		{
			cin >> s[i];
		}
		jMax_pos = 1;
		for (int i = 2 ; i <= n ; i++)
		{
			if (s[i][0] < s[jMax_pos][0])
			{
				jMax_pos = i;
			}
		}
		for (int i = 1 ; i <= n ; i++)
		{
			if (i == jMax_pos)
			{
				printf("1");
				continue;
			}
			printf("0");
		}
		return 0;
	}
	
	else 
	{
		for (int i = 1 ; i <= n ; i++)
		{
			cin >> s[i];	
		}
		
		for (int i = 1 ; i <= n ; i ++)
		{
			for (int j = 0 ; j < m ; j++)
			{
				a[i][j + 1] = s[i][j];
				U_P[i][j+1] = a[i][j + 1];
				L_OW[i][j + 1] = a[i][j + 1];
			}
			sort(U_P[i] + 1, U_P[i] + m + 1 , cmp_up);
			sort(L_OW[i] + 1 , L_OW[i] + m + 1 , cmp_low);
		}

		for (int i = 1 ; i <= n ; i++)
		{
			bool flag = true;
			for (int j = 1 ; j <= n ; j++)
			{
				if (i == j)
					continue;
				if (check(L_OW[j] , U_P[i]))
				{
					flag = false;
					break;
				}
			}
			if (flag)
				printf("1");
			else
				printf("0");
		}
		
	}
	return 0;
}
