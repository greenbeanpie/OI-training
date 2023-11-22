#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
const int INF = 0x3f3f3f3f;
int c, q, n, m;

int main() {
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);
    cin >> c >> n >> m >> q;
    if (c == 1) {
        int x, y;
        cin >> x >> y;
        string ans = "";
        if (x == y) {
            ans += '0';
        }else{
            ans += '1';
        }
        int kx, ky;
        int px, vx, py, vy;
        while(q--) {
            cin >> kx >> ky;
            while(kx--) {
                cin >> px >> vx;
            } 
            while(ky--) {
                cin >> py >> vy;
            }
            if (vx == vy) {
                ans += '0';
            }else{
                ans += '1';
            }
        }
        cout << ans << endl;
        return 0;
    }else{
        int a[MAXN], b[MAXN];
        int maa1 = -INF, maa2 = -INF, mia1 = INF, mia2 = INF;
        int mab1 = -INF, mab2 = -INF, mib1 = INF, mib2 = INF;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            if (a[i] >= maa1) {
                maa2 = maa1;
                maa1 = a[i];
            }else if (a[i] >= maa2) {
                maa2 = a[i];
            }
            if (a[i] <= mia1) {
                mia2 = mia1;
                mia1 = a[i];
            }else if (a[i] <= mia2) {
                mia2 = a[i];
            }
        }
        for (int i = 1; i <= m; i++) {
            scanf("%d", &b[i]);
            if (b[i] >= mab1) {
                mab2 = mab1;
                mab1 = b[i];
            }else if (b[i] >= mab2) {
                mab2 = b[i];
            }
            if (b[i] <= mib1) {
                mib2 = mib1;
                mib1 = b[i];
            }else if (b[i] <= mib2) {
                mib2 = b[i];
            }
        }
        string ans = "";
        if (maa1 < mib1 || maa2 < mia1) {
            ans += "1";
        }else{
            ans += "0";
        }
        
        int kx, ky;
        int px, vx, py, vy;
        while(q--) {
            cin >> kx >> ky;
            while(kx--) {
                cin >> px >> vx;
                a[px] = vx;
            } 
            while(ky--) {
                cin >> py >> vy;
                b[py] = vy;
            }
            if (vx == vy) {
                ans += '0';
            }else{
                ans += '1';
            }
        }
        cout << ans << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}