#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
#define int long long
const int N = 1e8;
#pragma GCC optimize("Ofast")
bitset<N> st;
cc_hash_table<int, int> primes;

signed main()
{
    freopen("dabiao.txt","w",stdout);
	ios::sync_with_stdio(false);
	cout.tie(0);
	int m, n = 1e8;
	//cin >> n >> m;
    int cnt = 0;
    for (int i = 2; i <= N; i++)
    {
        if (!st[i])
        {
            primes[cnt++] = i;
        }
        for (int j = 0; primes[j] <= n / i; j++)
        {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0)
            {
                break;
            }
        }
    }
    int num;
    for (int i = 0;primes[i]<=1e8; i++)
    {
        cout << primes[i] << ",";
    }
    return 0;
}
