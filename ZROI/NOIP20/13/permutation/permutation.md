# 【noip赛前20天冲刺集训day13】组合

## 题目描述

有两个隐藏的数字 $a,b$ ，保证 $ 1 \leq a,b \leq N $ ，你需要构造一系列询问，每次询问包含一个数字集合，你可以知道 $ a,b $ 中是否存在至少一个数字集合。你需要确保你可以通过这些询问找到这个无序对 $ (a,b) $ 。

## 输入格式

一行一个正整数 $ N $ ，表示 $ a,b $ 的范围。

## 输出格式

第一行一个正整数 $ m $ ，表示询问个数。
接下来 $ m $ 行，每行一个长度为 $ N $ 的 01 串，表示一次询问。询问的集合为所有1的位置。

## 样例 #1

### 样例输入 #1

```text
2
```

### 样例输出 #1

```text
2
10
01
```

## 提示

如果 $ (a,b) = (1,2)$ ，那么两次询问都会返回存在。如果 $ (a,b) = (1,1)$ ，那么只有第一次询问会返回存在。如果 $ (a,b) = (2,2)$ ，那么只有第二次询问会返回存在。

保证 $ N=1000 $。

注：你可能需要保证通过样例来防止获得 97 分。

subtask1(100pts)：无特殊性质。

你的的分与输出的询问个数相关。设得分为 $ S $ ，输出的询问个数为 $ m $ ，如果你的构造无法保证得到无序对 $ (a,b) $， $S=0$ 。否则，你的得分 $ S $ 将以如下方式计算：

- 如果 $ m>75 $ ，$ S=0 $。
- 如果 $ 40<m \leq 75 $ ，$ S=95-m $。
- 如果 $ 35<m \leq 40 $ ，$ S=135-2m $。
- 如果 $ 30<m \leq 35 $ ，$ S=170-3m $。
- 如果 $ 26<m \leq 30 $ ，$ S=230-5m $。
- 如果 $ m \leq 26 $ ，$ S=100 $。