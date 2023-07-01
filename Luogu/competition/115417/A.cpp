#include <bits/stdc++.h>
using namespace std;
#define int long long

int dabiao[1000005];
int a[1000005];
pair<int, int> lr[1000005];
const int mod=1e9+7;
bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.first == b.first)
    {
        return a.second > b.second;
    }
    return a.first < b.first;
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("A.in", "r", stdin);
#endif
    int n, m, x, y;
    scanf("%lld %lld %lld %lld",&n,&m,&x,&y);
    dabiao[1] = dabiao[2] = 1;
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld",a+i);
		a[i]%=mod;
    }
    int maxinum = 1;
    for (int i = 1; i <= m; i++)
    {
        scanf("%lld %lld",&lr[i].first, &lr[i].second);
        maxinum = max(maxinum, lr[i].second - lr[i].first + 1);
    }
    for(int i=3;i<=maxinum;i++){
        dabiao[i]=x*dabiao[i-1]+y*dabiao[i-2];
		dabiao[i]%=mod;
    }
    sort(lr + 1, lr + m + 1, cmp);
    for (int i = 1; i <= m; i++)
    {
        int start = i;
        while (i + 1 <= m && lr[i + 1].first == lr[i].first)
        {
            i++;
        }
        int end = i;
        for (int j = lr[start].first; j <= lr[start].second; j++)
        {
            while (lr[end].second < j)
            {
                end--;
            }
            a[j] = (a[j]+(end - start + 1) * dabiao[j - lr[start].first + 1])%mod;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        printf("%lld ",a[i]);
    }
    return 0;
}