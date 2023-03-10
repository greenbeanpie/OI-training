#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#pragma GCC optimize(3)

int n, m, num[1000005], maxinum = -1;

int a(int len)
{
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (num[i] > len)
        {
            sum += num[i] - len;
        }
    }
    return sum;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
        
        maxinum = max(num[i],maxinum);
    }
    int l = 0, r = maxinum;
    int mid;
    while (l < r)
    {
        mid = (l + r) / 2;
        int t = a(mid);
        if (t > m)
        {
            l = mid + 1;
        }
        else if (t < m)
        {
            r = mid;
        }
        if (abs(r - l) <= 0 || t == m)
        {
            break;
        }
    }
    while (a(mid + 1) >= m)
    {
        mid++;
    }
    if(a(mid)<m){
        mid--;
    }
    cout << mid;
    return 0;
}