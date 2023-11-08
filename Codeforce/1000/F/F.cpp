#include <bits/stdc++.h>
// #include <bits/extc++.h>
// using namespace __gnu_pbds;
// using namespace __gnu_cxx;
using namespace std;
#ifndef CODESPACE
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
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
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
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
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#endif

// #define int long long
// #define double long double
#define endl "\n"
#define problemname "F"
// #define const constexpr

namespace CF1000F
{
	inline char gc()
	{
		static char buf[100000], *p1 = buf, *p2 = buf;
		return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1++;
	}

	inline void read(int &x)
	{
		x = 0;
		char c = gc();
		while (c < '0' || c > '9')
			c = gc();
		while (c >= '0' && c <= '9')
		{
			x = (x << 3) + (x << 1) + (c ^ 48);
			c = gc();
		}
	}
	inline void write(int x)
	{
		if (x > 9)
			write(x / 10);
		putchar(x % 10 + '0');
	}
	struct ask
	{
		int l, r, id, lb;
	};
	const int N = 5e5 + 5;
	ask p[N];
	int num[N];
	int ans[N];
	int q, block_size;
	int cnt[N];
	// unordered_map<int, int>  once;
	int stk[N], pos[N], top;
	extern void add(int x);
	extern void sub(int x);
	void add(int x)
	{
		cnt[num[x]]=-~cnt[num[x]];
		if (cnt[num[x]] == 1)
		{
			stk[++top] = num[x];
			pos[num[x]] = top;
		}
		else if (cnt[num[x]] == 2)
		{
			stk[pos[num[x]]] = stk[top];
			pos[stk[top]] = pos[num[x]];
			stk[top--] = pos[num[x]] = 0;
		}
	}
	void sub(int x)
	{
		cnt[num[x]]=~-cnt[num[x]];
		if (cnt[num[x]] == 1)
		{
			stk[++top] = num[x];
			pos[num[x]] = top;
		}
		else if (cnt[num[x]] == 0)
		{
			stk[pos[num[x]]] = stk[top];
			pos[stk[top]] = pos[num[x]];
			stk[top--] = pos[num[x]] = 0;
		}
	}
	inline bool cmp(ask a, ask b)
	{
		return (a.lb ^ b.lb) ? a.lb < b.lb : (a.lb & 1 ? a.r < b.r : a.r > b.r);
	}

	int main()
	{
		int n;
		read(n);
		block_size = sqrt(n);
		for (int i = 1; i <= n; i++)
		{
			read(num[i]);
		}
		read(q);
		for (int i = 1; i <= q; i++)
		{
			read(p[i].l);
			read(p[i].r);
			p[i].id = i;
			p[i].lb = p[i].l / block_size;
		}
		sort(p + 1, p + 1 + q, cmp);
		int l = p[1].l, r = p[1].l - 1;
		cnt[0] = 1;
		for (int i = 1; i <= q; i++)
		{
			while (l < p[i].l)
			{
				sub(l++);
			}
			while (l > p[i].l)
			{
				add(--l);
			}
			while (r > p[i].r)
			{
				sub(r--);
			}
			while (r < p[i].r)
			{
				add(++r);
			}
			ans[p[i].id] = stk[top];
		}
		for (int i = 1; i <= q; i++)
		{
			write(ans[i]);
			putchar('\n');
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
	CF1000F::main();
	return 0;
}