#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define mpr make_pair
const int SIZE = 200005;
const int mod = 998244353;
int ID, T;
int n, m;
int cnt;
char ans[SIZE]; 

inline int rd(){
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9'){
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		x = (x<<1)+(x<<3)+(ch^48);
		ch = getchar();
	}
	return x*f;
}

struct A{
	char cc;
	int x, y;
}a[SIZE];

namespace solve3{
	int fa[SIZE*2], siz[SIZE*2]; bool tag[SIZE*2];//2n+1 F 2n+2 T
	bool v[SIZE], vis[SIZE];
	int get(int x){
		if(fa[x] == x) return x;
		return fa[x] = get(fa[x]);
	}
	void merge(int x, int y){
		int xx = get(x), yy = get(y);
		if(xx == yy) return;
		fa[xx] = yy, siz[yy] += siz[xx];
		tag[yy] |= tag[xx];
	}
	void Main(){
		n = rd(), m = rd(); cnt = 0;
		for(int i = 1; i <= m; i++){
			cin >> a[i].cc; a[i].x = rd();
			if(a[i].cc == '+' || a[i].cc == '-') a[i].y = rd();
		}
		for(int i = 1; i <= n*2+2; i++){
			fa[i] = i; siz[i] = 0; v[i] = 0; tag[i] = 0;
			if(i <= n) ans[i] = '&', siz[i] = 1, vis[i] = 0;
		} 
		for(int i = m; i >= 1; i--){
			int x = a[i].x, y = a[i].y;
			if(vis[x]) continue;
			vis[x] = 1;
			if(a[i].cc != '+' && a[i].cc != '-'){
				int xx = get(x); if(tag[xx]) continue;
				if(a[i].cc == 'U'){
					tag[xx] = 1; tag[get(x+n)] = 1;
				}
				else if(a[i].cc == 'F'){
					if(xx <= 2*n) merge(x, 2*n+1), merge(x+n, 2*n+2);
					else{
						if(xx == 2*n+2){
							tag[get(x)] = tag[get(x+n)] = 1;
						} 
					}
				}
				else if(a[i].cc == 'T'){
					if(xx <= 2*n) merge(x, 2*n+2), merge(x+n, 2*n+1);
					else{
						if(xx == 2*n+1){
							tag[get(x)] = tag[get(x+n)] = 1;
						} 
					}
				}
			}
			else if(a[i].cc == '+'){
				int xx = get(x), yy = get(y);
				if(xx == yy) continue;
				if(xx > 2*n && yy > 2*n){
					if(xx != yy){
						tag[get(x)] = tag[get(x+n)] = 1;
						tag[get(y)] = tag[get(y+n)] = 1;
					}
				}
				else if(xx > 2*n){
					merge(y, xx);
					merge(y+n, 4*n+3-xx);
				}
				else if(yy > 2*n){
					merge(x, yy);
					merge(x+n, 4*n+3-yy);
				}
				merge(x, y); merge(x+n, y+n);
			}
			else if(a[i].cc == '-'){
				int xx = get(x), yy = get(y);
				if(xx == yy){
					tag[get(x)] = tag[get(x+n)] = 1;
					tag[get(y)] = tag[get(y+n)] = 1;
				}
				if(xx > 2*n && yy > 2*n){
					if(xx == yy){
						tag[get(x)] = tag[get(x+n)] = 1;
						tag[get(y)] = tag[get(y+n)] = 1;
					}
				}
				else if(xx > 2*n){
					merge(y, 4*n+3-xx);
					merge(y+n, xx);
				}
				else if(yy > 2*n){
					merge(x, 4*n+3-yy);
					merge(x+n, yy);
				}
				merge(x+n, y); merge(x, y+n);				
			}
		}
//		for(int i = 1; i <= 2*n; i++){
//			printf("%d %d  %d\n", i, get(i), tag[get(i)]);
//		}
		for(int i = 1; i <= n; i++){
			int x = get(i);
			if(v[x]) continue;
			v[x] = 1;
			if(tag[x]) cnt += siz[x];
		}
		printf("%d\n", cnt);
	}
}

