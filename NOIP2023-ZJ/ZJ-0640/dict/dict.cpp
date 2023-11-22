#include <bits/stdc++.h>
using namespace std;

const int N = 3005, M = 3005;

char s[M];

int minn[N], maxx[N];

int main(){
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++){
        scanf("%s", s);
        minn[i] = 26, maxx[i] = -1;
        for (int j = 0; j < m; j++){
            int k = s[j] - 'a';
            minn[i] = min(minn[i], k);
            maxx[i] = max(maxx[i], k);
        }
    }
    for (int i = 1; i <= n; i++){
        int ans = 1;
        for (int j = 1; j <= n; j++){
            if (j == i) continue;
            if (maxx[j] <= minn[i]){
                ans = 0;
                break;
            }
        }
        printf("%d", ans);
    }
    return 0;
}