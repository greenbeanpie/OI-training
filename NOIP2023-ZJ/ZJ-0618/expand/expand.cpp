//T3
//Written by Naught
//menghun'guoguan? If you don't want to give me some points,just say it,there's no need to be shy,(beyond?).
#include<bits/stdc++.h>
using namespace std;

typedef int ll ;
#define Maxn 1005
#define fo(i,l,r) for ( int i = l ; i <= r ; ++i )

inline ll read(ll x=0,bool f=0,char c=getchar()) {while(!isdigit(c)) f=c=='-',c=getchar();while(isdigit(c)) x=(x<<1)+(x<<3)+(c^48),c=getchar();return f?-x:x;};

ll opt , n , m , q ;
ll kx , ky ;
ll p , v ;
ll a[Maxn] , b[Maxn] ;

int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	opt = read() , n = read() , m = read() , q = read() ;
	fo ( i , 1 , n ) a[i] = read() ;
	fo ( i , 1 , m ) b[i] = read() ;
	if ( opt == 1 )
	{
		if ( a[1] == b[1] ) printf ( "0" ) ;
		else printf( "1" ) ;
		while ( q-- )
		{
			kx = read() , ky = read() ;
			fo ( i , 1 , kx )
			{
				p = read() , v = read() ;
				a[p] = v ;
			}
			fo ( i , 1 , ky )
			{
				p = read() , v = read() ;
				b[p] = v ;
			}
			if ( a[1] == b[1] ) printf ( "0" ) ;
			else printf ( "1" ) ;
		}
	}
	else if ( opt == 2 )
	{
		sort ( a+1 , a+n+1 ) ;
		sort ( b+1 , b+m+1 ) ;
		if ( n == 2 && m == 2 )
		{
			if ( (a[1]>b[1]&&a[2]>b[2]) || (a[1]<b[1]&&a[2]<b[2]) ) printf ( "1" ) ;
			else printf ( "0" ) ;
			while ( q-- ) 
			{
				kx = read() , ky = read() ;
				fo ( i , 1 , kx )
				{
					p = read() , v = read() ;
					a[p] = v ;
				}
				fo ( i , 1 , ky )
				{
					p = read() , v = read() ;
					b[p] = v ;
				}
				if ( (a[1]>b[1]&&a[2]>b[2]) || (a[1]<b[1]&&a[2]<b[2]) ) printf ( "1" ) ;
				else printf ( "0" ) ;				
			}		
		}
		else if ( n == 1 && m == 1 ) 
		{
			if ( a[1] == b[1] ) printf ( "0" ) ;
			else printf( "1" ) ;
			while ( q-- )
			{
				kx = read() , ky = read() ;
				fo ( i , 1 , kx )
				{
					p = read() , v = read() ;
					a[p] = v ;
				}
				fo ( i , 1 , ky )
				{
					p = read() , v = read() ;
					b[p] = v ;
				}
				if ( a[1] == b[1] ) printf ( "0" ) ;
				else printf ( "1" ) ;
			}
		}
		else
		{
			if ( n < m ) 
			{
				if ( (a[1]>b[1]&&a[1]<b[2]) || a[1] == b[1] || a[1] == b[2] ) printf ( "0" ) ;
				else printf ( "1" ) ;
				while ( q-- )
				{
					kx = read() , ky = read() ;
					fo ( i , 1 , kx )
					{
						p = read() , v = read() ;
						a[p] = v ;
					}
					fo ( i , 1 , ky )
					{
						p = read() , v = read() ;
						b[p] = v ;
					}
					if ( b[1] > b[2] ) swap ( b[1] , b[2] ) ;
					if ( (a[1]>b[1]&&a[1]<b[2]) || a[1] == b[1] || a[1] == b[2] ) printf ( "0" ) ;
					else printf ( "1" ) ;
				}
			}
			else
			{
				if ( (b[1]>a[1]&&b[1]<a[2]) || b[1] == a[1] || b[1] == a[2] ) printf ( "0" ) ;
				else printf ( "1" ) ;
				while ( q-- )
				{
					kx = read() , ky = read() ;
					fo ( i , 1 , kx )
					{
						p = read() , v = read() ;
						a[p] = v ;
					}
					fo ( i , 1 , ky )
					{
						p = read() , v = read() ;
						b[p] = v ;
					}
					if ( a[1] > a[2] ) swap ( a[1] , a[2] ) ;
					if ( (b[1]>a[1]&&b[1]<a[2]) || b[1] == a[1] || b[1] == a[2] ) printf ( "0" ) ;
					else printf ( "1" ) ;
				}
			}
		}
	}
	else
	{
		printf ( "1" ) ;
		while (q--) printf ( "1" ) ;
	}
	return 0 ;
}