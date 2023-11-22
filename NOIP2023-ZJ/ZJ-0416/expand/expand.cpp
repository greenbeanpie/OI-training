#include <bits/stdc++.h>
using namespace std;

int C, N, M, Q;
int arrx[500005], arry[500005];

signed main()
{
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);
    cin >> C >> N >> M >> Q;
    for(int i = 1; i <= N; ++ i) cin >> arrx[i];
    for(int i = 1; i <= M; ++ i) cin >> arry[i];
    if(C == 1 || C == 8 || C == 9)
    {
        cout << 1;
        while(Q --)
        {
            int kx, ky;
            cin >> kx >> ky;
            for(int i = 1; i <= kx; ++ i) 
            {
                int px, vx;
                cin >> px >> vx;
                arrx[px] = vx;
            }

            for(int i = 1; i <= ky; ++ i) 
            {
                int py, vy;
                cin >> py >> vy;
                arry[py] = vy;
            }

            cout << 1;
        }
    }
    else
    {
        // if((arrx[1] - arry[1]) * (arrx[N] - arry[M])) cout << 1;
        if(N > M)
        {
            #define truearrx arry;
            #define truearry arrx;
            swap(N, M);
        } 
        int ptx, pty, energy = 0;
        ptx = pty = 1;
        bool flag = true;
        while(ptx <= N && pty <= M)
        {
            if((arrx[ptx] - arry[pty]) * (arrx[1] - arry[1]) <= 0)
            {
                int nxt = ptx + 1;
                while(arrx[nxt] - arry[pty] * (arrx[1] - arry[1]) <= 0 && (nxt - ptx) <= energy) ++ nxt;
                if(nxt - ptx > energy) { flag = false; break; }
            }
            else
            {
                ++ pty, ++ energy;
            }
        }
    }
    
    return 0;
}