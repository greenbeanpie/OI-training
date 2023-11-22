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
void make(int n,int m,int k,int d,int v){
	cout<<n<<' '<<m<<' '<<k<<' '<<d<<'\n';
	int i,x,y;
	for(i=1;i<=m;i++){
		x=rand()%n+1; y=rand()%n+1; if(x>y) mswap(x,y);
		cout<<y<<' '<<y-x+1<<' '<<rand()%v+1<<'\n';
	}
}
int main(){
	//freopen(".in","r",stdin);
	freopen("run.in","w",stdout);
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
	srand(GetTickCount());
	cout<<"5 2\n"; make(500,200,100,1e9,1e9); make(490,190,90,1e9,1e9);
	return 0;
}
