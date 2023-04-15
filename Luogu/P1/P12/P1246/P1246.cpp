#include <bits/stdc++.h>
using namespace std;
#define int long long
map<string, int> dabiao;
int cnt = 0;

void dfs(int n, string a)
{
    if (n == 6)
    {
        if (a != "")
        {
            dabiao[a] = ++cnt;
        }
        return;
    }
    dfs(n + 1, a);
    for (string i = a[a.length() - 1]; i <= 'z'; i += 1)
    {
        dfs(n + 1, a+i);
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    char str[6];
    for(int i=0;i<6;i++){
        cin >> char[i];
    }
    dfs(0, str);
    cin >> str;
    cout << dabiao[str];
    return 0;
}