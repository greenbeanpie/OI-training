#include<bits/stdc++.h>
#define maxn int(5e5+5)
#define ll long long
using namespace std;
struct chal{
	ll l, r, v;
} c[maxn];
bool day[maxn], flag[maxn];
ll value[maxn], n, m, k, d, ans;
void calcval(int x) {
	value[x] = c[x].v;
	for(int i = c[x].l; i <= c[x].r; i++)
		if(!day[i]) value[x]-=d;
}
void fill(int x) {
	ll last = 0;
	for(int i = 1; i <= n; i++) {
		if(day[i]||(i>=c[x].l&&i<=c[x].r))  {
			last++;
			if(last>k) return;
		} else last = 0;
	}
	for(int i = c[x].l; i <= c[x].r; i++) day[i] = 1;
	ans += value[x];
	return;
}
int main() {
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int op, T;
	cin>>op>>T;
	while(T--) {
		cin>>n>>m>>k>>d;
		memset(day, 0, sizeof(day));
		memset(flag, 0, sizeof(flag));
		ans = 0;
		for(int i = 1; i <= m; i++) {
			cin>>c[i].r>>c[i].l>>c[i].v;
			if(c[i].l>k) flag[i]=1;
			c[i].l = c[i].r-c[i].l+1;
		}
		
		int mx;
		for(int i = 1; i <= m; i++) {
			mx = 0;
			for(int j = 1; j <= m; j++) {
				if(flag[j]) continue;
				calcval(j);
				mx = (mx==0||value[j]>value[mx])?j:mx;
			}
			if(value[mx]<=0) break;
//			cout << mx << endl;
			fill(mx); flag[mx]=1;
		}
		cout << ans << endl;
	}
	
	return 0;
}
