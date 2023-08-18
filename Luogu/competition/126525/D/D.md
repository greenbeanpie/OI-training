# [SDCPC2023] D-Fast and Fat

## 题面翻译

**【题目描述】**

您正在参加一场团体越野比赛。您的队伍共有 $n$ 名队员，其中第 $i$ 名队员的速度为 $v_i$，体重为 $w_i$。

比赛允许每名队员独立行动，也允许一名队员背着另一名队员一起行动。当队员 $i$ 背着队员 $j$ 时，如果队员 $i$ 的体重大于等于队员 $j$，则队员 $i$ 的移动速度不会变化，仍然为 $v_i$；如果队员 $i$ 的体重小于队员 $j$，则队员 $i$ 的移动速度会减去两者的体重差值，即变为 $v_i - (w_j - w_i)$。如果队员 $i$ 的移动速度将变为负数，则队员 $i$ 无法背起队员 $j$。每名队员最多只能背负另一名队员，被背负的队员无法同时背负其他队员。

所有未被背负的队员中，最慢的队员的速度，即为整个队伍的速度。求整个队伍能达到的最大速度。

**【输入格式】**

有多组测试数据。第一行输入一个整数 $T$ 表示测试数据组数，对于每组测试数据：

第一行输入一个整数 $n$（$1 \le n \le 10^5$）表示队员人数。

对于接下来 $n$ 行，第 $i$ 行输入两个整数 $v_i$ 和 $w_i$（$1 \le v_i, w_i \le 10^9$）表示第 $i$ 名队员的速度和体重。

保证所有数据中 $n$ 之和不超过 $10^5$。

**【输出格式】**

每组数据输出一个整数，表示整个队伍可以达到的最大速度。

**【样例解释】**

样例数据的最优策略如下：

- 队员 $1$ 背起队员 $4$。因为 $w_1 > w_4$，因此队员 $1$ 速度不变，仍然为 $10$。
- 队员 $3$ 背起队员 $2$。因为 $w_3 < w_2$，因此队员 $3$ 的速度减少 $w_2 - w_3 = 2$，即速度变为 $10 - 2 = 8$。
- 队员 $5$ 独立行动，速度为 $9$。

因此答案为 $8$。

## 题目描述

You're participating in a team competition of trail running. There are $n$ members in your team where $v_i$ is the speed of the $i$-th member and $w_i$ is his/her weight.

The competition allows each team member to move alone or carry another team member on their back. When member $i$ carries member $j$, if member $i$'s weight is greater than or equal to member $j$'s weight, member $i$'s speed remains unchanged at $v_i$. However, if member $i$'s weight is less than member $j$'s weight, member $i$'s speed will decrease by the difference of their weight and becomes $v_i - (w_j - w_i)$. If member $i$'s speed will become negative, then member $i$ is not able to carry member $j$. Each member can only carry at most one other member. If a member is being carried, he/she cannot carry another member at the same time.

For all members not being carried, the speed of the slowest member is the speed of the whole team. Find the maximum possible speed of the whole team.

## 输入格式

There are multiple test cases. The first line of the input contains an integer $T$ indicating the number of test cases. For each test case:

The first line contains an integer $n$ ($1 \le n \le 10^5$) indicating the number of team members.

For the following $n$ lines, the $i$-th line contains two integers $v_i$ and $w_i$ ($1 \le v_i, w_i \le 10^9$) indicating the speed and weight of the $i$-th member.

It's guaranteed that the sum of $n$ of all test cases will not exceed $10^5$.

## 输出格式

For each test case output one line containing one integer indicating the maximum speed of the whole team.

## 样例 #1

### 样例输入 #1

```
2
5
10 5
1 102
10 100
7 4
9 50
2
1 100
10 1
```

### 样例输出 #1

```
8
1
```

## 提示

The optimal strategy for the sample test case is shown as follows:

- Let member $1$ carry member $4$. As $w_1 > w_4$, member $1$'s speed remains unchanged, which is still $10$.
- Let member $3$ carry member $2$. As $w_3 < w_2$, member $3$'s speed will decrease by $w_2 - w_3 = 2$ and becomes $10 - 2 = 8$.
- Member $5$ shall move alone. His/Her speed is $9$.

So the answer is $8$.