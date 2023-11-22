#include <bits/stdc++.h>
using namespace std;
#define N 100010

int C , T , n , m , cnt;
int x[ N ];
bool arc[ N ];

struct edge
{
	int to;
	bool val; // 0:equal ; 1:opposite
	int nxt;
} e[ N << 2 ];
int head[ N ] , tot;

void add_edge( int from , int to , bool val )
{
	e[ ++ tot ] = edge{ to , val , head[ from ] };
	head[ from ] = tot;
}

bool stair[ N ];
bool vis[ N ];
int sz;
bool unk;

void solve( int u )
{
	vis[ u ] = true;
	sz ++;
	if( u == n + 1 )
		unk = true , cnt --;
	
	int flag = false;
	for( int i = head[ u ] ; i ; i = e[ i ].nxt )
	{
		int v = e[ i ].to;
		bool val = e[ i ].val;
		if( ! vis[ v ] )
			continue;
			
		if( u == v )
		{
			if( val )
				unk = true;
			continue;
		}
		
		if( flag )
		{
			if( stair[ u ] != ( stair[ v ] ^ val ) )
				unk = true;
		}
		else
		{
			stair[ u ] = stair[ v ] ^ val;
			flag = true;
		}
	}
	
	for( int i = head[ u ] ; i ; i = e[ i ].nxt )
	{
		int v = e[ i ].to;
		if( vis[ v ] )
			continue;
		
		solve( v );
	}
}

signed main()
{
	freopen( "tribool.in" , "r" , stdin );
	freopen( "tribool.out" , "w" , stdout );
	
	scanf( "%d%d" , & C , & T );
	while( T -- )
	{
		tot = 0 , cnt = 0;
		memset( head , 0 , sizeof head );
		memset( stair , false , sizeof stair );
		memset( vis , false , sizeof vis );
		memset( arc , false , sizeof arc );
		
		scanf( "%d%d" , & n , & m );
		for( int i = 0 ; i <= n + 1 ; i ++ )
		{
			x[ i ] = i;
		}
		char c;
		int u , v;
		for( int i = 1 ; i <= m ; i ++ )
		{
			cin >> c >> u;
			if( c == 'U' )
				x[ u ] = n + 1;
			if( c == 'T' || c == 'F' )
				x[ u ] = n + 2;
			if( c == '+' || c == '-' )
			{
				cin >> v;
				x[ u ] = x[ v ];
				arc[ u ] = arc[ v ] ^ ( c == '-' );
			}
		}
		
		for( int i = 1 ; i <= n ; i ++ )
		{
			if( x[ i ] == n + 2 )
				continue;
			
			add_edge( i , x[ i ] , arc[ i ] );
			add_edge( x[ i ] , i , arc[ i ] );
		}
		
		for( int i = 1 ; i <= n + 1 ; i ++ )
			if( ! vis[ i ] )
			{
				unk = false;
				sz = 0;
				solve( i );
				if( unk )
					cnt += sz;
			}
		printf( "%d\n" , cnt );
	}
	return 0;
}