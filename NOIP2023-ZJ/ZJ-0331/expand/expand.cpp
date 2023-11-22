#include<bits/stdc++.h>
#define ZJL using
#define AK namespace
#define IOI std
#define Name "expand"
#define ll long long
#define INF 0x3f3f3f3f
const ll N = 1e5 + 10;
ZJL AK IOI;

int Y, _;

int C, n, m, q;
int A[N], B[N];
int a[N], b[N], ans[N];

namespace sol1{
	
	int A[N], B[N];
	bool f[2010][2010];
	inline bool sol(){
		if(a[1] == b[1]) return false;
		int nn = n, mm = m;
		if(a[1] > b[1]) swap(nn, mm);
		for(int i = 1;i <= nn;i++) A[i] = a[1] < b[1] ? a[i] : b[i];
		for(int i = 1;i <= mm;i++) B[i] = a[1] < b[1] ? b[i] : a[i];
		A[0] = -INF, B[0] = INF;
		memset(f, 0, sizeof f);
		for(int i = 1;i <= nn;i++){
			for(int j = 1;j <= mm;j++){
				if(A[i] >= B[j]) continue;
				if(i == 1 && j == 1) f[i][j] = 1;
				else f[i][j] = f[i - 1][j] || f[i][j - 1];
			}
		}
		return f[nn][mm];
	}
}

inline void sol(int x){
	ans[x] = sol1::sol();
}

inline ll read(){
	ll x = 0, y = 1;
	char c = getchar();
	while(c < '0' || c > '9'){
		if(c == '-') y = -y;
		c = getchar();
	}
	while(c >= '0' && c <= '9'){
		x = (x << 3) + (x << 1) + c - '0';
		c = getchar();
	}
	return x * y;
}

int main(){
	freopen(Name ".in", "r", stdin);
	freopen(Name ".out", "w", stdout);
	C = read(), n = read(), m = read(), q = read();
	for(int i = 1;i <= n;i++) a[i] = A[i] = read();
	for(int i = 1;i <= m;i++) b[i] = B[i] = read();
	sol(0);
	for(int i = 1;i <= q;i++){
		int n1 = read(), n2 = read();
		vector<int> A1, A2;
		for(int j = 1;j <= n1;j++){
			int x = read(), y = read();
			a[x] = y, A1.push_back(x);
		}
		for(int j = 1;j <= n2;j++){
			int x = read(), y = read();
			b[x] = y, A2.push_back(x);
		}
		sol(i);
		for(auto x : A1) a[x] = A[x];
		for(auto x : A2) B[x] = B[x];
	}
	for(int i = 0;i <= q;i++) putchar(ans[i] + '0');
	puts("");
	return ~~(Y^_^Y);
}
