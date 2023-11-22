#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read() {
  char ch = getchar(); int p = 1, x = 0;
  while(!isdigit(ch)) {if(ch == '-') {p = -1;} ch = getchar();}
  while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
  return x * p;
}
const int N = 5e5 + 10;
int C, T, n, m;
int a[N], b[N], c[N], d[N];
//exact sequence fill
/*
subtask:1 OK
subtask:2 OK
*/
vector<pair<int, int>> G[2010];
int nxt[2010][2010];
inline bool check() {
  memset(nxt, 0, sizeof(nxt));
  if(a[1] <= b[1] || a[n] <= b[m]) return false;
  nxt[1][0] = 1;
  b[m + 1] = 0x3f3f3f3f;
  for(int i = 1; i <= n; i++) {
    G[i].clear();
    int flag = false;
    int st = 1;
    for(int j = 1; j <= m + 1; j++) {
      if(a[i] > b[j] && !flag) {flag = 1; st = j;}
      if(flag && a[i] <= b[j]) {flag = 0; G[i].emplace_back(make_pair(st, j-1));
        for(int k = 0; k < (int)G[i - 1].size(); k++) {
          auto y = G[i - 1][k];
          
          if(st <= y.second + 1) nxt[i][(int)G[i].size() - 1] = nxt[i - 1][k];
        }
      }
    }
  }
  // for(int i = 1; i <= n; i++) {
  //   for(int j = 0; j < (int)G[i].size(); j++) {
  //     printf("%d %d ", G[i][j].first, G[i][j].second);
  //   }
  //   cout << endl;
  // }
  for(int i = 0; i < (int)G[n].size(); i++) {
    if(nxt[n][i]) return 1;
  }
  return 0;
}
int main()
{
  freopen("expand.in", "r", stdin);
  freopen("expand.out", "w", stdout);
  // std::ios::sync_with_stdio(false);
  // std::cin.tie(nullptr);
  // std::cout.tie(nullptr);
  // cin >> C >> n >> m >> T;
  C = read(), n = read(), m = read(), T = read();
  for(int i = 1; i <= n; i++) {
    a[i] = read(); c[i] = a[i];
  }
  for(int i = 1; i <= m; i++) {
    b[i] = read(); d[i] = b[i];
  }
  if(C == 1) printf("%d", a[1] > b[1]);
  else if(C == 2) printf("%d", a[1] > b[1] && a[2] > b[2]);
  else printf("%d", check());
  while(T--) {
    for(int i = 1; i <= n; i++) {
      a[i] = c[i], b[i] = d[i];
    }
    int k1 = read(), k2 = read();
    int p, v;
    for(int i = 1; i <= k1; i++) {
      p = read(), v = read();
      a[p] = v;
    }
    for(int i = 1; i <= k2; i++) {
      p = read(), v = read();
      b[p] = v;
    }
    if(C == 1) return a[1] > b[1];
    else if(C == 2) printf("%d", a[1] > b[1] && a[2] > b[2]);
    else printf("%d", check());
  }
  return 0;
}