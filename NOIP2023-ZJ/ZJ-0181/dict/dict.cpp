/**
 * 这道题不是 h 开头的，随便做/xyx
 * 我们考虑数据范围，可以想到一个 n^2\log m 的做法
 * 字符串哈希+倍增，找到最大的相同的前后缀
 * 判断哪个更大即可
 * 感觉只能过 90 分
 * 暴力都有 80 分啊
 * 考虑优化比较字典序的过程
 * 因为只有 26 个字符，每个字符串长度一样
 * 所以可以记录每个字符出现了几次，看第一次不一样即可
 * 同时可以再哈希一下，把 O(26) 优化成 O(log26)
 * 这个优化好像不是很明显，如果超时了再加上
 * 根本不用这样啊
 * 直接用 i 中最小的字符和 j 中最大的字符比较就好了啊
 * min i < max j，i < j，else i > j
 * 没有相同的字符串！
 */

#include <bits/stdc++.h>
using namespace std;
int n, m;
char mx[3030], mn[3030];
bool ans[3030];
int main() {
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        mn[i] = 'z';
        for (int j = 1; j <= m; j++) {
            char ch;
            scanf(" %c", &ch);
            mx[i] = max(mx[i], ch);
            mn[i] = min(mn[i], ch);
        }
        ans[i] = 1;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            bool tmp = (i == j) || (mn[i] < mx[j]);
            // printf("%d %c %c\n", i, mn[i], mx[j]);
            ans[i] &= tmp;
        }
    for (int i = 1; i <= n; i++)
        printf("%d", ans[i]);
    putchar('\n');
    return 0;
}