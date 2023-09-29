#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, m, a[5], op, l, r, k;
void Swap(int &x, int &y)
{
	// x^=y;
	// y^=x;
	// x^=y;
}

signed main(){
	freopen("P114514.in", "r", stdin);
	freopen("P114514.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0); cerr.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++)	cin >> a[i];
	for(int i = 1;i<=n;i++) cout<<a[i]<<" ";
		cout<<"\n";
	for(int i = 1; i <= m; i ++){
		cin >> op;
		cin >> l>> r >> k;
		int L = (1 << k) * l, R = (1 << k) * r;
		for(int i = 1; i <= (1 << k); i ++)	
		{
			Swap(a[L + i], a[R + i]);
		}
		for(int i = 1;i<=n;i++) cout<<a[i]<<" ";
		cout<<"\n";
	}
	
	return 0;
}

