#include <bits/stdc++.h>
using namespace std;

namespace solve
{
    bool flag;
    string s, ans;
    unsigned N, n, M, m;
    array<unsigned, 39> c;
    array<unsigned, 3009> A, B;

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

    void main()
    {
        freopen("dict.in", "r", stdin);
        freopen("dict.out", "w", stdout);
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        cin >> n >> m;
        ans.resize(n);
        for(unsigned i(0u); i != n; ++ i)
        {
            cin >> s;
            A[i] = INT_MAX;
            for(const auto &j: s)
                qmin(A[i], j - 'a');
            for(const auto &j: s)
                qmax(B[i], j - 'a');
        }

        for(unsigned i(0u); i != n; ++ i)
        {
            flag = true;
            for(unsigned j(0u); j != n; ++ j)
                if(i != j && A[i] >= B[j])
                {
                    flag = false;
                    break;
                }
            ans[i] = flag + '0';
        }

        cout << ans << flush;
    }
}

int main()
{
    solve::main();

    return 0;
}
