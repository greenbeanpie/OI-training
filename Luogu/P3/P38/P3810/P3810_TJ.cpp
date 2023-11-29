#include <cstdio>
#include <algorithm>
#include <string>
#define maxn 100010
#define maxk 200010
using namespace std;
struct node
{
	int x, y, z, ans, w;
};
node a[maxn], b[maxn];
int n, cnt[maxk];
int k, z;
bool cmp1(node u, node v)
{
	if (u.x == v.x)
	{
		if (u.y == v.y)
			return u.z < v.z;
		return u.y < v.y;
	}
	return u.x < v.x;
}
bool cmp2(node u, node v)
{
	if (u.y == v.y)
		return u.z < v.z;
	return u.y < v.y;
}
struct TREE
{
	int tre[maxk], kk;
	int lowbit(int x)
	{
		return x & (-x);
	}
	int ask(int i)
	{
		int ans = 0;
		for (; i; i -= lowbit(i))
		{
			ans += tre[i];
		}
		return ans;
	}
	void add(int i, int k)
	{
		for (; i <= kk; i += lowbit(i))
		{
			tre[i] += k;
		}
	}
} t;
void cdq(int l, int r)
{
	if (l == r)
	{
		return;
	}
	int mid = (l + r) >> 1;
	cdq(l, mid);
	cdq(mid + 1, r);
	sort(a + l, a + mid + 1, cmp2);
	sort(a + mid + 1, a + r + 1, cmp2);
	int i = mid + 1, j = l;
	while (i <= r)
	{
		while (a[j].y <= a[i].y && j <= mid)
		{
			t.add(a[j].z, a[j].w);
			j++;
		}
		a[i].ans += t.ask(a[i].z);
		i++;
	}
	for (i = l; i < j; i++)
	{
		t.add(a[i].z, -a[i].w);
	}
}

void FileIO(string s)
{
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + "_TJ.out").c_str(), "w", stdout);
}

int main()
{
#ifndef ONLINE_JUDGE
	FileIO("P3810");
#endif
	scanf("%d%d", &z, &k); // z是数量，k是最大属性值
	t.kk = k;			   // 设定上限，t是维护的树状数组
	for (int i = 1; i <= z; i++)
	{
		scanf("%d%d%d", &b[i].x, &b[i].y, &b[i].z); //
	}
	sort(b + 1, b + z + 1, cmp1); // 排序
	int c = 0;
	for (int i = 1; i <= z; i++)
	{
		c++;
		if (b[i].x != b[i + 1].x || b[i].y != b[i + 1].y || b[i].z != b[i + 1].z)
			a[++n] = b[i], a[n].w = c, c = 0;
	}		   // 去重
	cdq(1, n); // cdqaq
	for (int i = 1; i <= n; i++)
	{
		cnt[a[i].ans + a[i].w - 1] += a[i].w; // 这个地方不太好理解：cnt【x】就是储存f【i】= x的个数，x就等于i的答案加上它重复的个数（可以取等）减去本身
	}
	for (int i = 0; i < z; i++)
	{
		printf("%d\n", cnt[i]);
	}
	return 0;
}
