#include <iostream>
using namespace std;
#define int long long
int cnt = 1;
int num[10];
void merge(const int *aBegin, const int *aEnd, const int *bBegin, const int *bEnd, int *c)
{
    while (aBegin != aEnd && bBegin != bEnd)
    {
        if (*bBegin < *aBegin)
        {
            cnt += aEnd - aBegin;
            *c = *bBegin;
            ++bBegin;
        }
        else
        {
            cnt += bEnd - bBegin;
            *c = *aBegin;
            ++aBegin;
        }
        ++c;
    }
    for (; aBegin != aEnd; ++aBegin, ++c)
        *c = *aBegin;
    for (; bBegin != bEnd; ++bBegin, ++c)
        *c = *bBegin;
}
void merge_sort(int *a, int l, int r)
{
    if (r - l <= 1)
    {
        return;
    }
    int mid = l + ((r - l) >> 1);
    merge_sort(a, l, mid), merge_sort(a, mid, r);
    int tmp[1024] = {0};
    merge(a + l, a + mid, a + mid, a + r, tmp + l);
    for (int i = l; i < r; i++)
    {
        a[i] = tmp[i];
    }
    return;
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("P1908.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }
    merge_sort(num, 0, n-1);
    cout << cnt;
    return 0;
}