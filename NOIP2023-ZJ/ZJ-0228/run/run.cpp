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
ll n , m , k , d , C , Q , a , b , c , f[ 100005 ] ;
struct node{
	ll st , ed , val ;
} t[ 100005 ] ;
bool cmp( node x1 , node x2 ) {
	return x1.ed < x2.ed ;
}
ll s[ 100005 ] ;
ll val( ll x1 , ll x2 ) {
	ll res = 0 ;
	Rep( i , m , 1 ) {
		if( t[ i ].st >= x1 && t[ i ].ed <= x2 )
			res += t[ i ].val ;
		if( x1 > t[ i ].ed ) return res ;
	}
	return res ;
}
void getval( ll x ) {
	f[ x ] = f[ x - 1 ] ;
	Rep( i , x , 1 )
		Rep( j , i , max( 1ll , i - k + 1 ) )
			f[ x ] = max( f[ x ] , val( j , i ) - ( i - j + 1 ) * d + f[ max( j - 2 , 0ll ) ] ) ;
}
int main() {
    freopen("run.in" , "r" , stdin ) ;
    freopen("run.out" , "w" , stdout ) ;
    C = read() ; Q = read() ;
    while( Q-- ) {
		n = read() ;
		m = read() ;
		k = read() ;
		d = read() ;
		For( i , 1 , m ) {
			a = read() ;
			b = read() ;
			c = read() ;
			t[ i ].st = a - b + 1 ;
			t[ i ].ed = a ;
			t[ i ].val = c ;
		}
		sort( t + 1 , t + 1 + m , cmp ) ;
		f[ 0 ] = 0 ;
		For( i , 1 , n )
			getval( i ) ;
		printf("%lld\n" , f[ n ] ) ;
	}
    return 0 ;
}
