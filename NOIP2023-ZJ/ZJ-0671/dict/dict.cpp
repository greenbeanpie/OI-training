#include<bits/stdc++.h>
using namespace std ;

int n , m , words_[ 26 ] , maxn[ 3005 ] ;
char ss[ 3005 ][ 3005 ] ;
bool flag ;

void catch_min( int p )
{
	int cnt = 0 ;
	for ( int i = 0 ; cnt < m ; i ++ )
	{
		int w = words_[ i ] ;
		while ( w )
		{
			ss[ p ][ cnt ++ ] = i ;
			w -- ;
		}
	}
	return ;
}

void check_()
{
	int cnt = 0 , linshi[ 3005 ] ;
	for ( int i = 25 ; cnt < m ; i -- )
	{
		int w = words_[ i ] ;
		while ( w )
		{
			linshi[ cnt ++ ] = i ;
			w -- ;
		}
	}
	
	for ( int i = 0 ; i < m ; i ++ )
	{
		if ( linshi[ i ] > maxn[ i ] )
		{
			return ;
		}
		else if ( linshi[ i ] < maxn[ i ] )
		{
			break ;
		}
	}
	
	for ( int i = 0 ; i < m ; i ++ )
	{
		maxn[ i ] = linshi[ i ] ;
	}
	return ;
}

int main()
{
	freopen( "dict.in" , "r" , stdin ) ;
	freopen( "dict.out" , "w" , stdout ) ;
	
	ios::sync_with_stdio( false ) ;
	cin >> n >> m ;
	if ( n == 1 )
	{
		cout << 1 ;
		return 0 ;
	}
	for ( int i = 0 ; i < m ; i ++ )
	{
		maxn[ i ] = 26 ;
	}
	for ( int i = 1 ; i <= n ; i ++ )
	{
		for ( int j = 0 ; j < 26 ; j ++ )
		{
			words_[ j ] = 0 ;
		}
		for ( int j = 0 ; j < m ; j ++ )
		{
			cin >> ss[ i ][ j ] ;
			words_[ ss[ i ][ j ] - 'a' ] ++ ;
		}
		catch_min( i ) ;
		check_() ;
	}
	
	for ( int i = 1 ; i <= n ; i ++ )
	{
		flag = true ;
		for ( int j = 0 ; j < m ; j ++ )
		{
			if ( ss[ i ][ j ] < maxn[ j ] )
			{
				cout << 1 ;
				flag = false ;
				break ;
			}
			else if ( ss[ i ][ j ] > maxn[ j ] )
			{
				cout << 0 ;
				flag = false ;
				break ;
			}
		}
		if ( flag )
		{
			cout << 1 ;
		}
	}
	return 0 ;
}
