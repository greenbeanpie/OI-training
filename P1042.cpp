#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("P1042.in", "r", stdin);
    string a;
    pair<int, int> score11[62500], score21[62500];
    int s1w = 0, s1l = 0, s2w = 0, s2l = 0, s1n = 0, s2n = 0;
    bool flag = true;
    while (flag)
    {
        cin >> a;
        for (int i = 0; i < a.length(); i++)
        {
            if (a[i] == 'W')
            {
                s1w++;
                s2w++;
            }
            else if (a[i] == 'L')
            {
                s1l++;
                s2l++;
            }
            else if (a[i] == 'E')
            {
                flag = false;
            }
            if ((s1w>=11|| s1l >= 11)&&abs(s1w-s1l)>=2)
            {
                score11[s1n].first = s1w;
                score11[s1n].second = s1l;
                s1n++;
                s1w = 0;
                s1l = 0;
            }
            if ((s2w>=21|| s2l >= 21)&&abs(s2w-s2l)>=2)
            {
                score21[s2n].first = s2w;
                score21[s2n].second = s2l;
                s2n++;
                s2w = 0;
                s2l = 0;
            }
        }
    }
    score11[s1n].first = s1w;
    score11[s1n].second = s1l;
    s1n++;
    score21[s2n].first = s2w;
    score21[s2n].second = s2l;
    s2n++;
    for (int i = 0; i < s1n; i++)
    {
        cout << score11[i].first << ":" << score11[i].second << endl;
    }
    cout << endl;
    for (int i = 0; i < s2n; i++)
    {
        cout << score21[i].first << ":" << score21[i].second << endl;
    }
    return 0;
}