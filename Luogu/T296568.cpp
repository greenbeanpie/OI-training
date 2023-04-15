#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
  ios::sync_with_stdio(false);
  // #ifndef ONLINE_JUDGE
  //   freopen("T296568.in", "r", stdin);
  // #endif
  multiset<int> a, b;
  int n, k;
  cin >> n >> k;
  int temp;
  const int NMAX = 1 << (k - 1), NMIN = -NMAX;
  int cnt = 0, sum = 0;
  for (int i = 0; i < n; i++)
  {
    cin >> temp;
    if (temp > NMAX || temp < NMIN)
    {
      continue;
    }
    if (temp < 0)
    {
      a.insert(temp);
    }
    else if (temp > 0)
    {
      b.insert(temp);
    }
    else
    {
      cnt++;
    }
  }

  auto a1 = a.end(), b1 = b.begin();
  if (!a.empty())
  {
    a1--;
  }
  bool flag = true;
  while (flag)
  {
    flag = false;
    if (!a.empty() && *a1 + sum > NMIN && *a1 + sum < NMAX && a1 != --a.begin())
    {
      flag = true;
      cnt++;
      sum += *a1;
      a1--;
    }
    if (!b.empty() && *b1 + sum > NMIN && *b1 + sum < NMAX && b1 != b.end())
    {
      flag = true;
      cnt++;
      sum += *b1;
      b1++;
    }
  }
  cout << cnt;
  return 0;
}