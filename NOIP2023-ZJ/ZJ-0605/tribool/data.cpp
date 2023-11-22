#include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("tribool.in", "w", stdout);
	srand(time(0));
	srand((rand() * rand() ^ rand() * rand()));
	cout << 1 << ' ' << 1 << endl;
	int n = rand() % 10 + 1, m = rand() % 50 + 1;
	cout << n << ' ' << m << endl;
	for (int i = 1; i <= m; ++i) {
		int op = rand() % 5;
		if (n == 1) op = rand() % 3;
		if (op == 0) {
			int px = rand() % n + 1;
			cout << 'T' << ' ' << px << endl;
		}
		else if (op == 1) {
			int px = rand() % n + 1;
			cout << 'F' << ' ' << px << endl;
		}
		else if (op == 2) {
			int px = rand() % n + 1;
			cout << 'U' << ' ' << px << endl;
		}
		else if (op == 3) {
			int px = rand() % n + 1;
			int py = rand() % n + 1;
			for (; py == px; py = rand() % n + 1);
			cout << '+' << ' ' << px << ' ' << py << endl;
		}
		else if (op == 4) {
			int px = rand() % n + 1;
			int py = rand() % n + 1;
			for (; py == px; py = rand() % n + 1);
			cout << '-' << ' ' << px << ' ' << py << endl;
		}
	}
	fclose(stdout);
	return 0;
}