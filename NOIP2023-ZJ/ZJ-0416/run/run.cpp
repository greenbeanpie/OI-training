#include <bits/stdc++.h>
using namespace std;

long long T, C;
long long N, M, K, D;
struct Line {
    long long x, y, v;
} arr[100005];

bool cmp(Line x, Line y)
{
    return x.y > y.y;
}

long long calc(long long status)
{
    long long res = 0;
    int cover[105];
    memset(cover, 0, sizeof(cover));
    for(long long i = 1; i <= N; ++ i)
    {
        if((status & (1 << i)) && arr[i].y <= D)
        {
            for(long long k = arr[i].x - arr[i].y + 1; k <= arr[i].x; ++ k)
                cover[k] = 1;

            res += arr[i].v;
        }
    }

    for(long long i = 1; i <= 100; ++ i)
        res -= cover[i] * D;

    return res;
}

signed main()
{
    freopen("run.in", "r", stdin);
    freopen("run.out", "w", stdout);
    cin >> C >> T;
    if(C == 17 || C == 18)
    {
        while(T --)
        {
            long long ans = 0;
            cin >> N >> M >> K >> D;
            memset(arr, 0, sizeof(arr));
            for(long long i = 1; i <= M; ++ i)
                cin >> arr[i].x >> arr[i].y >> arr[i].v;

            for(long long i = 1; i <= M; ++ i)
                if(arr[i].v - arr[i].y * D >= 0 && arr[i].y <= K) ans += (arr[i].v - arr[i].y * D);

            cout << ans << endl;
        }
    }
    if(C == 1 || C == 2)
    {
        while(T --)
        {
            long long ans = 0;
            cin >> N >> M >> K >> D;
            for(long long i = 1; i <= M; ++ i)
                cin >> arr[i].x >> arr[i].y >> arr[i].v;

            for(long long status = 1; status < (1 << (N + 1)); ++ status)
                ans = max(ans, calc(status));
            
            // cout << calc(1100) << endl;
            cout << ans << endl;
        }
        
    }
    return 0;
}

/*
1 1
100 3 4 2
2 1 5
4 2 10
7 2 20
*/