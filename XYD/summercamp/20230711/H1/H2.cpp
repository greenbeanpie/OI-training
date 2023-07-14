#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 300003, INF = 0x7f7f7f7f;
int low[maxn], a[maxn], pos[maxn];
int ans[maxn];
int N, len;
int main()
{
    cin >> N;
    for(int i=0;i<N;i++)
    {
        cin>>a[i];
    }
    len = 1;
    low[1] = a[0];
    pos[0] = len;
    for (int i = 1; i < N; i++)
    {
        if (a[i] > low[len])
        {
            low[++len] = a[i];
            pos[i] = len; // 记录a[i]在dp数组中出现的位置
        }
        else
        {
            int m = lower_bound(low + 1, low + len + 1, a[i]) - low -1 + 1;
            low[m] = a[i];
            pos[i] = m;
        }
    }
    int tlen=len;
    for (int i = N - 1; i >= 0; i--)
    {
        if (!len)
            break;
        if (pos[i] == len)
        {
            ans[len] = i;
            len--;
        }
    }
    for (int i = 1; i <= tlen; i++)
    {
        cout << a[ans[i]]<<' ';
    }
}