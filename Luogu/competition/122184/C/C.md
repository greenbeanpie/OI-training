# 「RiOI-2」equals

## 题目背景

在小树上坐落着一个幻想的城堡。这里是 E 国的领地，而小 E，则是 E 国之王。

为了打造一个完美的 E 国，他需要明辨是非，走向正义。

但是，他似乎有些太理想了。有时并没有一个完美的准则。是黑是白，谁能分辨？

## 题目描述

给定一棵 $n$ 个结点，以 $1$ 为根的树，定义一个结点的深度 $d_i$ 表示它到根结点的简单路径上的结点个数。

你需要给每个结点黑白染色，满足黑色结点的深度和等于白色结点的深度和。设 $c_i = \{0, 1\}$ 分别代表编号为 $i$ 的结点为黑色或白色，那么这即 $\displaystyle\sum_{c_i=0}d_i=\sum_{c_i=1}d_i$。

若无解，仅输出一行一个整数 $-1$。

## 输入格式

第一行一个正整数 $n$。

接下来 $n - 1$ 行，每行两个整数 $u_i, v_i$，表示树上编号为 $u_i$ 的结点与编号为 $v_i$ 的结点之间有一条边。保证给出的边不重复。

## 输出格式

若有解，则输出一行 $n$ 个数 $c_1\dots c_n$。

若无解，仅输出一行一个整数 $-1$。

**本题开启 Special Judge，只要你的方案满足条件或正确判断无解即可拿到本测试点的分数。**

## 样例 #1

### 样例输入 #1

```
6
1 2
1 3
2 4
2 5
2 6
```

### 样例输出 #1

```
0 1 1 1 0 0
```

## 样例 #2

### 样例输入 #2

```
5
1 2
1 3
2 4
2 5
```

### 样例输出 #2

```
-1
```

## 提示

### 样例解释

对于第一组数据，每个结点的深度分别是 $d=[1,2,2,3,3,3]$。黑色结点的深度和为 $d_1+d_5+d_6=1+3+3=7$，白色结点的深度和为 $d_2+d_3+d_4=2+2+3=7$。它们相等，所以样例输出是正确的。可能的正确输出包括但不限于样例输出、`0 1 1 0 0 1`，`1 0 0 1 0 1` 等。

### 数据规模与约定

**本题采用捆绑测试。**

| $\rm Subtask$ | 分值 | $n\le $ | 特殊性质 |
| :-----------: | :--: | :-----: | :------: |
| $0$ | $5$ | $20$ | / |
| $1$ | $15$ | $500$ | / |
| $2$ | $20$ | $5\times 10^3$ | / |
| $3$ | $10$ | / | $n$ 为偶数 |
| $4$ | $5$ | / | 树为菊花图（不保证根为菊花中心） |
| $5$ | $5$ | / | 树为一条链（不保证根为链的端点） |
| $6$ | $40$ | / | / |

斜杠表示这一栏无特殊限制。

对于 $100\%$ 的数据，$1\le n\le 10^6$，输入数据构成一棵树。