#include <bits/stdc++.h>
using namespace std;

int C, T;
int N, M;

int val[200005];
pair<int, char> lastopr[200005];
int father[200005];

int getfather(int x)
{
    // if(x > N * 2) return x;
    if(father[x] == x) return x;
    else return father[x] = getfather(father[x]);
}

bool visited[200005], instk[200005];
int top, stk[200005];

void dfs(int u)
{
    visited[u] = instk[u] = true;
    stk[++ top] = u;
    if(visited[father[u]]) return;
    dfs(father[u]);
}

signed main()
{
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    cin >> C >> T;
    while(T --)
    {
        int ans = 0;
        cin >> N >> M;
        for(int i = 1; i <= N * 2 + 3; ++ i)
            father[i] = i;

        for(int i = 1; i <= M; ++ i)
        {
            char v;
            cin >> v;
            father[N * 2 + 1] = N * 2 + 1;
            father[N * 2 + 2] = N * 2 + 2;
            father[N * 2 + 3] = N * 2 + 3;
            if(v == 'T' || v == 'F' || v == 'U')
            {
                int x;
                cin >> x;
                if(v == 'T') father[x] = N * 2 + 2, father[x + N] = N * 2 + 1; 
                if(v == 'F') father[x] = N * 2 + 1, father[x + N] = N * 2 + 2; 
                if(v == 'U') father[x] = father[x + N] = N * 2 + 3; 
            }

            if(v == '+' || v == '-')
            {
                int x, y;
                cin >> x >> y;
                father[getfather(x)] = getfather(y);
                // getfather(x);
            }

            father[N * 2 + 1] = N * 2 + 1;
            father[N * 2 + 2] = N * 2 + 2;
            father[N * 2 + 3] = N * 2 + 3;
            // for(int j = 1; j <= N * 2 + 3; ++ j)
            //     cout << father[j] << ' ';

            // cout << endl;
        }
        
        for(int i = 1; i <= N * 2; ++ i)
        {
            if(father[i] == N * 2 + 3 && i <= N) ++ ans;
            if(!visited[i]) 
            {
                memset(instk, 0, sizeof(instk));
                top = 0;
                dfs(i);
                for(int j = 1; j <= top; ++ j)
                {
                    int ele = stk[j];
                    if(ele > N && instk[ele - N]) ++ ans;
                    if(ele < N && instk[ele + N]) ++ ans;
                }
            }
        }

        cout << ans << endl;
    }   

    return 0;
}