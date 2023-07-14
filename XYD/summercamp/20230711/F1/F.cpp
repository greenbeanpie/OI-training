#include <iostream>
using namespace std;

int n, k, a[100005], maxn;
bool check (int len){
    int cnt = 0;
    for (int i=1; i<=n; ++i){
        cnt += a[i]/len;
    }
    return cnt >= k;
}
int main(){
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for (int i=1; i<=n; ++i){
        cin >> a[i];
        maxn = max(maxn, a[i]);
    }
    int L = 0, R = maxn, mid;
    while (L < R){
        mid = L+R+1 >> 1;
        if (check(mid)) L = mid;
        else R = mid - 1;
    }
    cout << L << endl;
    return 0;
}
