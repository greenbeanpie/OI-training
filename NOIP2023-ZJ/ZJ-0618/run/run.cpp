#include<bits/stdc++.h>
using namespace std;

typedef int ll ;
#define Maxn 100005
#define fo(i,l,r) for ( int i = l ; i <= r ; ++i )

inline ll read(ll x=0,bool f=0,char c=getchar()) {while(!isdigit(c)) f=c=='-',c=getchar();while(isdigit(c)) x=(x<<1)+(x<<3)+(c^48),c=getchar();return f?-x:x;};

ll c , T ;
ll n , m , k , d ;

int main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	c = read() , T = read() ;
	while ( T-- ) 
	{
		n = read() , m = read() , k = read() , d = read() ;
//		??? 
	}
	return 0 ;
}