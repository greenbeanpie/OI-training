#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
int n, a1, b1;
int sum = 0;
int dabiao[13] = {0, 1, 20, 300, 4000, 50000, 600000, 7000000, 80000000, 900000000, 10000000000, 110000000000, 1200000000000};
int c1[13] = {0};

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
    int temp=0;
    int t2 = 0;
    int sum = 0;
    int c1[13]={0};
    while (page)
    {
        if (getlast(page) > num)
        {
            temp+=pow(10,t2);
            temp+=(dabiao[t2])*(getlast(page)-1);
            temp+=c1[max(t2-1,(long long)0)];
        }
        else if(getlast(page)==num)
        {
            temp++;
            temp+=opage-page*pow(10,t2);
            temp+=(dabiao[max(t2-1,(long long)0)])*(getlast(page));
        }
        else{
            temp+=c1[max(t2-1,(long long)0)];
            temp+=(dabiao[max(t2-1,(long long)0)])*(getlast(page));
        }
        sum+=temp;
        c1[t2]=temp;
        page /= 10;
        t2++;
    }
    return sum;
}

signed main()
{
    //#ifndef ONLINE_JUDGE
    //    freopen("P2602.cpp","r",stdin);
    //#endif
    //cin >> a1 >> b1;
    a1=1,b1=34;
    cout << count(b1, 1) - count(a1-1, 1) << endl;

    return 0;
}
