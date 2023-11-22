#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back 
#define mp make_pair
const int maxn = 5e5 + 10;
int c, n, m, q;
int a[maxn], b[maxn];
vector <pair<int, int> > vx, vy;
int main() {
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	cin >> c >> n >> m >> q;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= m; i++) {
		scanf("%d", &b[i]);
	}
	for (int i = 1; i <= q + 1; i++) {
		int num_x = 0, num_y = 0; 
		if (i != 1)scanf("%d%d", &num_x, &num_y);
		for (int j = 0; j < vx.size(); j++)  {
			a[vx[i].first] = vx[i].second;
		}
		for (int j = 0; j < vy.size(); j++)  {
			b[vy[i].first] = vy[i].second;
		}
		vx.clear(); vy.clear();
		for (int j = 1; j <= num_x; j++) {
			int pos, x; scanf("%d%d", &pos, &x);
			vx.pb(mp(pos, a[pos])); a[pos] = x;
		}
		//cout << a[1] << " " << a[2] << " " << b[1] << " " << b[2] << " debug" << endl;
		for (int j = 1; j <= num_y; j++) {
			int pos, x; scanf("%d%d", &pos, &x);
			vy.pb(mp(pos, b[pos])); b[pos] = x;
		}
		if (c == 1) {
			if (a[1] != b[1]) cout << "1";
			else cout << "0";
			continue;
		}
		if (c == 2) {
			ll flag = 0;
			if (n == 1) a[2] = a[1];
			if (m == 1) b[2] = b[1];
			flag = (ll)(a[1]-b[1]) * (ll)(a[2]-b[2]);
			if (flag > 0) printf("1");
			else printf("0");
			continue;
		}
		ll flag = 0;
		flag = (ll)(a[1]-b[1]) * (ll)(a[n]-b[m]);
		if (flag > 0) printf("1");
		else printf("0");
	}
	return 0;
}
/*
2 2 2 2
1 2
1 2
2 2
1 2
2 4
1 2
2 3
1 1
1 1
2 3
*/