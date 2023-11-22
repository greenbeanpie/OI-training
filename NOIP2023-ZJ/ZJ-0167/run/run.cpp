#include<bits/stdc++.h>
#define int long long
using namespace std;

int c, t;

namespace SolveB{
inline int main()
{
	int n, m, k, d, i, ans = 0;
	scanf("%lld%lld%lld%lld", &n, &m, &k, &d);
	for(i=1;i<=m;i++)
	{
		int x, y, v;
		scanf("%lld%lld%lld", &x, &y, &v);
		if(y*d<=v) ans += v - y * d;
	}
	printf("%lld\n", ans);
	return 0;
}
}//namespace SolveB

namespace SolveN1000{
const int N = 1e3 + 10;

int f[N][N], w[N][N];

inline int main()
{
	int n, m, k, d, i, j;
	memset(f,0x80,sizeof f);
	memset(w,0,sizeof w);
	scanf("%lld%lld%lld%lld", &n, &m, &k, &d);
	for(i=1;i<=m;i++)
	{
		int x, y, v;
		scanf("%lld%lld%lld", &x, &y, &v);
		w[x][y] += v;
	}
	f[0][0] = 0;
	for(i=1;i<=n+1;i++)
	{
		f[i][0] = f[i-1][0];
		for(j=1;j<=i&&j<=k;j++)
		{
			f[i][0] = max(f[i][0],f[i-1][j]);
			w[i][j] += w[i][j-1];
			f[i][j] = f[i-1][j-1] - d + w[i][j];
		}
	}
	printf("%lld\n", f[n+1][0]);
	return 0;
}
}//namespace SolveN3000

signed main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	scanf("%lld%lld", &c, &t);
	if(c==17||c==18)
	{
		while(t--) SolveB::main();
		return 0;
	}
	else
	{
		while(t--) SolveN1000::main();
		return 0;
	}
	return 0;
}