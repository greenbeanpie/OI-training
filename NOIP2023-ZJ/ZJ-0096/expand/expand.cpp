#include<cstdio>
#include<iostream>
using namespace std;
const int maxn = 500005;
int xs0[maxn], ys0[maxn];
int ar1[maxn], ar2[maxn], ta1[maxn], ta2[maxn], mx1[maxn], mx2[maxn], mn1[maxn], mn2[maxn];
int inline read(){int res = 0; char c = 0; while(c < '0' || c > '9') c = getchar(); while(c >= '0' && c <= '9') res = res * 10 + (c - '0'), c = getchar(); return res;}
void getmx(int n, int tmpa[], int mxs[])
{
	mxs[0] = 0, mxs[1] = 1;
	for(int i = 2; i <= n; i++)
		if(tmpa[i] > tmpa[mxs[i - 1]]) mxs[i] = i;
		else mxs[i] = mxs[i - 1];
}
void getmn(int n, int tmpa[], int mns[])
{
	mns[0] = 0, mns[1] = 1;
	for(int i = 2; i <= n; i++)
		if(tmpa[i] < tmpa[mns[i - 1]]) mns[i] = i;
		else mns[i] = mns[i - 1];
}
bool check0(int n0, int xs[], int m0, int ys[])
{
	xs[0] = 2e9, ys[0] = -2e9;
	getmx(n0, xs, mx1), getmx(m0, ys, mx2);
	getmn(n0, xs, mn1), getmn(m0, ys, mn2);
	int pos1 = n0, pos2 = m0;
	while(pos1 > 1 && pos2 > 1)
	{
		if(pos1 > 1 && xs[mx1[pos1 - 1]] > ys[mx2[pos2 - 1]]) pos1 = mx1[pos1 - 1];
		else if(pos2 > 1 && xs[mn1[pos1 - 1]] > ys[mn2[pos2 - 1]]) pos2 = mn2[pos2 - 1];
		else return 0;
	}
	return xs[1] > ys[1];
}
bool check1(int n0, int xs[], int m0, int ys[])
{
	int p1 = 0, p2 = 0, t1 = -2e9, t2 = 2e9;
	xs[0] = xs[n0 + 1] = -2e9, ys[0] = ys[m0 + 1] = 2e9;
	for(int i = 1; i <= n0; i++) if(xs[i] > xs[p1]) p1 = i;
	for(int i = 1; i <= m0; i++) if(ys[i] < ys[p2]) p2 = i;
	for(int i = 1; i <= m0; i++) t1 = max(t1, ys[i]);
	for(int i = 1; i <= n0; i++) t2 = min(t2, xs[i]);
	if(xs[p1] <= t1 || ys[p2] >= t2) return 0;
	for(int i = 1; i <= p1; i++) ta1[i] = xs[i];
	for(int i = 1; i <= p2; i++) ta2[i] = ys[i];
	if(!check0(p1, ta1, p2, ta2)) return 0;
	p1 = p2 = 0;
	for(int i = n0; i; i--) if(xs[i] > xs[p1]) p1 = i;
	for(int i = m0; i; i--) if(ys[i] < ys[p2]) p2 = i;
	for(int i = n0; i >= p1; i--) ta1[n0 - i + 1] = xs[i];
	for(int i = m0; i >= p2; i--) ta2[m0 - i + 1] = ys[i];
	if(!check0(n0 - p1 + 1, ta1, m0 - p2 + 1, ta2)) return 0;
	return 1;
}
int main()
{
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	int c0, n, m, q, k1, k2, t1, t2;
	bool ans[105];
	c0 = read(), n = read(), m = read(), q = read();
	for(int i = 1; i <= n; i++) xs0[i] = read();
	for(int i = 1; i <= m; i++) ys0[i] = read();
	ans[0] = (check1(n, xs0, m, ys0) || check1(m, ys0, n, xs0));
	for(int xi = 1; xi <= q; xi++)
	{
		for(int i = 1; i <= n; i++) ar1[i] = xs0[i];
		for(int i = 1; i <= m; i++) ar2[i] = ys0[i];
		k1 = read(), k2 = read();
		for(int i = 1; i <= k1; i++)
			t1 = read(), t2 = read(), ar1[t1] = t2;
		for(int i = 1; i <= k2; i++)
			t1 = read(), t2 = read(), ar2[t1] = t2;
		ans[xi] = (check1(n, ar1, m, ar2) || check1(m, ar2, n, ar1));
	}
	for(int i = 0; i <= q; i++) printf("%d", (int)ans[i]);
	return 0;
}