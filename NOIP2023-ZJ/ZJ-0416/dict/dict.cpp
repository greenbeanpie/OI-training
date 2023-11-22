#include <bits/stdc++.h>
using namespace std;

long long N, M;
char w[3005][3005];
char z[3005][3005], f[3005][3005];

signed main()
{
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    cin >> N >> M;
    if(N == 1) { puts("1"); return 0; }
    for(long long i = 1; i <= N; ++ i)
    {
        scanf("%s", w[i] + 1);
        sort(w[i] + 1, w[i] + M + 1, less<long long>());
        for(long long j = 1; j <= M; ++ j)
            z[i][j] = w[i][j];

        // cout << "Sort" << i << ": " << (w[i] + 1) << endl;
        sort(w[i] + 1, w[i] + M + 1, greater<long long>());
        // cout << "Sort" << i << "(rev): " << (w[i] + 1) << endl;
        for(long long j = 1; j <= M; ++ j)
            f[i][j] = w[i][j];
    }

    for(long long i = 1; i <= N; ++ i)
    {
        bool flag = true;
        for(long long j = 1; j <= N; ++ j)
        {
            if(i == j) continue;
            if(!flag) break;
            for(long long k = 1; k <= M; ++ k)
            {
                if(z[i][k] > f[j][k]) 
                {
                    // prlong longf("Compare i = %d, j = %d, Died on k = %d, z[i][k] = %c, f[j][k] = %c\n", i, j, k, z[i][k], f[j][k]);
                    flag = false;
                    break;
                }

                if(z[i][k] < f[j][k])
                    break;
            }
        }
        
        if(!flag) putchar('0');
        else putchar('1');
        // cout << endl;
    }
    // for(long long i = 0; i < 26; ++ i)
    //     cout << pos_z[8][i] << ' ' << pos_f[8][i] << endl;
    return 0;
}

/*
15 2
zx
qn
wn
nd
pl
pd
vm
ff
mh
ql
zi
yv
md
ji
oc
*/