# One Occurrence

## 题面翻译

**题目大意：**

给定一个长度为$n$序列，$m$个询问，每次询问给定一个区间$[l,r]$，如果这个区间里存在只出现一次的数，输出这个数（如果有多个就输出任意一个），没有就输出0，$n,m<=5*10^5$

**输入格式：**

第一行一个整数$n$

接下来1行$n$个小于$5*10^5$的正整数，即序列

下面一行一个整数$m$

在下面$m$行，每行两个整数$l,r$

**输入格式：**

共$m$行，如题目

感谢@守望 提供翻译

## 题目描述

You are given an array $ a $ consisting of $ n $ integers, and $ q $ queries to it. $ i $ -th query is denoted by two integers $ l_i $ and $ r_i $ . For each query, you have to find any integer that occurs exactly once in the subarray of $ a $ from index $ l_i $ to index $ r_i $ (a subarray is a contiguous subsegment of an array). For example, if $ a = [1, 1, 2, 3, 2, 4] $ , then for query $ (l_i = 2, r_i = 6) $ the subarray we are interested in is $ [1, 2, 3, 2, 4] $ , and possible answers are $ 1 $ , $ 3 $ and $ 4 $ ; for query $ (l_i = 1, r_i = 2) $ the subarray we are interested in is $ [1, 1] $ , and there is no such element that occurs exactly once.

Can you answer all of the queries?

## 输入格式

The first line contains one integer $ n $ ( $ 1 \le n \le 5 \cdot 10^5 $ ).

The second line contains $ n $ integers $ a_1, a_2, \dots, a_n $ ( $ 1 \le a_i \le 5 \cdot 10^5 $ ).

The third line contains one integer $ q $ ( $ 1 \le q \le 5 \cdot 10^5 $ ).

Then $ q $ lines follow, $ i $ -th line containing two integers $ l_i $ and $ r_i $ representing $ i $ -th query ( $ 1 \le l_i \le r_i \le n $ ).

## 输出格式

Answer the queries as follows:

If there is no integer such that it occurs in the subarray from index $ l_i $ to index $ r_i $ exactly once, print $ 0 $ . Otherwise print any such integer.

## 样例 #1

### 样例输入 #1

```
6
1 1 2 3 2 4
2
2 6
1 2
```

### 样例输出 #1

```
4
0
```
