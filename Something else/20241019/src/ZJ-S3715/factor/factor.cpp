#include<bits/stdc++.h>
#define maxn 100010
using namespace std;
typedef long long ll;
ll n, a[maxn], b[maxn], ans, f[maxn], t[maxn]; 
ll cnt; 
struct node{
	ll id, val;
} c[maxn];

ll lowbit(ll x){return x & -x;}
void xiugai(ll x, ll k){
	for(int i = x; i <= n; i += lowbit(i))	
		t[i] = max(t[i], k);
}
ll chaxun(ll x){
	ll ret = 0;
	for(int i = x; i >= 1; i -= lowbit(i))
		ret = max(ret, t[i]);
	return ret;
}
bool cmp(node n1, node n2){
	return n1.val < n2.val;
}
void era(ll x){
	for(int i = x; i <= n; i += lowbit(i)) t[i] = 0;
}
void solve(ll l, ll r){
//	cout << l << ' ' << r << '\n'; 
	if(l == r) return;
	ll mid = (l + r) >> 1;
	solve(l, mid);
	cnt = 0; 
	for(int i = l; i <= r; i++) c[++cnt] = node{i, a[i]};
	sort(c + 1, c + 1 + cnt, cmp);
	for(int i = 1; i <= cnt; i++)
		if(c[i].id <= mid)
			// that means we should modify on the array
			xiugai(b[c[i].id], f[c[i].id]);
		else
			f[c[i].id] = max(f[c[i].id], chaxun(b[c[i].id] - 1) + 1);
	for(int i = 1; i <= cnt; i++)
		if(c[i].id <= mid) era(b[c[i].id]);
	solve(mid + 1, r);
}
int main(){
	freopen("factor.in", "r", stdin);
	freopen("factor.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n; 
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) cin >> b[i];
	for(int i = 1; i <= n; i++) f[i] = 1; 
	solve(1, n);
	for(int i = 1; i <= n; i++) ans = max(ans, f[i]);
	cout << ans << endl;
	return 0;
}

