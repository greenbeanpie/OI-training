#include<bits/stdc++.h>
using namespace std;
const int maxn = 500100;
int c, n, m, q, arrx[maxn], arry[maxn];
int PX[maxn], VX[maxn];
int PY[maxn], VY[maxn];
struct TASK1{
	void work() {
		if(n==1 && m==1) {
			if(arrx[n] != arry[m]) cout << "1";
			else cout << "0";
			while(q--) {
				int tempx=arrx[n], tempy = arry[m];
				int kx, ky; cin >> kx >> ky;
				for(int i=1; i<=kx; ++i) {
					int a, q; cin >> a >> q;
					tempx = q;
				}
				for(int i=1; i<=ky; ++i) {
					int a, q; cin >> a >> q;
					tempy = q;
				}
				if(tempx != tempy) {
					cout << 1;
				} else {
					cout << 0;
				}
			}
			return;
		} else if(n <= 2 && m <= 2){
			if(n==1 && m==2) {
				if((arrx[n] - arry[1]) * (arrx[n] - arry[2]) > 0) {
					cout << 1;
				} else {
					cout << 0;
				}
				while(q--) {
					int tempx=arrx[n], tempy[3] = {0, arry[1], arry[m]};
					int kx, ky; cin >> kx >> ky;
					for(int i=1; i<=kx; ++i) {
						int p, q; cin >> p >> q;
						tempx = q;
					}
					for(int i=1; i<=ky; ++i) {
						int p, q; cin >> p >> q;
						tempy[p] = q;
					}
					if((tempx - tempy[1]) * (tempx - tempy[2]) > 0) {
						cout << 1;
					} else {
						cout << 0;
					}
				}
				return;
			}
			if(n==2 && m==1) {
				if((arrx[1] - arry[1]) * (arrx[2] - arry[1]) > 0) {
					cout << 1;
				} else {
					cout << 0;
				}
				while(q--) {
					int tempx[3]={0, arrx[1], arrx[2]}, tempy = arry[1];
					int kx, ky; cin >> kx >> ky;
					for(int i=1; i<=kx; ++i) {
						int p, q; cin >> p >> q;
						tempx[p] = q;
					}
					for(int i=1; i<=ky; ++i) {
						int p, q; cin >> p >> q;
						tempy = q;
					}
					if((tempx[1] - tempy) * (tempx[2] - tempy) > 0) {
						cout << 1;
					} else {
						cout << 0;
					}
				}
				return;
			}
			if(n==2 && m==2) {
				if((arrx[1] - arry[1]) * (arrx[2] - arry[2]) > 0) {
					cout << 1;
				} else {
					cout << 0;
				}
				while(q--) {
					int tempx[3] = {0, arrx[1], arrx[2]}, tempy[3] = {0, arry[1], arry[2]};
					int kx, ky; cin >> kx >> ky;
					for(int i=1; i<=kx; ++i) {
						int p, q; cin >> p >> q;
						tempx[p] = q;
					}
					for(int i=1; i<=ky; ++i) {
						int p, q; cin >> p >> q;
						tempy[p] = q;
					}
					if((tempx[1] - tempy[1]) * (tempx[2] - tempy[2]) > 0) {
						cout << 1;
					} else {
						cout << 0;
					}
				}
			}
		}
	}
}task1;
struct TASK2{
	int tree[maxn<<2];
	void build(int index, int l, int r) {
		if(l == r) {
			tree[index] = arry[l];
			return;
		}
		int mid = l + r >> 1;
		build(index*2, l, mid);
		build(index*2+1, mid+1, r);
		tree[index] = min(tree[index*2], tree[index*2+1]);
	}
	void modify(int index, int l, int r, int loc, int x) {
		if(l > loc || r < loc) return;
		if(l == r) {
			tree[index] = x;
			return;
		}
		int mid = l + r >> 1;
		modify(index*2, l, mid, loc, x);
		modify(index*2+1, mid+1, r, loc, x);
		tree[index] = min(tree[index*2], tree[index*2+1]);
	}
	void work() {
		build(1, 1, m);
		int minx = arrx[n];
		if(minx < tree[1]) cout << 1;
		else cout << 0;
		while(q--) {
			int tempminx = minx;
			int kx, ky; cin >> kx >> ky;
			for(int i=1; i<=kx; ++i) {
				int p, v; cin >> p >> v;
				if(p == n) tempminx = v;
			}
			for(int i=1; i<=ky; ++i) {
				cin >> PY[i] >> VY[i];
				modify(1,1,m, PY[i], VY[i]);
			}
			if(tempminx < tree[1]) {
				cout << 1;
			} else {
				cout << 0;
			}
			for(int i=1; i<=ky; ++i) {
				modify(1,1,m, PY[i], arry[PY[i]]);
			}
		}
	}
}task2;
struct TASK3{
	void work() {
		
	}
}task3;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	cin >> c >> n >> m >> q;
	for(int i=1; i<=n; ++i) {
		cin >> arrx[i];
	}
	for(int j=1; j<=m; ++j) {
		cin >> arry[j];
	}
	if(c>=8 && c<=14) {
		task2.work();
	} else if(c<8) {
		task1.work();
	} else {
		task3.work();
	}
	return 0;
}
/*
3 2 2 1
2 6
2 4
1 0
1 3
*/