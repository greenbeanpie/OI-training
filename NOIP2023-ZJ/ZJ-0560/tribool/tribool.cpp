#include<bits/stdc++.h>  // rp+++++++++++++++++++++++++++++++
using namespace std;
const int MS = 1e5 + 5;
long long dp[MS][2];
inline int read() {

    int t = 1, a = 0;
    char c = getchar();
    while(c < '0' || c > '9' && c != '-') c = getchar();
    if(c == '-') t = -1, c = getchar();
    while(c >= '0' && c <= '9') a = (a << 3) + (a << 1) + (c ^ 48), c = getchar();
    return a * t;

}
struct Node{
    int E, TF, num;
}a[MS];
int C, T, n, m;
int ans = 0;
bool vis[MS];
Node Find(Node &key) {
    vis[key.num] = 1;
    if(key.TF == 0) {
        return key;
    }
    if(key.TF == 1) {
        if(key.E > 0) {
            if(vis[key.E] == 1) {
                Node RTN;
                RTN.E = key.E;
                RTN.TF = 1;
                RTN.num = key.num;
                return RTN;
            }
            Node now = Find(a[key.E]);
            if(now.TF == 0) {

                key.E = now.E;
                key.TF = 0;
                return key;
            }
            if(now.TF == 1) {
                if(abs(now.E) == key.num) {
                        if(now.E < 0) {
                            ans++;
                            key.E = 0;
                            key.TF = 0;
                            return key;

                        }else {
                            key.E = 1;
                            key.TF = 0;
                            return key;
                        }
                    }
                else {
                    key = now;
                    return key;

                }

            }

        }else {
            if(vis[-key.E] == 1) {
                if(-key.E == key.num) {
                    key.E = 0;
                    key.TF = 0;
                    return key;
                }
                Node RTN;
                RTN.E = key.E;
                RTN.TF = 1;
                RTN.num = key.num;
                return RTN;
            }
            Node now = Find(a[-key.E]);
            if(now.TF == 0) {

                key.E = -1 * now.E;
                key.TF = 0;
                return key;
            }
            if(now.TF == 1) {
                if(abs(now.E) == key.num) {
                        if(now.E > 0) {
                            ans++;
                            key.E = 0;
                            key.TF = 0;
                            return key;

                        }else {
                            key.E = 1;
                            key.TF = 0;
                            return key;
                        }
                    }
                else {
                    key.TF = now.TF;
                    key.E = -1 * now.E;
                    return key;

                }

            }


        }
    }


}

int main() {

    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    C = read();
    T = read();
    while(T--) {
        ans = 0;
        n = read();
        m = read();
        memset(vis, 0, sizeof(vis));
        for(int i = 1; i<= n; i++) a[i].num = i, a[i].E = 1, a[i].TF = 0;
        for(int i = 1; i <= m; i++) {

            char c = getchar();

            if(c == 'T') {
                int x = read();
                a[x].E = 1;
                a[x].TF = 0;
            }
            if(c == 'F') {
                int x = read();
                a[x].E = 2;
                a[x].TF = 0;
            }
            if(c == 'U') {
                int x = read();
                a[x].E = 0;
                a[x].TF = 0;

            }
            if(c == '+') {
                int x = read(), y = read();
                a[x].E = y; a[x].TF = 1;
            }
            if(c == '-') {

                int x = read(), y = read();
                a[x].E = -1 * y; a[x].TF = 1;

            }

        }
        for(int i = 1; i <= n; i++) {

            if(a[i].E == 0 && a[i].TF == 0) ans++;

        }
        if(C == 3 || C == 4) printf("%d\n", ans);
        else {

            for(int i = 1; i <= n; i++) {
                if(!vis[a[i].num])a[i] = Find(a[i]);

            }
            ans = 0;
            for(int i = 1; i <= n; i++) {

                if(a[i].E == 0 && a[i].TF == 0) ans++;
                if(a[i].TF == 1 && a[abs(a[i].E)].E == 0 && a[abs(a[i].E)].TF == 0) ans++;
            }
            printf("%d\n", ans);
        }
    }

    return 0;

}
