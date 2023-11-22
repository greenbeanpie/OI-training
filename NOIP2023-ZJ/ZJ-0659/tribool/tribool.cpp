#include<bits/stdc++.h>

using namespace std;

inline int read(){
	int x = 0,f = 1;char c = getchar();
	for(;!isdigit(c);c = getchar())if( c == '-' )f = -1;
	for(;isdigit(c);c = getchar())x = ( x << 1 ) + ( x << 3 ) + c - '0';
	return x * f;
}

const int N = 1e5 + 5;

int c,T,n,m,ans = N;
int v[N],t[N];

struct que{
	char opt;
	int x,y;
}q[N];

inline bool check(){
	for(int i = 1;i <= n;i ++)t[i] = v[i];
	for(int i = 1;i <= m;i ++){
		if( q[i].opt == '-' )t[q[i].x] = -t[q[i].y];
		else if( q[i].opt == '+' )t[q[i].x] = t[q[i].y];
		else if( q[i].opt == 'U' )t[q[i].x] = 0;
		else if( q[i].opt == 'T' )t[q[i].x] = 1;
		else if( q[i].opt == 'F' )t[q[i].x] = -1;
	}
	for(int i = 1;i <= n;i ++)
		if( v[i] != t[i] )return 0;
	return 1;
}

inline void dfs(int cur,int sumU){
	if( cur > n ){
		if( check() && sumU < ans )ans = sumU;
		return;
	}	
	v[cur] = 1;
	dfs( cur + 1 , sumU );
	v[cur] = 0;
	dfs( cur + 1 , sumU + 1 );
	v[cur] = -1;
	dfs( cur + 1 , sumU );
	v[cur] = N;
}

inline void subtask1(){
	ans = N;
	for(int i = 1;i <= n;i ++)v[i] = t[i] = N;
	dfs( 1 , 0 );
	printf("%d\n",ans);
}

int main(){
	freopen("tribool.in" , "r" , stdin);
	freopen("tribool.out" , "w" , stdout);
	c = read();
	T = read();
	while( T -- ){
		n = read(),m = read();
		bool onlyutf = 1,onlyu = 1;
		for(int i = 1;i <= m;i ++){
			cin >> q[i].opt;
			q[i].x = read();
			if( q[i].opt != 'U' && q[i].opt != '+' )onlyu = 0;
			if( q[i].opt == '+' || q[i].opt == '-' ){
				q[i].y = read();
				onlyutf = 0;
			}
		}
		if( n <= 10 ){
			subtask1();
		}
		else if( onlyutf ){
			ans = 0;
			for(int i = 1;i <= n;i ++)v[i] = N;
			for(int i = 1;i <= m;i ++){
				if( q[i].opt == 'U' )v[q[i].x] = 0;
				else if( q[i].opt == 'T' )v[q[i].x] = 1;
				else v[q[i].x] = -1;
			}
			for(int i = 1;i <= n;i ++)if( v[i] == 0 )ans ++;
			printf("%d\n",ans);
		}
		else if( onlyu ){
			ans = 0;
			for(int i = 1;i <= n;i ++)v[i] = N;
			for(int i = 1;i <= m;i ++){
				if( q[i].opt == 'U' )v[q[i].x] = 0;
				else v[q[i].x] = v[q[i].y];
			}
			for(int i = 1;i <= n;i ++)if( v[i] == 0 )ans ++;
			printf("%d\n",ans);
		}
	}
	return 0;
}