#include <bits/stdc++.h>
using namespace std;
int c,n,m,q;
int yx[500005];
int yy[500005];
int x[500005];
int y[500005];
int mn = 1000001;
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> c >> n >> m >> q;
	for(int i = 1;i <= n;i++){
		cin >> yx[i];
		x[i] = yx[i];
	}
	for(int i = 1;i <= m;i++){
		cin >> yy[i];
		y[i] = yy[i];
		mn = min(mn,y[i]);
	}
	if(n == 1 && m == 1){
		if(x[1] <= y[1]){
			cout << "0";
		}else{
			cout << "1";
		}
		while(q--){
			int kx,ky;
			cin >> kx >> ky;
			x[1] = yx[1];
			y[1] = yy[1];
			for(int i = 1;i <= kx;i++){
				int p,xs;
				cin >> p >> xs;
				x[p] = xs;
			}
			for(int i = 1;i <= ky;i++){
				int p,ys;
				cin >> p >> ys;
				y[p] = ys;
			}
			if(x[1] <= y[1]){
				cout << "0";
			}else{
				cout << "1";
			}
		}
		return 0;
	}
	if(c == 2){
		if(n == 1){
			if(x[1] > y[1] && x[1] > y[2]){
				cout << "1";
			}else{
				cout << "0";
			}
			while(q--){
				int kx,ky;
				cin >> kx >> ky;
				x[1] = yx[1];
				y[1] = yy[1];
				y[2] = yy[2];
				for(int i = 1;i <= kx;i++){
					int p,xs;
					cin >> p >> xs;
					x[p] = xs;
				}
				for(int i = 1;i <= ky;i++){
					int p,ys;
					cin >> p >> ys;
					y[p] = ys;
				}
				if(x[1] > y[1] && x[1] > y[2]){
					cout << "1";
				}else{
					cout << "0";
				}
			}
		}else{
			if(m == 1){
				if(x[1] > y[1] && x[2] > y[1]){
					cout << "1";
				}else{
					cout << "0";
				}
				while(q--){
					int kx,ky;
					cin >> kx >> ky;
					x[1] = yx[1];
					y[1] = yy[1];
					x[2] = yx[2];
					for(int i = 1;i <= kx;i++){
						int p,xs;
						cin >> p >> xs;
						x[p] = xs;
					}
					for(int i = 1;i <= ky;i++){
						int p,ys;
						cin >> p >> ys;
						y[p] = ys;
					}
					if(x[1] > y[1] && x[2] > y[1]){
						cout << "1";
					}else{
						cout << "0";
					}
				}
			}else{
				if(x[1] > y[1] && x[2] > y[2]){
					cout << "1";
				}else{
					cout << "0";
				}
				while(q--){
					int kx,ky;
					cin >> kx >> ky;
					x[1] = yx[1];
					y[1] = yy[1];
					y[2] = yy[2];
					x[2] = yx[2];
					for(int i = 1;i <= kx;i++){
						int p,xs;
						cin >> p >> xs;
						x[p] = xs;
					}
					for(int i = 1;i <= ky;i++){
						int p,ys;
						cin >> p >> ys;
						y[p] = ys;
					}
					if(x[1] > y[1] && x[2] > y[2]){
						cout << "1";
					}else{
						cout << "0";
					}
				}
			}
		}
		return 0;
	}
	if(x[1] <= y[1]){
		cout << "0";
	}else if(x[n] <= y[m]){
		cout << "0";
	}else{
		bool flag = 1;
		for(int i = 2;i < n;i++){
			if(x[i] <= mn){
				cout << "0";
				flag = 0;
				break;
			}
		}
		if(flag) cout << "1";
	}
	int mnn = mn;
	while(q--){
		int kx,ky;
		cin >> kx >> ky;
		mnn = mn;
		for(int i = 1;i <= m;i++){
			y[i] = yy[i];
		}
		for(int i = 1;i <= n;i++){
			x[i] = yx[i];
		}
		for(int i = 1;i <= kx;i++){
			int p,xs;
			cin >> p >> xs;
			x[p] = xs;
		}
		for(int i = 1;i <= ky;i++){
			int p,ys;
			cin >> p >> ys;
			y[p] = ys;
			mnn = min(mnn,ys);
		}
		if(x[1] <= y[1]){
			cout << "0";
		}else if(x[n] <= y[m]){
			cout << "0";
		}else{
			bool flag = 1;
			for(int i = 2;i < n;i++){
				if(x[i] <= mnn){
					cout << "0";
					flag = 0;
					break;
				}
			}
			if(flag) cout << "1";
		}
	}
	return 0;
}
/*
1 2 2 2
1 3
2 4
2 1
1 4
2 2
2 1
2 0
1 3
2 4
*/
