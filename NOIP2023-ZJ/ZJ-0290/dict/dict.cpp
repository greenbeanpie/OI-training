#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 3e3 + 10;

int n, m;
string s[MAXN], maxs[MAXN], mins[MAXN];
string pre[MAXN], suf[MAXN];

int cnt[26];

void sort1(string &str)
{
	for (int i = 0; i < 26; i++)
		cnt[i] = 0;
	for (int i = 0; i < m; i++)
		cnt[str[i]-'a']++;
	for (int i = 1; i < 26; i++)
		cnt[i] += cnt[i - 1];
	string ans = str;
	for (int i = m - 1; i >= 0; i--)
		ans[--cnt[str[i]-'a']] = str[i];
	str = ans;
}

void sort2(string &str)
{
	for (int i = 0; i < 26; i++)
		cnt[i] = 0;
	for (int i = 0; i < m; i++)
		cnt[str[i]-'a']++;
	for (int i = 24; i >= 0; i--)
		cnt[i] += cnt[i + 1];
	string ans = str;
	for (int i = m - 1; i >= 0; i--)
		ans[--cnt[str[i]-'a']] = str[i];
	str = ans;	
}

int main()
{
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> s[i];
		maxs[i] = mins[i] = s[i];
	}
	for (int i = 1; i <= n; i++)
	{
		sort1(mins[i]);
		sort2(maxs[i]);
//		cout << mins[i] << ' ' << maxs[i] << endl;
	}
	
	pre[1] = maxs[1];
	for (int i = 2; i <= n; i++)
		pre[i] = min(pre[i - 1], maxs[i]);
	
	suf[n] = maxs[n];
	for (int i = n - 1; i >= 1; i--)
		suf[i] = min(suf[i + 1], maxs[i]);
	
	for (int i = 1; i <= n; i++)
		cout << ((i == 1 || mins[i] < pre[i - 1]) && (i == n || mins[i] < suf[i + 1]));
	cout << endl;
}
