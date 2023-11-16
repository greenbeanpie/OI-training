#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double

int n;
double l, r;

double k[15];

double eps = 1e-6;

double f(double x)
{
	double ans = 0;
	for (int i = n; i >= 0; i--)
	{
		ans *= x;
		ans += k[i];
	}
	return ans;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> l >> r;
	for (int i = n; i >= 0; i--)
	{
		cin >> k[i];
	}
	while(fabs(r-l)>=eps){
		auto mid = (l + r) /2;
		if(f(mid+eps)>f(mid-eps)){
			l = mid;
		}
		else{
			r = mid;
			
		}
	}
	cout << fixed << setprecision(5) << l << endl;
	return 0;
}