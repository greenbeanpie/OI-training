#include<bits/stdc++.h>
using namespace std;
int n, m, c, q;
const int N = 2e3 + 10;
int x[N], y[N];
struct n{
	int mi, ma;
}a[2];
int main(){
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	cin.tie(0);
	cout.tie(0);
	a[1].mi = a[2].mi = 0x3f3f3f3f;
	cin >> n >> m >> c >> q;
	for (int i = 1; i <= n; i++){
		cin >> x[i];
		a[1].mi = min(x[i], a[1].mi);
		a[1].ma = max(x[i], a[1].ma);
	}
	for (int i = 1; i <= m; i++){
		cin >> y[i];
		a[2].mi = min(y[i], a[2].mi);
		a[2].ma = max(y[i], a[2].ma);				
	}
	if(x[1] == y[1])
		cout << "0";
	else{
		if(x[1] < y[1]){
			if(a[1].mi <a[2].mi && a[2].ma > a[1].ma && x[n] < y[m])
				cout << "1";
			else
				cout << "0";
		}
		else{
			if(a[1].mi >a[2].mi && a[2].ma < a[1].ma && x[n] > y[m])
				cout << "1";
			else
				cout << "0";
		}
	}
	for (int i = 1; i <= q; i++){
		int kx, ky;
		cin >> kx >> ky;
//		cout << "gsg" << endl;
		for (int j = 1; j <= kx; j++){
			int px, vx;
			cin >> px >> vx;
			x[px] = vx;
		}
//		cout <<"gsg" << endl;
		for (int j = 1; j <= ky; j++){
			int py, vy;
			cin >> py >> vy;
			y[py] = vy;
		}
		for (int j = 1; j <= n; j++){
			a[1].mi = min(x[j], a[1].mi);
			a[1].ma = max(x[j], a[1].ma);
		}
		for (int j = 1; j <= m; j++){
			a[2].mi = min(y[j], a[2].mi);
			a[2].ma = max(y[j], a[2].ma);				
		}
//			cout << a[1].ma << a[1].mi << a[2].ma << a[2].mi;
		if(x[1] == y[1])
			cout << "0";
		else{
			if(x[1] < y[1]){
				if(a[1].mi <a[2].mi && a[2].ma > a[1].ma && x[n] < y[m])
					cout << "1";
				else
					cout << "0";
			}
			else{
				if(a[1].mi >a[2].mi && a[2].ma < a[1].ma && x[n] > y[m])
					cout << "1";
				else
					cout << "0";
			}
		}
	}
	cout << endl;
	return 0;
}