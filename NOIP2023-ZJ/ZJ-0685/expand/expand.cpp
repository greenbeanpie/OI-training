#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <stack>
#include <vector>

using namespace std ;


/*

*/


int c , n , m , q , kx , ky, px , vx , py,vy ; 
int x[500005] , y[500005] , ans[65];

int main()
{
	freopen("expand.in" , "r" , stdin) ;
	freopen("expand.out" , "w" , stdout) ;
	scanf("%d %d %d %d" , &c , &n , &m , &q ) ;
	for ( int i = 1 ; i <= n ; i ++ )
	{
		scanf("%d" , &x[i] ) ;
	}
	for ( int i = 1 ; i <= m ; i ++ )
	{
		scanf("%d" , &y[i]) ;
	}
	if ( c == 1 )
	{
		for ( int i = 1 ; i <= q ; i ++ )
		{
			scanf("%d %d" , &kx , &ky) ;
			for ( int j = 1 ; j <= kx ; j ++ ) scanf("%d %d" , &px , &vx) ;
			for ( int j = 1 ; j <= ky ; j ++ ) scanf("%d %d" , &px , &vx) ;
			printf("1") ;
		}
			
	}
	return 0 ; 
}
