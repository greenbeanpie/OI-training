//T1
//Written by Naught
#include<bits/stdc++.h>
using namespace std;

typedef int  ll ;
#define fo(i,l,r) for ( int i = l ; i <= r ; ++i )
#define Maxn 3005

inline ll read(ll x=0,bool f=0,char c=getchar()) {while(!isdigit(c)) f=c=='-',c=getchar();while(isdigit(c)) x=(x<<1)+(x<<3)+(c^48),c=getchar();return f?-x:x;};

ll n , m ;
string s ;
ll zm[30] , k ;
ll l , r , mid ;
bool f , da , xi ;
char s_max[Maxn][Maxn] , s_min[Maxn][Maxn] ;


void solve ( string s , ll pos ) 
{
	fo(i,0,m-1) ++zm[s[i]-'a'] ;
	k = 0 ;
	while ( k < m )
	{
		fo ( c , 0 , 25 )
		{
			fo ( i , 0 , zm[c] )
			{
				s_min[pos][k+i] = (char)('a'+c) ;
			}
			k += zm[c] ;
			if ( k >= m ) break ; 
		}
	}
	k = 0 ;
	while ( k < m )
	{
		for ( ll c = 25 ; c >= 0 ; --c )
		{
			fo ( i , 0 , zm[c] )
			{
				s_max[pos][k+i] = (char)('a'+c) ;
			}
			k += zm[c] ;
			if ( k >= m  ) break ;
		}
	}
}

bool comp ( char x[] , char y[] )
{
	fo ( i , 0 , m-1 )
	{
		if ( x[i] != y[i] ) 
		{
			return x[i] > y[i] ;
		}
	}
	return false ;
}

int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	n = read() , m = read() ;
	fo(i,1,n)
	{
		fo(c,0,26) zm[c] = 0 ;
		cin>>s ;
		solve ( s , i ) ;
	}
	
	fo ( i , 1 , n  )
	{
		f = true ;
		fo ( j , 1 , n )
		{
			if ( !f ) break ;
			if ( j == i ) continue ;
			if ( comp ( s_min[i] , s_max[j] ) ) f = false ;
		}
		if ( f ) printf ( "1" ) ;
		else printf ( "0" ) ;
	}
	
	return 0 ;
}

/*
	// I know the following algorithm is O((n^2)*m) and could get 80pts at most .
	// And I certainly know the Part2 of the right answer.
	//after getting the position and its number of s_max(Being sorted),Ican use two strings to get the answer(O(nm)).
	// But I don't know how to achieve the Part1 <- get all of the s_max and sort it .
	// I know that , but no time....
	//	if ( comp( s_max[1] , s_max[2] ) )
//	{
//		a=1,b=2;
//	}
//	else
//	{
//		b=1,a=2;
//	}
//	
//	fo ( j , 3 , n )
//	{
//		if ( comp ( s_max[j] , s_max[a] ) )
//		{
//			b = a ;
//			a = j ;
//		}
//		else if ( comp ( s_max[j] , s_max[b] ) )
//		{
//			b = j ;
//		}
//	}
//	fo ( i , 1 , n ) 
//	{
//		if ( a!=i )
//		{
//			if ( comp(s_min[i],s_max[a]) ) printf ( "0" ) ;
//			else printf ( "1" ) ;
//		}
//		else
//		{
//			if ( comp(s_min[i],s_max[b]) ) printf ( "0" ) ;
//			else printf ( "1" ) ;
//		}
//	}
//	fo ( i , 1 , n  )
//	{
//		f = true ;
//		fo ( j , 1 , n )
//		{
//			if ( !f ) break ;
//			if ( j == i ) continue ;
//			if ( comp ( s_min[i] , s_max[j] ) ) f = false ;
//		}
//		if ( f ) printf ( "1" ) ;
//		else printf ( "0" ) ;
//	}
*/
