#include<bits/stdc++.h>
using namespace std;

typedef int ll ;
#define Maxn 100005
#define fo(i,l,r) for ( int i = l ; i <= r ; ++i )

inline ll read(ll x=0,bool f=0,char c=getchar()) {while(!isdigit(c)) f=c=='-',c=getchar();while(isdigit(c)) x=(x<<1)+(x<<3)+(c^48),c=getchar();return f?-x:x;};

ll opt , T ;
ll n , t ;
ll a[5] , b[5] , ans ;
ll x , y ;
char c , ch[Maxn] ;	

map <char,int> mp;

void kkk()
{
	mp['T'] = 1 , mp['F'] = 2 , mp['U'] = 3 ;
	a[1] = 1 , a[2] = 2 , a[3] = 3 ;
	b[1] = 2 , b[2] = 1 , b[3] = 3 ;
}

int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	kkk() ;
	opt = read() , T = read() ;
	if ( opt == 3 || opt == 4 )
	{
		ll num[5] , zb[Maxn] ;
		while ( T-- )
		{
			num[3] = 0 ; 
			ans = 0 ;
			n = read() , t = read() ;
			fo ( i , 1 , n ) ch[i] = 'A' ;
			while(t--)
			{
				cin >> c ;
				x = read() ;
				ch[x] = c ;
			}
			fo ( i , 1 , n ) if ( ch[i] == 'U' ) ++ans ;
			printf  ( "%d\n" , ans ) ;
		}
	}
	else if ( opt == 5 || opt== 6 ) // ji
	{
		bool d[Maxn] ;
		while ( T-- )
		{
			ans = 0 ;
			n = read() , t = read() ;
			fo ( i , 1 , n ) d[i] = false ;
			while(t--)
			{
				cin >> c ;
				if ( c == '+' )
				{
					x = read() , y = read() ;
					d[x] = d[y] ;
				}
				else
				{
					x = read() ;
					d[x] = read() ;
				}
			}
			fo ( i , 1 , n ) if ( d[i] ) ++ans ;
			printf ( "%lld\n" , ans ) ;
		}
		
	}
	else if ( opt == 7 || opt == 8 )
	{
		while ( T-- )
		{
			
		}
	}
	return 0 ;
}  