namespace solve{
	int fa[SIZE*2], siz[SIZE*2]; bool tag[SIZE*2];//2n+1 F 2n+2 T
	bool v[SIZE], vis[SIZE];
	int get(int x){
		if(fa[x] == x) return x;
		return fa[x] = get(fa[x]);
	}
	void merge(int x, int y){
		int xx = get(x), yy = get(y);
		if(xx == yy) return;
		fa[xx] = yy, siz[yy] += siz[xx];
		tag[yy] |= tag[xx];
	}
	void Main(){
		n = rd(), m = rd(); cnt = 0;
		for(int i = 1; i <= m; i++){
			cin >> a[i].cc; a[i].x = rd();
			if(a[i].cc == '+' || a[i].cc == '-') a[i].y = rd();
		}
		for(int i = 1; i <= n*2+2; i++){
			fa[i] = i; siz[i] = 0; v[i] = 0; tag[i] = 0;
			if(i <= n) ans[i] = '&', siz[i] = 1, vis[i] = 0;
		} 
		for(int i = m; i >= 1; i--){
			int x = a[i].x, y = a[i].y;
			if(vis[x]) continue;
			vis[x] = 1;
			if(a[i].cc == 'U') tag[get(x)] = 1;
			else merge(a[i].x, a[i].y);
		}
		for(int i = 1; i <= n; i++){
			int x = get(i);
			if(v[x]) continue;
			v[x] = 1;
			if(tag[x]) cnt += siz[x];
		}
		printf("%d\n", cnt);
	}
}

namespace solve1{
	void Main(){
		n = rd(), m = rd(); cnt = 0;
		for(int i = 1; i <= n; i++) ans[i] = '&';
		for(int i = 1; i <= m; i++){
			cin >> a[i].cc; a[i].x = rd();
			if(a[i].cc == '+' || a[i].cc == '-') a[i].y = rd();
			ans[a[i].x] = a[i].cc;
		}
		for(int i = 1; i <= n; i++) if(ans[i] == 'U') cnt++;
		printf("%d\n", cnt);
	}
}

namespace solve2{
	char ans1[SIZE];
	bool check(){
		for(int i = 1; i <= n; i++) ans1[i] = ans[i];
		for(int i = 1; i <= m; i++){
			if(a[i].cc == '+'){
				ans1[a[i].x] = ans1[a[i].y];
			}
			else if(a[i].cc == '-'){
				if(ans1[a[i].y] == 'U') ans1[a[i].x] = 'U';
				else if(ans1[a[i].y] == 'F') ans1[a[i].x] = 'T';
				else if(ans1[a[i].y] == 'T') ans1[a[i].x] = 'F';
			}
			else ans1[a[i].x] = a[i].cc;
		}
		for(int i = 1; i <= n; i++) if(ans1[i] != ans[i]) return 0;
		return 1;
	}
	void dfs(int x, int cc){
		if(x > n){
			if(check()) cnt = min(cnt, cc);
			return;
		}
		ans[x] = 'T';
		dfs(x+1, cc);
		ans[x] = 'F';
		dfs(x+1, cc);
		ans[x] = 'U';
		dfs(x+1, cc+1);
	}
	void Main(){
		n = rd(), m = rd(); cnt = n;
		for(int i = 1; i <= n; i++) ans[i] = '&';
		for(int i = 1; i <= m; i++){
			cin >> a[i].cc; a[i].x = rd();
			if(a[i].cc == '+' || a[i].cc == '-') a[i].y = rd();
		}
		dfs(1, 0);
		printf("%d\n", cnt);
	}
}

int main(){
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	ID = rd(), T = rd();
	while(T--){
		if(ID >= 1 && ID <= 2) solve2::Main();
		else if(ID >= 3 && ID <= 4) solve1::Main();
		else solve::Main();
	}
	return 0;
}

/*
10 10
T 3
+ 1 2
- 7 1
+ 2 10
T 6
- 1 4
U 3
+ 7 10
F 5
+ 6 9


3 2
2 3
U 1
T 1
U 2
4 6
U 1
T 1
U 3
U 4
F 4
U 1
*/

