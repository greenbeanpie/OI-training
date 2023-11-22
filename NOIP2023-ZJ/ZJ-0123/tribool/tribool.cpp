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
#define N 300010
vector<int> g[N];
bitset<N> ban;
int sum[N],sz[N],f[N],from[100010][3],cas,t,n,m,ans;
inline int find(int u)
{
	if(f[u] == u) return u;
	return f[u] = find(f[u]);
}
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	cas = read(),t = read();
	while(t--)
	{
		n = read(),m = read();	
		F(i,1,n) from[i][0] = i,from[i][1] = i+n,from[i][2] = i+n*2;
		while(m--)
		{
			char str[2];
			scanf("%s",str);
			int x = read(),y;
			if(str[0] == 'F') from[x][0] = 0,from[x][1] = from[x][2] = 3*n+1;
			else if(str[0] == 'T') from[x][1] = 0,from[x][0] = from[x][2] = 3*n+1;
			else if(str[0] == 'U') from[x][2] = 0,from[x][0] = from[x][1] = 3*n+1;
			else 
			{
				y = read();
				if(str[0] == '+') from[x][0] = from[y][0],from[x][1] = from[y][1],from[x][2] = from[y][2];
				else from[x][0] = from[y][1],from[x][1] = from[y][0],from[x][2] = from[y][2];
			}
		}
		F(i,0,3*n+1) f[i] = i,sum[i] = sz[i] = 0;
		F(i,1,n) f[i] = find(from[i][0]),f[i+n] = find(from[i][1]),f[i+n*2] = find(from[i][2]);
		ban = 0;
		ban[3*n+1] = 1;
		F(i,1,n) 
		{
			find(i),find(i+n),find(i+2*n);
			if(f[i] == f[i+n]) ban[f[i]] = 1;
			++sum[f[i+2*n]];
			++sz[f[i]],++sz[f[i+n]],++sz[f[i+2*n]];
		}
		write(sum[0]);
		putchar(10);
	}
	return 0;
}