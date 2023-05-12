#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int n, m;
    cin >> n >> m;
    if (n == 0) {
        cout << "-" << m * m;
        return 0;
    }
    if (m == 0) {
        cout << n * n;
        return 0;
    }
    if (n == m) {
        if (n % 2 == 0) {
            cout << n * n / 2;
        }
        else {
            cout << n * n - (n - 1) * (n - 1) / 4 - (n + 1) * (n + 1) / 4;
            return 0;
        }
    }
    if (n > m) {
        int b;
        if (m % 2 == 1) {
            b = (m - 1) * (m - 1) / 4 + (m + 1) * (m + 1) / 4;
        }
        else{
            b=m*m/2;
            return 0;
        }
        cout << n * n - b;
    }
    else {

        return 1;
    }
}