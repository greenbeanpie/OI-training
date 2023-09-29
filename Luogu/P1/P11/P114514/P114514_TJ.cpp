#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, m, a[1000002], op, l, r, k;
void Swap(int &x, int &y){int t=y;y=x,x=t;}

signed main(){
	freopen("seg.in", "r", stdin);
	freopen("seg.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0); cerr.tie(0);
	cin >> n >> m;
	Swap(n,m);
	cout << n << " " << m;
	
	return 0;
}
