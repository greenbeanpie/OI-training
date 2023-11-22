#include <bits/stdc++.h>
using namespace std;
template<typename T = int>inline T read()
{
	int p = 1,c = getchar();
	T x = 0;
	while(c < 48||c > 57)
	{
		if(c == 45) p = -1;
		c = getchar();
	}
	while(48 <= c&&c <= 57)
	{
		x = (x<<3)+(x<<1)+(c^48);
		c = getchar();
	}
	return x*p;
}
template<typename T>inline void write(T x)
{
	if(!x)
	{
		putchar(48);
		return;
	}
	if(x < 0) putchar(45),x = -x;
	static int c[40],len = 0;
	while(x) c[++len] = x%10^48,x /= 10;
	while(len) putchar(c[len--]);
}
#define F(i,a,b) for(register int i=a;i<=b;++i)
#define D(i,a,b) for(register int i=a;i>=b;--i)
#define ull unsigned long long
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define debug(x) cerr<<#x<<'='<<x<<'\n'
#define N 2010
ll ans = 0;
int cas,t,n,m,k,d;
int main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	cas = read(),t = read();
	while(t--)
	{
		ans = 0;
		n = read(),m = read(),k = read(),d = read();
		F(i,1,m) 
		{
			int x = read(),y = read(),v = read();
			if(y <= k) ans += max(0ll,1ll * v - 1ll * d * y);
		}
		write(ans);
		putchar(10);
	}
	return 0;
}
