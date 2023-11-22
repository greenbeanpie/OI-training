#include <bits/stdc++.h>
using namespace std;
#define N 2005

int C , n , m , q;
int a[ N ] , b[ N ];
int x[ N ] , y[ N ];
bool fmx[ N ][ N ] , fmn[ N ][ N ];

bool solve()
{
	memset( fmx , 0 , sizeof fmx );
	memset( fmn , 0 , sizeof fmn );
	
	fmx[ 0 ][ 0 ] = 1;
	fmn[ 0 ][ 0 ] = 1;
	for( int i = 1 ; i <= n ; i ++ )
		for( int j = 1 ; j <= m ; j ++ )
		{	
			for( int k = j ; k >= 1 ; k -- )
			{
				if( y[ k ] >= x[ i ] )
					break;
				fmx[ i ][ j ] |= fmx[ i - 1 ][ k - 1 ] | fmx[ i - 1 ][ k ];
			}
			for( int k = j ; k >= 1 ; k -- )
			{
				if( y[ k ] <= x[ i ] )
					break;
				fmn[ i ][ j ] |= fmn[ i - 1 ][ k - 1 ] | fmn[ i - 1 ][ k ];
			}
		}
	
	return fmx[ n ][ m ] | fmn[ n ][ m ];
}

signed main()
{
	freopen( "expand.in" , "r" , stdin );
	freopen( "expand.out" , "w" , stdout );
	
	cin >> C >> n >> m >> q;
	for( int i = 1 ; i <= n ; i ++ )
		scanf( "%d" , a + i ) , x[ i ] = a[ i ];
	for( int i = 1 ; i <= m ; i ++ )
		scanf( "%d" , b + i ) , y[ i ] = b[ i ];
	
	printf( "%d" , solve() );
	
	while( q -- )
	{
		for( int i = 1 ; i <= n ; i ++ )
			x[ i ] = a[ i ];
		for( int i = 1 ; i <= m ; i ++ )
			y[ i ] = b[ i ];
		
		int kx , ky , p , v;
		scanf( "%d%d" , & kx , & ky );
		while( kx -- )
		{
			scanf( "%d%d" , & p , & v );
			x[ p ] = v;
		}
		while( ky -- )
		{
			scanf( "%d%d" , & p , & v );
			y[ p ] = v;
		}
		
		printf( "%d" , solve() );
	}
	return 0;
}