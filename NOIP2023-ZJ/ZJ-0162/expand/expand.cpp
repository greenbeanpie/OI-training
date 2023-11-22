#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
bool f1;
int _TCase, n, m, Q, a[N], b[N], aa[N << 2], tot, x[N], y[N], now, f_max[N][21], lg[N], f_min[N][21], l, r, mid, res, nn, mm;
bool ans;
struct opt{
	int pos, k;
}tem;
struct Que{
	int kx, ky;
	vector<opt>X, Y;
}q[65];
bool f2;
inline void read(int &res){
	res = 0;
	int f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9'){
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while('0' <= ch && ch <= '9'){
		res = (res << 1) + (res << 3) + (ch - 48);
		ch = getchar();
	}
	res *= f;
}
inline void Uniq(){
	sort(aa + 1, aa + tot + 1);
	tot = unique(aa + 1, aa + tot + 1) - aa - 1;
	for(int i = 1; i <= n; i++) a[i] = lower_bound(aa + 1, aa + tot + 1, a[i]) - aa;
	for(int i = 1; i <= m; i++) b[i] = lower_bound(aa + 1, aa + tot + 1, b[i]) - aa;
	for(int i = 1; i <= Q; i++){
		for(int j = 0; j < q[i].kx; j++) q[i].X[j].k = lower_bound(aa + 1, aa + tot + 1, q[i].X[j].k) - aa;
		for(int j = 0; j < q[i].ky; j++) q[i].Y[j].k = lower_bound(aa + 1, aa + tot + 1, q[i].Y[j].k) - aa;
	}
}
inline void upd(int id){
	for(int i = 1; i <= n; i++) x[i] = a[i];
	for(int i = 1; i <= m; i++) y[i] = b[i];
	for(auto i : q[id].X){
		x[i.pos] = i.k;
	}
	for(auto i : q[id].Y){
		y[i.pos] = i.k;
	}
	if(x[1] < y[1]){
		for(int i = 1; i <= max(n, m); i++) swap(x[i], y[i]);
		swap(n, m);
	}
}
inline void rmq(){
	for(int i = 2; i <= m; i++) lg[i] = lg[i >> 1] + 1;
	for(int i = 1; i <= m; i++) f_max[i][0] = f_min[i][0] = y[i];
	for(int j = 1; j <= lg[m]; j++){
		for(int i = 1; i + (1 << j) <= m + 1; i++){
			f_max[i][j] = max(f_max[i][j - 1], f_max[i + (1 << j - 1)][j - 1]);
			f_min[i][j] = min(f_min[i][j - 1], f_min[i + (1 << j - 1)][j - 1]);
		}
	}
}
inline int get_max(int x, int y){
	int K = lg[y - x + 1];
	return max(f_max[x][K], f_max[y - (1 << K) + 1][K]);
}
inline int get_min(int x, int y){
	int K = lg[y - x + 1];
	return min(f_min[x][K], f_min[y - (1 << K) + 1][K]);
}
inline void debug(){
	for(int i = 1; i <= n; i++) printf("%d ", aa[x[i]]);
	putchar('\n');
	for(int i = 1; i <= m; i++) printf("%d ", aa[y[i]]);
	putchar('\n');
}
inline void debug2(){
	for(int i = 1; i <= n; i++) printf("%d ", x[i]);
	putchar('\n');
	for(int i = 1; i <= m; i++) printf("%d ", y[i]);
	putchar('\n');
}
int main(){
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
//	printf("%.2lfMB\n", (&f2 - &f1) / 1024.0 / 1024.0);
	read(_TCase), read(n), read(m), read(Q);
	nn = n, mm = m;
	for(int i = 1; i <= n; i++) read(a[i]), aa[++tot] = a[i];
	for(int i = 1; i <= m; i++) read(b[i]), aa[++tot] = b[i];
	for(int i = 1; i <= Q; i++){
		read(q[i].kx), read(q[i].ky);
		for(int j = 1; j <= q[i].kx; j++){
			read(tem.pos), read(tem.k);
			q[i].X.push_back(tem);
			aa[++tot] = tem.k;
		}
		for(int j = 1; j <= q[i].ky; j++){
			read(tem.pos), read(tem.k);
			q[i].Y.push_back(tem);
			aa[++tot] = tem.k;
		}
	}
	Uniq();
	for(int qq = 0; qq <= Q; qq++){
		n = nn, m = mm;
		upd(qq);
//		debug2();
		if(x[1] == y[1] || x[n] <= y[m]){
			putchar('0');
			continue ;
		}
		now = 0;
		ans = 1;
		for(int i = 1; i <= n && ans; i++){
			res = 0;
			for(int j = min(now + 1, m); j >= 1 && !res; j--){
				if(x[i] > y[j]) res = j;
			}
			if(res == 0) ans = 0;
			if(res == now + 1){
				res = 1;
				for(int j = now + 1; j <= m && res; j++){
					if(x[i] > y[j]) now = j;
					else res = 0;
				}
			}
			else now = res;
		}
		if(now < m || !ans) putchar('0');
		else putchar('1');
	}
	return 0;
}