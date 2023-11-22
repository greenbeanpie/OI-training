#include<bits/stdc++.h>

int n, m;
int s[305][305];
int check(int i) {
	for(int j = 1; j <= n; j++)
		if(i != j)
			for(int k = 1; k <= m; k++)
				if(s[i][k] > s[j][m - k + 1]) return 0;
				else if(s[i][k] < s[j][m - k + 1]) break;
	return 1;
}

int main() {
    freopen("dict.in", "r", stdin); freopen("baoli.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for(int i = 1, ch; i <= n; i++) {
        scanf("\n");
        for(int j = 1; j <= m; j++) {
            ch = getchar() - 'a';
            s[i][j] = ch;
        }
 		std::sort(s[i] + 1, s[i] + m + 1);
    }
    for(int i = 1; i <= n; i++)
        printf("%d", check(i));
    puts("");
    return 0;
}

