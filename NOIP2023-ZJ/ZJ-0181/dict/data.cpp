#include <bits/stdc++.h>
using namespace std;
int main() {
    mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
    int n = 300, m = 300;
    printf("%d %d\n", n, m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            printf("%c", rd() % 26 + 'a');
        }
        printf("\n");
    }
    return 0;
}