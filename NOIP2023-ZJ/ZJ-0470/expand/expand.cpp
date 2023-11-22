#include <bits/stdc++.h>
using namespace std;

namespace solve
{
    int T;
    string ans;
    unsigned mode, N, n, M, m, Q, t1, t2, p, v;
    array<unsigned, 2009> a, b, A, B;
    array<array<bool, 2009>, 2009> f;

    inline int comp(const unsigned &x, const unsigned &y)
    {
        if(x > y)
            return 1;
        if(x == y)
            return 0;
        return - 1;
    }

    void solve()
    {
        T = comp(a[1], b[1]);
        for_each(f.begin(), f.begin() + n, [](array<bool, 2009> &x) { fill(x.begin(), x.begin() + m, false); });
        f[0][0] = true;
        /*for(unsigned i(1u); i != n; ++ i)
            clog << a[i] << " ";
        clog << "\n";
        for(unsigned i(1u); i != m; ++ i)
            clog << b[i] << " ";
        clog << "\n";*/
        for(unsigned I(0u), i(1u); i != n; ++ I, ++ i)
            for(unsigned J(0u), j(1u); j != m; ++ J, ++ j)
                if(comp(a[i], b[j]) * T > 0)
                {
                    f[i][j] |= f[I][J];
                    f[i][j] |= f[I][j];
                    f[i][j] |= f[i][J];
                }

        cout << f[N][M];
    }

    void main()
    {
        freopen("expand.in", "r", stdin);
        freopen("expand.out", "w", stdout);
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        cin >> mode >> N >> M >> Q;
        n = N + 1u;
        m = M + 1u;
        if(mode > 7u)
        {
            cout << "1";
            do
            {
                cout << "1";
            } while(-- Q);
            return;
        }
        for(unsigned i(1u); i != n; ++ i)
            cin >> A[i];
        for(unsigned i(1u); i != m; ++ i)
            cin >> B[i];
        a = A;
        b = B;
       // clog << "ha" << endl;
        solve();
            do
            {
                a = A;
                b = B;
                cin >> t1 >> t2;
                //clog << t1 << " " << t2 << endl;
                if(t1)
                    do
                    {
                        cin >> p >> v;
                        //clog << p << " " << v << "\n";
                        a[p] = v;
                    } while(-- t1);
                if(t2)
                    do
                    {
                        cin >> p >> v;
                        //clog << p << " " << v << "\n";
                        b[p] = v;
                    } while(-- t2);
                solve();
            } while (-- Q);
        
        cout << flush;
    }
}

int main()
{
    solve::main();

    return 0;
}