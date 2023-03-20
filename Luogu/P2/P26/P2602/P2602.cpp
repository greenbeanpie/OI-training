#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
using namespace std;
#define int long long
#define mod 1000000007
int n, a1, b1;
int sum = 0;
int dabiao[13] = {0, 1, 20, 300, 4000, 50000, 600000, 7000000, 80000000, 900000000, 10000000000, 110000000000, 1200000000000};
int c1[13] = {0};

int getfirst(int a)
{
    return floor(a / pow(10, floor(log10(a))));
}
int getlast(int a)
{
    return a % 10;
}
int getnotfirst(int a){
    return a-(getfirst(a)*(pow(10,floor(log10(a)))));
}
int getnotlast(int a){
    return a/10;
}
int getlen(int a){
    return floor(log10(a))+1;
}
int t2 = 0, t3 = 1;

int count(int page, int num)
{
    int sum = 0;
    if (num == 0)
    {
        return sum;
    }
    if (page == 0)
    {
        return 0;
    }
    if (page < 10)
    {
        if(page>=num){
        return 1;}
        else{
            return 0;
        }
    }
    for (int i = 0; i < getfirst(page); i++)
    {
        sum += dabiao[getlen(page)-1];
    }
    if (getfirst(page) > num)
    {
        sum+=pow(10,getlen(page)-1);
    }
    else if (num == getfirst(page))
    {
        sum+=getnotlast(page);
    }

    sum += count(getnotfirst(page), num);
    return sum;
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("P2602.in", "r", stdin);
    freopen("P2602.out", "w", stdout);
#endif
    cin >> a1 >> b1;
    for (int i = 0; i <= 9; i++)
    {
        cout << count(b1, i) - count(a1 - 1, i) << " ";
    }
    return 0;
}