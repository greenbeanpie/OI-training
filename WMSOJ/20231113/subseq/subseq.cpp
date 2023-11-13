#include <bits/stdc++.h>
using namespace std;

#pragma GCC target("tune=native")
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")

#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")

#pragma GCC optimize("-falign-functions")

#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")

#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
bool beg;
const int mod = 998244353, N = 1e5 + 5;
int n, T, a[N];
int dp[N];

#define gc() (p1 == p2 && (p2 = (p1 = ibuf) + fread(ibuf, 1, SIZE, stdin), p1 == p2) ? EOF : *p1++)
namespace FastIO { static constexpr int SIZE = 1 << 21; char ibuf[SIZE], obuf[SIZE], *p1 = ibuf, *p2 = ibuf, *p3 = obuf; inline void read(char& c) { for(c = gc(); !std::isgraph(c); c = gc()); } inline void read(char* s) { char c = gc(); for(; !std::isgraph(c); c = gc());for(; std::isgraph(c); c = gc()) *s++ = c; *s = 0; } inline void read(std::string& s) { s.clear(); char c = gc(); for(; !std::isgraph(c); c = gc()); for(; std::isgraph(c); c = gc()) s.push_back(c); } inline void pc(char c) { if(p3 - obuf == SIZE) fwrite(obuf, 1, SIZE, stdout), p3 = obuf; *p3++ = c; } inline void write(char c) { pc(c); } inline void write(const char* s) { while(*s) pc(*s), ++s; } inline void write(std::string s) { for(const char c : s) pc(c); } template<typename _Tp>inline void read(_Tp& x) { x = 0; char c = gc(); int f = 0; for(; !std::isdigit(c); c = gc()) f |= c == '-'; for(; std::isdigit(c); c = gc()) x = (x << 1) + (x << 3) + (c ^ 48); return f ? x = ~x + 1 : 1, void(); } template<typename _Tp>inline void write(_Tp x) { static int stk[40]; int tp = 0; if(!x) return pc('0'), void(); if(x < 0) pc('-'), x = ~x + 1; while(x) stk[++tp] = x % 10, x /= 10; while(tp) pc(stk[tp--] + '0'); } template<typename _Tp>inline void writesp(_Tp x) { write(x); pc(' '); } template<typename _Tp>inline void writeln(_Tp x) { write(x), pc('\n'); } template<typename _Tp, typename ...Args>inline void read(_Tp& x, Args& ...args) { read(x), read(args...); } template<typename _Tp, typename ...Args>inline void write(_Tp x, Args ...args) { write(x), write(args...); } template<typename _Tp, typename ...Args>inline void writesp(_Tp x, Args ...args) { writesp(x), writesp(args...); } template<typename _Tp, typename ...Args>inline void writeln(_Tp x, Args ...args) { writeln(x), writeln(args...); } inline void flush() { fwrite(obuf, p3 - obuf, 1, stdout); } }
using namespace FastIO;

inline int Mod(int x)
{
	return (x >= mod ? x - mod : x);
}
struct Tre
{
	int l, r, maxn;
	inline void clear()
	{
		l = r = maxn = 0;
	}
} tre[N * 405];
int root[N], ipx;
inline void pushup(int o)
{
	tre[o].maxn = max(tre[tre[o].l].maxn, tre[tre[o].r].maxn);
}
void build(int &o, int l, int r)
{
	if (!o)
		o = ++ipx;
	if (l == r)
	{
		if (l == 0)
			tre[o].maxn = 0;
		else
			tre[o].maxn = -1;
		return;
	}
	int mid = l + r >> 1;
	build(tre[o].l, l, mid), build(tre[o].r, mid + 1, r);
	pushup(o);
}
void ins(int &o, int p, int l, int r, int pos, int k)
{
	if (!o)
		o = ++ipx;
	if (l == r)
	{
		tre[o].maxn = k;
		return;
	}
	int mid = l + r >> 1;
	if (pos <= mid)
		ins(tre[o].l, tre[p].l, l, mid, pos, k), tre[o].r = tre[p].r;
	else
		ins(tre[o].r, tre[p].r, mid + 1, r, pos, k), tre[o].l = tre[p].l;
	pushup(o);
}
int check(int o, int l, int r, int x, int y)
{
	if (x > y)
		return -1;
	if (x <= l && r <= y)
	{
		return tre[o].maxn;
	}
	int mid = l + r >> 1, ans = -1;
	if (x <= mid)
		ans = max(ans, check(tre[o].l, l, mid, x, y));
	if (y > mid)
		ans = max(ans, check(tre[o].r, mid + 1, r, x, y));
	return ans;
}
bool ed;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("subseq.in", "r", stdin);
	freopen("subseq.out", "w", stdout);
#endif
	read(T);
	while (T--)
	{
		read(n);
		for (register int i = 1; i <= n; i++)
			read(a[i]);
		dp[0] = 1, a[n + 1] = n + 1;
		for (int i = 1; i <= ipx; i++)
			tre[i].clear();
		for (int i = 0; i <= n + 1; i++)
			root[i] = 0;
		ipx = 0;
		build(root[0], 0, n + 1);
		for (int i = 1; i <= n + 1; i++)
		{
			int maxn = 0, j = i;
			dp[i] = 0;
			while (j != 0)
			{
				j = check(root[j - 1], 0, n + 1, maxn, a[i] - 1);
				if (j == -1)
					break;
				maxn = a[j];
				dp[i] = (dp[i] + dp[j]) % mod;
			}
			ins(root[i], root[i - 1], 0, n + 1, a[i], i);
		}
		writeln(dp[n + 1]);
	}
	return 0;
}
