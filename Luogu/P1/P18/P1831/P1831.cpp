#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#define int long long
#define double long double
#define endl "\n"

int num[25];
cc_hash_table<int, int> f[25][25];

int dp(int nowpos/*当前处理位置*/, int fulcrum/*支点*/, int torque/*力矩*/, bool has_limit)
{
	/*if (torque <= 0)
	{
		if (torque == 0&&nowpos==0)
		{
			return 1;
		}
		return 0;
	}
	if (nowpos <= 0)
	{
		return 0;
	}*/
	if (!has_limit && f[nowpos][fulcrum].find(torque) != f[nowpos][fulcrum].end())
	{
		return f[nowpos][fulcrum][torque];
	}
	if(nowpos==0){
		if(torque==0){
			return 1;
		}
		return 0;
	}
	int max_num = 9;
	if (has_limit)
	{
		max_num = num[nowpos];
	}
	int nowans = 0;
	for (int i = 0; i < max_num; i++)
	{
		nowans += dp(nowpos - 1, fulcrum, torque + i * (nowpos - fulcrum), 0);
	}
	if(has_limit){
		nowans += dp(nowpos - 1, fulcrum, torque + max_num * (nowpos - fulcrum),1);
	}
	else{
		nowans += dp(nowpos - 1, fulcrum, torque + 9 * (nowpos - fulcrum),0);
	}
	if (!has_limit)
	{
		f[nowpos][fulcrum][torque] = nowans;
	}
	return nowans;
}

int solve(int number)
{
	if(number==0){
		return 0;
	}
	int len=log10(number)+1;
	for(int i=1;number;i++){
		num[i]=number%10;
		number/=10;
	}
	/*while(number){
		num[++len]=number%10;
		number/=10;
	}*/
	int ans = 0;
	for (int i = 1; i <= len; i++)
	{
		ans += dp(len, i, 0, 1);
	}
	return ans - len;
}

signed main()
{
#ifndef ONLINE_JUDGE
	freopen("P1831.in", "r", stdin);
	freopen("P1831.out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int l, r;
	cin >> l >> r;
	cout << solve(r) - solve(l - 1);
	return 0;
}