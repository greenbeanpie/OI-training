#include <bits/stdc++.h>
#define ll long long
using namespace std;

char buf[1000005];
int ppos, llen;

inline char gch()
{
	if (ppos == llen)
	{
		ppos = 0;
		llen = fread(buf, 1, 1000000, stdin);
	}
	if (ppos == llen) return -1;
	return buf[ppos++];
}

char obuf[1000005];
int opos;

inline void pch(char c)
{
	if (opos == 1000000)
	{
		fwrite(obuf, 1, 1000000, stdout);
		opos = 0;
	}
	obuf[opos++] = c;
}

template < typename T >
inline void read(T &x)
{
	bool flg = x = 0;
	char c;
	while ((c = gch()) < 48 || c > 57)
		flg |= c == '-';
	do
		x = (x << 1) + (x << 3) + (c ^ 48);
	while ((c = gch()) > 47 && c < 58);
	if (flg) x = -x;
}

const int N = 5e5 + 5;
int a[N], pos[N];
ll dis[N][2];
bool vis[N][2];
priority_queue < pair < ll, pair < int, int > >, vector < pair < ll, pair < int, int > > >, greater < pair < ll, pair < int, int > > > > q; 

template < typename T >
inline void Chkmin(T &x, T y)
{
	if (y < x) x = y;
}

int main()
{
	freopen("arrange.in","r",stdin);
	freopen("arrange.out","w",stdout);
	int n, m;
	read(n);
	read(m);
	for (int i = 1; i <= n; ++i)
	{
		read(a[i]);
		pos[a[i]] = i;
	}
	if (m == n)
	{
		puts("0");
		return 0;
	}
	ll ans = LONG_LONG_MAX;
	memset(dis, 0x3f, sizeof(dis));
	dis[0][0] = 0;
	q.emplace(0ll, make_pair(0, 0));
	while (q.size())
	{
		pair < ll, pair < int, int > > Top = q.top();
		q.pop();
		if (vis[Top.second.first][Top.second.second]) continue;
		vis[Top.second.first][Top.second.second] = 1;
		if (dis[Top.second.first][Top.second.second] >= ans) continue; 
		if (!Top.second.first)
		{
			int num = 0;
			while (num != n && pos[num + 1] <= m)
				++num;
			dis[num + 1][0] = n - pos[num + 1] + 1;
			q.emplace(dis[num + 1][0], make_pair(num + 1, 0));
			dis[num + 1][1] = pos[num + 1] - m;
			q.emplace(dis[num + 1][1], make_pair(num + 1, 1));
		}
		else if (Top.second.second)
		{
			int num = Top.second.first, delta;
			if (pos[Top.second.first] <= m) delta = m - pos[Top.second.first];
			else delta = n - pos[Top.second.first] + m;
			while (num != n)
			{
				int cur = pos[num + 1] + delta;
				if (cur > n) cur -= n;
				if (cur <= m) ++num;
				else break;
			}
			if (num == n) Chkmin(ans, dis[Top.second.first][Top.second.second]);
			else
			{
				int cur = pos[num + 1] + delta;
				if (cur > n) cur -= n;
				ll tmp = dis[Top.second.first][Top.second.second] + n - cur + 1;
				if (tmp < dis[num + 1][0])
				{
					dis[num + 1][0] = tmp;
					q.emplace(tmp, make_pair(num + 1, 0));
				}
				tmp = dis[Top.second.first][Top.second.second] + cur - m;
				if (tmp < dis[num + 1][1])
				{
					dis[num + 1][1] = tmp;
					q.emplace(tmp, make_pair(num + 1, 1));
				}
			}
		}
		else
		{
			int num = Top.second.first, delta;
			if (pos[Top.second.first] == 1) delta = 0;
			else delta = n - pos[Top.second.first] + 1;
			while (num != n)
			{
				int cur = pos[num + 1] + delta;
				if (cur > n) cur -= n;
				if (cur <= m) ++num;
				else break;
			}
			if (num == n) Chkmin(ans, dis[Top.second.first][Top.second.second]);
			else
			{
				int cur = pos[num + 1] + delta;
				if (cur > n) cur -= n;
				ll tmp = dis[Top.second.first][Top.second.second] + n - cur + 1;
				if (tmp < dis[num + 1][0])
				{
					dis[num + 1][0] = tmp;
					q.emplace(tmp, make_pair(num + 1, 0));
				}
				tmp = dis[Top.second.first][Top.second.second] + cur - m;
				if (tmp < dis[num + 1][1])
				{
					dis[num + 1][1] = tmp;
					q.emplace(tmp, make_pair(num + 1, 1));
				}
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}
