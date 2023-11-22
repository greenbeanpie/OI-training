#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 5e5 + 10;
int c, n, m, q;
int a[N], b[N];
int x[N], y[N];
int kx, ky, px, vx, py, vy;
string ans = "";
int dx[N], dy[N], indx = 0;
struct node{
	int l, r;
};
node ux[N], uy[N];
int main(){
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	scanf("%d%d%d%d", &c, &n, &m, &q);
	for(int i = 1; i <= n; i ++) scanf("%d", a + i);
	for(int i = 1; i <= m; i ++) scanf("%d", b + i);
	if(c == 2 or c == 1){
		if((a[1] - b[1]) * (a[n] - b[m]) > 0) ans += "1";
		else ans += "0";
		while(q --){
			for(int i = 1; i <= n; i ++) x[i] = a[i];
			for(int j = 1; j <= m; j ++) y[j] = b[j];
			scanf("%d%d", &kx, &ky);
			while(kx --){
				scanf("%d%d", &px, &vx);
				x[px] = vx;
			}
			while(ky --){
				scanf("%d%d", &py, &vy);
				y[py] = vy;
			}
			if((x[1] - y[1]) * (x[n] - y[m]) > 0) ans += "1";
			else ans += "0";
		}
		cout << ans << endl;
	}

	return 0;
}