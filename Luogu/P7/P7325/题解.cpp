#include <bits/stdc++.h>

const int N = 200000;

int gcd(int x, int y) {return (y == 0) ? x : gcd(y, x % y);}
void exgcd(int a, int b, int &x, int &y) {
	if( a == 1 ) {x = 1, y = 0;}
	else exgcd(b, a % b, y, x), y -= a / b * x;
}
int inv(int a, int m) {
	int x, y; exgcd(a, m, x, y);
	return (x % m + m) % m;
}

struct node{
	int x, y, z;
	friend bool operator < (const node &a, const node &b) {
		return (a.x == b.x) ? ((a.y == b.y) ? (a.z < b.z) : (a.y < b.y)) : (a.x < b.x);
	}
};

int m; std::map<node, int>mp[N + 5];
void init() {
	for(int i=2;i<=m;i++) if( m % i == 0 ) {
		int x = 1, y = 0;
		for(int j=0;;j++) {
			if( x && y ) {
				int d1 = gcd(i, x), d2 = gcd(i, y), m1 = i / d1 / d2;
				int k = (int)(1ll * (y / d2) * inv((x / d1), m1) % m1);
				if( !mp[i].count((node){k, d1, d2}) ) mp[i][(node){k, d1, d2}] = j;
			}
			int x1 = x; x = y, y = (x1 + y) % i;
			if( x == 1 && y == 0 ) break;
		}
	}
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("P7325.in", "r", stdin);
		//freopen("fib.out", "w", stdout);
	#endif
	int n; scanf("%d%d", &n, &m), init();
	
	for(int i=1,a,b;i<=n;i++) {
		scanf("%d%d", &a, &b), b = (m - b) % m;
		
		if( a == 0 ) {puts("0"); continue;}
		if( b == 0 ) {puts("1"); continue;}
		
		int d = gcd(gcd(a, b), m), m1 = m / d; a /= d, b /= d;
		int p = gcd(a, m1), q = gcd(b, m1), m2 = m1 / p / q; a /= p, b /= q;
		
		int k = (int)(1ll * a * inv(b, m2) % m2);
		
		if( mp[m1].count((node){k, q, p}) ) printf("%d\n", mp[m1][(node){k, q, p}]);
		else printf("-1\n");
	}
}
