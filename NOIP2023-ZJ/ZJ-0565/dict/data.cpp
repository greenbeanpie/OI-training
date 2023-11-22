#include<bits/stdc++.h>
int n, m;
int main() {
	srand(time(NULL));
    freopen("dict.in", "w", stdout);
    n = rand() % 250 + 50;
    m = rand() % 250 + 50;
    printf("%d %d", n, m);
    for(int i = 1; i <= n; i++) {
    	puts("");
    	for(int j = 1; j <= m; j++) {
    		printf("%c", rand() % 26 + 'a');
    	}
    }
    
    return 0;
}
