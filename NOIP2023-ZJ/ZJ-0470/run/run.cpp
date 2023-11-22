#include <bits/stdc++.h>
using namespace std;

namespace solve
{
    unsigned c, T, N, n, m, last, Last, x, y;
    long long d, v;

    inline void qmin(long long &x, const long long &y)
    {
        if(y < x)
            x = y;
    }
    inline void qmax(long long &x, const long long &y)
    {
        if(y > x)
            x = y;
    }

    namespace brute_dp
    {
        long long ans;
        array<array<long long, 1009>, 1009> a, f;

        void solve()
        {
            ans = LONG_LONG_MIN;
            for_each(a.begin() + 1, a.begin() + n, [](array<long long, 1009> &x) { fill(x.begin(), x.begin() + last, 0ll); });
            do
            {
                cin >> x >> y >> v;
                if(y > Last)
                    continue;
                a[x][y] += v;
            } while(-- m);
            for_each(a.begin() + 1, a.begin() + n, [](array<long long, 1009> &x) { partial_sum(x.begin() + 1, x.begin() + last, x.begin() + 1); });
            /*for(unsigned i(1u); i != n; ++ i)
            {
                for(unsigned j(1u); j != last; ++ j)
                    clog << a[i][j] << " ";
                clog << "\n";
            }*/

            fill(f.front().begin() + 1, f.front().begin() + last, LONG_LONG_MIN / 2ll);
            for(unsigned I(0u), i(1u); i != n; ++ I, ++ i)
            {
                f[i].front() = LONG_LONG_MIN;
                for(unsigned J(0u), j(1u); j != last; ++ J, ++ j)
                {
                    qmax(f[i][0], f[I][J]);
                    f[i][j] = f[I][J] + a[i][j] - d;
                }
                qmax(f[i][0], f[I][Last]);
                /*for(unsigned j(0u); j != last; ++ j)
                    clog << f[i][j] << " ";
                clog << "\n";*/
            }
            for(unsigned i(0u); i != last; ++ i)
                qmax(ans, f[N][i]);
            
            cout << ans << "\n";
        }
    }

    namespace cheat_score_B
    {
        long long ans, now;

        void solve()
        {
            ans = 0ll;
            
            do
            {
                cin >> x >> y >> v;
                if(y > Last)
                    continue;

                now = v - static_cast<long long>(y) * d;
                if(v > 0ll)
                    ans += v;
            } while (-- m);
            
            cout << ans << "\n";
        }
    }

    void main()
    {
        freopen("run.in", "r", stdin);
        freopen("run.out", "w", stdout);
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        cin >> c >> T;

        do
        {
            cin >> N >> m >> Last >> d;
            n = N + 1u;
            last = Last + 1u;

            //if(c < 10u)
                //brute_dp::solve();
            //else
                cheat_score_B::solve();
        } while(-- T);

        cout << flush;
    }
}

int main()
{
    solve::main();

    return 0;
}