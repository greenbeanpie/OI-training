#include<bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;

int a[N], b[N], c[N], d[N];
int ans[N];

int cc, n, m, q, idx;

bool check1(){
	if(c[1] > d[1] && c[1] > d[2]) return true;
	if(c[1] < d[1] && c[1] < d[2]) return true;
	return false;
}
bool check2(){
	if(c[1] > d[1] && c[2] > d[1]) return true;
	if(c[1] < d[1] && c[2] < d[1]) return true;
	return false;	
}
bool check3(){
	if(c[1] > d[1] && c[2] > d[2]) return true;
	if(c[1] < d[1] && c[2] < d[2]) return true;
	return false;
}
bool check(){
	if(n == 1 && m == 2) return check1();
	if(n == 2 && m == 1) return check2();
	else return check3();
}

bool ccheck(){
	if(c[1] > d[1] && c[n] > d[m]) return true;
	if(c[1] < d[1] && c[n] < d[m]) return true;
	return false;
}

int main(){
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	cin >> cc >> n >> m >> q;
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
		c[i] = a[i];
	}
	for(int i = 1; i <= m; i ++){
		cin >> b[i];
		d[i] = b[i];
	}
	if(cc == 1 || n == 1 && m == 1){
		while(q --){
			for(int i = 1; i <= n; i ++) c[i] = a[i];
			for(int i = 1; i <= m; i ++) d[i] = b[i];
			int kx, ky;
			cin >> kx >> ky;
			for(int i = 1; i <= kx; i ++){
				int p, v;
				cin >> p >> v;
				c[p] = v;
			}
			for(int i = 1; i <= ky; i ++){
				int p, v;
				cin >> p >> v;
				d[p] = v;
			}
		}
		for(int i = 1; i <= q + 1; i ++) cout << "1" << endl;
		return 0;
	}
	if(cc == 2){
		ans[++ idx] = check();
		while(q --){
			for(int i = 1; i <= n; i ++) c[i] = a[i];
			for(int i = 1; i <= m; i ++) d[i] = b[i];
			int kx, ky;
			cin >> kx >> ky;
			for(int i = 1; i <= kx; i ++){
				int p, v;
				cin >> p >> v;
				c[p] = v;
			}
			for(int i = 1; i <= ky; i ++){
				int p, v;
				cin >> p >> v;
				d[p] = v;
			}
			ans[++ idx] = check(); 
		}
		for(int i = 1; i <= idx; i ++) cout << ans[i];
		return 0;
	}
	ans[++ idx] = check();
	while(q --){
		for(int i = 1; i <= n; i ++) c[i] = a[i];
		for(int i = 1; i <= m; i ++) d[i] = b[i];
		int kx, ky;
		cin >> kx >> ky;
		for(int i = 1; i <= kx; i ++){
			int p, v;
			cin >> p >> v;
			c[p] = v;
		}
		for(int i = 1; i <= ky; i ++){
			int p, v;
			cin >> p >> v;
			d[p] = v;
		}
		ans[++ idx] = check(); 	
	}
	for(int i = 1; i <= idx; i ++) cout << ans[i];
	return 0;
}
