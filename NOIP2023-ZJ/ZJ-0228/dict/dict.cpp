#include<bits/stdc++.h>
#define For( i , a , b ) for( register int i = ( a ) ; i <= ( b ) ; ++i )
#define Rep( i , a , b ) for( register int i = ( a ) ; i >= ( b ) ; --i )
#define ll long long
using namespace std ;
inline int read() {
    int s = 0 ; char ch = getchar() ; bool f = 0 ;
    for( ; !isdigit( ch ) ; ch = getchar() ) f ^= !( 45 ^ ch ) ;
    for( ; isdigit( ch ) ; ch = getchar() ) s = ( s << 3 ) + ( s << 1 ) + ( ch ^ 48 ) ;
    if( f ) return -s ; return s ;
}
const int N = 3005 ;
int n , m , s[ N ][ 2 ] ;
char c[ N ] ;
bool check( int x1 , int x2 ) {
    return s[ x1 ][ 1 ] < s[ x2 ][ 0 ] ;
}
int main() {
    freopen("dict.in" , "r" , stdin ) ;
    freopen("dict.out" , "w" , stdout ) ;
    n = read() ; m = read() ;
    For( i , 1 , n ) {
        scanf("%s" , c + 1 ) ;
        s[ i ][ 0 ] = c[ 1 ] - 'a' + 1 ; s[ i ][ 1 ] = c[ 1 ] - 'a' + 1 ;
        For( j , 2 , m )
            s[ i ][ 0 ] = max( s[ i ][ 0 ] , ( int )( c[ j ] - 'a' + 1 ) ) ,
            s[ i ][ 1 ] = min( s[ i ][ 1 ] , ( int )( c[ j ] - 'a' + 1 ) ) ;
    }
    For( i , 1 , n ){
        bool flag = 1 ;
        For( j , 1 , n )
            if( i != j && !check( i , j ) )
            { flag = 0 ; break ; }
        printf("%d" , flag ) ;
    }
    puts("") ;
    return 0 ;
}
