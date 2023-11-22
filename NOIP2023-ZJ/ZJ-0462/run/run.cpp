#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
const int MMAXN = 1e8 + 5;
const int INF = 0x3f3f3f3f;
int c, t, n, m, k, d;
int energy;
int chl[MMAXN];
int chk[MMAXN];
void dfs(int day, int keep, int egy) {
    if (day == n) {
        energy = max(energy, egy);
        return;
    }
    if (keep >= chk[day]) {
        egy += chl[day];
    }
    if (keep >= k) {
        dfs(day + 1, 0, egy);
    }else{
        dfs(day + 1, 0, egy);
        dfs(day + 1, keep + 1, egy - d);
    }
}
int main() {
    freopen("run.in", "r", stdin);
    freopen("run.out", "w", stdout);
    scanf("%d %d", &c, &t);
    int td;
    while(t--) {
        energy = -INF;
        memset(chl, 0, sizeof(chl));
        memset(chk, 0, sizeof(chk));
        scanf("%d %d %d %d", &n, &m, &k, &d);
        for (int i = 0; i < m; i++) {
            scanf("%d ", &td);
            scanf("%d", &chk[td]);
            scanf("%d ", &chl[td]);
            //cout << chk[td] << " " << chl[td] << endl;
        }
        
        dfs(0, 0, 0);
        printf("%d", energy);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}