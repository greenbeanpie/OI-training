#include<bits/stdc++.h>

using namespace std;

const int N = 3000 + 10;
int n, m;
string s[N];

int main(void)
{
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;

    int minp = 0, cminp = 0;
    for(int i = 1; i <= n; i++)
    {
        cin >> s[i];
        sort(s[i].begin(), s[i].end(), greater<char>());
        if (minp == 0 || s[i] < s[minp])
        {
            cminp = minp;
            minp = i;
        }
        else if(cminp == 0 || s[i] < s[cminp])
        {
            cminp = i;
        }
    }

    if (n == 1)
    {
        cout << "1";
        return 0;
    }

    string gg;
    int mp;
    for(int i = 1; i <= n; i++)
    {
        mp = ((i == minp) ? cminp : minp);
        gg = s[i];
        reverse(gg.begin(), gg.end());
        if (gg < s[mp])
        {
            cout << "1";
        }
        else
        {
            cout << "0";
        }
    }

    return 0;
}