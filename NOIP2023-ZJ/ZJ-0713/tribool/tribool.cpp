#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int C, t, n, m, x[N], y[N],f[2 * N];

char sol1[2 * N];
//注意 初始化！！！!

int find(int x){
	if(f[x] == x) return x;
	return f[x] = find(f[x]);
}

void solve1(){
	while(t--){
		cin >> n >> m;
		for(int i = 1; i <= m; i++){
			char c; int id;
			cin >> c >> id;
			sol1[id] = c;
		}
		int ans = 0;
		for(int i = 1; i <= n; i++){
			if(sol1[i] == 'U') ans++;
		}
		cout << ans << endl;
	}
}

void solve2(){
	while(t--){
		cin >> n >> m;
		for(int i = 1; i <= 2 * n; i++) // 1~n, n + 1 ~ 2n扩展
		f[i] = i, sol1[i] = '0';
		while(m--){
			char c; int a, b;
			cin >> c;
			if(c == 'U'){
				cin >> a;
				sol1[a] = c;
			}
			else{
				if(c == 'T' || c == 'F') cin >> a;
			 	else{
			 		cin >> a >> b;
					int x = find(a), y = find(b), xx = find(a + n), yy = find(b + n);
	//				cout <<x << " "<< y << " " << xx << " " << yy << endl;
			 		if(c == '+'){
			 			if(abs(x - y) == n || abs(xx - yy) == n){
			 				sol1[x] = sol1[xx] = sol1[y] = sol1[yy] =  'U';
			 				continue;
						}
			 			f[x] = y;
			 			f[xx] = yy;
					 }
					 else{
					 	
					 	if(abs(x - yy) == n || abs(xx - y) == n){
			 				sol1[x] = sol1[xx] = sol1[y] = sol1[yy] =  'U';
			 				continue;
						}
					 	f[x] = yy;
					 	f[xx] = y;
					 }
				 }
			}
			
		}
		int ans = 0;
		for(int i = 1; i <= n; i++){
//			cout << f[i] << endl;
			if(sol1[find(i)] == 'U') ans++;
		}
		cout << ans << endl;
	}
}

signed main(){
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	cin >> C >> t;
	if(C == 3 || C == 4) solve1();
	else solve2(); 
	return 0;
}
