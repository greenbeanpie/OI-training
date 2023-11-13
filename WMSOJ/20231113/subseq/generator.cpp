#include <bits/stdc++.h>

#define i64 long long
#define all(x) x.begin(), x.end()
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define per(i, a, b) for(int i = (a); i >= (b); i--)

using namespace std;

mt19937 mt_rand(chrono::system_clock::now().time_since_epoch().count()); 

i64 rnd(i64 l, i64 r) {
    return mt_rand() % (r - l + 1) + l;
}

int a[200001];

int main() {
#ifndef ONLINE_JUDGE
	freopen("subseq.in","w",stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int T = 2;
    cout << T << "\n";

    while(T--) {
        int n = 100000;
        cout << n << "\n";

        rep(i, 0, 199) {
            rep(j, 1, 500) {
                a[i * 500 + j] = i * 500 + (500 - j + 1);
            }
        } 

        rep(i, 1, n) cout << a[i] << " ";
        cout << "\n";
    }    

    return 0;
}
