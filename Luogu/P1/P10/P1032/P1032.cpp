#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("P1032.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    string start, end;
    cin >> start >> end;
    int i = 0;
    string stra[20], strb[20];
    while (cin >> stra[i] >> strb[i])
    {
        i++;
    }
    unordered_map<string,int> step;
    step[start]=0;
    queue<string> q;
    q.push(start);
    
    return 0;
}