#include <bits/stdc++.h>
#define T 'T'
#define F 'F'
#define U 'U'
using namespace std;
int c,t;
int n,m;
constexpr int MAXN = 1E5+5;
char nt(char ch) {
	if (ch == T) return F;
	if (ch == F) return T;
	if (ch == U) return U;
	return '0';
}
struct Node {
	char c = '0'; // determined value
	char temp = '0';
};
struct Op {
	Op(bool a, int i, char va = U, int j = -1, bool b = false) {
		assign = a;
		v = va;
		nt = b;
		x1 = i;
		x2 = j;
	}
	bool assign;
	bool nt;
	int x1,x2;
	char v;
};
Node a[MAXN];
vector<Op> op;
int mn = 0x3f3f3f3f;

bool check() {
	for(int i=1; i<=n; i++) {
		a[i].temp = a[i].c;
	}
	for(int i=0; i<m; i++) {
		if (op[i].assign) {
			a[op[i].x1].temp = op[i].v;
		} else {
			char ch = a[op[i].x2].temp;
			a[op[i].x1].temp = ch;
			if (op[i].nt) {
				a[op[i].x1].temp = nt(a[op[i].x1].temp);
			}
		}
	}
	int cnt = 0;
	for(int i=1; i<=n; i++) {
		if (a[i].c != a[i].temp) {
			return false;
		}
		if (a[i].c == U)
			cnt++;
	}
	mn = min(mn, cnt);
	return true;
}

void sch(int i, int u) {
	if (mn == 0)
		return;
	if (i == n + 1) {
		check();
		return;
	}
	if (a[i].c == '0') {
		a[i].c = T;
		sch(i+1, u);
		a[i].c = F;
		sch(i+1, u);
		a[i].c = U;
		sch(i+1, u+1);
		a[i].c = '0';
	} else {
		sch(i+1, u+(a[i].c == U ? 1 : 0));
	}
}

int main() {

	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> c >> t;
	while(t--) {
		op.clear();
		cin >> n >> m;


		for(int i=0; i<n; i++) {
			a[i].c = '0';
			a[i].temp = '0';
		}
		mn = 0x3f3f3f3f;


		for(int i=0; i<m; i++) {
			int x1,x2;
			char v;
			cin >> v;
			if (v == T || v == F || v == U) {
				cin >> x1;
				a[x1].c = v;
				op.push_back(Op(true, x1, v));
			} else {
				cin >> x1 >> x2;
				op.push_back(Op(false, x1, U, x2, v == '-'));
				a[x1].c = '0';
			}
		}

		if (c <= 2) {
			sch(1, 0);
		} else if (c <= 4) {
			mn = 0;
			for(int i=0; i<n; i++) {
				if (a[i].c == U)
					mn++;
			}
		}
		cout << mn << endl;
	}
	fclose(stdin);
	fclose(stdout);
}
