#include <bits/stdc++.h>
using namespace std;
#define int long long
long long quickpower(long long a, long long b)
{
    if (b == 0)
    {
        return 1;
    }
    long long answer = 1;
    while (b)
    {
        if (b & 1)
        {
            answer = answer * a;
        }
        a = a * a;
        b >>= 1;
    }
    return answer;
}

signed main()
{
    int t;
    cin >> t;
    int x3[39];
    x3[0] = 1;
    for (int i = 1; i < 39; i++)
    {
        x3[i] = x3[i - 1] * 3;
    }
    for (int i = 0; i < t; i++)
    {
        int x10;
        cin >> x10;
        int sum = 0;
        int t = log(x10) / log(3);
        if (x10 % 3 == 2)
        {
            cout << 0 << endl;
            continue;
        }
        else if(x10%3==1){
            x10--;
        }
        for (int j = t+1; j > 0; j--)
        {
            if (x10 >= x3[j])
            {
                
                sum++;
                x10%=x3[j];
            }
            if (x10 == 0)
            {
                break;
            }
        }
        cout << quickpower(2, sum) << endl;
    }
    return 0;
}