# 【noip赛前20天冲刺集训day13】代数

## 题目描述

用以下经典的方式构造一棵树：对 $i = 2~n$ ，从 $1 ~ i-1$ 中随即选择一个点当作 $ i $ 的父亲。

设点 $ u $ 的子树大小的 $ k $ 次方为 $ F_u $ ，给定  $ a_u $ ，求 $\Sigma_u a_uf_u$ 的期望，对 $ 10^9+7 $ 取模。

## 输入格式

第一行两个正整数 $ n,k $ 。

第二行 $ n $ 个数，表示序列 $ a $ 。

## 输出格式

一行一个数，表示答案。

## 样例 #1

### 样例输入 #1

```text
3 1
1 2 3
```

### 样例输出 #1

```text
9
```

### 样例输入 #2

```text
3 2
1 2 3
```

### 样例输出 #2

```text
17
```

### 样例输入 #3

```text
10 3
1 2 3 4 5 6 7 8 9 10
```

### 样例输出 #3

```text
880954454
```

## 提示

保证 $ 1 \leq n \leq 10^5 , 1 \leq k \leq 20 , 1 \leq a_i \leq 10^9 $ 。

| 测试点 | 特殊性质 |
| -----------: | -----------: |
| 1~5 | $ n \leq 10 $ |
| 6~10 | $ n \leq 100 $ |
| 11~15 | $ k = 1 $ |
| 16~20 | $ k = 2 $ |
| 21~25 | 无特殊性质 |