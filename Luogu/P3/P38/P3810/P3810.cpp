#include <bits/stdc++.h>
#include <bits/extc++.h>
#include <sys/mman.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
#define int long long
#define double long double
#define endl "\n"
#define gc() (p1 == p2 && (p2 = (p1 = ibuf) + fread(ibuf, 1, SIZE, stdin), p1 == p2) ? EOF : *p1++)

namespace FastIO
{
	static constexpr int SIZE = 1 << 21;
	char ibuf[SIZE], obuf[SIZE], *p1 = ibuf, *p2 = ibuf, *p3 = obuf;
	inline void read(char &c)
	{
		for (c = gc(); !std::isgraph(c); c = gc())
			;
	}
	inline void read(char *s)
	{
		char c = gc();
		for (; !std::isgraph(c); c = gc())
			;
		for (; std::isgraph(c); c = gc())
			*s++ = c;
		*s = 0;
	}
	inline void read(std::string &s)
	{
		s.clear();
		char c = gc();
		for (; !std::isgraph(c); c = gc())
			;
		for (; std::isgraph(c); c = gc())
			s.push_back(c);
	}
	inline void pc(char c)
	{
		if (p3 - obuf == SIZE)
			fwrite(obuf, 1, SIZE, stdout), p3 = obuf;
		*p3++ = c;
	}
	inline void write(char c) { pc(c); }
	inline void write(const char *s)
	{
		while (*s)
			pc(*s), ++s;
	}
	inline void write(std::string s)
	{
		for (const char c : s)
			pc(c);
	}
	template <typename _Tp>
	inline void read(_Tp &x)
	{
		x = 0;
		char c = gc();
		int f = 0;
		for (; !std::isdigit(c); c = gc())
			f |= c == '-';
		for (; std::isdigit(c); c = gc())
			x = (x << 1) + (x << 3) + (c ^ 48);
		return f ? x = ~x + 1 : 1, void();
	}
	template <typename _Tp>
	inline void write(_Tp x)
	{
		static int stk[40];
		int tp = 0;
		if (!x)
			return pc('0'), void();
		if (x < 0)
			pc('-'), x = ~x + 1;
		while (x)
			stk[++tp] = x % 10, x /= 10;
		while (tp)
			pc(stk[tp--] + '0');
	}
	template <typename _Tp>
	inline void writesp(_Tp x)
	{
		write(x);
		pc(' ');
	}
	template <typename _Tp>
	inline void writeln(_Tp x) { write(x), pc('\n'); }
	template <typename _Tp, typename... Args>
	inline void read(_Tp &x, Args &...args) { read(x), read(args...); }
	template <typename _Tp, typename... Args>
	inline void write(_Tp x, Args... args) { write(x), write(args...); }
	template <typename _Tp, typename... Args>
	inline void writesp(_Tp x, Args... args) { writesp(x), writesp(args...); }
	template <typename _Tp, typename... Args>
	inline void writeln(_Tp x, Args... args) { writeln(x), writeln(args...); }
	inline void flush() { fwrite(obuf, p3 - obuf, 1, stdout); }
}
void FileIO(string s)
{
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

namespace P3810
{

	constexpr int lowbit(const int &x)
	{
		return x & (-x);
	}

	struct tarray
	{
		static constexpr int N = 2e5 + 5;
		int tree[N << 1];
		int sum(int i)
		{
			int ans = 0;
			while (i)
			{
				ans += tree[i];
				i -= lowbit(i);
			}
			return ans;
		}
		int range_sum(int l, int r)
		{
			return sum(r) - sum(l - 1);
		}
		inline void add(int i, int val)
		{
			while (i <= N)
			{
				tree[i] += val;
				i += lowbit(i);
			}
		}
	} Tree;

	const int N = 1e5 + 5;

	struct node
	{
		int x, y, z, cnt, ans;
	} dat[N], tmp[N];

	bool operator!=(node u, node v)
	{
		return u.x != v.x || u.y != v.y || u.z != v.z;
	}

	void cdq(int l, int r)
	{
		if (l == r)
		{
			return;
		}
		int mid = (l + r) >> 1;
		cdq(l, mid);	 // 求 [l,mid] 内部的贡献
		cdq(mid + 1, r); // 求 [mid+1,r] 内部的贡献
		sort(dat + l, dat + mid + 1, [](node u, node v)
			 { return u.y == v.y ? u.z < v.z : u.y < v.y; });
		sort(dat + mid + 1, dat + r + 1, [](node u, node v)
			 { return u.y == v.y ? u.z < v.z : u.y < v.y; });
		int i = mid + 1, j = l;
		while (i <= r)
		{
			while (j <= mid && dat[j].y <= dat[i].y)
			{
				Tree.add(dat[j].z, dat[j].cnt);
				++j;
			}
			dat[i].ans += Tree.sum(dat[i].z);
			++i;
		} //	求 [l,mid] 对 [mid+1,r] 的贡献
		for (i = l; i < j; i++)
		{
			Tree.add(dat[i].z, -dat[i].cnt);
		}
	}

	int ans[N];

	int main()
	{
		int n, k;
		FastIO::read(n, k);
		for (int i = 1; i <= n; i++)
		{
			FastIO::read(tmp[i].x, tmp[i].y, tmp[i].z);
		}
		sort(tmp + 1, tmp + n + 1, [](node u, node v)
			 { return u.x == v.x ? (u.y == v.y ? u.z < v.z : u.y < v.y) : u.x < v.x; });
		int tot = 0 /* 记录不重复元素个数 */, cnt = 0 /* 记录重复元素个数 */;
		for (int i = 1; i <= n; i++)
		{
			++cnt;
			if (tmp[i] != tmp[i + 1])
			{
				dat[++tot] = tmp[i];
				dat[tot].cnt = cnt;
				cnt = 0;
			}
		}
		cdq(1, tot);
		for (int i = 1; i <= tot; i++)
		{
			ans[dat[i].ans + dat[i].cnt - 1] += dat[i].cnt;
		}
		for (int i = 0; i < n; i++)
		{
			FastIO::writeln(ans[i]);
		}
		return 0;
	}
};

signed main()
{
#ifndef ONLINE_JUDGE
	FileIO("P3810");
#endif
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	P3810::main();
	FastIO::flush();
	return 0;
}