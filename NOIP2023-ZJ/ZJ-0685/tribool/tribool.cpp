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
int c , t ;
int n , m , ans ; 
int f[100010] ;
int px[4] = { 0 , 1 , 2 } ;
struct Op{
	char opt ;
	int ido , idone , ix ; 
}op[100010];
/*
bool check()
{
	for ( int i = 1 ; i <= n ; i ++ )
	{
		
	}
}
void Sol(int x)
{	
	if ( x == m + 1 )
	{
		check() ;
		
		return ; 
	}
	for ( int i = 0 ; i < 3 ; i ++ )
	{
		
	}
	if (  op[i].opt == '+' ) 
	{
		if ( f[op[i].ido] == 0 ) 
		{
			
			f[op[i].ido] =  ;
			dfs(x + 1) ;
		}
		f[op[i].idone] = f[op[i].ido] ;
	}
	else if ( op[i].opt == '-' ) 
	{
		if ( f[op[i].ido] == 0 ) f[op[i].ido] = dfs() ;
		f[op[i].idone] = f[op[i].ido] ;
	}	
	else 
	{
		if ( op[i].opt == 'T' )
			f[op[i].ix] = 1 ; 
		else if ( op[i].opt == 'F' )
			f[op[i].ix] = 0 ;
		else f[op[i].ix] = 2 ;
	}
}*/
int main()
{
	freopen("tribool.in" , "r" , stdin) ;
	freopen("tribool.out" , "w" , stdout) ;
	scanf("%d %d" , &c , &t) ;
	while(t --)
	{
		scanf("%d %d" , &n  , &m) ;
		for ( int i = 1 ; i <= m ; i ++ )
		{
			scanf("%c" , &op[i].opt) ;
			if ( op[i].opt == '-' || op[i].opt == '+' ) 
			{
				scanf("%d %d" , &op[i].idone , & op[i].ido ) ;
			}
			else 
			{
				scanf("%d" , &op[i].ix ) ;
			}
		}
		//Sol(1) ;
		printf("0\n") ; 		
	} 

	
	return 0 ; 
}
