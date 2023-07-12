#include<bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;
int n, con, h[N], ans = 1;

int main() {
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    if (h[2] >= h[1]) {
        con = 1;
    }
    for (int i = 1; i <= n; i++) {
        if (con == 0 && i == n) {
            ans++;
            break;
        }
        if (con ==1 && h[i + 1] < h[i]) {
            ans++;
            con = 0;
            continue;
        }
        if (con == 0 && h[i + 1]> h [i]) {
            ans++;
            con = 1;
            continue;
        }
    }
    cout << ans << endl;
    return 0;
}