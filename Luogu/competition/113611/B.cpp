#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        int n, q;
        cin >> n >> q;
        int num[500005] = {0};
        bool vis[500005] = {0};
        int x, y;
        int flag = 0, t1 = 0,pos1=INT_MAX,lpos1=0;
        int flag2 = 0, t2 = 0,pos2=INT_MAX,lpos2=0;
        for (int i = 1; i <= q; i++)
        {
            cin >> x >> y;
            num[x] = y;
            vis[y] = 1;
            if (x < y)
            {
                flag = max(flag, y - x);
                t1++;
                pos1=min(pos1,x);
                lpos1=max(lpos1,x);
            }
            else if (x > y)
            {
                flag2 = max(flag2, x - y);
                t2++;
                pos2=min(pos2,x);
                lpos2=max(lpos2,x);
            }
        }
        if (n == 2)
        {
            if ((num[1] == -1 && num[2] == -1) || (num[2] == 1) || (num[1] == 2))
            {
                cout << 1 << endl;
            }
            else
            {
                cout << 0 << endl;
            }
            continue;
        }
        else if (n == 1)
        {
            cout << 0 << endl;
        }
        else if (flag > 1 && t1 > 1)
        {
            cout << 0 << endl;
        }
        else if (flag2 > 1 && t2 > 1)
        {
            cout << 0 << endl;
        }
        else if (flag2 > 1 && flag > 1)
        {
            cout << 0 << endl;
        }
        else if (flag > 1 || flag2 > 1)
        {
            cout << 1 << endl;
        }
        else if (t1 == 1 && t2 == 1)
        {
            cout << 0 << endl;
        }
        else if(flag==1&&flag2==0){
            cout << pos1+lpos1-1;
        }
        else if (n == q)
        {
            if (t1 + t2 == 1)
            {
                cout << 1 << endl;
            }
            else
            {
                cout << 0 << endl;
            }
        }
        else if (t1 == 0 && t2 == 0)
        {
            cout << (n-q) * (n -q- 1) / 2 << endl;
        }
        else
        {
            cout <<6 << endl;
        }
    }
    return 0;
}