#include<bits/stdc++.h>
using namespace std ;

int c , t , ans ;
int n , m , k , d ;
int x[ 100005 ] , y[ 100005 ] , v[ 100005 ] ;
bool paobu[ 100005 ] ;

void DFS( int , int ) ;

int main()
{
	freopen( "run.in" , "r" , stdin ) ;
	freopen( "run.out" , "w" , stdout ) ;
	ios::sync_with_stdio( false ) ;
	cin >> c >> t ;
	if ( c <= 4 )
	{
		while ( t -- )
		{
			ans = -1e9 ;
			cin >> n >> m >> k >> d ;
			for ( int i = 1 ; i <= m ; i ++ )
			{
				cin >> x[ i ] >> y[ i ] >> v[ i ] ;
			}
			DFS( 1 , 0 ) ;
		}
		cout << ans << "\n" ;
	}
	else if ( c <= 9 )
	{
		while ( t -- )
		{
			int dp[ 100005 ][ 2 ] ;
			ans = -1e9 ;
			cin >> n >> m >> k >> d ;
			for ( int i = 1 ; i <= m ; i ++ )
			{
				cin >> x[ i ] >> y[ i ] >> v[ i ] ;
				if ( x[ i ] - y[ i ] <= x[ i - 1 ] && x[ i ] - y[ i - 1 ] + 1 <= k )
				{
					dp[ i ][ 1 ] = dp[ i - 1 ][ 1 ] + v[ i ] - y[ i ] * d ;
				}
				dp[ i ][ 0 ] = dp[ i - 1 ][ 1 ] ;
				dp[ i ][ 1 ] = 
			}
		}
	}
	return 0 ;
}

void DFS( int ti , int li )
{
	if ( ti > n )
	{
		int sum = 0 ;
		for ( int i = 1 ; i <= n ; i ++ )
		{
			if ( paobu[ i ] )
			{
				sum -= d ;
			}
		}
		for ( int i = 1 ; i <= m ; i ++ )
		{
			bool flag = true ;
			if ( y[ i ] > k )
			{
				continue ;
			}
			for ( int j = x[ i ] - y[ i ] + 1 ; j <= x[ i ] ; j ++ )
			{
				if ( !paobu[ j ] )
				{
					flag = false ;
					break ;
				}
			}
			if ( flag )
			{
				sum += v[ i ] ;
			}
		}
		ans = ans > sum ? ans : sum ;
		
		return ;
	}
	if ( li < k )
	{
		paobu[ ti ] = true ;
		DFS( ti + 1 , li + 1 ) ;
	}
	paobu[ ti ] = false ;
	DFS( ti + 1 , 0 ) ;
	return ;
}
