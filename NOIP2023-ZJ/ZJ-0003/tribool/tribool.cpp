#include <bits/stdc++.h>
#define rep(i, l, r) for(int i=l, _=r; i<=_; ++i)
using namespace std;
typedef long long ll;
#define Assert(b) if(!(b)) {\
	puts("-1");\
	return;\
}
const int mN=1e5+9;
int n, m, a[mN];
int ufa[mN][2], val[mN];
void find(int x) {
	int f=ufa[x][0];
	if(f==x) return;
	find(f);
	ufa[x][1]^=ufa[f][1], ufa[x][0]=ufa[f][0];
}

void solve() {
	scanf("%d%d", &n, &m);
	// Assert(n<114514);
	rep(i, 1, n) {
		a[i]=i, ufa[i][0]=i, ufa[i][1]=0;
	}
	rep(__, 1, m) {
		char opt;
		int x, y;
		scanf("\n%c%d", &opt, &x);
		if(opt=='+' || opt=='-') {
			scanf("%d", &y);	// notice x=y
			a[x]=opt=='+'? a[y]: -a[y];
		} else {
			a[x]=opt=='U'? 0: opt=='T'? n+1: -n-1;
		}
	}
	// rep(i, 1, n) {
	// 	printf("a[%d] = ", i);
	// 	if(a[i]!=-n-1 && a[i] && a[i]!=n+1) {
	// 		printf("%d\n", a[i]);
	// 	} else {
	// 		printf("%c\n", a[i]? a[i]>0? 'T': 'F': 'U');
	// 	}
	// }
	rep(i, 1, n) if(a[i]!=-n-1 && a[i] && a[i]!=n+1) {
		int xx=i, yy=a[i];
		bool z=0;
		if(yy<0) {
			z=1, yy=-yy;
		}
		find(xx), find(yy);
		int fx=ufa[xx][0], fy=ufa[yy][0];	// notice x=fx, y=fy, x=y
		z^=ufa[xx][1]^ufa[yy][1];
		if(fy==fx) {
			if(z==1) {
				// Assert((val[fx]==0 || val[fx]>114514)
				// && (val[fy]==0 || val[fy]>114514));
				val[fx]=0;
			}
		} else {
			// Assert(!(val[fx]<114514 && val[fy]<114514
			// && (z? val[fx]!=-val[fy]: val[fx]!=val[fy])));
			ufa[fy][0]=fx, ufa[fy][1]=z;
			if(val[fx]>114514 && val[fy]<114514) {
				val[fx]=z? -val[fy]: val[fy];
			}
		}
	} else {
		find(i);
		int x=i, y=ufa[i][0];	// notice i=fi
		bool z=ufa[i][1];
		int nv=z? -a[x]: a[x];
		// Assert(val[y]==nv || val[y]>114514);
		val[y]=nv;
	}
	int ans=0;
	rep(i, 1, n) {
		find(i);
		if(val[ufa[i][0]]==0) {
			++ans;
		}
	}
	printf("%d\n", ans);
}

int main() {
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);

	int T_T;
	scanf("%*d%d", &T_T);
	while(T_T--) {
		memset(val, 0x3f, sizeof val);

		solve();
	}
	return 0;
}

/*
8:54 ~ 10:16
每次赋值都新开一个点……感觉有点丑。
好像可以直接赋值。。。
带权并查集。

n+1 T, -n-1 F, 0 U

- 在 T2 多测 memset 大赛上获得了 0 分的好成绩。
- assert
61338
*/