#include<cstdio>
#include<iostream>
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
	freopen("1.in","w",stdout);
	//cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
	puts("0 2000 2000 60"); int i;
	for(i=1;i<=2000;i++) cout<<i<<" \n"[i==2000];
	for(i=1;i<=2000;i++) cout<<i+1<<" \n"[i==2000];
	for(i=1;i<=60;i++) puts("0 0");
	return 0;
}
