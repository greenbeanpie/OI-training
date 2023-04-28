#include <bits/stdc++.h>
#define y1 y114514

using namespace std;

const int N = 5e5 + 50;

int a[N], b[N];
long long ans;
int n;

void msort(int l, int r) {
  if (l == r) return;
  int mid = (l + r) >> 1;
  msort(l, mid), msort(mid + 1, r);
  int i = l, j = mid + 1, k = l;
  while (i <= mid && j <= r) {
    if (a[i] <= a[j])
      b[k++] = a[i++];
    else
      b[k++] = a[j++], ans += mid - i + 1;
  }
  for (; i <= mid; i++, k++) b[k] = a[i];
  for (; j <= r; j++, k++) b[k] = a[j];
  for (int k = l; k <= r; k++) a[k] = b[k];
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];

  msort(1, n);

  cout << ans << endl;
  return 0;
}