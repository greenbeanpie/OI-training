# 开会

## 题目描述

在x轴上有n个人，每个人有一个移动速度 $v_1,v_2,v_3...v_n$ , 现在需要找一个地方让大家聚到一起开会，问你最少需要多少时间才可以让所有人都到达同一个点

## 输入格式

第一行输入一个整数 $n$

第二行输入 $n$ 个整数

$x_1,x_2,x_3...x_n$ 表示每个人初始的位置

第三行输入n个整数

$v_1,v_2,v_3...v_n$ 表示每个人的移动速度

## 输出格式

输出一个浮点数，保留五位小数，四舍五入。比如答案为 $2.333336$ ，就输出 $2.33334$

## 样例 #1

### 样例输入 #1

```
3
7 1 3
1 2 1
```

### 样例输出 #1

```
2.00000
```

### 样例输入 #2

```
10
2 3 5 7 11 13 17 19 23 29
6 5 4 3 2 1 2 3 4 5
```

### 样例输出 #2

```
2.75000
```

## 提示

$2 \leq n \leq 60000,1 \leq x_i,v_i \leq 10^9$

时间：1s   空间：32MB