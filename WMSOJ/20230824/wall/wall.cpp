#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#define int long long
#define double long double
#define endl "\n"
#define problemname "wall"
#define const constexpr
const int N = 1e5 + 5;
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
namespace Main
{

	struct node
	{
		int x, y;
		bool dir = 0;
	} door[N];
	int N, M, d, K;
	bool cmp(node a, node b)
	{
		return a.y < b.y;
	}
	pair<int, int> status(int id, int t)
	{
		int T = (N - d) * 2;
		t %= T;
		pair<int, int> ans;
		int temp;
		if (door[id].dir)
		{
			temp = door[id].x;
			door[id].x = N - (door[id].x + d - 1) + 1;
		}
		if (t <= door[id].x - 1)
		{
			ans = {door[id].x - t, door[id].x - t + d - 1};
		}
		else if (t <= door[id].x + N - d - 1)
		{
			ans = {(t - (door[id].x-1) + 1), (t - door[id].x + 1) + d};
		}
		else
		{
			ans = {door[id].x + T - t, door[id].x + T - t + d-1};
		}
		if (door[id].dir)
		{
			door[id].x = temp;
			ans.first = N - ans.second + 1;
			ans.second = ans.first+d-1;
		}
		if (ans.first > ans.second)
		{
			swap(ans.first, ans.second);
		}
		return ans;
	}
	bool check(int nowx, int nowy)
	{
		int up = nowx, down = nowx;
		int t = 0;
		int st=lower_bound(door+1,door+1+N,(node){0,nowy,0},cmp)-door;
		if(st==1+N){
			st=1;
		}
		for (int i = st; i <= K; i++)
		{
			if (door[i].y < nowy)
			{
				continue;
			}
			t += door[i].y - nowy;
			auto rag = status(i, t);
			up = up - (door[i].y - nowy);
			down = down + (door[i].y - nowy);
			if (up > rag.second || down < rag.first)
			{
				return 0;
			}
			else
			{
				down = min(down, rag.second);
				up = max(up, rag.first);
				nowy = door[i].y;
			}
		}
		return 1;
	}
	int main()
	{
		cin >> N >> M >> d;
		cin >> K;
		char c;
		int tempx, tempy;
		for (int i = 1; i <= K; i++)
		{
			cin >> door[i].x >> door[i].y >> c;
			if (c == '+')
			{
				door[i].dir = 1;
			}
		}
		sort(door + 1, door + 1 + K, cmp);
		int q;
		cin >> q;
		for (int i = 1; i <= q; i++)
		{
			cin >> tempx >> tempy;
			cout << check(tempx, tempy) << endl;
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