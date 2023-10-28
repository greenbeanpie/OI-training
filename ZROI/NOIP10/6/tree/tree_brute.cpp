#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
#define int long long
#define double long double
#define endl "\n"
#define problemname "tree"

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
	inline void writeln(_Tp x) { write(x), pc(' '); }
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

#define const constexpr

namespace Main
{
	const int N = 1e5;
	vector<int> e[N];
	int fa[N];
	int ans;

	void dfs(int u,int father){
		fa[u] = father;
		for(int i:e[u]){
			if(i!=father){
				dfs(i, u);
			}
		}
	}

	// int dfs(int u, int fa, int l, int r)
	// {
	// 	int cnt = (u >= l && u <= r);
	// 	for (int i : e[u])
	// 	{
	// 		if (i != fa&&i<=r)
	// 		{
	// 			cnt += dfs(i, u, l, r);
	// 		}
	// 	}
	// 	if (u >= l && u <= r)
	// 	{
	// 		ans += cnt;
	// 	}
	// 	return cnt;
	// }
	int cnt[N];
	int solve(int l, int r)
	{
		ans = 0;
		// dfs(1, -1, l, r);
		int sum = 0;
		// cc_hash_table<int, int> cnt;
		for (int i = l; i <= r;i++){
			cnt[i]=1;
		}
		for (int i = r; i >= l;i--){
			sum += cnt[i];
			cnt[fa[i]] += cnt[i];
		}
		return sum;
	}

	int main()
	{
		int n;
		cin >> n;
		for (int i = 2, v; i <= n; i++)
		{
			cin >> v;
			e[i].push_back(v);
			e[v].push_back(i);
		}
		dfs(1, 0);
		int q;
		cin >> q;
		for (int i = 1, l, r, lastans = 0; i <= q; i++)
		{
			cin >> l >> r;
			l ^= lastans, r ^= lastans;
			l %= n, r %= n;
			++l, ++r;
			if (l > r)
			{
				swap(l, r);
			}
			cout << (lastans = solve(l, r)) << endl;
		}
		return 0;
	}
};

signed main()
{
#ifndef ONLINE_JUDGE
	freopen(problemname ".in", "r", stdin);
	freopen(problemname ".out", "w", stdout);
#endif
	ios::sync_with_stdio(false); 
	cin.tie(0), cout.tie(0);
	Main::main();
	return 0;
}
