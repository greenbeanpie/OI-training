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
int n,m,q;

int main(){
	freopen("expand.in","w",stdout);
	if(rnd() % 2) n = rnd() % 1000 + 1;
	else n = rnd() % 5 + 1;
	if(rnd() % 2) m = rnd() % 1000 + 1;
	else m = rnd() % 5 + 1;
	q = rnd() % 60 + 1;
	printf("0 %d %d %d\n",n,m,q);
	rep(i,1,n) printf("%d ",rnd() % (n + m));
	printf("\n");
	rep(i,1,m) printf("%d ",rnd() % (n + m));
	printf("\n");

	rep(i,1,q){
		int kx = rnd() % n + 1,ky = rnd() % m + 1;
		printf("%d %d\n",kx,ky);
		while(kx--){
			printf("%d %d\n",rnd() % n + 1,rnd() % (n + m));
		}
		while(ky--){
			printf("%d %d\n",rnd() % m + 1,rnd() % (n + m));			
		}
	}
	return 0;
}
//g++ Cgen.cpp -o Cgen -Wall -Wshadow -O2 -std=c++14 -Wno-unused-result