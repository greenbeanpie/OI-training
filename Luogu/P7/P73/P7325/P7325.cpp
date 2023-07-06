#include <bits/stdc++.h>
#define hmz sb
#define int long long
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int gcd(int a,int b){
  if(b==0){
    return a;
  }
  else if(a==b||a%b==0){
    return b;
  }
  else{
    return gcd(b,a%b);
  }
}
int newmod(int a, int b)
{
  return (a % b + a) % b;
}
struct node
{
  int first;  // p=gcd(a,mod)
  int second; // q=gcd(b,mod)
  int third;  // f[n]/f[n01]%m'/p/q
};
map<node, int> fib[100005];
unordered_set<int> fac;
int n, mod;
using namespace std;

bool operator<(node a, node b)
{
  if (a.first < b.first)
  {
    return true;
  }
  else if (a.first > b.first)
  {
    return false;
  }
  else
  {
    if (a.second < b.second)
    {
      return true;
    }
    else if (a.second > b.second)
    {
      return false;
    }
    else
    {
      if (a.third < b.third)
      {
        return true;
      }
      else
      {
        return false;
      }
    }
  }
}
pair<int, int> exgcd(int a, int b)
{
  int x, y;
  if (a == 1)
  {
    x = 1, y = 0;
  }
  else
  {
    auto temp = exgcd(b, a % b);
    x = temp.second;
    y = temp.first;
    y -= a / b * x;
  }
  return pair<int, int>{x, y};
}
int e(int n, int mod)
{
  return (exgcd(n, mod).first % mod + mod) % mod;
}
signed main()
{
#ifndef ONLINE_JUDGE
  freopen("P7325.in", "r", stdin);
#endif
  //cin >> n >> mod;
  scanf("%lld %lld",&n,&mod);
  fac.insert(mod);
  for (int i = 2; i <= sqrt(mod); i++)
  {
    if (mod % i == 0)
    {
      fac.insert(i);
      fac.insert(mod / i);
    }
  }

  while (!fac.empty())
  { // 进行预处理，判断对于哪些数可能使f[i]=0
    int nowfac = *fac.begin();
    fac.erase(fac.begin());
    int x = 1, y = 0;
    for (int j = 0;; j++)
    { // j表示f[j]

      if (x != 0 && y != 0)
      {
        int a = gcd(nowfac, x), b = gcd(nowfac, y);
        int tmod = nowfac / a / b;
        int temp1 = (y / b) * ((exgcd((x / a), tmod).first % tmod + tmod) % tmod)%tmod;
        if (!fib[nowfac].count(node{temp1, a, b}))
        { // 这里判0是因为如果之前已经有过了的话这里再赋值就不是最大的了
          fib[nowfac][node{temp1, a, b}] = j;
        }
      }
      swap(x, y);
      y = (x + y) % nowfac; // f[j+1]
      if (x == 1 && y == 0)
      {
        break;
      }
    }
  }

  int a, b;
  for (int i = 0; i < n; i++)
  {
    scanf("%lld %lld",&a,&b);
          b = (mod - b) % mod;
    if (a == 0)
    {
      cout << 0 << "\n";
      continue;
    }
    if (b == 0)
    {
      cout << 1 << "\n";
      continue;
    }
    else
    {

      int p = gcd(gcd(a, b), mod); // p是a、b、mod的最大公因数
      int tempm = mod / p;         // 这个询问中的mod，需要确保与a、b互质
      a /= p;
      b /= p;
      p = gcd(a, tempm);
      a /= p; // 使a与mod互质（下同理）
      int q = gcd(b, tempm);
      b /= q;
      int crm = tempm / p / q; // 确保mod与a、b、互质
      int k = a * (exgcd(b, crm).first % crm + crm) % crm;
      if (fib[tempm].count(node{k, q, p}))
      { // 如果这个数在fib里面找到了说明它有解，输出最早找到的i（在预处理中）
        printf("%lld\n",fib[tempm][node{k, q, p}]);
      }
      else
      {
        printf("-1\n");
      }
    }
  }
  return 0;
}
