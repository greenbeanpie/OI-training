#include <bits/stdc++.h>
int n;
int number[14][14];
int t = 0;
using namespace std;

void config(int x, int y,bool flag)
{
    for (int i = 1; i <= n; i++)
    {
        number[x][i] = flag;
        number[i][y] = flag;
    }
    if (x >= y)
    {
        for (int i = x - y + 1; i <= n-x+y; i++)
        {
            number[i][x - y + i] = flag;
            number[i][x + y - i] = flag;
        }
    }
    else{
        for(int i=y-x+1;i<=n-y+x;i++){
            number[y-x+i][i]=flag;
            number[x+y-i][i]=flag;
        }
    }
    if(flag){
        number[x][y]=2;
    }
    else{
        number[x][y]=0;
    }
}
void dfs(int x)
{ // x表示横向行数
    if (x == n)
    {
        if (t < 3)
        {
            for (int i = 1; i < n; i++)
            {
                int j = 0;
                while (j!=2)
                {
                    j++;
                }
                cout << j << " ";
            }
            cout << endl;
        }
        t++;
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            if (!number[x][i])
            {
                config(x,i,1);
                dfs(x + 1);
                config(x,i,0);
            }
        }
    }
}

int main()
{
    freopen("P1219.in", "r", stdin);
    // freopen("P1219.out","w",stdout);
    cin >> n;
    bool number[n][n];
    dfs(1);
    cout << t;
    return 0;
}