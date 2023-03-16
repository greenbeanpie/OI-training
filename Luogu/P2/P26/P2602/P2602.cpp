#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
int n, a1, b1;
int sum = 0;
int dabiao[13] = {0, 1, 20, 300, 4000, 50000, 600000, 7000000, 80000000, 900000000, 10000000000, 110000000000, 1200000000000};
int c1[13] = {0};
int a(int b)
{
    int c = b % 10 - 1;
    return c * (c + 1) / 2;
}
int getlast(int a)
{
    return a % 10;
}

int t2 = 0, t3 = 1;

int count(int page, int num)
{
    int opage = page;
    if (num == 0)
    {
    }
    t2 = 0;
    sum = 0;
    int temp = 0;
    while (page)
    {
        temp = c1[t2 - 1];
        if (getlast(page) > num)
        {
            
            if (t2 == 0)
            {
                temp++;

                temp += opage - page * pow(10, t2);
            }
            else
            {
                
                temp += opage - page * pow(10, t2);
            }
        }
        else
        {
            temp += opage - page * pow(10, t2) + 1;
        }
        temp += (getlast(page)-1) * dabiao[(int)(floor(log10(opage)) - floor(log10(page)))];
        c1[t2] = temp;
        sum += temp;
        page /= 10;
        t2++;
    }
    return sum;
}

signed main()
{

    cin >> a1 >> b1;
    cout << count(b1, 1) - count(a1, 1) << endl;

    return 0;
}