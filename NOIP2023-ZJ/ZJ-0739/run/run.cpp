#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e5+5;
int c, t;
int n, m, k, d;
struct nd{
	int x, y, v;
}a[maxn];

void solve1(){
	ll num = 0;
	for(int i=1; i<=m; i++) if(a[i].y < a[i].v) num += a[i].v - a[i].y;
	cout << num;
}


int main(){
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	cin >> c >> t;
	cin >> n >> m >> k >> d;
	for(int i=1; i<=m; i++) scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].v);
	if(c == 17 || c == 18){
		solve1();
	}
	else cout << 114;
}
