#include <bits/stdc++.h>
using namespace std;
const int N = 100000005;

bool st[N];
int primes[N];

int main()
{
    freopen("dabiao.txt","w",stdout);
    int m, n=1000005;
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
    for (int i = 0;primes[i]<=1e6; i++)
    {
        cout << primes[i] << ",";
    }
    return 0;
}