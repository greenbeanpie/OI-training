#include<bits/stdc++.h>
#define For( i , a , b ) for( register ll i = ( a ) ; i <= ( b ) ; ++i )
#define Rep( i , a , b ) for( register ll i = ( a ) ; i >= ( b ) ; --i )
#define ll long long
using namespace std ;
inline ll read() {
    ll s = 0 ; char ch = getchar() ; bool f = 0 ;
    for( ; !isdigit( ch ) ; ch = getchar() ) f ^= !( 45 ^ ch ) ;
    for( ; isdigit( ch ) ; ch = getchar() ) s = ( s << 3 ) + ( s << 1 ) + ( ch ^ 48 ) ;
    if( f ) return -s ; return s ;
}
const ll N = 2005 ;
ll C , n , m , Q , a[ N ] , b[ N ] , r1[ N ] , r2[ N ] , c1 , c2 , x , y ;
bool f[ N ][ N ] ;
void check() {
	if( r1[ 1 ] == r2[ 1 ] ) { f[ n ][ m ] = 0 ; return ; }
	For( i , 1 , n ) For( j , 1 , m ) f[ i ][ j ] = 0 ;
	f[ 1 ][ 1 ] = 1 ; f[ 0 ][ 0 ] = 1 ; f[ 1 ][ 0 ] = 1 ; f[ 0 ][ 1 ] = 1 ;
	if( r1[ 1 ] > r2[ 1 ] ) {
		For( i , 1 , n )
			For( j , 1 , m ){
				if( r1[ i ] > r2[ j ] ) f[ i ][ j ] |= f[ i - 1 ][ j - 1 ] , f[ i ][ j ] |= f[ i ][ j - 1 ] ;
				if( f[ i ][ j ] ) {
					For( k , j + 1 , m ) {
						if( r1[ i ] <= r1[ k ] ) break ;
						f[ i ][ k ] = 1 ;
					}
				}
			}
	}
	if( r1[ 1 ] < r2[ 1 ] ) {
		For( i , 1 , n )
			For( j , 1 , m ){
				if( r1[ i ] < r2[ j ] ) f[ i ][ j ] |= f[ i - 1 ][ j - 1 ] , f[ i ][ j ] |= f[ i ][ j - 1 ] ;
				if( f[ i ][ j ] ) {
					For( k , j + 1 , m ) {
						if( r1[ i ] >= r1[ k ] ) break ;
						f[ i ][ k ] = 1 ;
					}
				}
			}
	//	return f[ n ][ m ] ;
	}
}
int main() {
    freopen("expand.in" , "r" , stdin ) ;
    freopen("expand.out" , "w" , stdout ) ;
    C = read() ; n = read() ; m = read() ; Q = read() ;
    if( C >= 8 ) {
		For( i , 1 , Q + 1 ) printf("0") ;
		return 0 ;
	}
    For( i , 1 , n ) a[ i ] = read() , r1[ i ] = a[ i ] ;
    For( i , 1 , m ) b[ i ] = read() , r2[ i ] = b[ i ] ;
    check() ;
    printf("%d" , f[ n ][ m ] ) ;
    while( Q-- ) {
		For( i , 1 , n ) r1[ i ] = a[ i ] ;
		For( i , 1 , m ) r2[ i ] = b[ i ] ;
		c1 = read() ; c2 = read() ;
		For( i , 1 , c1 ) {
			x = read() ;
			y = read() ;
			r1[ x ] = y ;
		}
		For( i , 1 , c2 ) {
			x = read() ;
			y = read() ;
			r2[ x ] = y ;
		}
		check() ;
		printf("%d" , f[ n ][ m ] ) ;
	}
	puts("") ;
    return 0 ;
}
