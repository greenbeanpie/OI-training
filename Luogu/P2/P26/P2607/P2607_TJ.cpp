#include <iostream>
#include <cstdio>
#include <cstring>
#define maxn 2000000
using namespace std;
int n, cnt;
long long ans;
int root;
long long f[maxn][2];
int head[maxn], val[maxn], vis[maxn], fa[maxn];
struct edge
{
	int pre, to;
} e[maxn];
inline void add(int from, int to)
{
	e[++cnt].pre = head[from];
	e[cnt].to = to;
	head[from] = cnt;
}
void dp(int now)
{
	vis[now] = 1;
	f[now][0] = 0, f[now][1] = val[now];
	for (int i = head[now]; i; i = e[i].pre)
	{
		int go = e[i].to;
		if (go != root)
		{
			dp(go);
			f[now][0] += max(f[go][1], f[go][0]);
			f[now][1] += f[go][0];
		}
		else
		{
			f[go][1] = -maxn;
		}
	}
}
inline void find_circle(int x)
{
	vis[x] = 1;
	root = x;
	while (!vis[fa[root]])
	{
		root = fa[root];
		vis[root] = 1;
	} // 找环

	dp(root);
	long long t = max(f[root][0], f[root][1]);
	vis[root] = 1;
	root = fa[root];
	dp(root);
	ans += max(t, max(f[root][0], f[root][1]));
	return;
}
inline int in()
{
	char a = getchar();
	while (a < '0' || a > '9')
	{
		a = getchar();
	}
	int t = 0;
	while (a <= '9' && a >= '0')
	{
		t = (t << 1) + (t << 3) + a - '0';
		a = getchar();
	}
	return t;
}
// 写一下伪代码
// 在存的时候存一下每个人最讨厌的人为他的父亲
// 对每个没访问的点DFS
// 在这个没访问的点所在的连通块上找环
// 找到以后强制不选它的父亲对它进行DP
// 然后强制不选它对它的父亲进行DP
// 然后取一个最大值即可
// 在DP里面
// 先考虑f[x][0]是不选x,初始值为0
// f[x][1]是选x,初值为val[x]
// 这是一个很好的赋值方法
// 然后跑DP就行了
int main()
{
	n = in();
	for (int i = 1; i <= n; i++)
	{
		val[i] = in();
		int x = in();
		add(x, i);
		//    add(i,x);
		fa[i] = x;
	}
	for (int i = 1; i <= n; i++)
	{
		if (!vis[i])
		{
			find_circle(i);
		}
	}
	printf("%lld\n", ans);
	return 0;
}