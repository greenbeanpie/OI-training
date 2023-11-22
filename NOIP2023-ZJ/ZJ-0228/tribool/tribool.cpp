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
const int N = 100005 ;
int C , T , n , m , a , b ;
char ch ;
struct Val{
    int tp , num ; 
} t[ N ] ;
int val[ N ] , tmp[ N ] , ans ;
int fei( int x ) {
    if( x == 0 || x == 1 ) return x ^ 1 ;
    else return x ;
}
struct edge{
    int To , Nxt , W ;
} e[ N * 2 ] ;
int head[ N ] , tot ;
void add( int u , int v , int w ) {
    e[ ++tot ].Nxt = head[ u ] ;
    e[ tot ].To = v ;
    e[ tot ].W = w ;
    head[ u ] = tot ;
}
void dfs( int x ) {
	if( x == n + 1 ) {
		For( i , 1 , n ){
			if( t[ i ].tp == 2 ) {
				if( t[ i ].num != val[ i ] ) return ;
				tmp[ i ] = val[ i ] ;
			}
			else{
				if( val[ t[ i ].num ] == 2 ) tmp[ i ] = 2 ;
				else tmp[ i ] = ( val[ t[ i ].num ] ^ ( 1 ^ t[ i ].tp ) ) ;
			}
		}
		int res = 0 ;
		For( i , 1 , n ) {
			if( tmp[ i ] != val[ i ] ) return ;
			res += ( val[ i ] == 2 ) ;
		}
		ans = min( ans , res ) ;
		return ; 
	}
	val[ x ] = 0 ; dfs( x + 1 ) ;
	val[ x ] = 1 ; dfs( x + 1 ) ;
	val[ x ] = 2 ; dfs( x + 1 ) ;
}
void Dfs( int x ) {
	for( int i = head[ x ] ; i ; i = e[ i ].Nxt ) {
		int v = e[ i ].To ;
		if( val[ v ] == 2 ) continue ;
		val[ v ] = 2 ;
		Dfs( v ) ;
	}
}
bool vis[ N ][ 3 ] ;
void col( int x , int vl ) {
	vis[ x ][ vl ] = 1 ;
	for( int i = head[ x ] ; i ; i = e[ i ].Nxt ) {
		int v = e[ i ].To , tmp ;
		if( vl == 2 ) tmp = 2 ;
		else tmp = vl ^ ( 1 ^ e[ i ].W ) ;
		if( vis[ v ][ tmp ] ) continue ;
		vis[ v ][ tmp ] = 1 ;
		col( v , tmp ) ;
	}
}
int main() {
    freopen("tribool.in" , "r" , stdin ) ;
    freopen("tribool.out" , "w" , stdout ) ;
    C = read() ; T = read() ;
    while( T-- ) {
        n = read() ;
        m = read() ; tot = 0 ;
        For( i , 1 , n ) t[ i ].num = i , t[ i ].tp = 1 , head[ i ] = 0 , val[ i ] = 0 , vis[ i ][ 0 ] = 0 , vis[ i ][ 1 ] = 0 , vis[ i ][ 2 ] = 0 ;
        For( i , 1 , m ) {
            ch = getchar() ;
            while( ch != '-' && ch != '+' && ch != 'T' & ch != 'U' && ch != 'F' ) ch = getchar() ;
            if( ch == 'T' ) {
                a = read() ;
                t[ a ].tp = 2 ;
                t[ a ].num = 1 ;
            }
            if( ch == 'F' ) {
				a = read() ;
                t[ a ].tp = 2 ;
                t[ a ].num = 0 ;
            }
            if( ch == 'U' ) {
				a = read() ;
                t[ a ].tp = 2 ;
                t[ a ].num = 2 ;
            }
            if( ch == '-' ) {
                a = read() ; b = read() ;
                if( t[ b ].tp == 2 ) {
                    t[ a ].num = fei( t[ b ].num ) ;
                    t[ a ].tp = 2 ;
                }
                else {
                    t[ a ].tp = t[ b ].tp ^ 1 ;
                    t[ a ].num = t[ b ].num ;
                }
            }
            if( ch == '+' ) {
                a = read() ; b = read() ;
                t[ a ].num = t[ b ].num ;
                t[ a ].tp = t[ b ].tp ;
            }
        }
        if( C == 1 || C == 2 ) { ans = 1e9 ; dfs( 1 ) ; printf("%d\n" , ans ) ; continue ;}
        if( C == 3 || C == 4 ) { 
			ans = 0 ;
			For( i , 1 , n ) 
				if( t[ i ].tp == 2 )
					ans += ( t[ i ].num == 2 ) ;
			printf("%d\n" , ans ) ;
		}
        if( C == 5 || C == 6 ) { 
			For( i , 1 , n ){
				if( t[ i ].tp != 2 )
					add( i , t[ i ].num , t[ i ].tp ) , 
					add( t[ i ].num , i , t[ i ].tp ) ;
			}
			For( i , 1 , n ) if( t[ i ].tp == 2 && t[ i ].num == 2 ) val[ i ] = 2 , Dfs( i ) ;
			ans = 0 ; For( i , 1,  n ) ans += ( val[ i ] == 2 ) ;
			printf("%d\n" , ans ) ;
		}
		if( C >= 7 ) {
			For( i , 1 , n ){
				if( t[ i ].tp == 2 ) 
						vis[ i ][ t[ i ].num ] = 1 ;
				else if( t[ i ].num != i ) add( t[ i ].num , i , t[ i ].tp ) ; 
				else if( t[ i ].tp == 1 ) vis[ i ][ 2 ] = 0 ;
			}
			For( i , 1 , n ) {
				if( vis[ i ][ 0 ] ) col( i , 0 ) ;
				if( vis[ i ][ 1 ] ) col( i , 1 ) ;
				if( vis[ i ][ 2 ] ) col( i , 2 ) ;
			}
			For( i , 1 , n ) {
				if( !vis[ i ][ 0 ] && !vis[ i ][ 1 ] && !vis[ i ][ 2 ] )
					vis[ i ][ 0 ] = 1 , col( i , 1 ) ;
			}
			ans = 0 ;
			For( i , 1 , n )
				if( vis[ i ][ 2 ] || ( vis[ i ][ 1 ] && vis[ i ][ 2 ] ) )
					ans ++ ;
			printf("%d\n" , ans ) ;
		}
    }
    return 0 ;
}
