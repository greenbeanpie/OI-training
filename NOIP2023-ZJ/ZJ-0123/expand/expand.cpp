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
bitset<N> dp[N];
inline bool solve(int *a,int n,int *b,int m)
{
	if(a[1] >= b[1]||a[n] >= b[m]) return 0;
	memset(dp,0,sizeof(dp));
	dp[0][0] = 1;
	F(i,1,n)
		F(j,1,m)
		{
			D(k,j,1)
			{
				if(a[i] >= b[k]) break;
				if(dp[i-1][k-1]) 
				{
					dp[i][j] = 1;
					break;
				}
			}	
			if(dp[i][j]) continue;
			D(k,i,1)
			{
				if(a[k] >= b[j]) break;
				if(dp[k-1][j-1])
				{
					dp[i][j] = 1;
					break;	
				}	
			}	
		}
	return dp[n][m];
}
int A[N],B[N],a[N],b[N];
int cas,n,m,q;
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	cas = read(),n = read(),m = read(),q = read();
	if(n <= 2000&&m <= 2000)
	{
		F(i,1,n) a[i] = read();
		F(i,1,m) b[i] = read();
		if(solve(a,n,b,m)||solve(b,m,a,n)) putchar(49);
		else putchar(48);
		memcpy(A,a,sizeof(A));
		memcpy(B,b,sizeof(B));
		while(q--)
		{
			memcpy(a,A,sizeof(a));
			memcpy(b,B,sizeof(b));
			int k1 = read(),k2 = read(),x,y;
			while(k1--)
			{
				x = read(),y = read();
				a[x] = y;
			}
			while(k2--)
			{
				x = read(),y = read();
				b[x] = y;
			}
			if(solve(a,n,b,m)||solve(b,m,a,n)) putchar(49);
			else putchar(48);
		}	
	}
	else
	{
		++q;
		while(q--) putchar(49);
	}
	return 0;
}
