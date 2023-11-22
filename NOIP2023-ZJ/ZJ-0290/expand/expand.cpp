#include <iostream>
using namespace std;

const int MAXN = 5e5 + 10;

int c, n, m, q;
int a[MAXN], b[MAXN];

int main()
{
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	cin >> c >> n >> m >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= m; i++) cin >> b[i];
	cout << (a[1] != b[1]);
	int kx, ky, p, v;
	while (q--)
	{
		cin >> kx >> ky;
		for (int i = 1; i <= kx; i++)
		{
			cin >> p >> v;
			a[p] = v;
		}
		for (int i = 1; i <= ky; i++)
		{
			cin >> p >> v;
			b[p] = v;
		}
		cout << (a[1] != b[1]);
	}
	cout << endl;
}
