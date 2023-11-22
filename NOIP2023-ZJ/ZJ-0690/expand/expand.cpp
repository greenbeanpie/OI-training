#include <bits/stdc++.h>
using namespace std;
#define elif else if

int c, n, m, q, kx, ky, sx, sy, x[500005], y[500005], xx[500005], yy[500005];

//void work1(){
//	if(xx[1] == yy[1])
//		cout << 0;
//	if(xx[1] > yy[1])
//		for(int h1 = 1, h2 = 1; h1 <= n && h2 <= m; ){
//			if(xx[h1] > yy[h2]){
//				h2++;
//			}
//		}
//}
//
//void work2(){
//	if(xx[n])
//}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	cin >> c >> n >> m >> q;
	for(int i = 1; i <= n; i++)
		cin >> x[i];
	for(int i = 1; i <= m; i++)
		cin >> y[i];
	for(int i = 1; i <= n; i++)
		xx[i] = x[i];
	for(int i = 1; i <= m; i++)
		yy[i] = y[i];
		
	if(xx[1] == yy[1])
		cout << 0;
	else{
		int h = 1, f = 1;
		if(xx[1] > yy[1])
			for(int i = 1; i <= m; i++){
				if(xx[h] > yy[i]){
					if(h == n)
						continue;
					while(xx[h + 1] > yy[i])
						h++;
				}
				else{
					for(; xx[h] <= yy[i], h > 0; h--);
					if(h == 0){
						f = 0;
						break;
					}
				}
				if(i == m){
					for(; h < n, xx[h] > yy[i]; h++);
					if(h < n || xx[n] < yy[m]){
						f = 0;
						break;
					}
				}
				if(h == n)
					continue;
			}
		else
			for(int i = 1; i <= m; i++){
				if(xx[h] < yy[i]){
					if(h == n)
						continue;
					while(xx[h + 1] < yy[i])
						h++;
				}
				else{
					for(; xx[h] >= yy[i], h > 0; h--);
					if(h == 0){
						f = 0;
						break;
					}
				}
				if(i == m){
					for(; h < n, xx[h] < yy[i]; h++);
					if(h < n || xx[n] > yy[m]){
						f = 0;
						break;
					}
				}
				if(h == n)
					continue;
			}
		cout << f;
	}

//	if(c >= 8 && c <= 14)
//		work2();
	while(q--){
		cin >> kx >> ky;
		for(int i = 1; i <= n; i++)
			xx[i] = x[i];
		for(int i = 1; i <= m; i++)
			yy[i] = y[i];
		while(kx--){
			cin >> sx >> sy;
			xx[sx] = sy;
		}
		while(ky--){
			cin >> sx >> sy;
			yy[sx] = sy;
		}
		if(xx[1] == yy[1]){
			cout << 0;
			continue;
		}
		int h = 1, f = 1;
		if(xx[1] > yy[1])
			for(int i = 1; i <= m; i++){
				if(xx[h] > yy[i]){
					if(h == n)
						continue;
					while(xx[h + 1] > yy[i])
						h++;
				}
				else{
					for(; xx[h] <= yy[i], h > 0; h--);
					if(h == 0){
						f = 0;
						break;
					}
				}
				if(i == m){
					for(; h < n, xx[h] > yy[i]; h++);
					if(h < m || xx[n] < yy[m]){
						f = 0;
						break;
					}
				}
				if(h == n)
					continue;
			}
		else
			for(int i = 1; i <= m; i++){
				if(xx[h] < yy[i]){
					if(h == n)
						continue;
					while(xx[h + 1] < yy[i])
						h++;
				}
				else{
					for(; xx[h] >= yy[i], h > 0; h--);
					if(h == 0){
						f = 0;
						break;
					}
				}
				if(i == m){
					for(; h < n, xx[h] < yy[i]; h++);
					if(h < m || xx[n] > yy[m]){
						f = 0;
						break;
					}
				}
				if(h == n)
					continue;
			}
		cout << f;
	}
	return 0;
}
