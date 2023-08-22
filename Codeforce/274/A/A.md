# k-Multiple Free Set

## 题面翻译

给定正整数 $n,k$ 和 $n$ 个互不相同的正整数 $a_1,\cdots,a_n$，求最多能在 $a_1,\cdots,a_n$ 中选出多少个正整数，使得其中没有两个不同的正整数成 $k$ 倍关系。

## 题目描述

A $ k $ -multiple free set is a set of integers where there is no pair of integers where one is equal to another integer multiplied by $ k $ . That is, there are no two integers $ x $ and $ y $ $ (x<y) $ from the set, such that $ y=x·k $ .

You're given a set of $ n $ distinct positive integers. Your task is to find the size of it's largest $ k $ -multiple free subset.

## 输入格式

The first line of the input contains two integers $ n $ and $ k $ ( $ 1<=n<=10^{5},1<=k<=10^{9} $ ). The next line contains a list of $ n $ distinct positive integers $ a_{1},a_{2},...,a_{n} $ $ (1<=a_{i}<=10^{9}) $ .

All the numbers in the lines are separated by single spaces.

## 输出格式

On the only line of the output print the size of the largest $ k $ -multiple free subset of $ {a_{1},a_{2},...,a_{n}} $ .

## 样例 #1

### 样例输入 #1

```
6 2
2 3 6 5 4 10
```

### 样例输出 #1

```
3
```

## 提示

In the sample input one of the possible maximum 2-multiple free subsets is {4, 5, 6}.