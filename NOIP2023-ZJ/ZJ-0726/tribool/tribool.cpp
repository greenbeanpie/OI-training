#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read() {
  char ch = getchar(); int p = 1, x = 0;
  while(!isdigit(ch)) {if(ch == '-') {p = -1;} ch = getchar();}
  while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
  return x * p;
}
/*
sample or date? configureous
feels like a bingchaji qifashi merge...
or bingchaji with widge
Do you like the way it sound?...
*/
const int N = 1e5 + 10;
int C, T, n, m, op, ed;
char v;
int stat[N];//1 -> T | 2 -> F | 3 -> U
int reca[N], recb[N];
char recv[N];
int fa[N];
inline int find(int pos) {
  // if(pos != fa[pos]) fa[pos] = find(fa[pos]);
  int tmp = pos;
  while(tmp != fa[tmp]) tmp = fa[tmp];
  return fa[tmp];
}
inline void merge(int posx, int posy) {
  int fax = find(posx), fay = find(posy);
  fa[fax] = fay;
}
int ret, recod[20];
inline void dfs(int depth) {
  if(depth == n + 1) {
    for(int i = 1; i <= n; i++) stat[i] = recod[i];
    for(int i = 1; i <= m; i++) {
      if(recv[i] == 'U') stat[reca[i]] = 3;
      if(recv[i] == 'F') stat[reca[i]] = 2;
      if(recv[i] == 'T') stat[reca[i]] = 1;
      if(recv[i] == '+') stat[reca[i]] = stat[recb[i]];
      if(recv[i] == '-') stat[reca[i]] = stat[recb[i]] == 3 ? 3 : stat[recb[i]] == 2 ? 1 : 2;
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
      if(recod[i] == stat[i] && stat[i] == 3) cnt++;
      if(recod[i] != stat[i]) return; 
    }
    ret = min(ret, cnt);
    return;
  }
  recod[depth] = 1;
  dfs(depth + 1);
  recod[depth] = 2;
  dfs(depth + 1);
  recod[depth] = 3;
  dfs(depth + 1);
  return;
}

int main()
{
  freopen("tribool.in", "r", stdin);
  freopen("tribool.out", "w", stdout);
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  cin >> C >> T;
  if(C == 3 || C == 4) {//subtask 3/4 AC?
    while(T--) {
      cin >> n >> m;
      int cnt = 0;
      for(int i = 1; i <= n; i++) stat[i] = 0;
      for(int i = 1; i <= m; i++) {
        cin >> v >> op;
        if(v == 'U') stat[op] = 3;
        if(v == 'T') stat[op] = 1;
        if(v == 'F') stat[op] = 2;
      }
      for(int i = 1; i <= n; i++) {
        if(stat[i] == 3) cnt++;
      }
      cout << cnt << endl;
    } 
  }
  if(C == 1 || C == 2 || C > 6) {//subtask 1/2 AC!
    while(T--) {
      cin >> n >> m;
      for(int i = 1; i <= m; i++) {
        cin >> recv[i] >> reca[i];
        if(recv[i] == '+' || recv[i] == '-') cin>> recb[i];
      }
      ret = n;
      for(int i = 1; i <= 10; i++) recod[i] = 0;
      dfs(1);
      cout << ret << endl;
    }
  }
  if(C == 5 || C == 6) {//subtask 5/6 WA
    while(T--) {
      cin >> n >> m;
      int cnt = 0;
      for(int i = 1; i <= n + 1; i++) {
        stat[i] = 0, fa[i] = i;
      }
      for(int i = 1; i <= m; i++) {
        cin >> v >> op;
        if(v == '+') {cin>> ed; merge(op, ed);}
        if(v == 'U') {stat[i] = 3;}
        // stat[find(op)] = stat[op] == 3 ? 3 : stat[find(op)];
        // stat[op] = stat[find(op)];
        // stat[find(op)] = stat[op];
      }
      for(int i = 1; i <= n; i++) if(stat[find(i)] == 3) cnt++;
      cout << cnt << endl;
    }
  }
  // if(C == 7 || C == 8) {

  // }
  return 0;
}