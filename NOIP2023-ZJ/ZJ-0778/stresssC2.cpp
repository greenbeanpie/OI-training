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
	n = m = 500000;
	q = 60;
	printf("0 %d %d %d\n",n,m,q);
	rep(i,1,n) printf("%d ",i + 1);
	printf("\n");
	rep(i,1,m) printf("%d ",i);
	printf("\n");

	rep(i,1,q){
		int kx = rnd() % (n / q) + 1,ky = rnd() % (m / q) + 1,pos;
		printf("%d %d\n",kx,ky);
		while(kx--){
			pos = rnd() % n + 1;
			printf("%d %d\n",pos + 1,pos);
		}
		while(ky--){
			pos = rnd() % m + 1;
			printf("%d %d\n",pos + 1,pos);
		}
	}
	return 0;
}
//g++ stressC.cpp -o stressC -Wall -Wshadow -O2 -std=c++14 -Wno-unused-result