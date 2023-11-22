#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 150010;
struct Node {
  ll l, r, mx, mn;
};
ll c, n, m, q;
ll X[MAXN], Y[MAXN];
ll *x, *y;
Node SEGTX[MAXN * 4], SEGTY[MAXN * 4];
Node *segtx, *segty;
void pushup(Node* segt, ll p) {
  segt[p].mx = max(segt[p * 2].mx, segt[p * 2 + 1].mx);
  segt[p].mn = min(segt[p * 2].mn, segt[p * 2 + 1].mn);
}
void build(Node* segt, ll* orig, ll p, ll l, ll r) {
  segt[p].l = l;
  segt[p].r = r;
  if (l == r) {
    segt[p].mx = segt[p].mn = orig[l];
    return;
  }
  ll mid = (l + r) / 2;
  build(segt, orig, p * 2, l, mid);
  build(segt, orig, p * 2 + 1, mid + 1, r);
  pushup(segt, p);
}
ll querymx(Node* segt, ll p, ll l, ll r) {
  if (l <= segt[p].l && segt[p].r <= r) {
    return segt[p].mx;
  }
  ll res = 0;
  ll mid = (segt[p].l + segt[p].r) / 2;
  if (l <= mid) res = max(res, querymx(segt, p * 2, l, r));
  if (mid + 1 <= r) res = max(res, querymx(segt, p * 2 + 1, l, r));
  return res;
}
ll querymn(Node* segt, ll p, ll l, ll r) {
  if (l <= segt[p].l && segt[p].r <= r) {
    return segt[p].mn;
  }
  ll res = 1e9;
  ll mid = (segt[p].l + segt[p].r) / 2;
  if (l <= mid) res = min(res, querymn(segt, p * 2, l, r));
  if (mid + 1 <= r) res = min(res, querymn(segt, p * 2 + 1, l, r));
  return res;
}
void modify(Node* segt, ll p, ll pos, ll val) {
  if (segt[p].l == pos && segt[p].r == pos) {
    segt[p].mx = segt[p].mn = val;
    return;
  }
  ll mid = (segt[p].l + segt[p].r) / 2;
  if (pos <= mid)
    modify(segt, p * 2, pos, val);
  else
    modify(segt, p * 2 + 1, pos, val);
  pushup(segt, p);
}
bool dfs(ll lx, ll rx, ll ly, ll ry) {
  if (querymn(segtx, 1, lx, rx) > querymx(segty, 1, ly, ry)) {
    return true;
  }
  for (int i = lx; i + 1 <= rx; ++i) {
    for (int j = ly; j + 1 <= ry; ++j) {
      if (dfs(lx, i, ly, j) && dfs(i + 1, rx, j + 1, ry)) {
        return true;
      }
    }
  }
  return false;
}
stringstream ss;
void work() {
  bool res;
  x = X;
  y = Y;
  segtx = SEGTX;
  segty = SEGTY;
  res = dfs(1, n, 1, m);
  swap(x, y);
  swap(segtx, segty);
  res = res || dfs(1, n, 1, m);
  if (res)
    ss << '1';
  else
    ss << '0';
}
ll kx, ky, vx, vy;
ll px[MAXN], py[MAXN];
int main() {
#ifndef DEBUG
  freopen("expand.in", "r", stdin);
  freopen("expand.out", "w", stdout);
#endif
  cin >> c >> n >> m >> q;
  for (int i = 1; i <= n; ++i) {
    cin >> X[i];
  }
  for (int i = 1; i <= m; ++i) {
    cin >> Y[i];
  }
  build(SEGTX, X, 1, 1, n);
  build(SEGTY, Y, 1, 1, m);
  work();
  for (int i = 1; i <= q; ++i) {
    cin >> kx >> ky;
    for (int j = 1; j <= kx; ++j) {
      cin >> px[j] >> vx;
      modify(SEGTX, 1, px[j], vx);
    }
    for (int j = 1; j <= ky; ++j) {
      cin >> py[j] >> vy;
      modify(SEGTY, 1, py[j], vy);
    }
    work();
    for (int j = 1; j <= kx; ++j) {
      modify(SEGTX, 1, px[j], X[j]);
    }
    for (int j = 1; j <= ky; ++j) {
      modify(SEGTY, 1, py[j], Y[j]);
    }
  }
  cout << ss.str() << endl;
  return 0;
}