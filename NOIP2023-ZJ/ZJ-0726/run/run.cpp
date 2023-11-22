#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read() {
  char ch = getchar(); int p = 1, x = 0;
  while(!isdigit(ch)) {if(ch == '-') {p = -1;} ch = getchar();}
  while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
  return x * p;
}
int C, T;
const int N = 1e5 + 10;
int tree[N];
inline int lowbit(int x) {return x & -x;}
inline void update(int x, int d) {
  while(x < N) {
    tree[x] += d;
    x += lowbit(x);
  }
}
inline int qurery(int x) {
  int ans = 0;
  while(x > 0) {
    ans += tree[x];
    x -= lowbit(x);
  }
  return ans;
}
//segment tree is better?
//no
//
int stat[200];

int main()
{
  freopen("run.in", "r", stdin);
  freopen("run.out", "w", stdout);
  C = read(), T = read();
  int n, m, k, d;
  while(T--) {
    n = read(), m = read(), k = read(), d = read();

  }
  return 0;
}