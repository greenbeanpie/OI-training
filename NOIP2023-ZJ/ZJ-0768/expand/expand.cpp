#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int c,n,m,q,x[N],y[N];
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	ios::sync_with_stdio(0);
	cin >> c >> n>> m >> q;
	for (int i=1;i<=n;i++) cin >> x[i];
	for (int i=1;i<=m;i++) cin >> y[i];
	if (x[1]==y[1]) cout << 1;
	else cout << 0;
	while(q--)
	{
		int kx,ky,x,y;
		cin >> kx >> ky;
		cin >> x >> y;
		if (x==y) cout << 1;
		else cout << 0;
	}
}
