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
int T = 233;
int n,m;
random_device rd;
mt19937 rnd(rd());

void solve(){
	n = rnd() % 10 + 1;m = rnd() % 233 + 1;
	printf("%d %d\n",n,m);
	rep(i,1,m){
		int op = rnd() % 5 + 1,x = rnd() % n + 1,y = rnd() % n + 1;
		if(op == 1) printf("+ %d %d\n",x,y);
		else if(op == 2) printf("- %d %d\n",x,y);
		else if(op == 3) printf("T %d\n",x);
		else if(op == 4) printf("F %d\n",x);
		else printf("U %d\n",x);
	}
}

int main(){
	freopen("tribool.in","w",stdout);

	printf("0 %d\n",T);
	while(T--) solve();
	return 0;
}
//g++ Bgen.cpp -o Bgen -Wall -Wshadow -O2 -std=c++14 -Wno-unused-result