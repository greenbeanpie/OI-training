# Problem B 区间加法

## 1.1 题目描述

小Y手中有一个长度为 $n$ 的序列，初始时序列中第 $i$ 个元素的值为 $a$ 。现在他有 $m$ 个待选区间(第 $i$ 个区间为$[l_i, r_i]$)，和两个正整数 $b,k$ 。他需要从这 $m$ 个区间中选择恰好 $k$ 个区间，然后对每一个选中的区间执行一次区间加法，即区间中每一个数都加上 $b$ 。小Y希望序列中不要出现太小的数字，所以想要让操作完的序列中最小的数尽可能大。

## 1.2 输人描述

第一行包含一个正整数 $T$ ，表示数据的组数。

对于每一组数据，第一行包含四个正整数$n, m, k(k \leq m),b(b \leq 10^9)$。

第二行包含 $n$ 个正整数，表示序列初始值，其中 $a \leq 10^9$。

接下来 $m$ 行，每行包含两个正整数 $l,r(1 \leq l < r \leq n)$，表示一个待选区间。保证区间两两不同。

对于60%的数据，$\Sigma n,\Sigma m \leq 2000$ 。

对于100%的数据，$\Sigma n,\Sigma m \leq 2 \times 10^5$ 。

## 1.3 输出描述

对于每一组数据，输出一个整数表示操作后序列最小值的最大值。

## 1.4 样例

### 样例输入#1
```
1
3 3 2 1
1 3 2
1 1 
1 3
3 3
```

### 样例输出#1

```
3
```

## 1.5 时空限制

时间: 1 s

![](什么？你问我空间限制？我不道啊)

## 题解

显然这道题目在没有提示的情况下比较难以想到一种方法来一次确定哪些区间是需要选择的，所以我们这里就可以使用二分来处理。我们可以对 $h_min$ 来进行二分，我们很容易知道小于答案的高度是可行的，而大于答案的高度是不可行的，我们可以利用这个性质来进行二分。注意在贪心选择区间是我们要尽量选择右端点靠右的，因为我们左边的端点已经全都超过答案了，但右侧的端点可能没有。如果有某个端点没能达到答案就可以直接退出。时间复杂度为 $O(nlogn \times loga)$ 。可以通过。

## 标程

```cpp
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n, m, k, T, cnt;
int book[N], r[N];
long long a, lf = 0x7f7f7f7f, ri;

struct opt {
  long long val; //val对于序列点是点值，对于线段点是编号
  int tp, pos;
  friend bool operator <(opt a, opt b) {
    return a.pos + a.tp / 3.0 < b.pos + b.tp / 3.0;
  }
} op[3 * N];

struct data {
  int v;
  friend bool operator <(data a, data b) {
    return r[a.v] < r[b.v];
  }
};
priority_queue <data> pq;
void clear(priority_queue <data> &pq) {
  priority_queue <data> emp;
  swap(emp, pq);
}

bool jud(long long mid) {
  long long flow = 0;
  int tot = 0;

  for (int i = 1; i <= cnt; i++) {
    if (op[i].tp == 0) {
      pq.push((data) { (int)op[i].val });
    } else if (op[i].tp == 1) {
      long long ned = mid - op[i].val - flow;
      if (ned < 0) {
        continue;
      }
      long long ch = (ned + a - 1) / a;
      if (tot + ch > k) {
        return 0;   //如果超了限制的话可以拍false了
      }
      for (; !pq.empty() && ch; pq.pop()) {
        int v = (pq.top()).v;
        if (r[v] < op[i].pos) {
          return 0;   //如果此时堆为空也可以拍false了
        } else {
          book[v] = 1;    //区间+a
          flow += a;
          ch--;
          tot++;
        }
      }
      if (ch > 0) {
        return 0;  //如果没加完也可以拍false了
      }
    } else {
      flow -= book[op[i].val] * a;   //检查下这个区间有没有被选中
    }
  }
  return 1;
}

void solve() {
  scanf("%d%d%d%lld", &n, &m, &k, &a);

  for (int i = 1; i <= n; i++) { //插入序列点
    long long t;
    scanf("%lld", &t);
    op[++cnt] = (opt) { t, 1, i };
    lf = min(lf, (long long)t);
  }

  for (int i = 1; i <= m; i++) { //插入线段点
    scanf("%d", &r[i]);
    op[++cnt] = (opt) { i, 0, r[i] };
    scanf("%d", &r[i]);
    op[++cnt] = (opt) { i, 2, r[i] };
  }

  sort(op + 1, op + cnt + 1);
  ri = lf + m * a; //计算左右区间

  while (lf != ri) { //二分答案，记得清空
    long long mid = (lf + ri + 1) / 2;
    if (jud(mid)) {
      lf = mid;
    } else {
      ri = mid - 1;
    }

    clear(pq);
    for (int i = 1; i <= m; i++) {
      book[i] = 0;
    }
  }

  printf("%lld\n", lf);
  cnt = 0;
  lf = 0x7f7f7f7f;
}

int main() {
  scanf("%d", &T);
  for (int z = 1; z <= T; z++) {
    solve();
  }
  return 0;
}
```
