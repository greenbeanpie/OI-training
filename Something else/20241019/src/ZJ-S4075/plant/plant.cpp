#include<bits/stdc++.h>
#define int long long 
using namespace std;

const int N = 1e5+10;
int n, k, a[N], b[N], c[N];

signed main() {
	freopen("plant.in", "r", stdin);
	freopen("plant.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i ++) cin >> a[i];
	for(int i = 1; i <= n; i ++) cin >> b[i];
	for(int i = 1; i <= n; i ++) cin >> c[i];
	priority_queue<int, vector<int>, greater<int> > q;
	cin >> k;
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= n; j ++) {
			q.push(a[i] + b[i] * c[j]);
//			while(q.size() > k) q.pop();
		}
	}
	for(int i = 1; i < k; i ++) q.pop();
	cout << q.top();
}
