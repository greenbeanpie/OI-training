#include <bits/stdc++.h>
using namespace std;
#define M 2005
#define N 2005

int C , T , n , m , k , d;
int x[ M ] , y[ M ] , v[ M ];
int f[ M ][ N ];

signed main()
{
	freopen( "run.in" , "r" , stdin );
	freopen( "run.out" , "w" , stdout );
	
	cin >> C >> T;
	while( T -- )
	{
		cin >> n >> m >> k >> d;
		for( int i = 1 ; i <= m ; i ++ )
			scanf( "%d%d%d" , x + i , y + i , v + i );
		
		memset( f , 0x8f , sizeof f );
		for( int i = 1 ; i <= x[ 1 ] ; i ++ )
			f[ 1 ][ i ] = - d * ( x[ 1 ] - i + 1 ) + v[ 1 ] * ( x[ 1 ] - i + 1 >= y[ 1 ] );
		for( int i = 2 ; i <= m ; i ++ )
		{
			for( int j = 0 ; j <= k ; j ++ )
			{
				if( j < x[ i ] - x[ i - 1 ] )
				{
					for( int t = 0 ; t <= k ; t ++ )
						f[ i ][ j ] = max( f[ i ][ j ] , f[ i - 1 ][ t ] );
					f[ i ][ j ] -= d * j;
				}
				else
				{
					f[ i ][ j ] = f[ i - 1 ][ j - ( x[ i ] - x[ i - 1 ] ) ] - d * x[ i ] - x[ i - 1 ];
				}
				
				if( j >= y[ i ] )
					f[ i ][ j ] += v[ i ];
			}
		}
		
		int mx = 0;
		for( int i = 0 ; i <= k ; i ++ )
			mx = max( mx , f[ m ][ i ] );
		cout << mx << endl;
	}
		
	return 0;
}