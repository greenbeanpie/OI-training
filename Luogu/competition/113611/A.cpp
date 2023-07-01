#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("A.in","r",stdin);
    #endif
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        int n;
        cin >> n;
        int ans=floor(log2(n));
        if((1ll<<(ans+1))-n<n-(1ll<<ans)){
            ans++;
        }
        cout << ans+2 << endl;
    }
    return 0;
}