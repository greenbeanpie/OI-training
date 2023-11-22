#include <bits/stdc++.h>
using namespace std;
struct Type {
	int no, type;
	int c[26];
}a[10000];

inline bool cmp(const Type &x, const Type &y) {
	int x1 = x.type == 0 ? 0 : 25;
	int y1 = y.type == 0 ? 0 : 25;
	
	while (x1 >= 0 && x1 <= 25 && y1 >= 0 && y1 <= 25) {
		while (x.c[x1] == 0)
			x1 += x.type == 0 ? 1 : -1;
	
		while (y.c[y1] == 0)
			y1 += y.type == 0 ? 1 : -1;
		
		if (x1 < y1)
			return true;
		
		if (x1 > y1)
			return false;
		
		if (x1 == y1)
			if (x.c[x1] == y.c[y1]) {
				x1 += x.type == 0 ? 1 : -1;
				y1 += y.type == 0 ? 1 : -1;
			}
			else
				if (x.c[x1] < y.c[y1])
					if (x.type == 0)
						return false;
					else
						return true;
				else
					if (y.type == 0)
						return true;
					else
						return false;
	}
	
	if (x.type == 1)
		return true;
	
	if (y.type == 1)
		return false;
	
	return true;
}

int ans[4000], n, m;
int main() {
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	scanf("%d %d", &n, &m);
	int x = 0;
	
	for (int i = 1; i <= n; i++) {
		char ch = getchar();
		a[++x].no = i;
		a[x].type = 0;
		
		for (; ch < 'a' || ch > 'z'; ch = getchar())
			;
		
		for (; ch >='a' && ch <= 'z'; ch = getchar())
			a[x].c[ch - 'a']++;
		
		a[++x].no = i;
		a[x].type = 1;
		
		for (int j = 0; j < 26; j++)
			a[x].c[j] = a[x - 1].c[j];
	}
	
	sort(a + 1, a + x + 1, cmp);
	
	for (int i = 1; i <= n; i++)
		if (a[i].type == 0)
			ans[a[i].no] = 1;
		else {
			if (a[i + 1].no == a[i].no)
				ans[a[i].no] = 1;
			
			break;
		}
			
	
	if (n == 1)
		printf("0");
	else {
		for (int i = 1; i <= n; i++)
			if (ans[i])
				printf("1");
			else
				printf("0");
	}
	
	printf("\n");
	fclose(stdin);
	fclose(stdout);
	return 0;
}