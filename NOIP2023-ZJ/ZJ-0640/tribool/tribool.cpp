#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

int t[N], is[N];

int c, T;

void sub1(){
    while (T--){
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++)
            t[i] = 0;
        while (m--){
            char opt;
            int a;
            cin >> opt >> a;
            if (opt == 'T') t[a] = 1;
            if (opt == 'F') t[a] = 2;
            if (opt == 'U') t[a] = 3;
        }
        int ans = 0;
        for (int i = 1; i <= n; i++){
            if (t[i] == 3) ans++;
        }
        printf("%d\n", ans);
    }
}

void sub2(){
    while (T--){
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++){
            t[i] = i;
            is[i] = 0;
        }
        while (m--){
            char opt;
            int a, b;
            cin >> opt >> a >> b;
            if (opt == '+'){
                t[a] = t[b];
            }
            if (opt == '-'){
                t[a] = -t[b];
            }
        }
        int ans = 0, cnt = 0;
        for (int i = 1; i <= n; i++){
            if (abs(t[i]) == i){
                cnt++;
                is[i] = 1;
                if (t[i] + i == 0){
                    is[i] = 2;
                    ans++;
                }
            }
        }
        while (cnt < n){
            for (int i = 1; i <= n; i++){
                if (is[i] || !is[abs(t[i])]) continue;
                cnt++;
                is[i] = is[abs(t[i])];
                if (t[i] < 0) is[i] = is[i] % 2 + 1;
                if (is[i] == 2) ans++;
            }
        }
        printf("%d\n", ans);
    }
}



int main(){
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    scanf("%d%d", &c, &T);
    if (c == 3 || c == 4){
        sub1();
    }
    if (c == 7 || c == 8){
        sub2();
    }
    return 0;
}