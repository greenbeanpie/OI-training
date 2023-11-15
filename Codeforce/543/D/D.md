# Road Improvement

## 题面翻译

**题目描述**
  
这个国家有n座城市和n-1条双向道路，你可以沿道路从一个城市到任意一个其他城市。这些城市被编号为整数1到n。

所有的道路最初都是不良的，但是政府想要改善一些路的状况。我们认为如果从首都x城到其他城市的道路最多包含一条不良道路，市民会对此感到满意。
你的任务是——对于每一个可能的x，求出所有能够满足市民条件的改良道路的方式。因为结果可能很大，你需要输出mod 1000000007 ( 10^9+7 )后的结果。

**输入输出格式**

**输入格式**：

第一行有一个整数n ( 2<=n<=2⋅10^5 )——代表城市的数量。
第二行包括n-1个描述城市道路的整数p2,p3,p4,...,pn ( 1<=pi<=i−1 ) pi表示有一条连接城市pi和城市i 的道路。

**输出格式：**

输出n个整数a1,a2,...,an ，ai表示在城市i为首都时，改良道路的方式mod 1000000007 ( 10^9+7 )后的结果。

## 题目描述

The country has $ n $ cities and $ n-1 $ bidirectional roads, it is possible to get from every city to any other one if you move only along the roads. The cities are numbered with integers from $ 1 $ to $ n $ inclusive.

All the roads are initially bad, but the government wants to improve the state of some roads. We will assume that the citizens are happy about road improvement if the path from the capital located in city $ x $ to any other city contains at most one bad road.

Your task is — for every possible $ x $ determine the number of ways of improving the quality of some roads in order to meet the citizens' condition. As those values can be rather large, you need to print each value modulo $ 1000000007 $ ( $ 10^{9}+7 $ ).

## 输入格式

The first line of the input contains a single integer $ n $ ( $ 2<=n<=2·10^{5} $ ) — the number of cities in the country. Next line contains $ n-1 $ positive integers $ p_{2},p_{3},p_{4},...,p_{n} $ ( $ 1<=p_{i}<=i-1 $ ) — the description of the roads in the country. Number $ p_{i} $ means that the country has a road connecting city $ p_{i} $ and city $ i $ .

## 输出格式

Print $ n $ integers $ a_{1},a_{2},...,a_{n} $ , where $ a_{i} $ is the sought number of ways to improve the quality of the roads modulo $ 1000000007 $ ( $ 10^{9}+7 $ ), if the capital of the country is at city number $ i $ .

## 样例 #1

### 样例输入 #1

```
3
1 1
```

### 样例输出 #1

```
4 3 3
```

## 样例 #2

### 样例输入 #2

```
5
1 2 3 4
```

### 样例输出 #2

```
5 8 9 8 5
```