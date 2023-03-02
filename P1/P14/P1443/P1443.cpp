#include <bits/stdc++.h>
using namespace std;

queue<int> x;
queue<int> y;
int list1[401][401];

int main()
{
    freopen("P1443_1.in","r",stdin);
    int n, m, x1, y1;
    cin >> n >> m >> x1 >> y1;
    x.push(x1);
    y.push(y1);
    int a, b;
    memset(list1,-1,sizeof(list1));
    list1[x1][y1]=0;
    while (!x.empty())
    {
        a = x.front();
        b = y.front();
        x.pop();
        y.pop();
        if (a + 1 <= n)
        {
            if (a + 2 <= n)
            {
                if (b + 1 <= m)
                {
                    if (list1[a][b] + 1 < list1[a + 2][b + 1]||list1[a+2][b+1]==-1)
                    {
                        x.push(a + 2);
                        y.push(b + 1);
                        list1[a + 2][b + 1] = list1[a][b] + 1;
                    }
                }
                if (b - 1 >= 1)
                {
                    if (list1[a][b] + 1 < list1[a + 2][b - 1]||list1[a+2][b-1]==-1)
                    {
                        x.push(a + 2);
                        y.push(b - 1);
                        list1[a + 2][b - 1] = list1[a][b] + 1;
                    }
                }
            }
            if (b + 2 <= m)
            {
                if (list1[a + 1][b + 2] - 1 > list1[a][b] + 1||list1[a+1][b+2]==-1)
                {
                    x.push(a + 1);
                    y.push(b + 2);
                    list1[a + 1][b + 2] = list1[a][b] + 1;
                }
            }
            if (b - 2 >= 1)
            {
                if (list1[a + 1][b - 2] - 1 > list1[a][b] + 1||list1[a+1][b-2]==-1)
                {
                    x.push(a + 1);
                    y.push(b - 2);
                    list1[a + 1][b - 2] = list1[a][b] + 1;
                }
            }
        }
        if (a - 1 >= 1)
        {
            if (a - 2 >= 1)
            {
                if (b + 1 <= m)
                {
                    if (list1[a][b] + 1 < list1[a - 2][b + 1]||list1[a-2][b+1]==-1)
                    {
                        x.push(a - 2);
                        y.push(b + 1);
                        list1[a - 2][b + 1] = list1[a][b] + 1;
                    }
                }
                if (b - 1 >= 1)
                {
                    if (list1[a][b] + 1 < list1[a - 2][b - 1]||list1[a-2][b-1]==-1)
                    {
                        x.push(a - 2);
                        y.push(b - 1);
                        list1[a - 2][b - 1] = list1[a][b] + 1;
                    }
                }
            }
            if (b + 2 <= m)
            {
                if (list1[a - 1][b + 2] - 1 > list1[a][b] + 1||list1[a-1][b+2]==-1)
                {
                    x.push(a - 1);
                    y.push(b + 2);
                    list1[a - 1][b + 2] = list1[a][b] + 1;
                }
            }
            if (b - 2 >= 1)
            {
                if (list1[a - 1][b - 2] - 1 > list1[a][b] + 1||list1[a-1][b-2]==-1)
                {
                    x.push(a - 1);
                    y.push(b - 2);
                    list1[a - 1][b - 2] = list1[a][b] + 1;
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout << list1[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}