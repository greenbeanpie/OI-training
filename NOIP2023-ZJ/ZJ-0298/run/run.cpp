#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>

using namespace std;

struct task
{
    long long x, y, v;
};

vector<task> waitTask;
long long n, m, k, d;

namespace noob
{
    long long solve(long long t, long long len, long long has)
    {
        long long res = 0;
        for (long long i = t; i < waitTask.size(); i++)
        {
            if (waitTask[i].x - waitTask[i].y > len + 1)
            {
                res = max(waitTask[t].v + solve(i + 1, waitTask[i].x, waitTask[i].y), res);
            }
            if (waitTask[i].x - waitTask[i].y == len + 1 && waitTask[i].y + has <= k)
            {
                res = max(waitTask[t].v + solve(i + 1, waitTask[i].x, waitTask[i].y + has), res);
            }
        }
        return res;
    }
}

int main()
{
    freopen("run.in", "r", stdin);
    freopen("run.out", "w", stdout);
    long long c, T;
    scanf("%lld%lld", &c, &T);
    while (T--)
    {
        scanf("%lld%lld%lld%lld", &n, &m ,&k, &d);
        for (long long i = 1; i <= m; i++)
        {
            long long x, y, v;
            scanf("%lld%lld%lld", &x, &y, &v);
            if (y > x) continue;
            if (y > k) continue;
            if (x > n) continue;
            task temp;
            temp.x = x;
            temp.y = y;
            temp.v = v - y * d;
            if (temp.v <= 0) continue;
            waitTask.push_back(temp);
            // printf("ADD NEW TASK: [%lld, %lld, %lld]\n", temp.x, temp.y, temp.v);
        }
        printf("%lld\n", noob::solve(0, -1e9, 0));
        waitTask.clear();
    }
    return 0;
}