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
random_device rd;
mt19937 rnd(rd());
int T = 10;
int n,m,k,d;

int main(){
	freopen("run.in","w",stdout);
	printf("0 %d\n",T);
	while(T--){
		if(rnd() % 2) n = rnd() % 2000 + 1;
		else n = rnd() % 10 + 1;
		if(rnd() % 2) m = rnd() % 2000 + 1;
		else m = rnd() % 10 + 1;

		printf("%d %d %d %d\n",n,m,rnd() % n + 1,rnd() % 23 + 1);
		rep(i,1,m){
			int l = rnd() % n + 1,r = rnd() % n + 1;
			if(l > r) swap(l,r);
			printf("%d %d %d\n",r,r - l + 1,rnd() % 233 + 1);
		}
	}
	return 0;
}
//g++ Dgen.cpp -o Dgen -Wall -Wshadow -O2 -std=c++14 -Wno-unused-result