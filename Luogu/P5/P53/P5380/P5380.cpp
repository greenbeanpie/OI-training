#include <bits/stdc++.h>
#include <bits/extc++.h>
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
// #define const constexpr

namespace P3580
{

	struct node
	{
		bool color; // red:0 blue:1
		int typ;	// 1:captain 2:guard 3:elephant 4:horse 5:car 6:duck 7:soldier
		node(bool a, int b)
		{
			color = a, typ = b;
		}
	};
	random_device rd;
	sfmt19937_64 rand(rd());
	int k1 = rand(), k2 = rand();
	struct myhash
	{
		size_t operator()(const pt &a) const
		{
			return a.x * k1 + a.y * k2;
		}
	};

	struct pt
	{
		int x, y;
		pt(int a, int b) { x = a, y = b; }
	};
	cc_hash_table<pt, node, myhash> mp;

	void init()
	{
		mp[{0, 0}] = mp[{8, 0}] = {0, 5};
		mp[{1, 0}] = mp[{7, 0}] = {0, 4};
		mp[{2, 0}] = mp[{6, 0}] = {0, 3};
		mp[{3, 0}] = mp[{5, 0}] = {0, 2};
		mp[{4, 0}] = {0, 1};
		mp[{0, 2}] = mp[{8, 2}] = {0, 6};
		mp[{0, 3}] = mp[{2, 3}] = mp[{4, 3}] = mp[{6, 3}] = mp[{8, 3}] = {0, 7};
		mp[{0, 6}] = mp[{2, 6}] = mp[{4, 6}] = mp[{6, 6}] = mp[{8, 6}] = {1, 7};
		mp[{0, 7}] = mp[{8, 7}] = {1, 6};
		mp[{0, 9}] = mp[{8, 9}] = {1, 5};
		mp[{1, 9}] = mp[{7, 9}] = {1, 4};
		mp[{2, 9}] = mp[{6, 9}] = {1, 3};
	}

	int main()
	{
		int Q;
		FastIO::read(Q);
		return 0;
	}
};

signed main()
{
#ifndef ONLINE_JUDGE
	FileIO("P3580");
#endif
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	P3580::main();
	FastIO::flush();
	return 0;
}