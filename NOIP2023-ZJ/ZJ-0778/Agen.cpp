#include <bits/stdc++.h>
#define rep(i,j,k) for(int i = (j);i <= (k);i++)
#define per(i,j,k) for(int i = (j);i >= (k);i--)
#define ll long long
#define pii pair<int,int>
#define SZ(S) (int)S.size()
#define mkp make_pair
#define uint unsigned int
using namespace std;

template <class P>
void chkmax(P &x,P y){
	if(x < y) x = y;
}

template <class Q>
void chkmin(Q &x,Q y){
	if(x > y) x = y;
}
int n,m;

int main(){
	freopen("dict.in","w",stdout);
	random_device rd;
	mt19937 rnd(rd());
	if(rnd() % 2) n = rnd() % 233 + 1;
	else n = rnd() % 3 + 1;
	if(rnd() % 2) m = rnd() % 233 + 1;
	else m = rnd() % 3 + 1;
	int sz = rnd() % 26 + 1;
	printf("%d %d\n",n,m);
	rep(i,1,n){
		rep(j,1,m) printf("%c",rnd() % sz + 'a');
		printf("\n");
	}
	return 0;
}
//g++ Agen.cpp -o Agen -Wall -Wshadow -O2 -std=c++14 -Wno-unused-result