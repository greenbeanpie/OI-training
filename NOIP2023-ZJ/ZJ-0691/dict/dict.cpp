#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int> > w;

bool judge(int a, int b) {
	int pa = 0;
	int pb = 'z' - 'a';
	while (true) {
		while (pa < (int)('z' - 'a') && !w[a][pa]) {
			++pa;
		}
		while (pb > 0 && !w[b][pb]) {
			--pb;
		}
		if (pa < pb) {
			return true;
		} else if (pa > pb) {
			return false;
		} else {
			return w[a][pa] > w[a][pb];
		}
	} 
}

int main() {
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	cin >> n >> m;
	w.resize(n, vector<int>((int)('z' - 'a' + 1)));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			char t = getchar();
			while (t > 'z' || t < 'a') {
				t = getchar();
			}
			int k = t - 'a';
			++w[i][k];
		}
	}
	
	for (int i = 0; i < n; ++i) {
		bool flag;
		flag = 1;
		for (int j = 0; j < n; ++j) {
			if (i == j) {
				continue;
			}
			if (!judge(i, j)) {
				flag = 0;
				break;
			}
		}
		cout << flag;
	}
	//cout << judge(2, 1) << endl;
	/*
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < (int)('z' - 'a' + 1); ++j) {
			cout << w[i][j] << " ";
		}
		cout << endl;
	}
	*/
	return 0;
}
