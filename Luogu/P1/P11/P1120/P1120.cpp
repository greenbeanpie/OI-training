#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
int sum, maxinum, n;
int vis[70], len[70], now_len, stick_num,prefix[70];
bool isok = false;
void dfs(int now, int last, int rest)
{
	/*if(now>sum/now_len){
		isok=true;
		return;
	}*/
	// if(rest==0){
	if (!rest)
	{
		if (now == stick_num)
		{
			cout << now_len;
			exit(0);
		}
		else if(now<stick_num)
		{
			int start = now - 1;
			while (vis[start])
			{
				start = -~start;
			}
			vis[start] = 1;
			dfs(now+1, start, now_len - len[start]);
			vis[start] = 0;
			return;
			// dfs(now + 1, -1, now_len);
			// return;
		}
	}
	int start = lower_bound(len + last + 1, len + n, rest, greater<int>()) - len;
	while (1)
	{
		while (start < n && vis[start])
		{
			start = -~start;
		}
		if (start == n||prefix[start]<rest)
		{
			return;
		}
		vis[start] = true;
		dfs(now, start, rest - len[start]);
		vis[start] = false;
		if (len[start] == len[n - 1] || len[start] == rest)
		{
			return;
		}
		start = upper_bound(len + last + 1, len + n, len[start], greater<int>()) - len;
	}
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("P1120.in", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> len[i];
		sum += len[i];
	}
	sort(len, len + n, greater<int>());
	if (len[0] * 2 > sum)
	{
		cout << sum;
		exit(0);
	}
	else
	{
		prefix[n]=0;
		for(int i=n-1;i>=0;i--){
			prefix[i]=prefix[i+1]+len[i];
		}
		vis[0] = 1;
		for (now_len = len[0]; now_len <= sum / 2; now_len = -~now_len)
		{
			if (sum % now_len != 0)
			{
				continue;
			}
			stick_num = sum / now_len;

			dfs(1, 0, now_len - len[0]);
		}
	}
	cout << sum;
	return 0;
}