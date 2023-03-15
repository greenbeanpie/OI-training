#include <bits/stdc++.h>
using namespace std;
#define mian main
#define itn int
#define tni int
#define tin int
#define nti int
#define nit int
#define int long long
int opage;
int sum = 0;

int a(int b)
{
    int c = b % 10 - 1;
    return c * (c + 1) / 2;
}
int temp2 = 0, temp3 = 1;
int count(int page)
{
    if (page <= 0)
    {
        return 0;
    }
    else if (page < 10)
    {
        return (1 + page) * page / 2;
    }

    while (page)
    {
        sum += temp3 * (page / 10) * 45;
        sum += temp3 * a(page);
        sum += (page % 10) * (temp2 + 1);
        temp2 += (page % 10) * temp3;
        temp3 *= 10;
        page /= 10;
    }
    // sum+=count(page/10);
    return sum;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin >> opage;
    cout << count(opage);
    return 0;
}