#include <bits/stdc++.h>
typedef unsigned uint;
typedef long long llt;typedef unsigned long long ullt;
typedef bool bol;typedef char chr;typedef void voi;
typedef double dbl;
template<typename T>bol _max(T&a,T b){return a<b?(a=b,true):false;}
template<typename T>bol _min(T&a,T b){return b<a?(a=b,true):false;}
chr C[3005][3005];uint P[3005];
int main()
{
#ifdef MYEE
    freopen("QAQ.in","r",stdin);
    freopen("QAQ.out","w",stdout);
#else
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
#endif
    uint n,m;scanf("%u%u",&n,&m);if(n==1)return puts("1"),0;
    for(uint i=0;i<n;i++)scanf("%s",C[i]),std::sort(C[i],C[i]+m),std::reverse(C[i],C[i]+m),P[i]=i;
    std::nth_element(P,P+1,P+n,[&](uint a,uint b){
        for(uint j=0;j<m;j++)if(C[a][j]!=C[b][j])return C[a][j]<C[b][j];
        return false;
    });
    for(uint i=0;i<n;i++)
    {
        uint id=P[P[0]==i];
        bol ok=false;
        for(uint j=0;j<m;j++)if(C[i][m-j-1]!=C[id][j]){ok=C[i][m-j-1]<C[id][j];break;}
        putchar("01"[ok]);
    }
    putchar('\n');
    return 0;
}

/*

g++ dict.cpp -o dict -std=c++11 -Wall -fsanitize=undefined,address -DMYEE

*/

/*

你好。我是 myee。

由于花了 3h 不到我就 AK 了，所以开始写游记，顺带附份题解。

而且说实话这场已经是我的退役前最后一场正赛了。（都高三了）（抛开 CTT 之类的不谈）

虽然感觉会看到这篇游记的大多是从 ZJ NOIp2023 迷惑行为大赏里来的。/wx

写写流水帐。

### day 不记得多少了

AK 了 CSP-S。感觉很萌萌。

感觉 NOIp 应该不会这么萌。

### day 不记得多少了

集训队互测开始了。

场场打暴力。破防。

前 20 名太难进了。不过场场起码签到分总能到。

### day -8

我出 T1T2 的互测场。huahua T3。

T1 太乱搞被喷烂了。/ng

T3 too hard。这是碰都不能碰的花题.jpg。

欢迎大家来补我的题。

### day -5

nfls 的互测 Round。

集训队 rank20 没上 60pts。/kx

### day -1

终于把互测前 20 达到 5 场了。互测分满了。

### day 0

NOIp 还剩一天了，应该做些什么呢？.jpg

选项：
* 学习新算法（v图 提示：此算法没用）
* 做比赛（ucup1412 harbin）
* 写码农题（心跳排列图）
* 复习文化课
* 打隔膜

开始毒奶知识点。

### day 1

#### 赛前

喜闻乐见的面基环节！

#### 8:20

打开压缩包看了眼。

tribool？又来大模拟了？

run？润？那 expand 是不是寄？

样例咋都有起步 4 个。赢。

希望今年的样例不会复刻去年，给链不要链。/ww

#### 8:30

开题。

T1：我一眼秒了。

T2：我一眼秒了。

T3：好复杂，再想想。

T4：我一眼秒了。

咋一道数数都没有。

#### 9:00

T1 done。

首先我们给每个字符串逆序排序，然后给字符串之间排序，然后就只用比较一次最大非本身串即可判断。

记得特判 n=1。

#### 9:30

T2 done。

类似 2-SAT 的形式，我们直接拆点建图，然后对每个不合法的连通块嗯做就好了。

这里有向边相当于变成了无向边（都是 equal 的限制）

记得加逆否命题。

多测别忘了清空。

#### 10:30

T3 done。

首先很容易通过 max 来推断谁应当更大。

我们考虑一个很显然的贪心：现在我们有序列 a_1 a_2 ... a_n，满足 a_1 - a_n 的元素都在 a_1 和 a_n 内，则删去 a_2 a_3 ... a_{n-1} 后答案不变。

我们把较小的那个序列取出最大值，然后往后找到最小值、最大值、最小值、最大值……交替，删去中间无用元素；往前同样操作。

我们发现这样子整个序列就变成了一个先不断扩大再不断缩小的『振波』。

然后我们考虑怎么一个前缀可以匹配这个『振波』的前半段；显然可以一个贪心搞出来。后半段与后缀匹配同理。

现在我们把前后缀拼在一起后如果能恰好同时完成前半段、后半段，那当然就可以，否则就不行。

这样单次回答容易做到线性，然后就做完了。

感觉这题有点 AtCoder-style，但也有可能是我题目做少了才会想这么慢。

#### 11:20

T4 done。

不知道为啥这么点代码能写这么久。

直接离散化然后线段树维护 dp 即可。有效的决策点显然只有端点。

#### 11:30

四道题基本都是一遍过样例，一点没调。开始写游记。

现在差不多是 12:00，游记写完了。

*/
