#include <bits/stdc++.h>
#define int long long
#define lp (p<<1)
#define rp (p<<1|1)

using namespace std;

int read() {
	int x=0, f=0; char c=getchar();
	while (!isdigit(c)) f|=c=='-', c=getchar();
	while (isdigit(c)) x=(x<<3)+(x<<1)+(c^48), c=getchar();
	return f ? -x : x;
}

const int N=1e5+10;
int n, m, k, d, t[N<<2], mx[N<<2];
struct node {
	int x, y, v;
} a[N];

bool cmp(node a, node b) {
	return a.x<b.x;
}

void pushdown(int p) {
	if (!t[p]) return;
	t[lp]+=t[p];
	t[rp]+=t[p];
	mx[lp]+=t[p];
	mx[rp]+=t[p];
	t[p]=0;
}

void add(int p, int l, int r, int L, int R, int x) {
	if (L<=l && r<=R) {
		t[p]+=x;
		mx[p]+=x;
		return;
	}
	pushdown(p);
	int mid=l+r>>1;
	if (L<=mid) add(lp, l, mid, L, R, x);
	if (R>mid) add(rp, mid+1, r, L, R, x);
	mx[p]=max(mx[lp], mx[rp]);
}

int ask(int p, int l, int r, int L, int R) {
	if (L<=l && r<=R) return mx[p];
	pushdown(p);
	int mid=l+r>>1, res=mx[0];
	if (L<=mid) res=max(res, ask(lp, l, mid, L, R));
	if (R>mid) res=max(res, ask(rp, mid+1, r, L, R));
	return res;
}

signed main() {
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	int C=read(), T=read();
	if (C==17 || C==18) {
		while (T--) {
			n=read(), m=read(), k=read(), d=read();
			long long ans=0;
			for (int i=1; i<=m; i++) {
				int x=read(), y=read(), v=read();
				if (y>k || x-y+1<1 || x>n) continue;
				if (v>y*d) ans+=v-y*d;
			}
			printf("%lld\n", ans);
		}
		return 0;
	}
	while (T--) {
		memset(t, 0, sizeof t);
		memset(mx, -10, sizeof mx);
		n=read(), m=read(), k=read(), d=read();
		for (int i=1; i<=m; i++) a[i].x=read(), a[i].y=read(), a[i].v=read();
		sort(a+1, a+m+1, cmp);
		int t=1, ans=0, ans1=0;
		for (int i=1; i<=n; i++) {
			if (i>1) add(1, 1, n, max(1ll, i-k+1), i-1, -d);
			add(1, 1, n, i, i, -mx[0]-d);
			if (ans1-d>0) add(1, 1, n, i, i, ans1);
			while (a[t].x==i) {
				if (i-a[t].y+1>=1 && a[t].y<=k) {
					add(1, 1, n, max(1ll, i-k+1), i-a[t].y+1, a[t].v);
				}
				t++;
			}
			ans1=ans;
			ans=max(ans, ask(1, 1, n, max(1ll, i-k+1), i));
		}
		printf("%lld\n", ans);
	}
	return 0;
}