#include<bits/stdc++.h>

#define int long long

using namespace std;

inline int read(){
	int x = 0,f = 1;char c = getchar();
	for(;!isdigit(c);c = getchar())if( c == '-' )f = -1;
	for(;isdigit(c);c = getchar())x = ( x << 1 ) + ( x << 3 ) + c - '0';
	return x * f;
}

const int N = 1e5 + 5;
const int inf = 2e18;

int c,T,n,m,k,d,ans;
int vis[N],presum[N];

struct node{
	int x,y,v;
}a[N];

inline int calc(){
	int ret = 0;
	for(int i = 1;i <= n;i ++)presum[i] = 0;
	for(int i = 1;i <= n;i ++)presum[i] = presum[i - 1] + vis[i];
	ret -= d * presum[n];
	for(int i = 1;i <= m;i ++){
		int r = a[i].x,l = a[i].x - a[i].y + 1;
		if( presum[r] - presum[l - 1] == a[i].y )ret += a[i].v;
	}
	return ret;
}

inline void dfs(int cur,int sum){
	if( cur > n ){
		int ret = calc();
		ans = max( ans , ret );
		return;
	}
	if( sum == k ){
		vis[cur] = 0;
		dfs( cur + 1 , 0 );
	}
	else{
		vis[cur] = 1;
		dfs( cur + 1 , sum + 1 );
		vis[cur] = 0;
		dfs( cur + 1 , 0 );
	}
}
signed main(){
	freopen("run.in" , "r" , stdin);
	freopen("run.out" , "w" , stdout);
	c = read();
	T = read();
	while( T -- ){
		ans = -inf;
		for(int i = 1;i <= n;i ++)vis[i] = presum[i] = 0;
		n = read(),m = read();
		k = read(),d = read();
		for(int i = 1;i <= m;i ++){
			a[i].x = read();
			a[i].y = read();
			a[i].v = read();
		}
		dfs( 1 , 0 );
		printf("%lld\n",ans);
	}
	return 0;
}
