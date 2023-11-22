#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	int sum = 0, f = 1;
	char ch = getchar();
	for(; !isdigit(ch); ch = getchar()) if(ch == '-') f = -f;
	for(; isdigit(ch); ch = getchar()) sum = (sum << 3) + (sum << 1) + (ch ^ 48);
	return sum * f;
}
void write(int x){
	if(x < 0) putchar('-'), x = -x;
	if(x > 9) write(x / 10);
	putchar('0' + x % 10);
	return;
}
const int N = 3001;
int n, m;
char s[N][N];
string Mi[N], Mx[N], g[N];
void solve(int id){
	string str;
	str = "";
	for(int i = 1; i <= m; ++ i) str += s[id][i];
	sort(str.begin(), str.end(), less<char>());
	Mi[id] = str;
	str = "";
	for(int i = 1; i <= m; ++ i) str += s[id][i];
	sort(str.begin(), str.end(), greater<char>());
	Mx[id] = str;
	return;
}
void build(string str, int l, int r){
	if(l == r){
		g[l] = str;
		return;
	}
	string L = str, R = str;
	int mid = l + r >> 1;
	for(int i = l; i <= mid; ++ i) R = min(R, Mx[i]);
	for(int i = mid + 1; i <= r; ++ i) L = min(L, Mx[i]);
	build(L, l, mid);
	build(R, mid + 1, r);
	return;
}
signed main(){
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	n = read(), m = read();
	for(int i = 1; i <= n; ++ i)
		scanf("%s", s[i] + 1);
	for(int i = 1; i <= n; ++ i)
		solve(i);
	string str = "";
	for(int i = 1; i <= m; ++ i) str += 'z';
	build(str, 1, n);
	for(int i = 1; i <= n; ++ i)
		putchar(g[i] > Mi[i] ? '1' : '0');
	return 0;
}