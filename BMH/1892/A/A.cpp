#include <bits/stdc++.h>
using namespace std;
#define int long long
const double Pi = 3.1415926535;

struct node
{
	int x,y;
}kun[1005];
double dis(int i , int j)
{
	double a = abs(kun[i].x - kun[j].x);
	double b = abs(kun[i].y - kun[j].y);
	return sqrt(a * a + b * b);
}
signed main()
{
    int n;
    double ans=DBL_MAX;
    cin >> n;
    for(int i = 1;i <= n;i++)
    	cin >> kun[i].x >> kun[i].y;
    for(int i = 1;i <= n;i++)
    {
    	double k = 0;
    	for(int j = 1;j <= n;j++)
    		k = max(dis(i , j) , k);
		ans = min(k * k * Pi , ans);
	}
	cout << fixed << setprecision(4) << ans;
    return 0;
}