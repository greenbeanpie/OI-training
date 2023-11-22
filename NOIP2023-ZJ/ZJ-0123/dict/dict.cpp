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
#define N 3010
char s[N][N],t[N][N]; 
ull hs[N][N],ht[N][N];
int T[30],n,m;
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	n = read(),m = read();
	F(i,1,n) 
	{
		scanf("%s",s[i]+1);	
		F(j,1,m) ++T[s[i][j]-'a'];
		int now = 0;
		F(j,1,m) 
		{
			while(!T[now]) ++now;
			s[i][j] = now;
			--T[now];
		}
		memcpy(&t[i][1],&s[i][1],m+2);
		reverse(&t[i][1],&t[i][m+1]);
		F(j,1,m) 
		{
			hs[i][j] = (hs[i][j-1] << 5) + (hs[i][j-1] << 2) + hs[i][j-1] + s[i][j];
			ht[i][j] = (ht[i][j-1] << 5) + (ht[i][j-1] << 2) + ht[i][j-1] + t[i][j];	
		}
	}
	F(i,1,n)
	{
		int flag = 1;
		F(j,1,n)
		{
			if(i == j) continue;
			int l = 0,r = m,mid;
			while(l <= r)
			{
				mid = (l + r) >> 1;
				if(hs[i][mid] == ht[j][mid]) l = mid + 1;
				else r = mid - 1;
			}
			if(l > m||s[i][l] > t[j][l]) 
			{
				flag = 0;
				break;
			}
		}
		putchar(flag^48);
	}
	return 0;
}
