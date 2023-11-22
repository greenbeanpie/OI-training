#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>

using namespace std;

char str[3005][3005];
char temp[3005];
int ans[3005];

bool cmpMax(char a, char b)
{
    return (int)a > (int)b;
}

bool cmpMin(char a, char b)
{
    return (int)a < (int)b;
}

int n, m;

bool check(char *a, char *b)
{
    for (int i = 0; i < m; i++)
    {
        if ((int)a[i] == (int)b[i]) continue;
        else if ((int)a[i] > (int)b[i]) return false;
        return true;
    }
    return true;
}

int main()
{
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> str[i];
    for (int i = 1; i <= n; i++) sort(str[i], str[i] + m, cmpMax);
    for (int i = 1; i <= n; i++)
    {
        ans[i] = 1;
        for (int j = 0; j < m; j++) temp[j] = str[i][j];
        sort(temp, temp + m, cmpMin);
        for (int j = 1; j <= n; j++)
        {
            if (i == j) continue;
            bool tmp = check(temp, str[j]);
            if (tmp && ans[j] == 1) break;
            ans[i] &= tmp;
            if (ans[i] == 0) break;
        }
       	cout << ans[i];
    }
    return 0;
}
