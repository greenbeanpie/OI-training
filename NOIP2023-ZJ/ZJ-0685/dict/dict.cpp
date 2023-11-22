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
typedef long long ll ;
*/
int n , m ;
int box[30][3010] , fbox[30][3010] , pd[3010];
string s[3010];

int main()
{
	freopen("dict.in" , "r" , stdin) ;
	freopen("dict.out" , "w" , stdout) ;
/*
	ios::sync_with_stdio(false);
	cin.tie(0) ;
	cout.tie(0) ;
*/
	cin >> n >> m ;
	for ( int i = 1; i <= n ; i ++ )
	{
		cin >> s[i] ;
	}
	if ( n == 1 ) 
	{
		cout << 1 ;
		return 0 ;
	}
	else
	{
		for ( int i = 1 ; i <= n ; i ++ )
		{
			for ( int j = 0 ; j < m ; j ++ )
			{
				box[(int)s[i][j] - 'a' + 1][i] ++ ;
			}
		}
		for ( int i = 1 ; i <= n ; i ++ )
		{
			for ( int j = 1 ; j <= 26 ; j ++ )
			{
				fbox[j][i] = box[j][i] ;
			}
		}

		for ( int i = 1 ; i <= n ; i ++ )
		{
			int flag = 1 ; 
			for ( int j = 1 ; j <= n ; j ++ )
			{
				for ( int k = 1 ; k <= 26 ; k ++ ) 
				{
					box[k][i] = fbox[k][i] ;
					box[k][j] = fbox[k][j] ;
				}
				
				
				if ( j == i ) continue ;	
				int posi = 1 , posj = 26  ;
		
				/*
				if ( flag == 0 )
				{
					//if ( i == 10 )cout << s[i] << " " << s[j - 1] << endl ;
					break ;
				} 
				*/
				
			//	cout << i << "  " << j << " : " << endl; 
			
			
				while( posi <= 26 && posj >= 1 ) 
				{
					while( box[posi][i] == 0 && posi <= 26 ) posi ++ ;
					while( box[posj][j] == 0 && posj >= 1 ) posj -- ;
		
			/*		cout << posi << " : "<< (char)((int)'a' + posi - 1) << " "
						 << posj << " : "<< (char)((int)'a' + posj - 1) << endl ; 
					cout << box[posi][i] << " " << box[posj][j] << endl ;
			*/
 					if ( posi > 26 || posj < 1)
					{ 
						break ;
					}
					if ( posi == posj )
					{
						int  minx = min(box[posi][i] , box[posj][j]) ;
						if ( minx == m )
						{
							flag = 0 ; 
							break ;
						}
						box[posi][i] -= minx ; box[posj][j] -= minx ;
			//			cout << posi << " : " << box[posi][i] << "    " << posj << " : " << box[posj][j] << endl ; 
						if ( box[posj][j] > 0 || box[posi][i] > 0 ) 
						{
							flag = 0 ;
							break ;
						}
						else break ;
					}
					else if ( posi < posj )
					{
						break ;	
					} 
					else 
					{
						flag = 0 ; 
						break ;
					}
				}
	
		//		cout << endl ;
	
			}
	
		//	cout  << i << " " << flag << endl ;
	
			if ( flag == 1 ) 
			{
				pd[i] = 1 ;
			}
			else 
			{
				pd[i] = 0 ;
			}	
		}	
		for ( int i = 1 ; i <= n ; i ++ )
		{
			cout << pd[i] ; 	
		}	
		//cout << endl ;
	}
	
	return 0 ; 
}
/*
15 2
zx
qn
wn
nd
pl
pd
vm
ff
mh
ql ???? 
zi
yv
md
ji
oc
*/
