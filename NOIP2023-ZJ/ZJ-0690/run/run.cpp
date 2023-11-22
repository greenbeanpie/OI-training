#include <bits/stdc++.h>
using namespace std;
#define elif else if
#define int long long

int c, T, n, m, k, d, f[10000005];
struct node{
	int x, y, v;
}a[100005];

int max(int x, int y){
	if(x > y)
		return x;
	return y;
}

bool cmp(node a, node b){
	return (a.x < b.x) || (a.x == b.x && a.y > b.y);
}

int check(int day, int kk, int v){
	if(day < kk || k < kk || v <= kk * d)
		return 0;
	return 1;
}

void work(){
	int sum = 0;
	for(int i = 1; i <= m; i++){
		cin >> a[i].x >> a[i].y >> a[i].v;
		if(check(a[i].x, a[i].y, a[i].v))
			sum += a[i].v - a[i].y * d;
	}
	cout << sum << '\n';
	return;
}

void work1(){
	int ans = 0;
	for(int i = 1; i <= m; i++){
		cin >> a[i].x >> a[i].y >> a[i].v;
		if(check(a[i].x, a[i].y, a[i].v))
			ans = max(ans, a[i].v - a[i].y * d);
	}
	cout << ans << '\n';
	return;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	cin >> c >> T;
	while(T--){
		cin >> n >> m >> k >> d;
		if(c == 17 || c == 18){
			work();
			continue;
		}
		if(c >= 19 || c <= 21){
			work1();
			continue;
		}
		for(int i = 1; i <= m; i++)
			cin >> a[i].x >> a[i].y >> a[i].v;
		sort(a + 1, a + n + 1, cmp);
		int cnt = m;
		for(int i = 2; i <= cnt; i++){
			if(a[i].x - a[i].y == a[i - 1].x + 1){
				int j = i - 1;
				while(a[j].x - a[j].y == a[j - 1].x + 1 && j > 1)
					j--;
				for(int k1 = 2; k1 <= i - j + 1; k1++)
					for(int k2 = j; k2 <= i - k1 + 1; k2++){
						m++;
						a[m].x = a[j + k1 - 1].x;
						for(int k3 = k2; k3 <= k2 + k1 - 1; k3++)
							a[m].y += a[k3].y, a[m].v += a[k3].v;
					}
			}
		}
		sort(a + 1, a + n + 1, cmp);
		memset(f, 0, sizeof(f));
		for(int i = 1; i <= m; i++)
			if(check(a[i].x, a[i].y, a[i].v))
				if(a[i].x - a[i].y > a[i - 1].x + 1)
					f[i] = max(f[a[i].x - a[i].y] + a[i].v - a[i].y * d, max(0, f[a[i - 1].x]));
	}
	return 0;
}




/*

It may be my last time
I can't understand why I chose to learn OI
I can't understand why I spent lots of time on it before
but I have got nothing from it
It had tood me a lot of time
I think it's a waste of my life
I hate OI
but
if I can make a choice again
I think I will choose it again
with no reason

*/
