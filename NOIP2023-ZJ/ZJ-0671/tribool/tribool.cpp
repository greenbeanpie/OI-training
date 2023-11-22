#include<bits/stdc++.h>
using namespace std ;

int c , t ;
int n , m , ans , fa[ 200005 ] ;
int a , b , xn[ 100005 ] , sum[ 100005 ] ;
bool xm[ 100005 ] ;
char v ;
char vvv[ 100005 ] ;

int fi( int ) ;

int change( char ) ;

void DFS( int ) ;

int main()
{
	freopen( "tribool.in" , "r" , stdin ) ;
	freopen( "tribool.out" , "w" , stdout ) ;
	
	ios::sync_with_stdio( false ) ;
	cin >> c >> t ;
	
	if ( c == 3 || c == 4 )
	{
		while ( t -- )
		{	
			cin >> n >> m ;
			ans = 0 ;
			for ( int i = 1 ; i <= n ; i ++ )
			{
				xn[ i ] = i ;
			}
			while ( m -- )//²Ù×÷ 
			{
				cin >> v ;
				cin >> a ;
				xn[ a ] = change( v ) ;
			}
			for ( int i = 1 ; i <= n ; i ++ )
			{
				if ( !xn[ i ] )
				{
					ans ++ ;
				}
			}
			cout << ans << "\n" ;
		}
		return 0 ;
	}
	
	if ( c == 5 || c == 6 )
	{
		while ( t -- )
		{	
			
			cin >> n >> m ;
			ans = 0 ;
			for ( int i = 1 ; i <= n ; i ++ )
			{
				fa[ i ] = i ;
				sum[ i ] = 1 ;
				xn[ i ] = i ;
			}
			while ( m -- )//²Ù×÷ 
			{
				cin >> v ;
				if ( v == '+' )
				{
					cin >> a >> b ;
					fa[ a ] = fi( b ) ;
					xn[ a ] = xn[ b ] ;
				}
				else
				{
					cin >> a ;
					fa[ a ] = a ;
					xn[ a ] = change( v ) ;
				}
			}
			for ( int i = 1 ; i <= n ; i ++ )
			{
				if ( !xn[ fi( i ) ] )
				{
					ans ++ ;
				}
			}
			cout << ans << "\n" ;
		}
		return 0 ;
	}
	
	
	while( t -- )
	{
		for ( int i = 1; i <= n ; i ++ )
		{
			xn[ i ] = i ;
			fa[ i ] = i ;
			xm[ i ] = true ;
		}
		cin >> n >> m ;
		ans = 1e5 ;
		while ( m -- )
		{
			cin >> v ;
			if ( v == '+' )
			{
				cin >> a >> b ;
				fa[ a ] = fi( b ) ;
				xn[ a ] = xn[ b ] ;
				xm[ a ] = xm[ b ] ;
			}
			else if ( v == '-' )
			{
				cin >> a >> b ;
				fa[ a ] = fi( b ) ;
				xn[ a ] = -xn[ b ] ;
				xm[ a ] = xm[ b ] ;
			}
			else
			{
				cin >> a ;
				fa[ a ] = a ;
				xn[ a ] = change( v ) ;
				xm[ a ] = false ;
			}
		}
		for ( int i = 1 ; i <= n ; i ++ )
		{
			if ( !xn[ fi( i ) ] )
			{
				ans ++ ;
			}
			else if ( !( xn[ fi( i ) ] + fi( i ) ) )
			{
				ans ++ ;
			}
		}
		cout << ans << "\n" ;
	}
	return 0 ;
}

int fi( int x )
{
	return x == fa[ x ] ? x : fi( fa[ x ] ) ;
}

int change( char vv )
{
	if ( vv == 'T' )
	{
		return 2e5+1 ;
	}
	if ( vv == 'F' )
	{
		return -2e5-1 ;
	}
	return 0 ;
}

