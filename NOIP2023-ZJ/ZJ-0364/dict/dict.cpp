// 08:39 发现: 一个单词所有字母升序时字典序最小
// 09:00 欧, 还要判一下最小值是不是自己
// 09:03 大样例过了
#include <bits/stdc++.h>
using namespace std;
const int N = 3007, M = 3007;
char s[N][M];
char mn[M];
int pl = 1;
int main()
{
    #ifndef DEBUG
    freopen("dict.in", "r", stdin);
    freopen("dict.out","w",stdout);
    #endif
    int n, m, cc = 0;
    scanf("%d%d", &n, &m);
    for(int i = 1 ; i <= n ; i++)
    {
        scanf("%s", &s[i][1]);
        sort(&s[i][1], &s[i][m + 1], greater<char>());
        int flg = 1;
        if(i != 1)
        {
            flg = 0;
            for(int j = 1 ; j <= m ; j++)
            {
                if(mn[j] != s[i][j])
                {
                    if(mn[j] < s[i][j]) flg = 2;
                    else if(mn[j] > s[i][j]) flg = 1;
                    break;
                }
            }
        }
        if(flg == 1)
        {
            for(int j = 1 ; j <= m ; j++) mn[j] = s[i][j];
            pl = i, cc = 1;
        }
        else if(flg == 0) cc ++;
    }
    for(int i = 1 ; i <= n ; i++)
    {
        if(pl == i && cc == 1) printf("1");
        else
        {
            int flg = 0;
            for(int j = 1 ; j <= m ; j++)
            {
                if(mn[j] != s[i][m - j + 1])
                {
                    if(mn[j] < s[i][m - j + 1]) flg = 0;
                    else if(mn[j] > s[i][m - j + 1]) flg = 1;
                    break;
                }
            }
            printf("%d",flg);
        }
    }
    puts("");
    return 0;
}