#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 500010

int n, m, x[N], y[N], _x[N], _y[N];

void close_flow(){
	ios :: sync_with_stdio (false);
	cin.tie(0);
	cout.tie(0);
	return;
}

void solve1(){
	if(x[1] == y[1])
		cout << 0;
	else
		cout << 1;
	return;
}

void solve2(){
	if(n == 1 && m == 1){
		solve1();
	}
	if(n == 1 && m == 2){
		if((x[1] > y[1] && x[1] > y[2])||(x[1] < y[1] && x[1] < y[2]))
			cout << 1;
		else
			cout << 0;
	}
	if(n == 2 && m == 1){
		if((x[1] > y[1] && x[2] > y[1])||(x[1] < y[1] && x[2] < y[1]))
			cout << 1;
		else
			cout << 0;
	}
	if(n == 2 && m == 2){
		if((x[1] > y[1] && x[2] > y[2])||(x[1] < y[1] && x[2] < y[2]))
			cout << 1;
		else
			cout << 0;
	}
	return;
}

signed main(){
	freopen("expend.in", "r", stdin);
	freopen("expend.out", "w", stdout);
	close_flow();
	int c, q;
	cin >> c >> n >> m  >> q;
	if(c == 1){//5 point!!!
		cin >> x[1] >> y[1];
		_x[1] = x[1];
		_y[1] = y[1];
		solve1();
		while(q--){
			int kx, ky;
			cin >> kx >> ky;
			while(kx--){
				int p, v;
				cin >> p >> v;
				x[p] = v;
			}
			while(ky--){
				int p, v;
				cin >> p >> v;
				y[p] = v;
			}
			solve1();
			x[1] = _x[1];
			y[1] = _x[1];
		}
		return 0;
	}
	if(c == 2){//5 point!!!
		for(int i = 1; i <= n; ++i){
			cin >> x[i];
			_x[i] = x[i];
		}
		for(int i = 1; i <= m; ++i){
			cin >> y[i];
			_y[i] = y[i];
		}
		solve2();
		while(q--){
			int kx, ky;
			cin >> kx >> ky;
			while(kx--){
				int p, v;
				cin >> p >> v;
				x[p] = v;
			}
			while(ky--){
				int p, v;
				cin >> p >> v;
				y[p] = v;
			}
			solve2();
			for(int i = 1; i <= n; ++i){
				x[i] = _x[i];
			}
			for(int i = 1; i <= m; ++i){
				y[i] = _y[i];
			}
		}
		return 0;
	}
	return 0;
}