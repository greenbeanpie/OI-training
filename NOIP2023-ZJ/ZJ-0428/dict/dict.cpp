#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

int n, m;
char c[3001][3001];

bool cmp(char amin, char oac) {
	return (amin > oac);
}

int main() {
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	scanf("%d %d\n", &n, &m);
	if ((n == 1) && (m == 1)) {
		printf("1\n");
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			c[i][j] = getchar();
		scanf("\n");
	}
	if ((n <= 26) && (m == 1)) {
		char minima = c[1][1];
		int aminoac = 1;
		for (int i = 2; i <= n; i++)
			if (minima > c[i][1]) {
				aminoac = i;
				minima = c[i][1];
			}
		for (int i = 1; i <= n; i++)
			if (i == aminoac) 
				printf("1");
			else
				printf("0");
		return 0;
	}
	for (int i = 1; i <= n; i++)
		sort(c[i] + 1, c[i] + m + 1, cmp);
// min1
	int min1 = 1;
	for (int i = 2; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			if (c[min1][j] < c[i][j])
				break;
			if (c[min1][j] > c[i][j]) {
				min1 = i;
				break; 
			}
		}
// min2
	int min2 = 1;
	if (min1 == 1)
		min2 = 2;
	for (int i = 2; i <= n; i++) {
		if (i == min1)
			continue;
		for (int j = 1; j <= m; j++) {
			if (c[min2][j] < c[i][j])	            
				break;
			if (c[min2][j] > c[i][j]) {
				min2 = i;
				break;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		bool flag = false;
		if (i == min1) {
			bool aa = true;
			for (int j = 1; (j <= m) && aa; j++) {
				if (c[i][m - j + 1] > c[min2][j])
					aa = false;
				if (c[i][m - j + 1] < c[min2][j]) {
					flag = true;
					aa = false;
				}
				if (flag)
					printf("1");
				else
					printf("0");			
			}      
			continue;
		}
		for (int j = 1; j <= m; j++) {
			if (c[i][m - j + 1] > c[min1][j]) 
				break;
			if (c[i][m - j + 1] < c[min1][j]) {
				flag =true;
				break;
			}
		}
		if (flag)
			printf("1");
		else
			printf("0");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}