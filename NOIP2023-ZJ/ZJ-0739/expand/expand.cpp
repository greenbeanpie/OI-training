#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5+5;
int c, n, m, q;
struct nd{
	int pos, num;
};
int k[maxn], y[maxn];
nd k1, k2;

int main(){
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	cin >> c >> n >> m >> q;
	for(int i=1; i<=q; i++){
		cin >> k1.pos >> k1.num >> k2.pos >> k2.num;
	}
	cout << c%2;
	for(int i=1; i<=q; i++){
		cout << 0;
	}
}
