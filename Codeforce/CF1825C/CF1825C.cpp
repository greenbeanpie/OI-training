#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
#ifndef ONLINE_JUDGE
  freopen("CF1825C.in", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;

  for (int T = 0; T < t; T++)
  {
    int n, m;
    cin >> n >> m;
    int n1 = 0, n2 = 0;
    set<int> n3;
    for (int i = 0; i < n; i++)
    {
      int t;
      cin >> t;
      if (t == -1)
      {
        n1++;
      }
      else if (t == -2)
      {
        n2++;
      }

      else if (t > 0)
      {
        n3.insert(t);
      }
    }
    if (n3.empty())
    {
      cout << min(n1, 1ll) + min(n2, 1ll) << endl;
      continue;
    }
    if (n1 + n2 >= m)
    {
      cout << max(n1 + n2, m) << endl;
      continue;
    }
    auto t1 = n3.lower_bound(n1);
    auto t2 = t1--;
    int sum0=-1;
    for(auto t2=n3.begin();t2!=n3.end();t2++){
      sum0= max(sum0,min(m - *t2, n2) + min(*t2-1, n1)+1);
    }

    cout << sum0 << endl;
  }
  return 0;
}