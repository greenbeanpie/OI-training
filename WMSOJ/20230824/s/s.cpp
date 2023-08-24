#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#define int long long
#define double long double
#define endl "\n"
#define problemname "s"
#define const constexpr
#define max(a, b) (a) > (b) ? (a) : (b)
#define min(a, b) (a) < (b) ? (a) : (b)

namespace Main
{
	int team[2005][6];
	// int minval[6][100005], minvalt[6], maxval[6][100005], cnt[100005], temp[6], tcnt1, tcnt2;
	// bool flag;
	// int main()
	// {
	// 	int n, k, idx = 0;
	// 	cin >> n >> k;
	// 	minval[0][0] = minval[1][0] = minval[2][0] = minval[3][0] = minval[4][0] = minval[5][0] = INT_MAX;
	// 	for(int i=1;i<=k;i++){
	// 		cin >> maxval[i][1];
	// 		minvalt[i]=maxval[i][1];
	// 	}
	// 	cnt[1]=1;
	// 	++idx;
	// 	cout << 1 << " ";
	// 	for (int i = 2; i <= n; i++)
	// 	{
	// 		tcnt1 = 0;
	// 		for (int j = 1; j <= k; j++)
	// 		{
	// 			cin >> temp[j];
	// 			// minvalt[j]=min(temp[j],minvalt[j]);
	// 			maxval[j][i] = max(temp[j], maxval[j][i-1]);
	// 			tcnt1 += temp[j] > maxval[j][i - 1];
	// 		}
	// 		if (tcnt1 == k)
	// 		{
	// 			for (int j = 1; j <= k; j++)
	// 			{
	// 				minval[j][idx] = minvalt[j];
	// 				minvalt[j] = temp[j];
	// 			}
	// 			++idx;
	// 		}
	// 		else if (idx != 1)
	// 		{
	// 			flag = 0;
	// 			int endpos = INT_MAX;
	// 			for (int j = 1; j <= k; j++)
	// 			{
	// 				endpos = min(endpos, lower_bound(minval[j] + 1, minval[j] + idx, temp[j]) - minval[j]);
	// 				if (endpos != idx)
	// 				{
	// 					flag = 1;
	// 				}
	// 			}
	// 			if (flag)
	// 			{
	// 				idx=endpos;
	// 				for (int j = 1; j <= k; j++)
	// 				{
	// 					minval[j][idx] = min(minval[j][idx], temp[j]);
	// 				}
	// 			}
	// 		}
	// 		cnt[idx] = i - cnt[idx - 1];
	// 		cout << cnt[idx] << " ";
	// 	}
	// 	return 0;
	// }
	int minval[100005][6],maxval[100005][6],idx,tmp[6];
	int main()
	{
		int n, k;
		cin >> n >> k;
		if (k == 1)
		{
			int maxinum = 0, cnt = 0, tmp;
			cin >> maxinum;
			++cnt;
			cout << cnt << " ";
			for (int i = 2; i <= n; i++)
			{
				cin >> tmp;
				if (tmp > maxinum)
				{
					maxinum = tmp;
					cnt = 1;
				}
				else if (tmp == maxinum)
				{
					++cnt;
				}
				cout << cnt << " ";
			}
		}
		else
		{
			for (int i = 1; i <= n; i++)
			{
				for (int j = 1; j <= k; j++)
				{
					cin >> team[i][k];
				}
			}
			for (int i = 1; i <= n; i++)
			{
				bool flag1=1,flag2=1;
				for(int j=1;j<=k;j++){
					if(team[i][j]>minval[idx][j]){
						flag1=0;
					}
					if(team[i][j]<maxval[idx][j]){
						flag2=0;
					}
				}
				if(flag1){
					
				}
			}
		}
	}
};

signed main()
{
#ifndef ONLINE_JUDGE
	freopen(problemname "1.in", "r", stdin);
	freopen(problemname ".out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	Main::main();
	return 0;
}