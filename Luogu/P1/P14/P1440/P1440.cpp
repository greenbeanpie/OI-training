#include <bits/stdc++.h>
using namespace std;
#define int long long
#define map unordered_map

struct node{
    int num,cnt;
};
bool operator<(node a,node b){
    return a.num<b.num;
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("P1886.in", "r", stdin);
#endif
    int n, k;
    cin >> n >> k;
    deque<node> d;
    int nums[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%lld",nums + i);
    }
    printf("%d\n",0);
    d.push_front(node{nums[0],0});
    for (int i = 1; i < n; i++)
    {
        printf("%lld\n",d.back().num);
        while (!d.empty() && d.front().num >= nums[i])
        {
            d.pop_front();
        }
        d.push_front(node{nums[i],i});
        if (i - d.back().cnt >= k)
        {
            d.pop_back();
        }
    }
    return 0;
}