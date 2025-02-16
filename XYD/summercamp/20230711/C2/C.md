# 无想の一刀

## 题目描述

在提瓦特这篇广袤的大陆上，存在这这样一个名为“稻妻”的国度，百姓们世世代代生活在雷神的统治之下。小Y作为一名冒险家，驾驶着浪船在稻妻的领海上探索，突然他驶入了一条狭窄的水道，两侧则是险峻的高山，四周漂浮着雷鸣之气。这时小Y的眼神逐渐迷离，思绪开始逐渐飘荡，仿佛回到了千年之前雷神开拓这篇土地的时候。在亦虚亦实中，小Y站在雷神的旁边，此时雷神正准备把一片矩形的岛屿分割为两个部分，记为 $A,B$ 。方便起见，我们把长宽分别为 $n,m$ 的岛屿先分成不能继续细分的 $n \times m$ 个 $1 \times 1$ 的小方格，然后指定每一个小方格所属的区域是 $A$ 还是 $B$ 。但是雷神可不是凡夫俗子，她对于区域划分的要求相当严苛。具体来讲：

1 区域 $A$ 和区域 $B$ 都至少包含一个小方格，每个小方格属于且只属于其中一个区域。

2 同一个区域的任意两个小方格相互连通。即从起点小方格出发，上下左右移动，不经过另一区域的方格可以达到终点小方格。

3 对于每一行/列,如果我们将这一行/列单独取出,这一行/列里同区域的任意两个小方格互相连通。这一行/列内的所有小方格可以全部属于一个区域。

当然满足上述要求的分割方案有很多，雷神想要找到一个最优雅的。每个小方格都有一个海拔，我们用 $h_{i,j}$ 来记录。我们定义一个区域的极差为区域内最高海拔减去最低海拔，用 $R_A,R_B$来表示。如果一个区域内极差很大，也就是说高山之下即为盆地，雷神会觉得过于突兀，她不喜欢这种风格，她希望找到一种分割方案使得 $max(R_A,R_B)$ 尽可能小。她说:“小Y，你怎么看?”

## 输入描述

第一行包含两个正整数 $n,m$ ，表示矩形岛屿的长宽，其中 $2 \leq n,m \leq 2000$ 。接下来给出 $n$ 行，每行 $m$ 个数。表示每个小方格的海拔。其中 $h_{i,j} \leq 10^9$ 。

**温馨提示:输入规模较大，请使用较快的读入方式。**

## 输出描述

输出一行，一个整数，表示 $max(R_A,R_B)$ 可能的最小值。

## 样例

### 样例输入 #1

```
4 4
1 12 6 11
11 10 2 14
10 1 9 20
4 17 19 10
```

### 样例输出 #2

```
11
```

### 样例输入 #2

```
8 6
23 23 10 11 16 21
15 26 19 28 19 20
25 26 28 16 15 11
11 8 19 11 15 24
14 19 15 14 24 11
10 8 11 7 6 14
23 5 19 23 17 17
18 11 21 14 20 16
```

### 样例输出 #2

```
18
```

## 1.5 时空限制

时间：4s

空间：256MB
