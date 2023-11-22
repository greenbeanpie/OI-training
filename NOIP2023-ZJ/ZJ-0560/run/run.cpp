#include<bits/stdc++.h> // rp++++++++
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
struct Challenge {
    int x, y;
    long long v;

};
bool cmp(Challenge a, Challenge b) {
    return a.y < b.y;

}
vector<Challenge>a[MS];
int c, T, n, m, k, d;
int main() {

    freopen("run.in", "r", stdin);
    freopen("run.out", "w", stdout);
    c = read(); T = read();
    long long ad[MS];
    while(T--) {
        long long add = 0;
        memset(dp, 0, sizeof(dp));
        n = read();
        m = read();
        k = read();
        d = read();
        for(int i = 1; i<= n; i++) a[i].clear();
        for(int i = 1; i <= m; i++) {
            Challenge aa;
            aa.x = read(); aa.y = read(); aa.v = read();
            if(aa.y > k || aa.y > aa.x) continue;
            if(aa.x == 1 && aa.y == 1) add += aa.v;
            a[aa.x].push_back(aa);
        }
        for(int i = 1; i <= n; i++){
            sort(a[i].begin(), a[i].end(), cmp);
            int len = a[i].size();
            for(int j = 1; j < len; j++) {
                a[i][j].v += a[i][j - 1].v;
            }
            for(int j = len - 1; j >= 0; j--){
                a[i][j].v += ad[a[i][j].y - 1];
                ad[a[i][j].y] = a[i][j].v;
            }
        }
        dp[1][0] = 0;
        dp[1][1] = -d + add;
        for(int i = 2; i <= n; i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);

            for(vector<Challenge>::iterator j = a[i].begin(); j != a[i].end(); j++) {

                dp[i][1] = max(dp[i][1], dp[i - (*j).y][0] + (*j).v - d * (*j).y);

            }

        }
        printf("%lld\n", max(dp[n][1], dp[n][0]));
    }

    return 0;

}
