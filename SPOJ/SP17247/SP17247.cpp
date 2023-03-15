#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
int l,r;
int sum = 0;

int a(int b)
{
    int c = b % 10 - 1;
    return c * (c + 1) / 2;
}

int t2 = 0, t3 = 1;

int count(int page)
{
	t2 = 0, t3 = 1,sum=0;
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
        sum += t3 * (page / 10) * 45;
        sum += t3 * a(page);
		sum += (page % 10) * (t2 + 1);
		t2 += (page % 10) * t3;
        t3 *= 10;
        page /= 10;
    }
    return sum;
}

signed main()
{
	int n,a,b;
	int ans1,ans2;
	cin>>n;
    for(int i = 1;i<=n;i++)
    {
    	cin>>a>>b;
		cout<<(count(b)-count(max((long long)0,a-1)))<<endl;
	}
	return 0;
}