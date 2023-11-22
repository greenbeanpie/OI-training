#include <bits/stdc++.h>
using namespace std;
#define N 3005

int n , m;
string s[ N ] , t[ N ];

bool cmp( char x , char y )
{
	return x > y;
}

signed main()
{
	freopen( "dict.in" , "r" , stdin );
	freopen( "dict.out" , "w" , stdout );
	
	scanf( "%d%d" , & n , & m );
	for( int i = 1 ; i <= n ; i ++ ) //O(nmlogm)
	{
		cin >> s[ i ];
		t[ i ] = s[ i ];
		sort( t[ i ].begin() , t[ i ].end() , cmp );
	}
	
	for( int i = 1 ; i <= n ; i ++ ) //O(nmlogm)
	{
		bool flag = true;
		string tmp = s[ i ];
		sort( tmp.begin() , tmp.end() );
		
		for( int j = 1 ; j <= n ; j ++ )
		{
			if( j == i )
				continue;
			
			flag = ( flag && tmp < t[ j ] );
		}
		
		printf( flag ? "1" : "0" );
	}
	return 0;
}