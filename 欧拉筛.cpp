#include <bits/stdc++.h>
using namespace std;
const int N = 100000005;

bool st[N];
int primes[N];

int main()
{
    int m, n;
    cin >> n >> m;
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
    for (int i = 0; i < m; i++)
    {
        cin >> num;
        cout << primes[num - 1] << endl;
    }
    return 0;
}