#include<bits/stdc++.h>
#define int long long
#define _ (int)(5e5 + 4)
using namespace std;

int c,n,m,q;
int ia,ib,ir = 1;
int a[_],b[_],na[_],nb[_],res[_];
bool in[_];

inline void init() {
	memset(in,0,sizeof(in));
}
inline void solve1() {
	int i,j; 
	i = 1, j = 1;
	init();
	while(i <= n && j <= m) {
		if(a[i] > b[j]) in[i] = 1, j ++;
		else i ++;
	}
	for(int i = 1; i <= n; i ++) {
		if(!in[i] && j < m) {
			res[ir] = 0;
			return;
		}
	}
	res[ir] = 1;
	return;
}
inline void solve2() {
	int i,j; 
	i = 1, j = 1;
	init();
	while(i <= n && j <= m) {
		if(a[i] < b[j]) in[j] = 1, i ++;
		else j ++;
	}
	for(int i = 1; i <= m; i ++) {
		if(!in[i] && i < n) {
			res[ir] = 0;
			return;
		}
	}
	res[ir] = 1;
	return;
}
inline void start() {
	if((a[1] - b[1])*(a[n] - b[m]) <= 0) {
		res[ir] = 0;
		return;
	}
	if(a[1] > b[1]) solve1();
	else solve2();
}
signed main() {
	
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	
	scanf("%lld %lld %lld %lld",&c,&n,&m,&q);
	for(int i = 1; i <= n; i ++) scanf("%lld",&a[i]);
	for(int i = 1; i <= m; i ++) scanf("%lld",&b[i]);
	
	start();
	ir = 2;
	for(int i = 1; i <= q; i ++, ir ++) {
		int kx,ky; scanf("%lld %lld",&kx,&ky);
		
		for(int j = 1; j <= n; j ++) na[j] = a[j];
		for(int j = 1; j <= m; j ++) nb[j] = b[j];
		for(int j = 1; j <= kx; j ++) {
			int p,v; scanf("%lld %lld",&p,&v); a[p] = v;
		}
		for(int j = 1; j <= ky; j ++) {
			int p,v; scanf("%lld %lld",&p,&v); b[p] = v;
		}
		
		start();
		
		for(int j = 1; j <= n; j ++) a[j] = na[j];
		for(int j = 1; j <= m; j ++) b[j] = nb[j];
	}
	for(int i = 1; i <= q + 1; i ++) printf("%lld",res[i]);
	
	return 0;
}

/*
3 3 3 3
8 6 9
1 7 4
1 0
3 0
0 2
1 8
3 5
1 1
2 8
1 7
*/
