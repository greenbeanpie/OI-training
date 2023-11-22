#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 3010;
const ll MAXM = 3010;
ll n, m;
string s[MAXN];
string mp[MAXN];
ll minp, sminp;
stringstream ss;
int main() {
#ifndef DEBUG
  freopen("dict.in", "r", stdin);
  freopen("dict.out", "w", stdout);
#endif
  ios::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> s[i];
    mp[i] = s[i];
    sort(mp[i].begin(), mp[i].end(), greater<char>());
    if (minp == 0 || mp[i] < mp[minp]) {
      sminp = minp;
      minp = i;
    }
    sort(s[i].begin(), s[i].end());
  }
  for (int i = 1; i <= n; ++i) {
    if (i != minp && s[i] < mp[minp])
      ss << '1';
    else if (i == minp && s[i] < mp[sminp] || sminp == 0)
      ss << '1';
    else
      ss << '0';
  }
  cout << ss.str() << endl;
  return 0;
}