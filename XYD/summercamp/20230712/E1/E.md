# MEX vs MED

## 题面翻译

给定一个值域从 $0$ 到 $n-1$ 的排列 $p$，求有多少个区间 $[l,r]$ 满足 $\operatorname{mex}(p_l,p_{l+1},\dots,p_r)>\operatorname{med}(p_l,p_{l+1},\dots,p_r)$。

这里的 $p$ 的值域为 $[0, n - 1]$，但是 $p$ 的**下标范围**为 $[1, n]$。

其中 $\operatorname{mex}(S)$ 为没有在 $S$ 中出现的最小非负整数；$\operatorname{med}(S)$ 为 $S$ 从小到大排序后 $S_{\left\lfloor\frac{\vert S\vert+1}2\right\rfloor}$ 的值（下标从 $0$ 开始）。

$\sum n\leqslant 2\times10^5$。

## 题目描述

You are given a permutation $ p_1, p_2, \ldots, p_n $ of length $ n $ of numbers $ 0, \ldots, n - 1 $ . Count the number of subsegments $ 1 \leq l \leq r \leq n $ of this permutation such that $ mex(p_l, p_{l+1}, \ldots, p_r) > med(p_l, p_{l+1}, \ldots, p_r) $ .

 $ mex $ of $ S $ is the smallest non-negative integer that does not occur in $ S $ . For example:

- $ mex({0, 1, 2, 3}) = 4 $
- $ mex({0, 4, 1, 3}) = 2 $
- $ mex({5, 4, 0, 1, 2}) = 3 $

 $ med $ of the set $ S $ is the median of the set, i.e. the element that, after sorting the elements in non-decreasing order, will be at position number $ \left \lfloor{ \frac{|S| + 1}{2} } \right \rfloor $ (array elements are numbered starting from $ 1 $ and here $ \left \lfloor{v} \right \rfloor $ denotes rounding $ v $ down.). For example:

- $ med({0, 1, 2, 3}) = 1 $
- $ med({0, 4, 1, 3}) = 1 $
- $ med({5, 4, 0, 1, 2}) = 2 $

A sequence of $ n $ numbers is called a permutation if it contains all the numbers from $ 0 $ to $ n - 1 $ exactly once.

## 输入格式

The first line of the input contains a single integer $ t $ $ (1 \leq t \leq 10^4 $ ), the number of test cases.

The descriptions of the test cases follow.

The first line of each test case contains a single integer $ n $ ( $ 1 \leq n \leq 2 \cdot 10^5 $ ), the length of the permutation $ p $ .

The second line of each test case contains exactly $ n $ integers: $ p_1, p_2, \ldots, p_n $ ( $ 0 \leq p_i \leq n - 1 $ ), elements of permutation $ p $ .

It is guaranteed that the sum of $ n $ over all test cases does not exceed $ 2 \cdot 10^5 $ .

## 输出格式

For each test case print the answer in a single line: the number of subsegments $ 1 \leq l \leq r \leq n $ of this permutation such that $ mex(p_l, p_{l+1}, \ldots, p_r) > med(p_l, p_{l+1}, \ldots, p_r) $ .

## 样例 #1

### 样例输入 #1

```
8
1
0
2
1 0
3
1 0 2
4
0 2 1 3
5
3 1 0 2 4
6
2 0 4 1 3 5
8
3 7 2 6 0 1 5 4
4
2 0 1 3
```

### 样例输出 #1

```
1
2
4
4
8
8
15
6
```

## 提示

The first test case contains exactly one subsegment and $ mex({0}) = 1 > med({0}) = 0 $ on it.

In the third test case, on the following subsegments: $ [1, 0] $ , $ [0] $ , $ [1, 0, 2] $ and $ [0, 2] $ , $ mex $ is greater than $ med $ .

In the fourth test case, on the following subsegments: $ [0, 2] $ , $ [0] $ , $ [0, 2, 1] $ and $ [0, 2, 1, 3] $ , $ mex $ greater than $ med $ .