#include <bits/stdc++.h>
using namespace std;

namespace solve
{
    bool flag;
    char op;
    unsigned c, T, N, n, Q, x, y;
    array<tuple<unsigned, unsigned, unsigned>, 100009> query;

    inline void qmin(unsigned &x, const unsigned &y)
    {
        if(y < x)
            x = y;
    }
    inline void qmax(unsigned &x, const unsigned &y)
    {
        if(y > x)
            x = y;
    }
    
    namespace brute_dfs
    {
        unsigned now, ans;
        array<unsigned, 19> a, b;

        void dfs(unsigned dep)
        {
            if(dep == n)
            {
                copy(a.begin(), a.begin() + n, b.begin());
                for(unsigned i(0u); i != Q; ++ i)
                    switch(get<0>(query[i]))
                    {
                        case 0u:
                        case 1u:
                        case 2u:
                            b[get<1>(query[i])] = get<0>(query[i]);
                            break;
                        case 4u:
                            b[get<1>(query[i])] = b[get<2>(query[i])];
                            break;
                        case 5u:
                            b[get<1>(query[i])] = b[get<2>(query[i])] == 2u ? 2u : ! b[get<2>(query[i])];
                            break;
                    }
                now = 0u;
                for(unsigned i(0u); i != n; ++ i)
                {
                    if(a[i] != b[i])
                        return;
                    now += a[i] == 2u;
                    //clog << i << " " << a[i] << " " << b[i] << "\n";
                }
                qmin(ans, now);
                return;
            }

            for(unsigned i(0u); i != 3u; ++ i)
            {
                a[dep] = i;
                dfs(dep + 1u);
            }
        }

        void solve()
        {
            ans = INT_MAX;
            dfs(0u);

            cout << ans << "\n";
        }
    }

    namespace cheat_score_3_4
    {
        unsigned ans;
        array<bool, 100009> vis;
        array<unsigned, 100009> a;

        void solve()
        {
            ans = 0u;
            fill(vis.begin(), vis.begin() + n, false);

            for(unsigned i(0u); i != Q; ++ i)
            {
                a[get<1>(query[i])] = get<0>(query[i]);
                vis[get<1>(query[i])] = true;
            }

            for(unsigned i(0u); i != n; ++ i)
                if(vis[i] && a[i] == 2u)
                    ++ ans;

            cout << ans << "\n";
        }
    }
    
    void main()
    {
        freopen("tribool.in", "r", stdin);
        freopen("tribool.out", "w", stdout);
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        cin >> c >> T;
        do
        {
            cin >> N >> Q;
            n = N + 1u;

            for(unsigned i(0u); i != Q; ++ i)
            {
                cin >> op;
                if(op == 'T')
                {
                    get<0>(query[i]) = 1u;
                    cin >> get<1>(query[i]);
                    -- get<1>(query[i]);
                }
                else if(op == 'F')
                {
                    get<0>(query[i]) = 0u;
                    cin >> get<1>(query[i]);
                    -- get<1>(query[i]);
                }
                else if(op == 'U')
                {
                    get<0>(query[i]) = 2u;
                    cin >> get<1>(query[i]);
                    -- get<1>(query[i]);
                }
                else if(op == '+')
                {
                    get<0>(query[i]) = 4u;
                    cin >> get<1>(query[i]) >> get<2>(query[i]);
                    -- get<1>(query[i]);
                    -- get<2>(query[i]);
                }
                else if(op == '-')
                {
                    get<0>(query[i]) = 5u;
                    cin >> get<1>(query[i]) >> get<2>(query[i]);
                    -- get<1>(query[i]);
                    -- get<2>(query[i]);
                }
            }

            switch(c)
            {
                case 1u:
                case 2u:
                    brute_dfs::solve();
                    break;
                case 3u:
                case 4u:
                    cheat_score_3_4::solve();
                    break;
            }
        } while(-- T);

        cout << flush;
    }
}

int main()
{
    solve::main();

    return 0;
}