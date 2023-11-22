#include <bits/stdc++.h>
using namespace std;

int c, n, m, q;
vector<int> A, B;
vector<int> e, l;

bool judge() {
	if ((A[0] - B[0]) * (A[n - 1] - B[m - 1]) <= 0) {
		return false;
	}
	if (A[0] > B[0]) {
		int pre = 0;
		for (int i = 0; i < n; ++i) {
			int k = -1;
			for (int p = pre; p < m; ++p) {
				if (A[i] > B[p]) {
					k = p;
					break;
				}
			}
			if (k == -1) {
				return false;
			}
			e[i] = k;
			pre = k;
		}
		
		pre = m - 1;
		for (int i = n - 1; i > 0; --i) {
			int k = -1;
			for (int p = pre; p >= e[i - 1]; --p) {
				if (A[i] > B[p]) {
					k = p;
					break;
				}
			}
			if (k == -1) {
				return false;
			}
			l[i] = k;
			pre = k;
		}
		int k = -1;
		for (int p = pre; p >= 0; --p) {
			if (A[0] > B[p]) {
				k = p;
				break;
			}
		}
		if (k == -1) {
			return false;
		}
		l[0] = k;
		
	} else {
		int pre = 0;
		for (int i = 0; i < n; ++i) {
			int k = -1;
			for (int p = pre; p < m; ++p) {
				if (A[i] < B[p]) {
					k = p;
					break;
				}
			}
			if (k == -1) {
				return false;
			}
			e[i] = k;
			pre = k;
		}
		
		pre = m - 1;
		for (int i = n - 1; i > 0; --i) {
			int k = -1;
			for (int p = pre; p >= e[i - 1]; --p) {
				if (A[i] < B[p]) {
					k = p;
					break;
				}
			}
			if (k == -1) {
				return false;
			}
			l[i] = k;
			pre = k;
		}
		int k = -1;
		for (int p = pre; p >= e[0]; --p) {
			if (A[0] < B[p]) {
				k = p;
				break;
			}
		}
		if (k == -1) {
			return false;
		}
		l[0] = k;
	}
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i < e[i] || i > l[j]) {
				return false;
			}
		}	
	}
	return true;
}

int main() {
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	cin >> c >> n >> m >> q;
	A.resize(n);
	e.resize(n);
	l.resize(n);
	B.resize(m);
	for (int i = 0; i < n; ++i) {
		cin >> A[i];
	}
	for (int i = 0; i < m; ++i) {
		cin >> B[i];
	}
	cout << judge();
	vector<int> AC, BC;
	AC = A;
	BC = B;
	for (int i = 0; i < q; ++i) {
		A = AC;
		B = BC;
		int kx, ky;
		cin >> kx >> ky;
		for (int j = 0; j < kx; ++j) {
			int px, vx;
			cin >> px >> vx;
			A[px - 1] = vx;
		}
		for (int j = 0; j < ky; ++j) {
			int py, vy;
			cin >> py >> vy;
			B[py - 1] = vy;
		}
		cout << judge();
	}
	/*
	for (int i = 0; i < n; ++i) {
		cout << e[i] << " " << l[i] << endl;
	}
	*/
	return 0;
}
