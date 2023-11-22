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
	//freopen(".out","w",stdout);
	//cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
	int i,T; cin>>T;
	for(i=1;i<=T;i++){
		printf("-----[test%d]-----\n",i);
		system("maker"); system("bf");
		if(system("dict")){ puts("RE"); return 0; }
		if(system("fc dict.out dict.ans")) return 0;
	}
	return 0;
}
