#include <cstdio>
#include <queue>
#include <cstring>
#include <queue>
#include <algorithm>
#define INF 2147483647
#define LL long long
using namespace std;
queue<int> f;
int n, m, m1, t1, m2, t2, len = -1, st, ed;
struct node
{
	int x, y, c, d, next;
} a[100000];
int b[100000], last[100000], pre[100000], pos[100000], p[100000];
LL dis[100000];
bool bz[100000];
void ins(int x, int y, int c, int d)
{
	a[++len].x = x;
	a[len].y = y;
	a[len].c = c;
	a[len].d = d;
	a[len].next = last[x];
	last[x] = len;
	a[++len].x = y;
	a[len].y = x;
	a[len].c = 0;
	a[len].d = -d;
	a[len].next = last[y];
	last[y] = len;
}
bool spfa()
{
	memset(bz, true, sizeof(bz));
	bz[st] = false;
	memset(dis, 63, sizeof(dis));
	dis[st] = 0;
	p[st] = INF;
	f.push(st);
	while (!f.empty())
	{
		int x = f.front();
		bz[x] = true;
		for (int i = last[x]; i > -1; i = a[i].next)
		{
			int y = a[i].y;
			if (a[i].c > 0 && dis[y] > dis[x] + a[i].d)
			{
				dis[y] = dis[x] + a[i].d;
				pos[y] = x;
				pre[y] = i;
				p[y] = min(p[x], a[i].c);
				if (bz[y])
				{
					f.push(y);
					bz[y] = false;
				}
			}
		}
		f.pop();
	}
	return dis[ed] < 4557430888798830399;
}
LL flow()
{
	LL ans = 0;
	while (spfa())
	{
		ans += p[ed] * dis[ed];
		for (int i = ed; i != st; i = pos[i])
		{
			a[pre[i]].c -= p[ed];
			a[pre[i] ^ 1].c += p[ed];
		}
	}
	return ans;
}
int main()
{
	int x;
	scanf("%d", &n);
	st = 0, ed = 2 * n + 1;
	memset(last, -1, sizeof(last));
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &x);
		ins(st, i, x, 0);	  // 每天晚上从起点获得x条脏餐巾
		ins(i + n, ed, x, 0); // 每天白天,向汇点提供x条干净的餐巾,流满时表示第i天的餐巾够用
	}
	scanf("%d %d %d %d %d", &m, &t1, &m1, &t2, &m2);
	for (int i = 1; i <= n; i++)
	{
		if (i + 1 <= n)
			ins(i, i + 1, INF, 0); // 每天晚上可以将脏餐巾留到第二天晚上
		if (i + t1 <= n)
			ins(i, i + n + t1, INF, m1); // 每天晚上可以送去快洗部,在地i+t1天早上收到餐巾
		if (i + t2 <= n)
			ins(i, i + n + t2, INF, m2); // 每天晚上可以送去慢洗部,在地i+t2天早上收到餐巾
		ins(st, i + n, INF, m);			 // 每天早上可以购买餐巾
	}
	printf("%lld", flow());
}
