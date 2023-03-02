#include <bits/stdc++.h>
int n;
int number[14][14];
int result[14][14];
int t = 0;
using namespace std;

void config(int x, int y,int flag)
{
    for (int i = 1; i <= n; i++)
    {
        
        number[x][i] += flag;
        number[i][y] += flag;
    }
    for(int i=1;i<=max(n,x+y);i++){
        if(y+x-i>=1&&y+x-i<=n&&i<=n){
            number[i][x+y-i]+=flag;
        }
        if(y-x+i>=1&&y-x+i<=n&&i<=n){
            number[i][y-x+i]+=flag;
        }
    }
    if(flag==1){
        result[x][y]=1;
    }
    else{
        result[x][y]=0;
    }
}
void dfs(int x)
{ // x表示横向行数
    if (x == n+1)
    {
        if (t < 3)
        {
            for (int i = 1; i <= n; i++)
            {
                int j = 1;
                while (result[i][j]!=1)
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
                config(x,i,-1);
            }
        }
    }
}

int main()
{
    freopen("P1219.in", "r", stdin);
    // freopen("P1219.out","w",stdout);
    cin >> n;
    memset(number,0,sizeof(number));
    dfs(1);
    cout << t;
    return 0;
}