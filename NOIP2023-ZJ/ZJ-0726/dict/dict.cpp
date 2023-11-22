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
easy?
yellow?
*/
const int N = 3e3 + 10;
bool cmp[N][N];//memorilize _ [1] -> i < j
int rcd[2][N];//min/max
string s[N];
int n, m;
inline void init() {
  for(int i = 1; i <= n; i++) {
    rcd[0][i] = 11451;
    rcd[1][i] = -1145;
  }
}
int main()
{
  freopen("dict.in", "r", stdin);
  freopen("dict.out", "w", stdout);
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  cin >> n >> m;
  init();
  for(int i = 1; i <= n; i++) {
    cin >> s[i];
    for(int j = 0; j < m; j++) {
      // s[i][j] = getchar();
      if(rcd[0][i] > s[i][j]) rcd[0][i] = s[i][j];
      if(rcd[1][i] < s[i][j]) rcd[1][i] = s[i][j];
      
    }
  }
  for(int i = 1; i <= n; i++) {
    bool flag = 1;
    for(int j = i + 1; j <= n; j++) {
      if(rcd[0][i] < rcd[1][j]) cmp[i][j] = 1;
      if(rcd[1][i] > rcd[0][j]) cmp[j][i] = 1;
    }
    for(int j = 1; j <= n; j++) {
      if(j == i) continue;
      if(!cmp[i][j]) {flag = 0; break;}
    }
    cout << flag;
  }
  return 0;
}