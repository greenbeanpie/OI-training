# 小的数不是小数

## 题目描述

大哈现在有4个整数，他想经过一些操作使他最后手里只剩1个数。但他才1岁，最近刚自学了加法和乘法。所以他决定通过加法和乘法来进行操作。因为他还没有学会加括号，所以4个整数他打算选用3个符号来计算。他想每次选两个数，然后用给定符号的顺序对这两个数进行运算，并将结果当做一个新数继续操作，直到只剩下一个数为止。现在大哈想知道剩下的数最小可能是多少。输出这个最小值。

## 输入格式

第一行四个整数 $a,b,c,d$

第二行三个符号(+ 或 *)

## 输出格式

一个整数.

## 样例 #1

### 样例输入 #1

```
1 1 1 1
+ + *
```

### 样例输出 #1

```
3
```

### 样例输入 #2

```
2 2 2 2
* * +
```

### 样例输出 #2

```
8
```

### 样例输入 #3

```
1 2 3 4
* + +
```

### 样例输出 #3

```
9
```

## 数据范围

$0 \leq a,b,c,d \leq 1000$

## 样例解释

样例输入1的解释：$1 + 1 + 1 \times 1 = 3$

样例输入2的解释：$2 \times 2 + 2 \times 2 = 8$

样例输入3的解释：$1 \times 2 + 3 + 4 = 9$