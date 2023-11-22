#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<windows.h>
#define ll long long
#define ull unsigned ll
#define Tp template<typename _T>
Tp _T mabs(_T x){ return x<0?-x:x; }
Tp _T mmin(_T x,_T y){ return x<y?x:y; }
Tp _T mmax(_T x,_T y){ return x<y?y:x; }
Tp void mswap(_T &x,_T &y){ _T t=x; x=y; y=t; return; }
using namespace std;
#define maxn
int main(){
	//freopen(".in","r",stdin);
	freopen("dict.in","w",stdout);
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
	srand(GetTickCount());
	int n=1000,m=5,i,j; cout<<n<<' '<<m<<'\n';
	for(i=1;i<=n;i++) for(j=1;j<=m;j++)
		cout<<char('a'+rand()%3),(j==m)&&(cout<<'\n');
	return 0;
}
